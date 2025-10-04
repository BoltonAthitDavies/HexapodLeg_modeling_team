#!/usr/bin/python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64MultiArray
from sensor_msgs.msg import JointState
import time
import pinocchio as pin
import os
import numpy as np
from visualization_msgs.msg import Marker
from std_msgs.msg import Header, ColorRGBA
from geometry_msgs.msg import Point

class GravityCompensationController(Node):
    """
    A ROS2 Node for controlling a robot with gravity compensation.
    This controller uses Pinocchio for dynamics calculations and applies torques
    to compensate for gravity while also maintaining a target joint position.
    """
    def __init__(self):
        super().__init__('gravity_compensation_controller')

        # --- Parameters ---
        # File Paths
        urdf_filename = "/home/kittinook/Documents/GitHub/volta_ws/src/volta_description/urdf/volta_full.urdf"
        package_dir = os.path.dirname(os.path.dirname(urdf_filename))
        
        # PD Controller Gains
        self.kp = 0.9
        self.kd = 0.01
        self.MAX_TORQUE = 4.0
        
        # Target joint positions (standing pose)
        self.target_joint_positions = np.zeros(12) 
        # Example standing pose:
        self.target_joint_positions = np.array([-0.664, 0.0, 0.0, -0.675, -0.316, 0.0,
                                                0.664, 0.0, 0.0, 0.675, 0.316, 0.0])

        # --- Robot Model ---
        self.robot = pin.RobotWrapper.BuildFromURDF(urdf_filename, package_dirs=[package_dir], root_joint=pin.JointModelFreeFlyer())
        self.model = self.robot.model
        self.data = self.model.createData()
        self.get_logger().info(f"Robot model '{self.model.name}' loaded successfully.")
        
        self.get_logger().info("--- Pinocchio Model In section ---")
        self.get_logger().info(f"Number of joints (nq): {self.model.nq}")
        self.get_logger().info(f"Degrees of freedom (nv): {self.model.nv}")
        self.get_logger().info(f"Joint names in model: {[n for n in self.model.names]}")
        self.get_logger().info("------------------------------------")

        # --- State Variables ---
        self.joint_state = {}
        self.q = np.zeros(self.model.nq)
        self.v = np.zeros(self.model.nv)

        # --- ROS2 Communications ---
        self.effort_publisher = self.create_publisher(Float64MultiArray, '/effort_controller/commands', 10)
        self.com_marker_publisher = self.create_publisher(Marker, 'com_marker', 10)
        self.create_subscription(JointState, '/joint_states', self.joint_state_callback, 10)
        
        # --- Control Loop ---
        # Wait for the first joint state message to arrive
        self.get_logger().info("Waiting for the first joint state message...")
        while not self.joint_state:
            rclpy.spin_once(self, timeout_sec=0.1)
        self.get_logger().info("First joint state received. Starting control loop.")
        
        self.create_timer(0.01, self.control_loop)

    def joint_state_callback(self, msg: JointState):
        """
        Callback function to update the robot's current joint states.
        It reorders the received data to match the Pinocchio model's joint order.
        """
        # Define the desired order of joints, matching the URDF/Pinocchio model
        joint_order = [
            'motor_1', 'motor_2', 'motor_3', 'motor_4', 'motor_5', 'motor_6',
            'motor_7', 'motor_8', 'motor_9', 'motor_10', 'motor_11', 'motor_12'
        ]
        
        # Create a dictionary for quick lookup of joint data
        joint_data_map = {name: (pos, vel) for name, pos, vel in zip(msg.name, msg.position, msg.velocity)}

        q_actuated = np.array([joint_data_map[name][0] for name in joint_order])
        v_actuated = np.array([joint_data_map[name][1] for name in joint_order])

        # Populate the state variables in the correct order
        # self.q = np.array([joint_data_map[name][0] for name in joint_order])
        # self.v = np.array([joint_data_map[name][1] for name in joint_order])
        
        # นำค่าที่ได้ไปใส่ใน 12 ช่องสุดท้ายของ self.q และ self.v
        # q[0:7] คือส่วนของ base, q[7:19] คือส่วนของข้อต่อ
        self.q[7:] = q_actuated
        # v[0:6] คือส่วนของ base, v[6:18] คือส่วนของข้อต่อ
        self.v[6:] = v_actuated

        # Store the raw data if needed elsewhere
        self.joint_state = {
            'name': joint_order,
            'position': self.q,
            'velocity': self.v
        }

    def position_controller(self, target_positions: np.ndarray) -> np.ndarray:
        """
        Calculates the required torques using a PD controller.
        
        Args:
            target_positions: A numpy array of target joint positions.
            
        Returns:
            A numpy array of calculated torques for each joint.
        """
        # if not self.joint_state:
        #     self.get_logger().warn("Position controller called before joint states were received.")
        #     return np.zeros(self.model.nv)
        if 'position' not in self.joint_state:
            self.get_logger().warn("Position controller called before joint states were received.")
            return np.zeros(12) # คืนค่าขนาด 12

        # self.q[7:] คือตำแหน่งของข้อต่อ 12 ตัว
        current_q_actuated = self.q[7:]
        # self.v[6:] คือความเร็วของข้อต่อ 12 ตัว
        current_v_actuated = self.v[6:]

        errors = target_positions - current_q_actuated
        torques = self.kp * errors - self.kd * current_v_actuated
        
        # Clamp the torques to the maximum allowed value
        return np.clip(torques, -self.MAX_TORQUE, self.MAX_TORQUE)
    
    def _calculate_contact_force_torques(self) -> np.ndarray:
        """
        Calculates the effect of external contact forces on joint torques.
        This is a feed-forward term to counteract ground reaction forces.
        
        Returns:
            A numpy array of joint torques resulting from contact forces.
        """
        # ... (ส่วนโค้ดก่อนหน้า) ...

        contact_frame_names = ["L_foot_contact", "R_foot_contact"]
        total_contact_torque = np.zeros(self.model.nv)
        
        print(self.data)
        for frame_name in contact_frame_names:
            if not self.model.existFrame(frame_name):
                self.get_logger().error(f"Frame '{frame_name}' does not exist in the model.")
                continue

            frame_id = self.model.getFrameId(frame_name)
            
            # 1. คำนวณ Jacobian สำหรับ Frame ที่ต้องการ
            #    ฟังก์ชันนี้จะเก็บผลลัพธ์ไว้ใน self.data
            pin.computeFrameJacobian(self.model, self.data, self.q, frame_id)
            
            # 2. ดึงค่า Jacobian ออกมาจาก self.data
            #    เราสามารถเลือกระบบอ้างอิง (Reference Frame) ได้
            Jc = pin.getFrameJacobian(self.model, self.data, frame_id, pin.ReferenceFrame.LOCAL_WORLD_ALIGNED)
            
            # --- เพิ่มส่วนนี้เพื่อแสดงผล ---
            self.get_logger().info(f"Jacobian for frame '{frame_name}':")
            # ใช้ np.round เพื่อให้แสดงผลทศนิยมไม่เยอะเกินไป
            print(np.round(Jc, 3)) 
            # --- สิ้นสุดส่วนแสดงผล ---

            # total_contact_torque += Jc.T @ force_per_foot.vector
                
        return total_contact_torque

    def control_loop(self):
        """
        The main control loop. Executed at a fixed frequency.
        """
        if not self.joint_state:
            self.get_logger().error("Control loop running without joint state. Skipping iteration.")
            return

        pin.forwardKinematics(self.model, self.data, self.q, self.v)
        pin.updateFramePlacements(self.model, self.data)

        # --- [เพิ่มเพื่อดีบัก] ตรวจสอบตำแหน่งปลายเท้า ---
        l_foot_id = self.model.getFrameId("L_foot")
        l_foot_placement = self.data.oMf[l_foot_id]
        l_foot_position = l_foot_placement.translation
        # พิมพ์ทั้งสองค่าออกมาคู่กัน
        self.get_logger().info(f"q: {np.round(self.q, 3)}")
        self.get_logger().info(f"Current L_foot position: {np.round(l_foot_position, 3)}")
        self.get_logger().info("---") # เพิ่มตัวคั่นเพื่อให้อ่านง่าย
        # --- สิ้นสุดส่วนดีบัก ---

        # 1. Calculate Gravity Compensation Torques
        tau_gravity = pin.computeGeneralizedGravity(self.model, self.data, self.q)
        # tau_gravity = pin.computeGeneralizedGravity(self.model, self.data, self.target_joint_positions)

        # 2. Calculate Position Control Torques (PD Controller)
        tau_pd = self.position_controller(self.target_joint_positions)

        # 3. (Optional) Calculate Feed-Forward Torques for External Forces
        # Note: This is a simplified model of ground reaction forces.
        # It helps the robot to stand without sagging.
        tau_contact = self._calculate_contact_force_torques()

        # 4. Combine all torques
        # The final torque is gravity compensation + position control - contact forces
        # We subtract contact torques because they represent the torques generated *by* the environment on the robot.
        # The actuator must counteract this.
        final_torques = tau_gravity[6:] + tau_pd - tau_contact[6:]
        print("Gravity Compensation Torques:")
        print(tau_gravity)
        print("Position Control Torques:")
        print(tau_pd)
        print("Contact Force Torques:")
        print(tau_contact)
        print("Final Torques to be applied:")
        print(final_torques)
        print("=======================================")
        # 5. Publish the torques
        effort_msg = Float64MultiArray()
        effort_msg.data = final_torques.tolist()
        self.effort_publisher.publish(effort_msg)
        
        # (Optional) Update and publish CoM for visualization
        self.update_com_visualization()

    def update_com_visualization(self):
        """
        Computes the Center of Mass and publishes it as a Marker for RViz.
        """
        # Update forward kinematics to get the latest CoM
        pin.centerOfMass(self.model, self.data, self.q)
        com_position = self.data.com[0]

        marker = Marker()
        marker.header.frame_id = "torso" # Base frame
        marker.header.stamp = self.get_clock().now().to_msg()
        marker.ns = "center_of_mass"
        marker.id = 0
        marker.type = Marker.SPHERE
        marker.action = Marker.ADD
        marker.scale.x = 0.05
        marker.scale.y = 0.05
        marker.scale.z = 0.05
        marker.color = ColorRGBA(r=1.0, g=0.0, b=0.0, a=0.8)
        marker.pose.position = Point(x=float(com_position[0]), y=float(com_position[1]), z=float(com_position[2]))
        marker.pose.orientation.w = 1.0

        self.com_marker_publisher.publish(marker)

def main(args=None):
    rclpy.init(args=args)
    controller_node = GravityCompensationController()
    rclpy.spin(controller_node)
    controller_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()