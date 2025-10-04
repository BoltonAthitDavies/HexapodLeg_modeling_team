#!/usr/bin/env python3

"""
BNO055 USB Stick ROS2 IMU Node

This node reads data from the BNO055 USB stick and publishes it as sensor_msgs/Imu messages.
Publishes at the highest possible frequency for real-time IMU data streaming.

Author: Generated for ROS2 integration
License: MIT
"""

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy, DurabilityPolicy
from sensor_msgs.msg import Imu
from geometry_msgs.msg import Vector3, Quaternion
from std_msgs.msg import Header
import numpy as np
import threading
import time
from typing import Optional
from bno055_usb_stick_py import BnoUsbStick#, BNO055
from tf2_ros import TransformBroadcaster
from geometry_msgs.msg import TransformStamped
# try:
#     from bno055_usb_stick_py import BnoUsbStick, BNO055
# except ImportError:
#     print("ERROR: bno055_usb_stick_py not found. Install with: pip install bno055-usb-stick-py")
#     exit(1)


class BNO055IMUNode(Node):
    """ROS2 node for BNO055 USB stick IMU data publishing"""
    
    def __init__(self):
        super().__init__('bno055_IMU_node')
        
        # Declare parameters
        self.declare_parameter('frame_id', 'imu_link')
        self.declare_parameter('port', '')  # Empty string for auto-detection
        self.declare_parameter('publish_rate', 100.0)  # Hz
        self.declare_parameter('covariance_linear_acceleration', [0.01, 0.01, 0.01])
        self.declare_parameter('covariance_angular_velocity', [0.01, 0.01, 0.01])
        self.declare_parameter('covariance_orientation', [0.01, 0.01, 0.01])
        
        # Get parameters
        self.frame_id = self.get_parameter('frame_id').get_parameter_value().string_value
        self.port = self.get_parameter('port').get_parameter_value().string_value
        self.publish_rate = self.get_parameter('publish_rate').get_parameter_value().double_value
        
        # Covariance matrices (diagonal values)
        self.linear_accel_cov = self.get_parameter('covariance_linear_acceleration').get_parameter_value().double_array_value
        self.angular_vel_cov = self.get_parameter('covariance_angular_velocity').get_parameter_value().double_array_value
        self.orientation_cov = self.get_parameter('covariance_orientation').get_parameter_value().double_array_value
        
        # Setup QoS profile for high-frequency IMU data
        qos_profile = QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            durability=DurabilityPolicy.VOLATILE,
            history=HistoryPolicy.KEEP_LAST,
            depth=10
        )
        
        # Create publisher
        self.imu_publisher = self.create_publisher(
            Imu,
            'imu/data',
            qos_profile
        )
        
        # Initialize BNO055 USB stick
        self.bno_stick: Optional[BnoUsbStick] = None
        self.running = False
        self.data_thread: Optional[threading.Thread] = None
        
        # Statistics
        self.packet_count = 0
        self.last_stats_time = time.time()
        
        # Initialize the device
        self.initialize_bno055()
        
        # Start data streaming thread
        self.start_streaming()
        
        # Create timer for statistics logging
        self.stats_timer = self.create_timer(5.0, self.log_statistics)
        
        self.get_logger().info(f"BNO055 IMU Node initialized. Publishing on 'imu/data' topic.")
        self.get_logger().info(f"Frame ID: {self.frame_id}")
        self.get_logger().info(f"Target publish rate: {self.publish_rate} Hz")


        self.tf_broadcaster = TransformBroadcaster(self)
    
    def initialize_bno055(self):
        """Initialize the BNO055 USB stick"""
        try:
            if self.port:
                self.get_logger().info(f"Connecting to BNO055 on port: {self.port}")
                self.bno_stick = BnoUsbStick(port=self.port)
            else:
                self.get_logger().info("Auto-detecting BNO055 USB stick...")
                self.bno_stick = BnoUsbStick()
            
            # Query board information
            self.bno_stick.query_board_info()
            
            # Verify chip ID
            chip_id = self.bno_stick.read_register(0x00)
            if chip_id == 0xA0:
                self.get_logger().info(f"BNO055 chip detected successfully (ID: 0x{chip_id:02X})")
            else:
                self.get_logger().warn(f"Unexpected chip ID: 0x{chip_id:02X} (expected 0xA0)")
            
            # Set operation mode to NDOF (Nine Degrees of Freedom fusion mode)
            # This provides calibrated accelerometer, gyroscope, magnetometer, and quaternion data
            opr_mode_addr = 0x3D
            ndof_mode = 0x0C  # NDOF mode for full sensor fusion
            self.bno_stick.write_register(opr_mode_addr, ndof_mode)
            time.sleep(0.1)  # Allow mode change to take effect
            
            # Verify mode was set
            current_mode = self.bno_stick.read_register(opr_mode_addr) & 0x0F
            self.get_logger().info(f"BNO055 operation mode set to: 0x{current_mode:02X} (NDOF)")
            
        except Exception as e:
            self.get_logger().error(f"Failed to initialize BNO055: {str(e)}")
            raise
    
    def create_covariance_matrix(self, diagonal_values):
        """Create a 3x3 covariance matrix from diagonal values"""
        if len(diagonal_values) != 3:
            diagonal_values = [0.01, 0.01, 0.01]  # Default values
        
        # Create 3x3 covariance matrix (flattened for ROS message)
        covariance = [0.0] * 9
        covariance[0] = diagonal_values[0]  # xx
        covariance[4] = diagonal_values[1]  # yy
        covariance[8] = diagonal_values[2]  # zz
        return covariance
    
    def send_tf(self, msg: Imu):
        """Broadcast TF from IMU data"""
        t = TransformStamped()

        # Read message content and assign it to
        # corresponding tf variables
        t.header.stamp = self.get_clock().now().to_msg()
        t.header.frame_id = 'world'
        t.child_frame_id = 'torso'

        t.transform.translation.x = 0.0
        t.transform.translation.y = 0.0
        t.transform.translation.z = 0.0
        t.transform.rotation.x = msg.orientation.x
        t.transform.rotation.y = msg.orientation.y
        t.transform.rotation.z = msg.orientation.z
        t.transform.rotation.w = msg.orientation.w

        # Send the transformation
        self.tf_broadcaster.sendTransform(t)

    def convert_bno_to_imu_msg(self, bno_data) -> Imu:
        """Convert BNO055 data to ROS2 Imu message"""
        imu_msg = Imu()
        
        # Header
        imu_msg.header = Header()
        imu_msg.header.stamp = self.get_clock().now().to_msg()
        imu_msg.header.frame_id = self.frame_id
        
        # Orientation (quaternion) - BNO055 provides w, x, y, z
        # Note: BNO055 quaternion is already normalized
        imu_msg.orientation = Quaternion()
        imu_msg.orientation.w = bno_data.quaternion[0]  # q_w
        imu_msg.orientation.x = bno_data.quaternion[1]  # q_x
        imu_msg.orientation.y = bno_data.quaternion[2]  # q_y
        imu_msg.orientation.z = bno_data.quaternion[3]  # q_z
        
        # Angular velocity (rad/s) - from gyroscope
        # BNO055 provides gyro data in deg/s, need to convert to rad/s
        imu_msg.angular_velocity = Vector3()
        imu_msg.angular_velocity.x = np.deg2rad(bno_data.g[0])
        imu_msg.angular_velocity.y = np.deg2rad(bno_data.g[1])
        imu_msg.angular_velocity.z = np.deg2rad(bno_data.g[2])
        
        # Linear acceleration (m/s²) - from accelerometer
        # BNO055 provides linear acceleration (gravity removed)
        imu_msg.linear_acceleration = Vector3()
        imu_msg.linear_acceleration.x = bno_data.lin_a[0]
        imu_msg.linear_acceleration.y = bno_data.lin_a[1]
        imu_msg.linear_acceleration.z = bno_data.lin_a[2]
        
        # Covariance matrices
        imu_msg.orientation_covariance = self.create_covariance_matrix(self.orientation_cov)
        imu_msg.angular_velocity_covariance = self.create_covariance_matrix(self.angular_vel_cov)
        imu_msg.linear_acceleration_covariance = self.create_covariance_matrix(self.linear_accel_cov)
        
        return imu_msg
    
    def data_streaming_thread(self):
        """Main data streaming thread - runs at maximum frequency"""
        self.get_logger().info("Starting high-frequency data streaming...")
        
        try:
            # Activate streaming mode
            self.bno_stick.activate_streaming()
            
            # Stream data at maximum rate using generator
            for bno_data in self.bno_stick.recv_streaming_generator():
                # print(bno_data)
                
                if not self.running:
                    break
                
                try:
                    # Convert to IMU message and publish
                    imu_msg = self.convert_bno_to_imu_msg(bno_data)
                    self.send_tf(imu_msg)
                    self.imu_publisher.publish(imu_msg)
                    
                    self.packet_count += 1
                    
                except Exception as e:
                    self.get_logger().warn(f"Error processing IMU data: {str(e)}")
                    continue
                    
        except Exception as e:
            self.get_logger().error(f"Streaming thread error: {str(e)}")
        finally:
            if self.bno_stick:
                try:
                
                    self.bno_stick.deactivate_streaming()
                except:
                    pass
    
    def start_streaming(self):
        """Start the data streaming thread"""
        self.running = True
        self.data_thread = threading.Thread(target=self.data_streaming_thread, daemon=True)
        self.data_thread.start()
    
    def stop_streaming(self):
        """Stop the data streaming thread"""
        self.running = False
        if self.data_thread and self.data_thread.is_alive():
            self.data_thread.join(timeout=2.0)
    
    def log_statistics(self):
        """Log publishing statistics"""
        current_time = time.time()
        time_diff = current_time - self.last_stats_time
        
        if time_diff > 0:
            actual_rate = self.packet_count / time_diff
            self.get_logger().info(
                f"IMU publishing rate: {actual_rate:.1f} Hz "
                f"(target: {self.publish_rate:.1f} Hz), "
                f"packets: {self.packet_count}"
            )
        
        # Reset counters
        self.packet_count = 0
        self.last_stats_time = current_time
    
    def destroy_node(self):
        """Clean shutdown"""
        self.get_logger().info("Shutting down BNO055 IMU node...")
        self.stop_streaming()
        
        if self.bno_stick:
            try:
                self.bno_stick.deactivate_streaming()
                del self.bno_stick
            except:
                pass
        
        super().destroy_node()


def main(args=None):
    """Main entry point"""
    rclpy.init(args=args)
    
    try:
        node = BNO055IMUNode()
        
        # Use MultiThreadedExecutor for better performance
        from rclpy.executors import MultiThreadedExecutor
        executor = MultiThreadedExecutor()
        
        try:
            rclpy.spin(node, executor=executor)
        except KeyboardInterrupt:
            node.get_logger().info("Received keyboard interrupt, shutting down...")
        finally:
            node.destroy_node()
            
    except Exception as e:
        print(f"Failed to start BNO055 IMU node: {str(e)}")
    finally:
        rclpy.shutdown()


if __name__ == '__main__':
    main()