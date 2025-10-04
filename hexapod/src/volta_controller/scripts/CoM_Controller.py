#!/usr/bin/env python3
"""
CoM torque controller ROS2 node using Pinocchio.
Computes CoM and its Jacobian in body frame, generates task torques,
and publishes per-joint effort commands.
"""
import os
import time
import numpy as np

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from std_msgs.msg import Float64MultiArray
from visualization_msgs.msg import Marker
from geometry_msgs.msg import Point
from std_msgs.msg import Header, ColorRGBA

import pinocchio as pin
from pinocchio.utils import zero
from pinocchio.visualize import MeshcatVisualizer

class CoMTorqueController(Node):
    def __init__(self):
        super().__init__('com_torque_controller')
        # --- Robot model ---
        urdf_path = '/home/kittinook/Documents/GitHub/volta_ws/src/volta_description/urdf/volta.urdf'
        pkg_dir = os.path.dirname(os.path.dirname(urdf_path))
        self.robot = pin.RobotWrapper.BuildFromURDF(urdf_path,
                                                   [pkg_dir])
        self.model = self.robot.model
        self.data  = self.model.createData()

        # Initialize Pinocchio visualizer (Meshcat)
        self.viz = MeshcatVisualizer(self.model,
                                     self.robot.collision_model,
                                     self.robot.visual_model)
        self.viz.initViewer(zmq_url="tcp://127.0.0.1:6000")
        self.viz.loadViewerModel(rootNodeName="pinocchio_robot")

        # --- State vectors ---
        self.q     = pin.neutral(self.model)            # configuration (nq)
        self.qd    = zero(self.model.nv)                # velocity (nv)
        self.qddot = zero(self.model.nv)

        # --- CoM setpoints & gains ---
        self.c_ref      = np.array([0.005, 0.165, -0.2])
        self.c_dot_ref  = np.zeros(3)
        self.c_ddot_ref = np.zeros(3)
        self.Kp = 10.0
        self.Kd = 0.5

        # Precompute total mass
        self.mass = sum(I.mass for I in self.model.inertias)
        self.get_logger().info(f"Total robot mass: {self.mass:.3f} kg")

        # Joint order for actuated motors
        self.joint_names = [
            'motor_1', 'motor_2', 'motor_3',
            'motor_4', 'motor_5', 'motor_6'
        ]

        # --- Publishers & Subscribers ---
        self.effort_pub = self.create_publisher(
            Float64MultiArray,
            '/effort_controller/commands',
            10
        )
        self.cm_marker_pub = self.create_publisher(Marker,
                                                   '/com_marker', 10)
        self.create_subscription(
            JointState,
            '/joint_states',
            self.feedback_cb,
            10
        )

        # Timer for control loop at 100Hz
        self.create_timer(0.01, self.control_loop)

    def feedback_cb(self, msg: JointState):
        # Update self.q and self.qd from incoming JointState
        for name, pos, vel in zip(msg.name, msg.position, msg.velocity):
            if name in self.joint_names:
                jid = self.model.getJointId(name)
                self.q[jid-1]  = pos
                self.qd[jid-1] = vel

    def publish_com_marker(self, com_body):
        m = Marker()
        m.header = Header()
        m.header.stamp = self.get_clock().now().to_msg()
        m.header.frame_id = 'torso'       # body frame
        m.ns     = 'com'
        m.id     = 0
        m.type   = Marker.SPHERE
        m.action = Marker.ADD
        m.scale.x = m.scale.y = m.scale.z = 0.05
        m.color = ColorRGBA(r=1.0, g=0.0, b=0.0, a=0.8)
        m.pose.position.x = com_body[0]
        m.pose.position.y = com_body[1]
        m.pose.position.z = com_body[2]
        m.pose.orientation.w = 1.0
        self.cm_marker_pub.publish(m)

    def control_loop(self):
        # 1) Forward kinematics
        pin.forwardKinematics(self.model, self.data, self.q, self.qd)
        pin.updateFramePlacements(self.model, self.data)

        # 2) Compute CoM in world
        com_world = pin.centerOfMass(self.model, self.data, self.q)

        # 3) Centroidal map → world‐Jacobian of CoM
        A_G       = pin.computeCentroidalMap(self.model, self.data, self.q)
        Jc_world  = A_G[3:6, :] / self.mass

        # 4) Convert to body frame 'torso'
        base_frame = 'torso'
        base_id    = self.model.getFrameId(base_frame)
        oMi        = self.data.oMf[base_id]
        R_w_b      = oMi.rotation.T
        # CoM position in body frame
        com_body   = R_w_b.dot(com_world - oMi.translation)
        # CoM Jacobian in body
        Jc_body    = R_w_b.dot(Jc_world)

        # Publish CoM marker
        self.publish_com_marker(com_body)

        # 5) Task‐space control law
        e      = self.c_ref      - com_body
        edot   = self.c_dot_ref  - Jc_body.dot(self.qd)
        a_des  = self.Kp*e + self.Kd*edot + self.c_ddot_ref
        F_com  = self.mass * a_des

        # 6) Joint‐space torque
        tau_task = Jc_body.T.dot(F_com)
        tau_g    = pin.rnea(self.model, self.data, self.q,
                             self.qd, zero(self.model.nv))
        tau      = tau_task + tau_g

        # 7) Extract actuated torques
        cmd = []
        for name in self.joint_names:
            jid = self.model.getJointId(name)
            cmd.append(float(tau[jid-1]))

        # Publish efforts
        effort = Float64MultiArray(data=cmd)
        self.effort_pub.publish(effort)

        # 8) Visualize in Meshcat
        self.viz.display(self.q)

    def destroy_node(self):
        # cleanly shut down
        self.viz.viewer.client.close()
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = CoMTorqueController()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
