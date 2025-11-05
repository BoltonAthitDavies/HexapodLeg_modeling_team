#!/usr/bin/python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64MultiArray, Bool
from sensor_msgs.msg import JointState, Imu
import time
import pinocchio as pin
import os
from pinocchio.visualize import MeshcatVisualizer
import numpy as np
from visualization_msgs.msg import Marker
from std_msgs.msg import Header, ColorRGBA
from geometry_msgs.msg import Point

class ControllerNode(Node):
    def __init__(self):
        super().__init__('dummy_node')
        self.joint_state = {}
        urdf_filename = "/home/kittinook/Documents/GitHub/volta_ws/src/volta_description/urdf/volta_full.urdf"
        package_dir = os.path.dirname(os.path.dirname(urdf_filename))
        self.robot = pin.RobotWrapper.BuildFromURDF(urdf_filename, package_dirs=[package_dir])#, root_joint=pin.JointModelFreeFlyer())
        self.model = self.robot.model
        self.visual_model = self.robot.visual_model
        self.collision_model = self.robot.collision_model
        self.data = self.model.createData()
        # self.viz = MeshcatVisualizer(self.model, self.collision_model, self.visual_model)
        # self.viz.initViewer(zmq_url="tcp://127.0.0.1:6000")
        # self.viz.loadViewerModel(rootNodeName="pinocchio_robot")     

        self.effort_publisher = self.create_publisher(Float64MultiArray,'/effort_controller/commands',10)
        self.cm_marker_publisher = self.create_publisher(Marker, 'com_marker', 10)
        self.create_subscription(JointState,'/joint_states',self.feedback_callback,10)
        time.sleep(1)
        self.create_timer(0.01, self.control_loop_callback)
        self.q = np.zeros(12)
        self.qdot = np.zeros(12)
        self.qddot = np.zeros(12)
        # self.ctrl_input = np.zeros(6)
        self.ctrl_input = [0.0] * 12

    def center_of_mass_publisher(self, com):
        # สร้าง Marker ให้เป็นลูกบอลขนาดเล็กสีแดง
        marker = Marker()
        marker.header = Header()
        marker.header.stamp = self.get_clock().now().to_msg()
        marker.header.frame_id = 'torso'         # กำหนดเฟรม (ปรับตาม URDF ของคุณ)
        marker.ns = 'com'
        marker.id = 0
        marker.type = Marker.SPHERE
        marker.action = Marker.ADD

        # ตั้งขนาดสเกลของลูกบอล
        marker.scale.x = 0.05
        marker.scale.y = 0.05
        marker.scale.z = 0.05

        # สีแดงโปร่งแสง
        marker.color = ColorRGBA(r=1.0, g=0.0, b=0.0, a=0.8)

        # ตำแหน่ง Center of Mass
        marker.pose.position = Point(x=float(com[0]), y=float(com[1]), z=float(com[2]))
        marker.pose.orientation.w = 1.0  # no rotation

        # เผยแพร่ Marker
        self.cm_marker_publisher.publish(marker)

    def control_loop_callback(self):
        # c_target = np.array([0.0, 0.1, -0.25])
        tol = 0.01
        damping = 0.01
        if self.joint_state == {}:
            self.get_logger().error("Joint state not received yet.")
            return
        self.qd = np.array(self.joint_state["qd"])
        self.q = np.array(self.joint_state["q"])
        self.c_ref      = np.array([0.005, 0.165, -0.2])
        # self.c_ref      = np.array([0.0, 0.1, -0.25])
        self.c_dot_ref  = np.zeros(3)
        self.c_ddot_ref = np.zeros(3)
        self.Kp = 300.0
        self.Kd = 2.5

        self.mass = sum(inertia.mass for inertia in self.model.inertias)
        # print('Total mass of the model: ', self.mass)
        # total_Mass = pin.computeTotalMass(self.model,self.data)
        # print('Total mass of the model: ', total_Mass)
        pin.forwardKinematics(self.model, self.data, self.q)
        pin.updateFramePlacements(self.model, self.data)
        # com = pin.centerOfMass(self.model, self.data, self.q)
        # self.center_of_mass_publisher(com)
        # J_com = pin.jacobianCenterOfMass(self.model, self.data, self.q)
        # print(J_com)
        # tau_position = self.position_control([0.493, 0.221, -0.119, -0.696, -0.2, 0.18])
        tau = self.position_control([0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0])
        # tau = self.position_control([-0.364, 0.0, 0.0, -0.675, -0.316, 0.0, 
        #                              0.364, 0.0, 0.0, 0.675, 0.316, 0.0])
        # tau_g = pin.rnea(self.model, self.data, self.q, self.qd, self.qddot)   # 1*7 vector
        tau_g = pin.computeGeneralizedGravity(self.model, self.data,self.q)
        print(tau)
        print(tau_g)
        print("---")

        # ค่าแรงที่คำนวณ/ประมาณได้ (ใน World Frame)
        fx = 0.0
        fy = 0.0
        fz = 25.0

        # ค่าโมเมนต์ (ใน World Frame) - สมมติเป็นศูนย์สำหรับ Point Contact
        tau_x = 0.0
        tau_y = 0.0
        tau_z = 0.0 # อาจใส่ค่าถ้ามี Yaw friction

        linear_force_components = np.array([fx, fy, fz])
        angular_torque_components = np.array([tau_x, tau_y, tau_z])
        
        force_wheel1_world = pin.Force(linear_force_components, angular_torque_components)
        force_wheel2_world = pin.Force(linear_force_components, angular_torque_components)

        contact_frame_names = ["L_foot", "R_foot"]
        contact_forces_world = [force_wheel1_world, force_wheel2_world]
        
        tau_actuation = tau_g.copy()

        if contact_frame_names and contact_forces_world:
            if len(contact_frame_names) != len(contact_forces_world):
                raise ValueError("Number of contact frame names and contact forces must match.")

            for i, frame_name in enumerate(contact_frame_names):
                # --- ส่วนที่แก้ไข ---
                # ตรวจสอบว่า Frame มีอยู่ใน Model หรือไม่
                if not self.model.existFrame(frame_name):
                    print(f"[ERROR] Frame '{frame_name}' does not exist in the model.")
                    continue # ข้าม Frame นี้ไป หรือจะให้หยุด Error ก็ได้

                # แปลงชื่อ Frame (string) เป็น Frame ID (integer)
                frame_id = self.model.getFrameId(frame_name)
                # --- สิ้นสุดส่วนที่แก้ไข ---

                Fc_world = contact_forces_world[i]

                # ใช้ frame_id (integer) ในการเรียกฟังก์ชัน
                pin.computeFrameJacobian(self.model, self.data, self.q, frame_id) # คำนวณ Jacobian
                Jc = pin.getFrameJacobian(self.model, self.data, frame_id, pin.ReferenceFrame.LOCAL_WORLD_ALIGNED)

                tau_contact_effect = Jc.T @ Fc_world.vector
                tau_actuation -= tau_contact_effect
        # A_G = pin.computeCentroidalMap(self.model, self.data, self.q)
        # extract linear part and normalize
        # total_mass = self.mass
        # Jc_world = A_G[3:6, :] / total_mass       # shape (3×nv)
        # get base_link frame placement (world→base_link)
        # base_id = self.model.getFrameId('torso')
        # oMi     = self.data.oMf[base_id]
        # R_w_b   = oMi.rotation.T                  # from world → base_link

        # CoM Jacobian in base_link
        # Jc_body = R_w_b @ Jc_world                # still 3×nv

        # F_b_cm = (self.c_ref - com) * 300
        # print(com)
        # tau_cm = Jc_body.T @ F_b_cm
        # tau = tau_cm
        # self.ctrl_input[0] = float(tau_position[0] + tau.T[0])
        # self.ctrl_input[1] = float(tau_position[1] + tau.T[1])
        # self.ctrl_input[2] = float(tau_position[2] + tau.T[2])
        # self.ctrl_input[3] = float(tau_position[3] + tau.T[3])
        # self.ctrl_input[4] = float(tau_position[4] + tau.T[4])
        # self.ctrl_input[5] = float(tau_position[5] + tau.T[5])
        # self.ctrl_input =  tau + tau_g 
 
        # self.ctrl_input[0] = float(tau[0] + tau_g[0])#.T[0])
        # self.ctrl_input[1] = float(tau[1] + tau_g[1])#.T[1])
        # self.ctrl_input[2] = float(tau[2] + tau_g[2])#.T[2])
        # self.ctrl_input[3] = float(tau[3] + tau_g[3])#.T[3])
        # self.ctrl_input[4] = float(tau[4] + tau_g[4])#.T[4])
        # self.ctrl_input[5] = float(tau[5] + tau_g[5])#.T[5])
        # self.ctrl_input[6] = float(tau[6] + tau_g[6])#.T[0])
        # self.ctrl_input[7] = float(tau[7] + tau_g[7])#.T[1])
        # self.ctrl_input[8] = float(tau[8] + tau_g[8])#.T[2])
        # self.ctrl_input[9] = float(tau[9] + tau_g[9])#.T[3])
        # self.ctrl_input[10] = float(tau[10] + tau_g[10])#.T[4])
        # self.ctrl_input[11] = float(tau[11] + tau_g[11])#.T[5])
        
        self.ctrl_input[0] = float(tau[0] + tau_g[0])#.T[0])
        self.ctrl_input[1] = float(tau[1] + tau_g[1])#.T[1])
        self.ctrl_input[2] = float(tau[2] + tau_g[2])#.T[2])
        self.ctrl_input[3] = float(tau[3] + tau_g[3])#.T[3])
        self.ctrl_input[4] = float(tau[4] + tau_g[4])#.T[4])
        self.ctrl_input[5] = float(tau[5] + tau_g[5])#.T[5])
        self.ctrl_input[6] = float(tau[6] + tau_g[6])#.T[0])
        self.ctrl_input[7] = float(tau[7] + tau_g[7])#.T[1])
        self.ctrl_input[8] = float(tau[8] + tau_g[8])#.T[2])
        self.ctrl_input[9] = float(tau[9] + tau_g[9])#.T[3])
        self.ctrl_input[10] = float(tau[10] + tau_g[10])#.T[4])
        self.ctrl_input[11] = float(tau[11] + tau_g[11])#.T[5])

        # self.ctrl_input[0] = float(tau[0])#.T[0])
        # self.ctrl_input[1] = float(tau[1])#.T[1])
        # self.ctrl_input[2] = float(tau[2])#.T[2])
        # self.ctrl_input[3] = float(tau[3])#.T[3])
        # self.ctrl_input[4] = float(tau[4])#.T[4])
        # self.ctrl_input[5] = float(tau[5])#.T[5])
        # self.ctrl_input[6] = float(tau[6])#.T[0])
        # self.ctrl_input[7] = float(tau[7])#.T[1])
        # self.ctrl_input[8] = float(tau[8])#.T[2])
        # self.ctrl_input[9] = float(tau[9])#.T[3])
        # self.ctrl_input[10] = float(tau[10])#.T[4])
        # self.ctrl_input[11] = float(tau[11])#.T[5])

        # # ค่าแรงที่คำนวณ/ประมาณได้ (ใน World Frame)
        # fx = 0.0
        # fy = 0.0
        # fz = (5.0 * 9.81) / 2.0

        # # ค่าโมเมนต์ (ใน World Frame) - สมมติเป็นศูนย์สำหรับ Point Contact
        # tau_x = 0.0
        # tau_y = 0.0
        # tau_z = 0.0 # อาจใส่ค่าถ้ามี Yaw friction

        # สร้าง NumPy arrays
        # linear_force_components = np.array([fx, fy, fz])
        # angular_torque_components = np.array([tau_x, tau_y, tau_z])

        # pin.computeFrameJacobian(self.model, self.data, self.q, "R_foot") # คำนวณ Jacobian
        # Jc = pin.getFrameJacobian(self.model, self.data, "R_foot", pin.ReferenceFrame.LOCAL_WORLD_ALIGNED)

        # tau_contact_effect = Jc.T @ Fc_world.vector
        # tau_actuation -= tau_contact_effect
        # self.get_logger().info(f'Publishing torque: {self.ctrl_input}')

        effort = Float64MultiArray()
        effort.data = self.ctrl_input
        self.effort_publisher.publish(effort)
        # self.get_logger().info(f'Publishing effort: {effort.data}')
        # q = np.array( [self.q[0], self.q[1], self.q[2], 0.0, 1.0,
        #                    self.q[5], self.q[6], self.q[7], 0.0, 1.0] )
        # q = np.array( [0.0, 0.0, 0.0, 0.0, 0.0, 0.0] )
        # self.viz.display(self.q)
        pass

    def feedback_callback(self, msg):
        joint_names = msg.name
        joint_q = msg.position
        joint_qd = msg.velocity
        joint_eff = msg.effort

        order = [
            'motor_1', 'motor_2', 'motor_3',
            'motor_4', 'motor_5', 'motor_6',
            'motor_7', 'motor_8', 'motor_9',
            'motor_10', 'motor_11', 'motor_12'
        ]

        joint_data = {
            name: (q, qd, effort)
            for name, q, qd, effort in zip(joint_names, joint_q, joint_qd, joint_eff)
        }

        self.joint_state = {
            'names': order,
            'q': [joint_data[joint][0] for joint in order],
            'qd': [joint_data[joint][1] for joint in order],
            'efforts': [joint_data[joint][2] for joint in order]
        }
    
    def position_control(self,targ):
        if not self.joint_state:
            return 
        MAX_TRQ = 4.0
        kp = 1.9
        kd = 0.01
        e_q0 = targ[0] - self.joint_state["q"][0]
        tau_q0 = kp*e_q0 - kd*self.joint_state["qd"][0]
        tau_q0 = max(-MAX_TRQ , min(MAX_TRQ , tau_q0))

        e_q1 = targ[1] - self.joint_state["q"][1]
        tau_q1 = kp*e_q1  - kd*self.joint_state["qd"][1]
        tau_q1 = max(-MAX_TRQ , min(MAX_TRQ , tau_q1))

        e_q2 = targ[2] - self.joint_state["q"][2]
        tau_q2 = kp*e_q2 - kd*self.joint_state["qd"][2]
        tau_q2 = max(-MAX_TRQ , min(MAX_TRQ , tau_q2))

        e_q3 = targ[3] - self.joint_state["q"][3]
        tau_q3 = kp*e_q3 - kd*self.joint_state["qd"][3]
        tau_q3 = max(-MAX_TRQ , min(MAX_TRQ , tau_q3))

        e_q4 = targ[4] - self.joint_state["q"][4]
        tau_q4 = kp*e_q4 - kd*self.joint_state["qd"][4]
        tau_q4 = max(-MAX_TRQ , min(MAX_TRQ , tau_q4))

        e_q5 = targ[5] - self.joint_state["q"][5]
        tau_q5 = kp*e_q5 - kd*self.joint_state["qd"][5]
        tau_q5 = max(-MAX_TRQ , min(MAX_TRQ , tau_q5))

        e_q6 = targ[6] - self.joint_state["q"][6]
        tau_q6 = kp*e_q6 - kd*self.joint_state["qd"][6]
        tau_q6 = max(-MAX_TRQ , min(MAX_TRQ , tau_q6))

        e_q7 = targ[7] - self.joint_state["q"][7]
        tau_q7 = kp*e_q7 - kd*self.joint_state["qd"][7]
        tau_q7 = max(-MAX_TRQ , min(MAX_TRQ , tau_q7))

        e_q8 = targ[8] - self.joint_state["q"][8]
        tau_q8 = kp*e_q8 - kd*self.joint_state["qd"][8]
        tau_q8 = max(-MAX_TRQ , min(MAX_TRQ , tau_q8))

        e_q9 = targ[9] - self.joint_state["q"][9]
        tau_q9 = kp*e_q9 - kd*self.joint_state["qd"][9]
        tau_q9 = max(-MAX_TRQ , min(MAX_TRQ , tau_q9))

        e_q10 = targ[10] - self.joint_state["q"][10]
        tau_q10 = kp*e_q10 - kd*self.joint_state["qd"][10]
        tau_q10 = max(-MAX_TRQ , min(MAX_TRQ , tau_q10))

        e_q11 = targ[11] - self.joint_state["q"][11]
        tau_q11 = kp*e_q11 - kd*self.joint_state["qd"][11]
        tau_q11 = max(-MAX_TRQ , min(MAX_TRQ , tau_q11))
        return tau_q0, tau_q1, tau_q2, tau_q3, tau_q4, tau_q5, tau_q6, tau_q7, tau_q8, tau_q9, tau_q10, tau_q11
    
def main(args=None):
    rclpy.init(args=args)
    node = ControllerNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__=='__main__':
    main()
