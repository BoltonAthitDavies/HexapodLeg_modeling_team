#!/usr/bin/env python3
"""
PD Torque Controller for Hexapod Robot
Uses PD control to compute desired torque based on position and velocity errors
Implements the control diagram: Torque = Kp*(angle_error) + Kd*(velocity_error) + t_ref
"""
import math
from typing import List

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from std_msgs.msg import Float64MultiArray

from hexapod_gz.PD_Controller import PDController


class PDPositionCommander(Node):
    def __init__(self):
        super().__init__('pd_torque_controller')
        
        # Declare parameters
        self.declare_parameter('kp_rev1', 5.0)
        self.declare_parameter('kd_rev1', 0.5)
        self.declare_parameter('kp_rev2', 4.0)
        self.declare_parameter('kd_rev2', 0.4)
        self.declare_parameter('update_rate', 200.0)  # Match controller_manager rate
        
        # Get parameters
        kp_rev1 = self.get_parameter('kp_rev1').value
        kd_rev1 = self.get_parameter('kd_rev1').value
        kp_rev2 = self.get_parameter('kp_rev2').value
        kd_rev2 = self.get_parameter('kd_rev2').value
        update_rate = self.get_parameter('update_rate').value
        
        # Create PD controllers
        self.pd_rev1 = PDController(Kp=kp_rev1, Kd=kd_rev1)
        self.pd_rev2 = PDController(Kp=kp_rev2, Kd=kd_rev2)
        
        # Publisher for torque/effort commands (actual commands sent to controller)
        self.effort_pub = self.create_publisher(
            Float64MultiArray,
            '/joint_effort_controller/commands',
            10
        )
        
        # Publisher for reference trajectory (for visualization)
        self.reference_pub = self.create_publisher(
            Float64MultiArray,
            '/joint_reference',
            10
        )
        
        # Subscriber for joint states
        self.joint_state_sub = self.create_subscription(
            JointState,
            '/joint_states',
            self.joint_state_callback,
            10
        )
        
        # State tracking
        self.current_positions = [0.0, 0.0]
        self.current_velocities = [0.0, 0.0]
        self.previous_positions = [0.0, 0.0]
        self.has_joint_state = False
        
        # Trajectory generation
        self.t = 0.0
        self.dt = 1.0 / update_rate
        
        # Control timer
        self.timer = self.create_timer(self.dt, self.control_loop)
        
        self.get_logger().info(f'PD Torque Controller started')
        self.get_logger().info(f'  Control mode: Torque (Effort) based on position/velocity errors')
        self.get_logger().info(f'  rev1: Kp={kp_rev1}, Kd={kd_rev1}')
        self.get_logger().info(f'  rev2: Kp={kp_rev2}, Kd={kd_rev2}')
        self.get_logger().info(f'  Update rate: {update_rate} Hz')
    
    def joint_state_callback(self, msg: JointState):
        """Receive current joint states"""
        try:
            idx_rev1 = msg.name.index('rev1')
            idx_rev2 = msg.name.index('rev_2')
            
            self.previous_positions = self.current_positions.copy()
            self.current_positions[0] = msg.position[idx_rev1]
            self.current_positions[1] = msg.position[idx_rev2]
            
            self.current_velocities[0] = msg.velocity[idx_rev1]
            self.current_velocities[1] = msg.velocity[idx_rev2]
            
            self.has_joint_state = True
            
        except (ValueError, IndexError):
            pass
    
    def control_loop(self):
        """Generate trajectory and compute torque commands using PD control"""
        
        # Reference trajectory (sine wave within joint limits)
        # rev1: range [0, 6.28] → center at 3.14, amplitude 2.0
        ref_pos_rev1 = 3.14 + 2.0 * math.sin(self.t)
        ref_vel_rev1 = 2.0 * math.cos(self.t)
        
        # rev_2: range [-1.47, 3.0] → center at 0.765, amplitude 1.5
        ref_pos_rev2 = 0.765 + 1.5 * math.sin(self.t * 0.8 + 0.5)
        ref_vel_rev2 = 1.5 * 0.8 * math.cos(self.t * 0.8 + 0.5)
        
        # Publish reference trajectory (for visualization in PlotJuggler)
        ref_msg = Float64MultiArray()
        ref_msg.data = [ref_pos_rev1, ref_pos_rev2, ref_vel_rev1, ref_vel_rev2]
        self.reference_pub.publish(ref_msg)
        
        # Use PD controller to compute torque commands based on control diagram
        if self.has_joint_state:
            # Compute torque using PD control (as per your control diagram)
            # Output is TORQUE (Desired torque = Kp * angle_error + Kd * speed_error + t_ref)
            torque_rev1 = self.pd_rev1.compute_torque(
                set_angle=ref_pos_rev1,
                current_angle=self.current_positions[0],
                set_speed=ref_vel_rev1,
                current_speed=self.current_velocities[0],
                t_ref=0.0
            )
            
            torque_rev2 = self.pd_rev2.compute_torque(
                set_angle=ref_pos_rev2,
                current_angle=self.current_positions[1],
                set_speed=ref_vel_rev2,
                current_speed=self.current_velocities[1],
                t_ref=0.0
            )
            
            cmd_torque_rev1 = torque_rev1
            cmd_torque_rev2 = torque_rev2
        else:
            # No feedback yet, send zero torque
            cmd_torque_rev1 = 0.0
            cmd_torque_rev2 = 0.0
        
        # Publish torque/effort commands
        cmd_msg = Float64MultiArray()
        cmd_msg.data = [cmd_torque_rev1, cmd_torque_rev2]
        self.effort_pub.publish(cmd_msg)
        
        # Increment time
        self.t += self.dt


def main(args=None):
    rclpy.init(args=args)
    node = PDPositionCommander()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
