#!/usr/bin/env python3
import math
from typing import List

import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64MultiArray


class JointPositionCommander(Node):
    def __init__(self):
        super().__init__('joint_position_commander')
        # Controller name must match ros2_controllers.yaml
        self.controller_name = self.declare_parameter('controller_name', 'joint_position_controller').get_parameter_value().string_value
        self.joints = self.declare_parameter('joints', ['rev1', 'rev_2']).get_parameter_value().string_array_value

        topic = f'/{self.controller_name}/commands'
        self.pub = self.create_publisher(Float64MultiArray, topic, 10)

        self.get_logger().info(f'Publishing joint positions to {topic} for joints: {self.joints}')
        self.t = 0.0
        self.dt = 0.01  # Time step for smoother control
        self.timer = self.create_timer(self.dt, self.on_timer)  # 100 Hz

    def on_timer(self):
        # Simple sine sweep for two joints; extend if more joints exist later
        pos: List[float] = []
        pos.append(0.5 * math.sin(self.t))  # rev1
        pos.append(-0.5 * math.sin(self.t * 0.8 + 0.5))  # rev_2
        self.t += self.dt

        msg = Float64MultiArray()
        msg.data = pos
        self.pub.publish(msg)


def main():
    rclpy.init()
    node = JointPositionCommander()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
