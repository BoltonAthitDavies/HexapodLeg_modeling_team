#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
import csv
from datetime import datetime
import os


class JointStateLogger(Node):
    def __init__(self):
        super().__init__('joint_state_logger')
        
        # Create CSV filename with timestamp
        timestamp = datetime.now().strftime('%Y%m%d_%H%M%S')
        self.csv_filename = f'joint_states_log_{timestamp}.csv'
        
        # Initialize CSV file with headers
        self.csv_file = open(self.csv_filename, 'w', newline='')
        self.csv_writer = csv.writer(self.csv_file)
        
        # Write header
        self.csv_writer.writerow([
            'timestamp_sec', 'timestamp_nsec',
            'joint_name', 'position', 'velocity', 'effort'
        ])
        
        # Create subscription to /joint_states
        self.subscription = self.create_subscription(
            JointState,
            '/joint_states',
            self.joint_state_callback,
            10
        )
        
        self.get_logger().info(f'Joint State Logger started. Logging to: {self.csv_filename}')
        self.message_count = 0
    
    def joint_state_callback(self, msg):
        """Callback function that processes incoming JointState messages"""
        timestamp_sec = msg.header.stamp.sec
        timestamp_nsec = msg.header.stamp.nanosec
        
        # Log each joint's data
        for i, joint_name in enumerate(msg.name):
            position = msg.position[i] if i < len(msg.position) else float('nan')
            velocity = msg.velocity[i] if i < len(msg.velocity) else float('nan')
            effort = msg.effort[i] if i < len(msg.effort) else float('nan')
            
            # Write row to CSV
            self.csv_writer.writerow([
                timestamp_sec,
                timestamp_nsec,
                joint_name,
                position,
                velocity,
                effort
            ])
        
        # Flush to ensure data is written
        self.csv_file.flush()
        
        self.message_count += 1
        if self.message_count % 10 == 0:
            self.get_logger().info(f'Logged {self.message_count} messages')
    
    def destroy_node(self):
        """Clean up resources when node is destroyed"""
        self.get_logger().info(f'Closing CSV file. Total messages logged: {self.message_count}')
        self.csv_file.close()
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    
    joint_state_logger = JointStateLogger()
    
    try:
        rclpy.spin(joint_state_logger)
    except KeyboardInterrupt:
        joint_state_logger.get_logger().info('Keyboard interrupt, shutting down...')
    finally:
        joint_state_logger.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
