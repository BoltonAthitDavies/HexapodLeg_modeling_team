#!/usr/bin/env python3
"""
PD Step Commander for Link2 Only (rev_2 joint)
Uses PD control with step function trajectory for testing step response
Implements the control diagram: Torque = Kp*(angle_error) + Kd*(velocity_error) + t_ref
"""
import math
from typing import List

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from std_msgs.msg import Float64MultiArray

from experiment_kit.PD_Controller import PDController


class PDStepCommanderLink2(Node):
    def __init__(self):
        super().__init__('pd_step_controller_link2')
        
        # Declare parameters for rev_2 only
        self.declare_parameter('kp_rev2', 4.0)
        self.declare_parameter('kd_rev2', 0.01)
        self.declare_parameter('update_rate', 200.0)  # Match controller_manager rate
        self.declare_parameter('step_duration', 5.0)  # Duration of each step in seconds
        
        # Get parameters
        kp_rev2 = self.get_parameter('kp_rev2').value
        kd_rev2 = self.get_parameter('kd_rev2').value
        update_rate = self.get_parameter('update_rate').value
        self.step_duration = self.get_parameter('step_duration').value
        
        # Create PD controller for rev_2
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
        
        # Step function parameters for rev_2
        # Define step positions within joint limits (rev_2: -1.47 to 3.0)
        self.rev2_steps = [-0.5, 0.0, -0.5, 0.0, -0.5, 1.5, 0.0, 2.0, 0.765]  # Different positions

        self.current_step_index = 0
        self.time_in_step = 0.0
        
        # Control timer
        self.timer = self.create_timer(self.dt, self.control_loop)
        
        self.get_logger().info(f'PD Step Controller Link2 started')
        self.get_logger().info(f'  Control mode: Torque (Effort) with Step Function trajectory')
        self.get_logger().info(f'  rev_2: Kp={kp_rev2}, Kd={kd_rev2}')
        self.get_logger().info(f'  Update rate: {update_rate} Hz')
        self.get_logger().info(f'  Step duration: {self.step_duration} seconds')
        self.get_logger().info(f'  Total steps: {len(self.rev2_steps)}')
    
    def joint_state_callback(self, msg: JointState):
        """Receive current joint states for rev_2"""
        try:
            idx_rev2 = msg.name.index('rev_2')
            
            self.previous_positions = self.current_positions.copy()
            self.current_positions[1] = msg.position[idx_rev2]
            
            self.current_velocities[1] = msg.velocity[idx_rev2]
            
            self.has_joint_state = True
            
        except (ValueError, IndexError):
            pass
    
    def control_loop(self):
        """Generate step function trajectory and compute torque commands using PD control"""
        
        # Update time in current step
        self.time_in_step += self.dt
        
        # Check if we need to move to next step
        if self.time_in_step >= self.step_duration:
            self.time_in_step = 0.0
            self.current_step_index = (self.current_step_index + 1) % len(self.rev2_steps)
            self.get_logger().info(f'Step {self.current_step_index + 1}/{len(self.rev2_steps)}: '
                                   f'rev_2={self.rev2_steps[self.current_step_index]:.2f}')
            # Publish zero torque command for single joint
            cmd_msg = Float64MultiArray()
            cmd_msg.data = [0.0]
            self.effort_pub.publish(cmd_msg)

        
        # Reference trajectory (step function) for rev_2
        ref_pos_rev2 = self.rev2_steps[self.current_step_index]
        ref_vel_rev2 = 0.5 
    
        
        # Publish reference trajectory (for visualization in PlotJuggler)
        ref_msg = Float64MultiArray()
        ref_msg.data = [ref_pos_rev2, ref_vel_rev2]
        self.reference_pub.publish(ref_msg)
        
        # Use PD controller to compute torque commands based on control diagram
        if self.has_joint_state:
            # Compute torque using PD control (as per your control diagram)
            # Output is TORQUE (Desired torque = Kp * angle_error + Kd * speed_error + t_ref)
            torque_rev2 = self.pd_rev2.compute_torque(
                set_angle=ref_pos_rev2,
                current_angle=self.current_positions[1],
                set_speed=ref_vel_rev2,
                current_speed=self.current_velocities[1],
                t_ref=0.0
            )
            
            
            cmd_torque_rev2 = torque_rev2
        else:
            # No feedback yet, send zero torque
            cmd_torque_rev2 = 0.0
        
        # Publish torque/effort commands (single joint)
        cmd_msg = Float64MultiArray()
        cmd_msg.data = [cmd_torque_rev2]
        self.effort_pub.publish(cmd_msg)
        
        # Increment time
        self.t += self.dt


def main(args=None):
    rclpy.init(args=args)
    node = PDStepCommanderLink2()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
