#!/usr/bin/env python3
"""
PD Torque Controller Node for Hexapod Robot
Uses PD_Controller class to compute torques based on position/velocity errors
"""
import math
from typing import List

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from std_msgs.msg import Float64MultiArray

from hexapod_gz.PD_Controller import PDController


class PDTorqueControllerNode(Node):
    def __init__(self):
        super().__init__('pd_torque_controller')
        
        # Declare parameters with defaults
        self.declare_parameter('kp_rev1', 10.0)
        self.declare_parameter('kd_rev1', 1.0)
        self.declare_parameter('kp_rev2', 8.0)
        self.declare_parameter('kd_rev2', 0.8)
        self.declare_parameter('control_frequency', 100.0)
        
        # Get parameters
        kp_rev1 = self.get_parameter('kp_rev1').value
        kd_rev1 = self.get_parameter('kd_rev1').value
        kp_rev2 = self.get_parameter('kp_rev2').value
        kd_rev2 = self.get_parameter('kd_rev2').value
        control_freq = self.get_parameter('control_frequency').value
        
        # Create PD controllers for each joint
        self.pd_rev1 = PDController(Kp=kp_rev1, Kd=kd_rev1)
        self.pd_rev2 = PDController(Kp=kp_rev2, Kd=kd_rev2)
        
        # Publishers
        self.effort_pub = self.create_publisher(
            Float64MultiArray,
            '/effort_controller/commands',
            10
        )
        
        # Subscribers
        self.joint_state_sub = self.create_subscription(
            JointState,
            '/joint_states',
            self.joint_state_callback,
            10
        )
        
        # State variables
        self.current_positions = [0.0, 0.0]  # [rev1, rev2]
        self.current_velocities = [0.0, 0.0]
        self.has_joint_state = False
        
        # Desired trajectory (sine wave for demo)
        self.t = 0.0
        self.dt = 1.0 / control_freq
        
        # Timer for control loop
        self.timer = self.create_timer(self.dt, self.control_loop)
        
        self.get_logger().info(f'PD Torque Controller initialized')
        self.get_logger().info(f'  rev1: Kp={kp_rev1}, Kd={kd_rev1}')
        self.get_logger().info(f'  rev2: Kp={kp_rev2}, Kd={kd_rev2}')
        self.get_logger().info(f'  Control frequency: {control_freq} Hz')
    
    def joint_state_callback(self, msg: JointState):
        """Update current joint states from feedback"""
        try:
            # Find indices for rev1 and rev_2
            idx_rev1 = msg.name.index('rev1')
            idx_rev2 = msg.name.index('rev_2')
            
            self.current_positions[0] = msg.position[idx_rev1]
            self.current_positions[1] = msg.position[idx_rev2]
            
            self.current_velocities[0] = msg.velocity[idx_rev1]
            self.current_velocities[1] = msg.velocity[idx_rev2]
            
            self.has_joint_state = True
            
        except (ValueError, IndexError) as e:
            if not self.has_joint_state:
                self.get_logger().warn(f'Joint state parsing error: {e}', throttle_duration_sec=5.0)
    
    def control_loop(self):
        """Main control loop - compute and publish torques"""
        if not self.has_joint_state:
            return
        
        # Generate desired trajectory (sine wave)
        set_angle_rev1 = 0.5 * math.sin(self.t)
        set_speed_rev1 = 0.5 * math.cos(self.t)  # derivative of position
        
        set_angle_rev2 = -0.5 * math.sin(self.t * 0.8 + 0.5)
        set_speed_rev2 = -0.5 * 0.8 * math.cos(self.t * 0.8 + 0.5)
        
        # Compute torques using PD controllers
        torque_rev1 = self.pd_rev1.compute_torque(
            set_angle=set_angle_rev1,
            current_angle=self.current_positions[0],
            set_speed=set_speed_rev1,
            current_speed=self.current_velocities[0],
            t_ref=0.0
        )
        
        torque_rev2 = self.pd_rev2.compute_torque(
            set_angle=set_angle_rev2,
            current_angle=self.current_positions[1],
            set_speed=set_speed_rev2,
            current_speed=self.current_velocities[1],
            t_ref=0.0
        )
        
        # Publish torque commands
        msg = Float64MultiArray()
        msg.data = [torque_rev1, torque_rev2]
        self.effort_pub.publish(msg)
        
        # Increment time
        self.t += self.dt


def main(args=None):
    rclpy.init(args=args)
    node = PDTorqueControllerNode()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
