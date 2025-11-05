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
import csv
from datetime import datetime

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

        # Sine wave torque parameters
        self.start_time = time.time()
        self.sine_amplitude = 1.0  # Torque amplitude in Nm
        self.sine_frequency = 1.0  # Frequency in Hz (1 cycle per second)

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
        
        # For acceleration calculation
        self.current_velocity = np.zeros(len(self.valid_motor_ids))
        self.previous_velocity = np.zeros(len(self.valid_motor_ids))
        self.current_acceleration = np.zeros(len(self.valid_motor_ids))
        self.current_position = np.zeros(len(self.valid_motor_ids))
        self.current_effort = np.zeros(len(self.valid_motor_ids))
        self.last_velocity_time = None
        self.current_velocity_time = None
        
        # CSV logging setup
        self.csv_logging_enabled = True  # Set to False to disable logging
        if self.csv_logging_enabled:
            self.setup_csv_logging()

    def CreatePublisher(self)->None:
        self.publisher_ = self.create_publisher(MotorControlGroup, 
                                                'motor_group_command', 10)
        # Publisher for joint acceleration
        self.acceleration_publisher_ = self.create_publisher(
            Float64MultiArray,
            '/joint_acceleration',
            10
        )
    
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
        # if not self.cli.wait_for_service(timeout_sec=5.0):
        #     self.get_logger().error("setparam service not available after 5s")
        #     rclpy.shutdown()
        #     return
    
    def setup_csv_logging(self):
        """Setup CSV file for logging motor data"""
        # Create logs directory if it doesn't exist
        log_dir = os.path.expanduser('~/motor_logs')
        os.makedirs(log_dir, exist_ok=True)
        
        # Create filename with timestamp
        timestamp = datetime.now().strftime('%Y%m%d_%H%M%S')
        self.csv_filename = os.path.join(log_dir, f'motor_data_{timestamp}.csv')
        
        # Open CSV file and write header
        self.csv_file = open(self.csv_filename, 'w', newline='')
        self.csv_writer = csv.writer(self.csv_file)
        
        # Write header row
        header = ['timestamp', 'time_sec']
        for i, motor_id in enumerate(self.valid_motor_ids):
            header.extend([
                f'motor_{motor_id}_position',
                f'motor_{motor_id}_velocity',
                f'motor_{motor_id}_effort',
                f'motor_{motor_id}_acceleration'
            ])
        self.csv_writer.writerow(header)
        
        self.get_logger().info(f'CSV logging enabled: {self.csv_filename}')
    
    def log_to_csv(self):
        """Log current motor data to CSV file"""
        if not self.csv_logging_enabled or not hasattr(self, 'csv_writer'):
            return
        
        # Get current timestamp
        current_time = time.time()
        time_sec = current_time - self.start_time
        
        # Build data row
        row = [current_time, time_sec]
        for i, motor_id in enumerate(self.valid_motor_ids):
            row.extend([
                self.current_position[i],
                self.current_velocity[i],
                self.current_effort[i],
                self.current_acceleration[i]
            ])
        
        self.csv_writer.writerow(row)
        
        # Flush periodically (every 100 rows) to ensure data is written
        if not hasattr(self, 'csv_row_count'):
            self.csv_row_count = 0
        self.csv_row_count += 1
        if self.csv_row_count % 100 == 0:
            self.csv_file.flush()
    
    def TimerCallback(self):
        """Regularly publish the current motor parameters to the motor_group_command topic."""

        msg = MotorControlGroup()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = "base_link"

        motor_controls = []
        ind = 0

        # คำนวณ sine wave torque
        current_time = time.time() - self.start_time
        sine_torque = self.sine_amplitude * math.sin(2 * math.pi * self.sine_frequency * current_time)

        for mid in self.valid_motor_ids:
            if mid in self.motor_params:
                mc = MotorControl()
                mc.motor_id = mid
                mc.control_mode = 0  # MIT mode = 0 (pure torque control)

                # อ่าน velocity และ acceleration feedback
                velocity = self.current_velocity[ind]
                acceleration = self.current_acceleration[ind]

                mc.set_point.position = 0.0       # ไม่ใช้ position control
                mc.set_point.velocity = 0.0       # ไม่ใช้ velocity setpoint
                mc.set_point.effort = sine_torque  # ส่ง sine wave torque
                mc.set_point.kp = 0.0             # ไม่ใช้ position gain
                mc.set_point.kd = 0.0             # ไม่ใช้ velocity gain (MIT built-in)

                motor_controls.append(mc)

                # แสดงข้อมูลการคำนวณ
                self.get_logger().info(
                    f"Motor {mid}: time={current_time:.3f}s, "
                    f"sine_torque={sine_torque:.3f} Nm, "
                    f"vel={velocity:.3f} rad/s, "
                    f"acc={acceleration:.3f} rad/s²",
                    throttle_duration_sec=0.5  # แสดงทุก 0.5 วินาที
                )
            ind += 1

        msg.motor_controls = motor_controls
        self.publisher_.publish(msg)

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
        """อ่าน velocity feedback จาก joint states และคำนวณ acceleration"""
        # Debug: Check what joint names we received
        self.get_logger().info(
            f"Received joints: {msg.name}, Looking for: {self.joint_names}",
            throttle_duration_sec=2.0
        )
        
        # Update time stamps
        self.last_velocity_time = self.current_velocity_time
        self.current_velocity_time = msg.header.stamp.sec + msg.header.stamp.nanosec * 1e-9
        
        # Create a temporary array to store new velocity values
        new_velocity = np.zeros(len(self.valid_motor_ids))
        
        # Update new velocity, position, and effort from message
        velocity_updated = False
        for i, name in enumerate(self.joint_names):
            if name in msg.name:
                idx = msg.name.index(name)
                if idx < len(msg.velocity):
                    new_velocity[i] = msg.velocity[idx]
                    velocity_updated = True
                    self.get_logger().info(
                        f"Found {name} at index {idx}, velocity={msg.velocity[idx]:.6f}",
                        throttle_duration_sec=2.0
                    )
                # Update position and effort as well
                if idx < len(msg.position):
                    self.current_position[i] = msg.position[idx]
                if idx < len(msg.effort):
                    self.current_effort[i] = msg.effort[idx]
        
        if not velocity_updated:
            self.get_logger().warn(
                f"No matching joint names found! Expected: {self.joint_names}, Got: {msg.name}",
                throttle_duration_sec=2.0
            )
            return
        
        # Calculate acceleration (dv/dt) BEFORE updating current_velocity
        if self.last_velocity_time is not None and self.current_velocity_time is not None:
            dt = self.current_velocity_time - self.last_velocity_time
            
            # Handle divide by zero
            if dt > 1e-6:  # Only calculate if dt is greater than 1 microsecond
                self.current_acceleration = (new_velocity - self.current_velocity) / dt
                
                # Debug logging (throttled)
                self.get_logger().info(
                    f"Accel calc: dt={dt:.6f}s, "
                    f"prev_vel={self.current_velocity}, "
                    f"new_vel={new_velocity}, "
                    f"accel={self.current_acceleration}",
                    throttle_duration_sec=1.0
                )
                
                # Publish acceleration topic
                acc_msg = Float64MultiArray()
                acc_msg.data = self.current_acceleration.tolist()
                self.acceleration_publisher_.publish(acc_msg)
                
                # Log data to CSV
                self.log_to_csv()
            else:
                # If dt is too small, keep previous acceleration
                self.get_logger().warn(
                    f"Time difference too small (dt={dt:.9f}s), keeping previous acceleration",
                    throttle_duration_sec=1.0
                )
        else:
            self.get_logger().info("First callback - initializing timestamps", once=True)
        
        # NOW update current velocity for next iteration
        self.current_velocity = new_velocity.copy()
    
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
    
    def ZeroPositionCallback(self, request, response):
        """
        Service callback to set current position as zero reference.
        This stores the current position as an offset so that subsequent readings are relative to this point.
        """
        try:
            # Store current position as offset
            for i in range(len(self.valid_motor_ids)):
                # Add current position to offset (so new readings will be zeroed)
                self.position_offset[i] += self.current_position[i]
            
            response.success = True
            response.message = f"Position zeroed for motors {self.valid_motor_ids}. Current positions set to zero."
            self.get_logger().info(f"Position zeroed. Offset: {self.position_offset}")
            
        except Exception as e:
            response.success = False
            response.message = f"Failed to zero position: {str(e)}"
            self.get_logger().error(f"Error zeroing position: {str(e)}")
        
        return response

    def DestroyNode(self):
        # Close CSV file if it's open
        if self.csv_logging_enabled and hasattr(self, 'csv_file'):
            self.csv_file.close()
            self.get_logger().info(f'CSV file closed: {self.csv_filename}')
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
        # Close CSV file before shutdown
        if node.csv_logging_enabled and hasattr(node, 'csv_file'):
            node.csv_file.close()
            node.get_logger().info(f'CSV file saved: {node.csv_filename}')
        # node.DestroyNode()
        rclpy.shutdown()

if __name__ == '__main__':
    main()