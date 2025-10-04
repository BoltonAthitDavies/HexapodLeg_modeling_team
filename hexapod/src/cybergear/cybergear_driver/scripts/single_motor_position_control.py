#!/usr/bin/env python3
"""
Single Motor Position Control with Steady State Error Monitoring
Publishes position commands and monitors feedback from joint_states topic
"""

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, QoSReliabilityPolicy, QoSHistoryPolicy, QoSDurabilityPolicy
from cybergear_interfaces.msg import MotorControlGroup, MotorControl
from cybergear_interfaces.srv import SetParam
from sensor_msgs.msg import JointState
import time
import numpy as np

class SingleMotorPositionControl(Node):
    def __init__(self):
        super().__init__('single_motor_position_control')

        # Parameters
        self.declare_parameter('motor_id', 1)
        self.declare_parameter('target_position', 1.0)  # radians (only used if multi_position_mode is False)
        self.declare_parameter('kp', 5.0)
        self.declare_parameter('kd', 0.5)
        self.declare_parameter('steady_state_error_tolerance', 0.1)  # 10%
        self.declare_parameter('settle_duration', 3.0)  # seconds to stay within tolerance
        self.declare_parameter('multi_position_mode', False)  # Enable multi-position cycling

        self.motor_id = self.get_parameter('motor_id').value
        self.kp = self.get_parameter('kp').value
        self.kd = self.get_parameter('kd').value
        self.ss_error_tolerance = self.get_parameter('steady_state_error_tolerance').value
        self.settle_duration = self.get_parameter('settle_duration').value
        self.multi_position_mode = self.get_parameter('multi_position_mode').value

        # Multi-position sequence: 90°, 180°, 270°, 360° (in radians)
        self.position_sequence = [
            np.deg2rad(90),   # 90 degrees
            np.deg2rad(180),  # 180 degrees
            np.deg2rad(270),  # 270 degrees
            np.deg2rad(360)   # 360 degrees (2π)
        ]
        self.current_position_index = 0

        if self.multi_position_mode:
            self.target_position = self.position_sequence[0]
        else:
            self.target_position = self.get_parameter('target_position').value

        # State variables
        self.current_position = 0.0
        self.current_velocity = 0.0
        self.current_effort = 0.0
        self.feedback_received = False
        self.start_time = None

        # Auto-stop variables
        self.within_tolerance_start_time = None
        self.has_reached_target = False

        # Create service client to enable motor
        self.cli = self.create_client(SetParam, 'setparam')
        self.get_logger().info("Waiting for setparam service...")
        if not self.cli.wait_for_service(timeout_sec=10.0):
            self.get_logger().error("setparam service not available after 10s. Make sure cybergear_driver_node is running!")
            rclpy.shutdown()
            return
        self.get_logger().info("setparam service found!")

        # Enable motor
        self.get_logger().info(f"Enabling motor {self.motor_id}...")
        if self.send_request_sync(control_mode=4, motor_id=self.motor_id):
            self.get_logger().info(f"Motor {self.motor_id} enabled successfully")
        else:
            self.get_logger().error(f"Failed to enable motor {self.motor_id}")
            rclpy.shutdown()
            return

        # Publishers and subscribers

        # Create Best Effort QoS profile to match the driver's publisher
        best_effort_qos = QoSProfile(
            reliability=QoSReliabilityPolicy.BEST_EFFORT,
            history=QoSHistoryPolicy.KEEP_LAST,
            depth=10,
            durability=QoSDurabilityPolicy.VOLATILE
        )

        self.command_pub = self.create_publisher(
            MotorControlGroup,
            'motor_group_command',
            best_effort_qos
        )

        self.joint_state_sub = self.create_subscription(
            JointState,
            'joint_states',
            self.joint_state_callback,
            best_effort_qos
        )

        # Timer for publishing commands (100 Hz)
        self.timer_period = 0.01
        self.timer = self.create_timer(self.timer_period, self.timer_callback)

        self.get_logger().info(f"Single Motor Position Control Started")
        self.get_logger().info(f"Motor ID: {self.motor_id}")

        if self.multi_position_mode:
            self.get_logger().info(f"Multi-Position Mode: ENABLED")
            self.get_logger().info(f"Position Sequence: 90° → 180° → 270° → 360° (cycling)")
            self.get_logger().info(f"Starting at: {np.rad2deg(self.target_position):.1f}°")
        else:
            self.get_logger().info(f"Target Position: {self.target_position:.3f} rad ({np.rad2deg(self.target_position):.2f} deg)")

        self.get_logger().info(f"Control Gains - Kp: {self.kp}, Kd: {self.kd}")
        self.get_logger().info(f"Steady State Error Tolerance: {self.ss_error_tolerance*100}%")
        self.get_logger().info(f"Auto-advance after {self.settle_duration:.1f}s within tolerance")

        self.start_time = time.time()

    def send_request_sync(self, control_mode, motor_id,
                         communication_type=0, param_name='',
                         param_value=0.0, timeout_sec=5.0):
        """Send SetParam request synchronously"""
        req = SetParam.Request()
        req.control_mode = control_mode
        req.motor_id = motor_id
        req.communication_type = communication_type
        req.param_name = param_name
        req.param_value = param_value

        future = self.cli.call_async(req)

        start_time = time.time()
        while not future.done():
            rclpy.spin_once(self, timeout_sec=0.1)
            if time.time() - start_time > timeout_sec:
                self.get_logger().error(f"Service call timed out after {timeout_sec} seconds")
                return False

        try:
            response = future.result()
            if response.success:
                return True
            else:
                self.get_logger().error(f"Service call failed: {response.message}")
                return False
        except Exception as e:
            self.get_logger().error(f"Service call raised an exception: {str(e)}")
            return False

    def joint_state_callback(self, msg: JointState):
        """Callback to receive joint state feedback"""
        # Find our motor in the joint states
        motor_name = f"motor_{self.motor_id}"

        try:
            idx = msg.name.index(motor_name)
            self.current_position = msg.position[idx] if idx < len(msg.position) else 0.0
            self.current_velocity = msg.velocity[idx] if idx < len(msg.velocity) else 0.0
            self.current_effort = msg.effort[idx] if idx < len(msg.effort) else 0.0
            self.feedback_received = True

        except (ValueError, IndexError) as e:
            if not self.feedback_received:
                self.get_logger().warn(f"Motor {self.motor_id} not found in joint states")

    def calculate_steady_state_error(self):
        """Calculate steady state error as percentage"""
        if abs(self.target_position) < 1e-6:
            # If target is zero, use absolute error
            return abs(self.current_position)
        else:
            # Calculate percentage error
            error = abs(self.target_position - self.current_position)
            return error / abs(self.target_position)

    def timer_callback(self):
        """Publish position command and monitor feedback"""
        # Check if we've already reached target and should stop
        if self.has_reached_target:
            return

        # Create motor control message
        msg = MotorControlGroup()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = "base_link"

        motor_ctrl = MotorControl()
        motor_ctrl.motor_id = self.motor_id
        motor_ctrl.control_mode = 1  # Position control mode
        motor_ctrl.set_point.position = self.target_position
        motor_ctrl.set_point.velocity = 0.0
        motor_ctrl.set_point.effort = 0.0
        motor_ctrl.set_point.kp = self.kp
        motor_ctrl.set_point.kd = self.kd

        msg.motor_controls = [motor_ctrl]
        self.command_pub.publish(msg)

        # Calculate and log feedback information
        if self.feedback_received and self.start_time is not None:
            elapsed_time = time.time() - self.start_time
            position_error = self.target_position - self.current_position
            ss_error_percent = self.calculate_steady_state_error() * 100

            # Check if within tolerance
            within_tolerance = ss_error_percent <= (self.ss_error_tolerance * 100)
            status_symbol = "✓" if within_tolerance else "✗"

            # Track time within tolerance for auto-stop
            current_time = time.time()
            if within_tolerance:
                if self.within_tolerance_start_time is None:
                    self.within_tolerance_start_time = current_time
                    self.get_logger().info("Target reached! Monitoring stability...")

                time_within_tolerance = current_time - self.within_tolerance_start_time

                # Check if we've been within tolerance long enough
                if time_within_tolerance >= self.settle_duration:
                    if self.multi_position_mode:
                        # Advance to next position in sequence
                        self.current_position_index = (self.current_position_index + 1) % len(self.position_sequence)
                        self.target_position = self.position_sequence[self.current_position_index]

                        self.get_logger().info(
                            f"✓✓✓ TARGET REACHED ✓✓✓\n"
                            f"Position: {self.current_position:.3f} rad ({np.rad2deg(self.current_position):.1f}°)\n"
                            f"Time to reach: {elapsed_time:.2f}s\n"
                            f"→ Moving to next target: {np.rad2deg(self.target_position):.1f}°"
                        )

                        # Reset timing for next target
                        self.within_tolerance_start_time = None
                        self.start_time = time.time()
                        return
                    else:
                        # Single position mode - stop after reaching target
                        self.has_reached_target = True
                        self.get_logger().info(
                            f"✓✓✓ TARGET REACHED AND STABLE ✓✓✓\n"
                            f"Final Position: {self.current_position:.3f} rad ({np.rad2deg(self.current_position):.1f}°)\n"
                            f"Final Error: {ss_error_percent:.2f}%\n"
                            f"Time to reach: {elapsed_time:.2f}s\n"
                            f"Stopping controller..."
                        )
                        # Disable motor and shutdown
                        self.send_request_sync(control_mode=5, motor_id=self.motor_id)
                        rclpy.shutdown()
                        return

                remaining = self.settle_duration - time_within_tolerance
                self.get_logger().info(
                    f"{status_symbol} t={elapsed_time:.2f}s | "
                    f"Target: {self.target_position:.3f} rad ({np.rad2deg(self.target_position):.1f}°) | "
                    f"Current: {self.current_position:.3f} rad ({np.rad2deg(self.current_position):.1f}°) | "
                    f"Error: {position_error:.4f} rad ({np.rad2deg(position_error):.2f}°) | "
                    f"SS Error: {ss_error_percent:.2f}% | "
                    f"Vel: {self.current_velocity:.3f} rad/s | "
                    f"Torque: {self.current_effort:.3f} Nm | "
                    f"Settling: {remaining:.1f}s"
                )
            else:
                # Reset timer if we go outside tolerance
                self.within_tolerance_start_time = None
                self.get_logger().info(
                    f"{status_symbol} t={elapsed_time:.2f}s | "
                    f"Target: {self.target_position:.3f} rad ({np.rad2deg(self.target_position):.1f}°) | "
                    f"Current: {self.current_position:.3f} rad ({np.rad2deg(self.current_position):.1f}°) | "
                    f"Error: {position_error:.4f} rad ({np.rad2deg(position_error):.2f}°) | "
                    f"SS Error: {ss_error_percent:.2f}% | "
                    f"Vel: {self.current_velocity:.3f} rad/s | "
                    f"Torque: {self.current_effort:.3f} Nm"
                )
        else:
            self.get_logger().warn("Waiting for joint state feedback...")

    def destroy_node(self):
        """Cleanup: disable motor before shutting down"""
        self.get_logger().info(f"Disabling motor {self.motor_id}...")
        self.send_request_sync(control_mode=5, motor_id=self.motor_id)
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = SingleMotorPositionControl()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info("Keyboard Interrupt, shutting down.")
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
