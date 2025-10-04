#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy, DurabilityPolicy
from rclpy.qos import (
    QoSProfile, QoSReliabilityPolicy,
    QoSHistoryPolicy, QoSDurabilityPolicy
)
from sensor_msgs.msg import JointState
from std_msgs.msg import Float64MultiArray, Int16, Int64
import numpy as np
import sys
import os
PATH_TO_PROJECT = "/home/tanawatp/volta_ws/src/volta_controller"
sys.path.append(PATH_TO_PROJECT+"/Utils")
from OfflinePlanningFunc import *
from VoltaStateMachine import *

from cybergear_interfaces.srv import VoltaOperationCommand
import time
class DesiredJointsState(Node):
    def __init__(self):
        super().__init__('desired_joints_state_node')
        self.DefineVariables()
        self.CreatePublisher()
        self.CreateSubscription()
        self.CreateServiceServer()
        execute_hz = 70.0 # joint state can publish at 75 Hz
        self.update_event_timer = self.create_timer(1/execute_hz, self.UpdateEvent)  # 70 Hz

    def DefineVariables(self):
        self.InitGaitPlanner()
        self.num_motors = 12
        self.controller_enabled = 0
        self.operation_state = 0
        self.operation_command = 0
        self.current_joints_position = np.zeros(self.num_motors)
        self.desired_joints_position = np.zeros(self.num_motors)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
        self.desired_joints_velocity = np.zeros(self.num_motors)
        self.state_machine = VoltaStateMachine(gait_planner=self.GaitPlanner)
        
    def InitGaitPlanner(self):
        self.GaitPlanner = LIPJointTrajectory(model_series="Volta",
                                 model_name="Volta_rev4",
                                 step_length=0.1,
                                 step_height=0.05,
                                 step_time=5.0,
                                 z_com=5.5,
                                 desire_torso_high=0.3,
                                 y_0=0.125)

    def CreatePublisher(self):
        self.desired_q_pub = self.create_publisher(
            Float64MultiArray,
            '/desired_joints_position',
            10
        )
        self.desired_qd_pub = self.create_publisher(
            Float64MultiArray,
            '/desired_joints_velocity',
            10
        )
        self.controller_enabled_pub = self.create_publisher(
            Int16,
            '/controller_enabled_command',
            10
        )
    
    def CreateSubscription(self):
        sensor_qos = QoSProfile(depth=10)
        sensor_qos.reliability = ReliabilityPolicy.BEST_EFFORT
        self.joint_state_sub = self.create_subscription(
            JointState,
            '/joint_states',
            self.JointStateCallback,
            qos_profile=sensor_qos
        )

    def CreateServiceServer(self):
        self.operation_command_srv = self.create_service(
            VoltaOperationCommand,
            '/volta_operation_command',
            self.SetOperationCommandCallback
        )

    def UpdateEvent(self):
        # if self.state_machine.current_state == self.state_machine.walking:
        #     print("Current state: ", self.state_machine.GetCurrentStateName)
        # print("Current joint position: ", self.current_joints_position)
        self.state_machine.UpdateCurrentJointsPosition(self.current_joints_position)
        self.state_machine.UpdateWalkingState()
        # Get data from state machine   
        self.controller_enabled = self.state_machine.GetControllerEnabledCommand()
        self.desired_joints_position = self.state_machine.GetDesiredJointsPosition()
        self.desired_joints_velocity = self.state_machine.GetDesiredJointsVelocity()
        # Publish data
        self.PublishControllerEnabled(self.controller_enabled)
        self.PublishDesiredJointsPosition(self.desired_joints_position.tolist())
        self.PublishDesiredJointsVelocity(self.desired_joints_velocity.tolist())


    def PublishDesiredJointsPosition(self,data:list):
        desired_q_msg = Float64MultiArray()
        desired_q_msg.data = data
        self.desired_q_pub.publish(desired_q_msg)

    def PublishDesiredJointsVelocity(self,data:list):
        desired_qd_msg = Float64MultiArray()
        desired_qd_msg.data = data
        self.desired_qd_pub.publish(desired_qd_msg)
    
    def PublishControllerEnabled(self,enabled:int):
        controller_enabled_msg = Int16()
        controller_enabled_msg.data = enabled
        self.controller_enabled_pub.publish(controller_enabled_msg)
    
    def OperationCommandCallback(self, msg: Int16):
        self.operation_command = msg.data
        self.get_logger().info(f"Operation command received: {self.operation_command}")

    def JointStateCallback(self, msg: JointState):
        for i in range(self.num_motors):
            if i < self.num_motors:
                self.current_joints_position[i] = msg.position[i]
                # self.current_joints_velocity[i] = msg.velocity[i]
                # self.current_joints_effort[i] = msg.effort[i]

    def SetOperationCommandCallback(self, request, response):
        # start = time.time()
        self.operation_command = request.operation_command
        self.state_machine.SetOperationCommand(self.operation_command)
        response.response = self.state_machine.action_msg
        # end = time.time()
        self.get_logger().info(f"Operation command received: {self.operation_command}")
        return response
    
def main(args=None):
    rclpy.init(args=args)
    node = DesiredJointsState()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()