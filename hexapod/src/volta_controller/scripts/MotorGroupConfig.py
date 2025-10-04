#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64MultiArray, Int16
from cybergear_interfaces.msg import MotorControlGroup, MotorControl
from cybergear_interfaces.srv import SetParam, SetMotionGain
from std_msgs.msg import Header
from sensor_msgs.msg import JointState
import math
import numpy as np
import time
import os

from std_msgs.msg import Header, ColorRGBA
from visualization_msgs.msg import Marker

from rclpy.qos import QoSProfile, ReliabilityPolicy

class MotorGroupConfigPublisher(Node):
    def __init__(self):
        super().__init__('motor_group_config_publisher')
        self.DefinedVariables()
        self.CreatePublisher()
        self.CreateSubscriber()
        self.CreateServiceCli()

    def DefinedVariables(self)->None:
        # Dictionary to store current motor parameters
        self.motor_params = {}
        
        # Define which motor IDs are valid in your system
        self.valid_motor_ids = [1]
        self.joint_names = [
            'motor_1'
        ]
        self.tau_id = np.zeros(len(self.valid_motor_ids))
        # Default values for each parameter
        self.default_values = {
            'position': 0.0,
            'velocity': 0.0,
            'effort': 0.0,
            'kp': 0.65,
            'kd': 0.2
        }
        # Initialize motor params with default values
        for mid in self.valid_motor_ids:
            self.motor_params[mid] = self.default_values.copy()
            # Set default positions based on your original code
            if mid == 1 or mid == 4:
                self.motor_params[mid]['position'] = np.deg2rad(0.0)
            elif mid == 2 or mid == 5:
                self.motor_params[mid]['position'] = np.deg2rad(0.0)
            elif mid == 3 or mid == 6:
                self.motor_params[mid]['position'] = np.deg2rad(0.0)
        self.timer_period = 1.0/500.0
        self.timer = self.create_timer(self.timer_period, self.TimerCallback)
        self.get_logger().info("Motor Control Group Publisher started")
        self.desired_joints_position = np.zeros(len(self.valid_motor_ids))
        self.desired_joints_velocity = np.zeros(len(self.valid_motor_ids))
        self.controller_enabled = 0

    def CreatePublisher(self)->None:
        self.publisher_ = self.create_publisher(MotorControlGroup, 
                                                'motor_group_command', 10)
    
    def CreateSubscriber(self)->None:
        # Create a sensor-style QoS profile
        sensor_qos = QoSProfile(depth=10)
        sensor_qos.reliability = ReliabilityPolicy.BEST_EFFORT
        self.create_subscription(
            JointState,
            '/joint_states',
            self.JointStateCallback,
            qos_profile=sensor_qos
        )
        self.create_subscription(Float64MultiArray,
                                 '/tau_id', 
                                 self.TauidCallBack, 10)
        
        self.desired_joint_position_sub = self.create_subscription(
            Float64MultiArray,
            '/desired_joints_position',
            self.DesiredJointPositionCallback,
            10
        )
        self.desired_joint_velocity_sub = self.create_subscription(
            Float64MultiArray,
            '/desired_joints_velocity',
            self.DesiredJointVelocityCallback,
            10
        )
        self.controller_enabled_sub = self.create_subscription(
            Int16,
            '/controller_enabled_command',
            self.ControllerEnabledCallback,
            10
        )
        
    def CreateServiceCli(self)->None:
        self.cli = self.create_client(SetParam, 'setparam')
        if not self.cli.wait_for_service(timeout_sec=5.0):
            self.get_logger().error("setparam service not available after 5s")
            rclpy.shutdown()
            return   
    
    def TimerCallback(self):
        """Regularly publish the current motor parameters to the motor_group_command topic."""
        
        msg = MotorControlGroup()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = "base_link"
        
        motor_controls = []
        ind = 0
        for mid in self.valid_motor_ids:
            if mid in self.motor_params:
                mc = MotorControl()
                mc.motor_id = mid
                mc.control_mode = 0  # Position control mode
                mc.set_point.position = self.motor_params[mid]["position"]
                # mc.set_point.velocity = self.motor_params[mid]["velocity"]
                mc.set_point.velocity = 3.0
                mc.set_point.effort = 0.0
                if self.controller_enabled:
                    mc.set_point.kp = self.motor_params[mid]["kp"]
                else:
                    mc.set_point.kp = 0.0
                mc.set_point.kd = self.motor_params[mid]["kd"]    
                motor_controls.append(mc)
            ind += 1
        
        msg.motor_controls = motor_controls
        self.publisher_.publish(msg)
        print(msg)
        # self.previous_time = current_time

    def ReadJointStates(self, file_path):
        """
        Reads joint_states.txt of the format:
        time j1 j2 j3 j4 j5 j6
        Returns:
        times: list of float timestamps
        joint_data: dict mapping joint_name -> numpy array of positions
        """
        with open(file_path, 'r') as f:
            lines = [l.strip() for l in f if l.strip()]
        header = lines[0].split()
        joint_names = header[1:]
        data = np.loadtxt(lines[1:], dtype=float)
        times = data[:, 0].tolist()
        positions = data[:, 1:]
        joint_data = {
            name: positions[:, idx]
            for idx, name in enumerate(joint_names)
        }
        return times, joint_data

    def BuildTrajectory(self, file_path):
        """
        Builds a trajectory list of dicts:
        [ { 'time': t0, 'joint1': p0_1, ..., 'joint6': p0_6 },
            { 'time': t1, ... }, ... ]
        """
        times, joint_data = self.ReadJointStates(file_path)
        joint_names = list(joint_data.keys())
        trajectory = []
        for i, t in enumerate(times):
            point = {'time': t}
            for name in joint_names:
                point[name] = joint_data[name][i]
            trajectory.append(point)
        return trajectory

    def JointStateCallback(self, msg: JointState):
        pass
    
    def TauidCallBack(self,msg: Float64MultiArray):
        self.tau_id = msg.data

    def SendRequestSync(self,
                     control_mode: int,
                     motor_id: int,
                     communication_type: int = 0,
                     param_name: str = '',
                     param_value: float = 0.0,
                     timeout_sec: float = 5.0) -> bool:
        """
        Build and send a SetParam request synchronously, waiting for the response.
        Returns True if successful, False if timed out or error occurred.
        """
        # Build the request
        req = SetParam.Request()
        req.control_mode = control_mode
        req.motor_id = motor_id
        req.communication_type = communication_type
        req.param_name = param_name
        req.param_value = param_value

        # Call the service asynchronously
        future = self.cli.call_async(req)
        
        # Wait for the response with timeout
        start_time = time.time()
        while not future.done():
            rclpy.spin_once(self, timeout_sec=0.1)
            if time.time() - start_time > timeout_sec:
                self.get_logger().error(f"Service call timed out after {timeout_sec} seconds")
                return False
                
        # Check if the call was successful
        try:
            response = future.result()
            if response.success:
                self.get_logger().info(f"Service call succeeded: {response.message}")
                return True
            else:
                self.get_logger().error(f"Service call failed: {response.message}")
                return False
        except Exception as e:
            self.get_logger().error(f"Service call raised an exception: {str(e)}")
            return False

    def SendRequest(self,
                     control_mode: int,
                     motor_id: int,
                     communication_type: int = 0,
                     param_name: str = '',
                     param_value: float = 0.0):
        """
        Build and send a SetParam request asynchronously.
        """
        # Build the request
        req = SetParam.Request()
        req.control_mode = control_mode
        req.motor_id = motor_id
        req.communication_type = communication_type
        req.param_name = param_name
        req.param_value = param_value

        # Call the service
        future = self.cli.call_async(req)
        
        # Add a callback to handle the response when it comes
        future.add_done_callback(self.RequestCallback)

    def RequestCallback(self, future):
        """
        Callback for handling service response
        """
        try:
            response = future.result()
            if response.success:
                self.get_logger().info(f"Service call succeeded: {response.message}")
            else:
                self.get_logger().error(f"Service call failed: {response.message}")
        except Exception as e:
            self.get_logger().error(f"Service call raised an exception: {str(e)}")

    def DesiredJointPositionCallback(self, msg: Float64MultiArray):
        if len(msg.data) != len(self.valid_motor_ids):
            self.get_logger().error(f"Received desired position array of length {len(msg.data)}, expected {len(self.valid_motor_ids)}")
            return
        self.desired_joints_position = np.array(msg.data)
        for i, mid in enumerate(self.valid_motor_ids):
            self.motor_params[mid]['position'] = self.desired_joints_position[i]
    
    def DesiredJointVelocityCallback(self, msg: Float64MultiArray):
        if len(msg.data) != len(self.valid_motor_ids):
            self.get_logger().error(f"Received desired velocity array of length {len(msg.data)}, expected {len(self.valid_motor_ids)}")
            return
        self.desired_joints_velocity = np.array(msg.data)
        for i, mid in enumerate(self.valid_motor_ids):
            self.motor_params[mid]['velocity'] = self.desired_joints_velocity[i]

    def SetMotionGainCallback(self, request, response):
        """Callback function for the SetMotionGain service."""
        self.get_logger().info(f"Received request: motor_id={request.motor_id}, param={request.param_name}")
        
        # Validate motor_id
        if request.motor_id != 0 and request.motor_id not in self.valid_motor_ids:
            response.success = False
            response.message = f"Invalid motor_id: {request.motor_id}. Valid IDs are: {self.valid_motor_ids} or 0 for all motors."
            return response
        
        # Validate param_name
        if request.param_name not in self.default_values:
            response.success = False
            response.message = f"Invalid param_name: {request.param_name}. Valid parameters are: {list(self.default_values.keys())}"
            return response
        
        # Determine which motors to update
        motors_to_update = self.valid_motor_ids if request.motor_id == 0 else [request.motor_id]
        
        # Update the specified parameter for all selected motors
        for mid in motors_to_update:
            # Get current parameters for this motor
            motor_param = self.motor_params.get(mid, self.default_values.copy())
            
            # Update the specified parameter
            if request.param_name == "position":
                motor_param["position"] = np.deg2rad(request.position)
            elif request.param_name == "velocity":
                motor_param["velocity"] = request.velocity
            elif request.param_name == "effort":
                motor_param["effort"] = request.effort
            elif request.param_name == "kp":
                motor_param["kp"] = request.kp
            elif request.param_name == "kd":
                motor_param["kd"] = request.kd
            
            # Store updated parameters
            self.motor_params[mid] = motor_param
        
        # Set response
        response.success = True
        if request.motor_id == 0:
            response.message = f"Updated {request.param_name} for all motors"
        else:
            response.message = f"Updated {request.param_name} for motor {request.motor_id}"
        
        return response

    def ControllerEnabledCallback(self, msg: Int16):
        self.controller_enabled = msg.data
        self.get_logger().info(f"Controller enabled set to: {self.controller_enabled}")

    def DestroyNode(self):
        super().DestroyNode()

def main(args=None):
    rclpy.init(args=args)
    node = MotorGroupConfigPublisher()
    
    try:
        node.get_logger().info("Motor Control Group Publisher running. Use Ctrl+C to stop.")
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info("Service stopped by keyboard interrupt")
    finally:
        # node.DestroyNode()
        rclpy.shutdown()

if __name__ == '__main__':
    main()