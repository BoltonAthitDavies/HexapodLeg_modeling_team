#!/usr/bin/env python3
import math
from typing import List

import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64MultiArray
from sensor_msgs.msg import JointState

JOINTS = ["rev1", "rev_2"]


class PositionVelocityDemo(Node):
    """Publishes simple position and velocity commands and repackages joint states for plotting."""

    def __init__(self):
        super().__init__('position_velocity_demo')
        # Avoid redeclare errors when launch passes use_sim_time
        if not self.has_parameter('use_sim_time'):
            self.declare_parameter('use_sim_time', True)
        self.declare_parameter('rate_hz', 50.0)
        self.declare_parameter('amp', 0.5)
        self.declare_parameter('freq', 0.2)  # Hz

        rate_hz = float(self.get_parameter('rate_hz').value)
        self.dt = 1.0 / rate_hz
        self.timer = self.create_timer(self.dt, self._on_timer)

        # Command publishers for group controllers
        self.pos_pub = self.create_publisher(Float64MultiArray, '/joint_position_controller/commands', 10)
        # If you later add a velocity controller, publish to it similarly
        self.vel_pub = self.create_publisher(Float64MultiArray, '/joint_velocity_controller/commands', 10)

        # Subscribe to joint_states to extract positions + velocities
        self.js_sub = self.create_subscription(JointState, '/joint_states', self._on_joint_states, 10)

        # Internal state for plotting convenience
        self.last_positions = [0.0, 0.0]
        self.last_velocities = [0.0, 0.0]
        self.start_time = self.get_clock().now()

    def _on_timer(self):
        t = self.get_clock().now().nanoseconds * 1e-9
        amp = float(self.get_parameter('amp').value)
        freq = float(self.get_parameter('freq').value)
        omega = 2.0 * math.pi * freq

        # Command: simple sinusoid on both joints, quarter-phase offset on second
        pos_cmd = [amp * math.sin(omega * t), amp * math.sin(omega * t + math.pi/2.0)]
        vel_cmd = [amp * omega * math.cos(omega * t), amp * omega * math.cos(omega * t + math.pi/2.0)]

        pos_msg = Float64MultiArray()
        pos_msg.data = pos_cmd
        self.pos_pub.publish(pos_msg)

        vel_msg = Float64MultiArray()
        vel_msg.data = vel_cmd
        # This will only have effect if you add and start a velocity controller; harmless otherwise
        self.vel_pub.publish(vel_msg)

    def _on_joint_states(self, msg: JointState):
        # reorder into our JOINTS order for consistency
        name_to_index = {n: i for i, n in enumerate(msg.name)}
        positions = []
        velocities = []
        for j in JOINTS:
            idx = name_to_index.get(j, None)
            if idx is None:
                positions.append(0.0)
                velocities.append(0.0)
            else:
                positions.append(msg.position[idx] if idx < len(msg.position) else 0.0)
                velocities.append(msg.velocity[idx] if idx < len(msg.velocity) else 0.0)
        self.last_positions = positions
        self.last_velocities = velocities


def main():
    rclpy.init()
    node = PositionVelocityDemo()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        try:
            import rclpy as _r
            if _r.ok():
                _r.shutdown()
        except Exception:
            pass
