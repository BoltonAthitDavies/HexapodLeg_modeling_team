#!/usr/bin/env python3
"""
Manual Joint Position Control for Hexapod Robot
Usage: ros2 run hexapod_gz manual_joint_control
Then enter joint positions when prompted.
"""
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64MultiArray


class ManualJointControl(Node):
    def __init__(self):
        super().__init__('manual_joint_control')
        self.pub = self.create_publisher(
            Float64MultiArray,
            '/joint_position_controller/commands',
            10
        )
        self.get_logger().info('Manual Joint Control Node Started')
        self.get_logger().info('Enter joint positions for [rev1, rev_2]')
        self.get_logger().info('Example: 0.5 -0.5')
        self.get_logger().info('Press Ctrl+C to exit')
        
    def publish_positions(self, pos1, pos2):
        msg = Float64MultiArray()
        msg.data = [float(pos1), float(pos2)]
        self.pub.publish(msg)
        self.get_logger().info(f'Published: rev1={pos1:.3f}, rev_2={pos2:.3f}')


def main():
    rclpy.init()
    node = ManualJointControl()
    
    try:
        while rclpy.ok():
            try:
                user_input = input('\nEnter positions (rev1 rev_2): ')
                positions = user_input.strip().split()
                
                if len(positions) != 2:
                    print('Error: Please enter exactly 2 values')
                    continue
                    
                pos1 = float(positions[0])
                pos2 = float(positions[1])
                
                node.publish_positions(pos1, pos2)
                
            except ValueError:
                print('Error: Please enter valid numbers')
            except EOFError:
                break
                
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
