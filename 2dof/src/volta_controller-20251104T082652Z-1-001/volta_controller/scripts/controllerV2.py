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
    A ROS2 Node for controlling a robot with gravity compensation using a floating-base model.
    """
    def __init__(self):
        super().__init__('gravity_compensation_controller')

        # --- Parameters ---
        # urdf_filename = "/home/kittinook/Documents/GitHub/volta_ws/src/volta_description/urdf/volta_full.urdf"
        urdf_filename = "/home/kittinook/Documents/GitHub/volta_ws/src/volta_description/urdf/volta_full-dew.urdf"
        package_dir = os.path.dirname(os.path.dirname(urdf_filename))
        
        self.kp = 1.5  # เพิ่ม Gain ขึ้นเล็กน้อย
        self.kd = 0.05 # เพิ่ม Damping เพื่อลดการสั่น
        self.MAX_TORQUE = 6.0
        
        self.target_joint_positions = np.array([
            -0.664, 0.0, 0.0, -0.675, -0.316, 0.0,
             0.664, 0.0, 0.0,  0.675, 0.316, 0.0
        ])
        # self.target_joint_positions = np.array([
        #     0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        #     0.0, 0.0, 0.0, 0.0, 0.0, 0.0
        # ])

        # --- Robot Model (สำคัญ: ใช้ JointModelFreeFlyer) ---
        self.robot = pin.RobotWrapper.BuildFromURDF(urdf_filename,
                                                    package_dirs=[package_dir],
                                                    root_joint=pin.JointModelFreeFlyer())
        self.model = self.robot.model
        self.data = self.model.createData()
        self.get_logger().info(f"Robot model '{self.model.name}' loaded successfully with floating base.")
        self.get_logger().info(f"Model nq: {self.model.nq}, nv: {self.model.nv}") # ควรแสดง nq: 19, nv: 18
        self.get_logger().info(f"Joint names in model: {[n for n in self.model.names]}")
        total_mass = sum(inertia.mass for inertia in self.model.inertias)
        self.get_logger().info(f"Total mass of the robot: {total_mass}")

        # --- [แก้ไข] State Variables (สำคัญ: เริ่มต้น q ให้ถูกต้อง) ---
        self.joint_state = {}
        # pin.neutral() จะสร้าง q ที่ถูกต้อง (quat = [0,0,0,1])
        self.q = pin.neutral(self.model) 
        self.v = np.zeros(self.model.nv)
        
        # สมมติให้หุ่นยนต์เริ่มต้นที่ความสูง 0.8 เมตรจากพื้น
        # q[0:3] คือตำแหน่ง x,y,z
        self.q[2] = 0.0
        # --- สิ้นสุดการแก้ไข ---

        # --- ROS2 Communications ---
        self.effort_publisher = self.create_publisher(Float64MultiArray, '/effort_controller/commands', 10)
        self.com_marker_publisher = self.create_publisher(Marker, 'com_marker', 10)
        self.create_subscription(JointState, '/joint_states', self.joint_state_callback, 10)
        
        # --- Control Loop ---
        self.get_logger().info("Waiting for the first joint state message...")
        while 'position' not in self.joint_state:
            rclpy.spin_once(self, timeout_sec=0.1)
        self.get_logger().info("First joint state received. Starting control loop.")
        
        self.create_timer(0.01, self.control_loop)

    def joint_state_callback(self, msg: JointState):
        """
        [ถูกต้อง] อัปเดตเฉพาะส่วนข้อต่อของ state vectors
        """
        joint_order = [
            'motor_1', 'motor_2', 'motor_3', 'motor_4', 'motor_5', 'motor_6',
            'motor_7', 'motor_8', 'motor_9', 'motor_10', 'motor_11', 'motor_12'
        ]
        
        joint_data_map = {name: (pos, vel) for name, pos, vel in zip(msg.name, msg.position, msg.velocity)}

        q_actuated = np.array([joint_data_map[name][0] for name in joint_order])
        v_actuated = np.array([joint_data_map[name][1] for name in joint_order])

        # q[7:] คือส่วนของข้อต่อ (12 ตัว)
        self.q[7:] = q_actuated
        # v[6:] คือส่วนของข้อต่อ (12 ตัว)
        self.v[6:] = v_actuated
        
        self.joint_state = {'position': q_actuated, 'velocity': v_actuated}

    def position_controller(self, target_positions: np.ndarray) -> np.ndarray:
        """
        [ถูกต้อง] คำนวณ PD torque สำหรับข้อต่อ 12 ตัว
        """
        current_q_actuated = self.q[7:]
        current_v_actuated = self.v[6:]

        errors = target_positions - current_q_actuated
        torques = self.kp * errors - self.kd * current_v_actuated
        
        return np.clip(torques, -self.MAX_TORQUE, self.MAX_TORQUE)
    
    def _calculate_contact_force_torques(self) -> np.ndarray:
        """
        [ถูกต้อง] คำนวณ torque จากแรงกระทำที่เท้า
        """
        linear_force = np.array([0.0, 0.0, 46.0]) 
        angular_torque = np.zeros(3)
        force_per_foot = pin.Force(linear_force, angular_torque)

        contact_frame_names = ["L_foot_contact", "R_foot_contact"]
        total_contact_torque = np.zeros(self.model.nv) # ขนาด 18
        
        for frame_name in contact_frame_names:
            if not self.model.existFrame(frame_name):
                self.get_logger().error(f"Frame '{frame_name}' does not exist in the model.")
                continue

            frame_id = self.model.getFrameId(frame_name)
            Jc = pin.getFrameJacobian(self.model, self.data, frame_id, pin.ReferenceFrame.LOCAL_WORLD_ALIGNED)
            total_contact_torque += Jc.T @ force_per_foot.vector
            
        return total_contact_torque

    def control_loop(self):
        """
        [ถูกต้อง] The main control loop
        """
        if 'position' not in self.joint_state:
            return

        # อัปเดต kinematics ทั้งหมดก่อน
        pin.forwardKinematics(self.model, self.data, self.q, self.v)
        pin.updateFramePlacements(self.model, self.data)
        pin.computeJointJacobians(self.model, self.data, self.q) # คำนวณ Jacobians ทั้งหมด

        # 1. Gravity Compensation (ขนาด 18)
        tau_gravity = pin.computeGeneralizedGravity(self.model, self.data, self.q)

        # 2. PD Controller (ขนาด 12)
        tau_pd_actuated = self.position_controller(self.target_joint_positions)

        # 3. Contact Forces (ขนาด 18)
        tau_contact = self._calculate_contact_force_torques()

        # 4. รวม Torques ทั้งหมด
        final_torques = np.zeros(self.model.nv) # ขนาด 18
        final_torques += tau_gravity
        final_torques -= tau_contact
        final_torques[6:] += tau_pd_actuated # เพิ่ม PD torque เฉพาะส่วนข้อต่อ

        # Debugging output
        self.get_logger().info(f"------------- START --------------------")
        self.get_logger().info(f"Gravity torques: {np.round(tau_gravity, 2)}")
        self.get_logger().info(f"PD torques: {np.round(tau_pd_actuated, 2)}")
        self.get_logger().info(f"Contact torques: {np.round(tau_contact, 2)}")
        self.get_logger().info(f"Final torques: {np.round(final_torques, 2)}")
        self.get_logger().info(f"Current joint positions: {np.round(self.q[7:], 2)}")   
        self.get_logger().info(f"------------- END --------------------")
        # --- DEBUG ---
        # ลอง print Jacobian ของ L_foot_contact ดูอีกครั้ง
        # l_foot_id = self.model.getFrameId("L_foot_contact")
        # Jc_left = pin.getFrameJacobian(self.model, self.data, l_foot_id, pin.ReferenceFrame.LOCAL_WORLD_ALIGNED)
        # print(f"Jacobian L_foot:\n{np.round(Jc_left, 2)}")
        # print(Jc_left)
        # --- END DEBUG ---
        
        # 5. Publish Torque (เฉพาะ 12 ค่าของมอเตอร์)
        effort_msg = Float64MultiArray()
        effort_msg.data = final_torques[6:].tolist()
        self.effort_publisher.publish(effort_msg)
        
        self.update_com_visualization()

    def update_com_visualization(self):
        # ... (โค้ดส่วนนี้ถูกต้อง ไม่ต้องแก้ไข) ...
        pin.centerOfMass(self.model, self.data, self.q)
        com_position = self.data.com[0]
        marker = Marker()
        marker.header.frame_id = "torso"
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