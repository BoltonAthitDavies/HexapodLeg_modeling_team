#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy, DurabilityPolicy
from rclpy.qos import (
    QoSProfile, QoSReliabilityPolicy,
    QoSHistoryPolicy, QoSDurabilityPolicy
)
from visualization_msgs.msg import Marker
from geometry_msgs.msg import Point
from sensor_msgs.msg import JointState
from std_msgs.msg import Float64MultiArray, Int16MultiArray
from std_msgs.msg import Float64MultiArray as DesiredJointMsg
from cascade_controller_interfaces.msg import MotorControl, MotorControlGroup, SetPoint
import numpy as np
from pydrake.math import RigidTransform, RollPitchYaw
from pydrake.multibody.parsing import Parser
from pydrake.multibody.plant import MultibodyPlant
from pydrake.multibody.math import SpatialForce
from pydrake.multibody.tree import MultibodyForces
from sensor_msgs.msg import Imu
from nav_msgs.msg import Odometry
import os

class InverseDynamicsController(Node):
    def __init__(self):
        super().__init__('inverse_dynamics_controller_node')
        self.get_logger().info("Starting Inverse Dynamics Controller Node")
        self.plant,self.robot_idx = DefinePlant(model_name="Volta_rev4",
                                 is_fixed=False,
                                 fixed_frame="torso")
        self.DefineVariables()
        self.CreateSubscribers()
        self.CreatePublishers()
        execute_hz = 70.0 # joint state can publish at 75 Hz
        self.update_event_timer = self.create_timer(1/execute_hz, self.UpdateEvent)  # 70 Hz
      
    def CreateSubscribers(self):
        sensor_qos = QoSProfile(depth=10)
        sensor_qos.reliability = ReliabilityPolicy.BEST_EFFORT
        self.joint_state_sub = self.create_subscription(
            JointState,
            '/joint_states',
            self.JointStateCallback,
            qos_profile=sensor_qos
        )
        # imu_qos = QoSProfile(
        #     reliability=ReliabilityPolicy.BEST_EFFORT,
        #     durability=DurabilityPolicy.VOLATILE,
        #     history=HistoryPolicy.KEEP_LAST,
        #     depth=10
        # )
        # self.imu_sub = self.create_subscription(
        #     Imu,
        #     'imu/data',   # topic name
        #     self.IMUCallback,
        #     qos_profile=imu_qos  # QoS profile   
        # )
        self.camera_pose_qos = QoSProfile(
            reliability=QoSReliabilityPolicy.BEST_EFFORT,
            history=QoSHistoryPolicy.KEEP_LAST,
            depth=10,
            durability=QoSDurabilityPolicy.VOLATILE
        )
        self.camera_pose_sub = self.create_subscription(
            Odometry,
            '/camera/pose/sample',
            self.CameraPoseCallback,
            qos_profile=self.camera_pose_qos
        )
    def CreatePublishers(self):
        self.com_maker_pub = self.create_publisher(Marker,
                                                   '/com_marker',10)
        self.tau_id_pub = self.create_publisher(Float64MultiArray,
                                               '/tau_id',10)
    
    def DefineVariables(self):
        self.total_torque = np.zeros(12)
        self.plant_context = self.plant.CreateDefaultContext()
        self.num_motors = 12
        self.current_joints_position   = np.zeros(self.num_motors)
        self.current_joints_velocity   = np.zeros(self.num_motors)
        self.current_joints_effort     = np.zeros(self.num_motors)
        self.current_base_pose = np.array([1.0,0.0,0.0,0.0,0.0,0.0,0.0]) # w,x,y,z, x, y, z
        self.generalize_position = np.concatenate((self.current_base_pose,self.current_joints_position))
        self.selection_matrix = np.concatenate((np.zeros((12, 6)), np.eye(12)), axis=1)
        self.contact_frames = [
            "L_foot_contact_FL", "L_foot_contact_FR", "L_foot_contact_RL", "L_foot_contact_RR",
            "R_foot_contact_FL", "R_foot_contact_FR", "R_foot_contact_RL", "R_foot_contact_RR"
        ]
        self.plant.SetPositions(self.plant_context,self.generalize_position)
        self.contact_positions = CalcContactPointPositionsInCoM(plant=self.plant, 
                                                                context=self.plant_context, 
                                                                contact_frame_names=self.contact_frames)
        
        force_distribution_z = []
        for i in range(self.contact_positions.shape[0]):
            force_distribution_z.append([self.contact_positions[i,0],
                                        self.contact_positions[i,1],
                                        1.0])
        self.force_distribution_matrix_Z = np.array(force_distribution_z).T
        self.force_distribution_matrix_X = np.concatenate((np.array(self.force_distribution_matrix_Z[0,:]).reshape(1, -1),
                                                    np.ones((1, self.force_distribution_matrix_Z.shape[1]))), axis=0)
        self.force_distribution_matrix_Y = np.concatenate((np.array(self.force_distribution_matrix_Z[1,:]).reshape(1, -1),
                                                    np.ones((1, self.force_distribution_matrix_Z.shape[1]))), axis=0)
        self.leg_state = "double_stance" # L_stance or R_stance or double_stance
    
    def UpdateEvent(self):
        self.UpdateVariables() 
        known_vdot = np.zeros(18)
        f_u = np.zeros(3)
        gravitational_vector  = np.array([0, 0, -9.81])
        m = self.plant.CalcTotalMass(self.plant_context)
        # print("mass: ", m)
        desired_GAF = f_u + m*gravitational_vector
        desired_CoP_position = np.array([0.0, 0.0])
        contact_forces_Z = self.CalcContactForcesDistribution(desired_GAF=desired_GAF,
                                                              desired_CoP_position=desired_CoP_position)
        torque_g = self.plant.CalcGravityGeneralizedForces(context=self.plant_context)
        torque_id = self.CalcTorqueFromInverseDynamics(known_vdot=known_vdot,
                                                       contact_forces=-1.0*contact_forces_Z)
        # torque_u = self.CalcAccFromPDController() 
        self.total_torque = (self.selection_matrix@(torque_id - torque_g))  
        # print("total torque: ", self.total_torque)
        self.PubTauid(tau_id=list(self.total_torque))

    def UpdateVariables(self):
        self.generalize_position = np.concatenate((self.current_base_pose,self.current_joints_position))
        # print("generalized position: ", self.generalize_position)
        self.plant.SetPositions(self.plant_context,self.generalize_position)
        self.plant.SetVelocities(self.plant_context,np.zeros(self.plant.num_velocities()))
        self.UpdateLegState(generalized_position=self.generalize_position)
        print("leg state: ", self.leg_state)
        match self.leg_state:
            case "L_stance":
                active_contact_frames = self.contact_frames[0:4]
            case "R_stance":
                active_contact_frames = self.contact_frames[4:8]
            case "double_stance":
                active_contact_frames = self.contact_frames
        self.contact_positions = CalcContactPointPositionsInCoM(plant=self.plant, 
                                                                context=self.plant_context, 
                                                                contact_frame_names=active_contact_frames)
        
        force_distribution_z = []
        for i in range(self.contact_positions.shape[0]):
            force_distribution_z.append([self.contact_positions[i,0],
                                        self.contact_positions[i,1],
                                        1.0])
        self.force_distribution_matrix_Z = np.array(force_distribution_z).T
        self.force_distribution_matrix_X = np.concatenate((np.array(self.force_distribution_matrix_Z[0,:]).reshape(1, -1),
                                                    np.ones((1, self.force_distribution_matrix_Z.shape[1]))), axis=0)
        self.force_distribution_matrix_Y = np.concatenate((np.array(self.force_distribution_matrix_Z[1,:]).reshape(1, -1),
                                                    np.ones((1, self.force_distribution_matrix_Z.shape[1]))), axis=0)

    def UpdateLegState(self, generalized_position):
        self.plant.SetPositions(self.plant_context, generalized_position)
        W_P_com = self.plant.CalcCenterOfMassPositionInWorld(self.plant_context)
        # print("W_P_com : ", W_P_com[0:2])
        torso = self.plant.GetFrameByName("torso")
        W_P_torso = torso.CalcPoseInWorld(self.plant_context).translation()
        L_foot_contact = self.plant.GetFrameByName("L_foot_contact")
        L_P_com = L_foot_contact.CalcPoseInWorld(self.plant_context).inverse().multiply(W_P_com)
        # L_P_torso = L_foot_contact.CalcPoseInWorld(self.plant_context).inverse().multiply(W_P_torso)
        R_foot_contact = self.plant.GetFrameByName("R_foot_contact")
        R_P_com = R_foot_contact.CalcPoseInWorld(self.plant_context).inverse().multiply(W_P_com)
        # R_P_torso = R_foot_contact.CalcPoseInWorld(self.plant_context).inverse().multiply(W_P_torso)
        self.PubCoMMarker(torso_P_com=W_P_com)
        offset = 5 # [mm]
        L_foot_rect = np.array([-110+offset,-49+offset,
                                110-offset, 49-offset]) * 1e-3
        R_foot_rect = np.array([-110+offset,-49+offset,
                                110-offset, 49-offset]) * 1e-3
        if IsInsideRectangle(point=L_P_com[0:2], rect=L_foot_rect):
            self.leg_state = "L_stance"
        elif IsInsideRectangle(point=R_P_com[0:2], rect=R_foot_rect):
            self.leg_state = "R_stance"
        else:
            self.leg_state = "double_stance"

    def PubTauid(self,tau_id):
        msg = Float64MultiArray()
        msg.data = tau_id
        self.tau_id_pub.publish(msg)

    def CalcAccFromPDController(self):
        q_error = self.q_desire - self.q
        qd_error = self.qd_desire - self.qd
        return self.kp * q_error + self.kd * qd_error
    
    def CalcContactForcesDistribution(self,desired_GAF,desired_CoP_position):
        contact_forces_Z = np.linalg.pinv(self.force_distribution_matrix_Z) @ np.array([desired_CoP_position[0], desired_CoP_position[1], 1.0]) * desired_GAF[2]
        if self.leg_state == "L_stance":
            contact_forces_Z = np.concatenate((contact_forces_Z, np.zeros(4)), axis=0)
        elif self.leg_state == "R_stance":
            contact_forces_Z = np.concatenate((np.zeros(4), contact_forces_Z), axis=0)
        return contact_forces_Z

    def CalcTorqueFromInverseDynamics(self,known_vdot,contact_forces):
        external_forces = MultibodyForces(self.plant)
        for i in range(len(self.contact_frames)):
            contact_frame = self.plant.GetBodyByName(self.contact_frames[i])
            F_Bo_W = SpatialForce(tau=np.zeros(3), f=np.array([0,0,contact_forces[i]]))
            contact_frame.AddInForceInWorld(self.plant_context, F_Bo_W, external_forces)
        # known_vdot = np.zeros(18)

        torque_id = self.plant.CalcInverseDynamics(context=self.plant_context,
                                    known_vdot=known_vdot,
                                    external_forces=external_forces)
        return torque_id

    def JointStateCallback(self, msg: JointState):
        for i in range(self.num_motors):
            if i < self.num_motors:
                self.current_joints_position[i] = msg.position[i]
                self.current_joints_velocity[i] = msg.velocity[i]
                self.current_joints_effort[i] = msg.effort[i]
        
    def CameraPoseCallback(self, msg: Odometry):
        # print("Camera pose data received")
        # print("Position: x={:.3f}, y={:.3f}, z={:.3f}".format(
        #     msg.pose.pose.position.x, msg.pose.pose.position.y, msg.pose.pose.position.z))
        # print("Orientation: x={:.3f}, y={:.3f}, z={:.3f}, w={:.3f}".format(
        #     msg.pose.pose.orientation.x, msg.pose.pose.orientation.y, msg.pose.pose.orientation.z, msg.pose.pose.orientation.w))    
        # print(" self.current_base_pose[0] pre",self.current_base_pose[0])
        self.current_base_pose[0] = msg.pose.pose.orientation.w
        self.current_base_pose[1] = msg.pose.pose.orientation.x
        self.current_base_pose[2] = msg.pose.pose.orientation.y
        self.current_base_pose[3] = msg.pose.pose.orientation.z


    # def IMUCallback(self, msg: Imu):
    #     # Example: print orientation, angular velocity, linear acceleration
    #     print("IMU data received")
    #     self.get_logger().info(
    #         f"\nOrientation: x={msg.orientation.x:.3f}, y={msg.orientation.y:.3f}, z={msg.orientation.z:.3f}, w={msg.orientation.w:.3f}\n"
    #         # f"Angular Vel: x={msg.angular_velocity.x:.3f}, y={msg.angular_velocity.y:.3f}, z={msg.angular_velocity.z:.3f}\n"
    #         # f"Linear Accel: x={msg.linear_acceleration.x:.3f}, y={msg.linear_acceleration.y:.3f}, z={msg.linear_acceleration.z:.3f}"
    #     )
    #     self.current_base_pose[0] = msg.orientation.w
    #     self.current_base_pose[1] = msg.orientation.x
    #     self.current_base_pose[2] = msg.orientation.y
    #     self.current_base_pose[3] = msg.orientation.z

    def PubCoMMarker(self, torso_P_com):
        marker = Marker()
        marker.header.frame_id = "torso"  # Or your root link
        marker.header.stamp = self.get_clock().now().to_msg()
        marker.ns = "center_of_mass"
        marker.id = 0
        marker.type = Marker.SPHERE
        marker.action = Marker.ADD
        marker.pose.position.x = torso_P_com[0]
        marker.pose.position.y = torso_P_com[1]
        marker.pose.position.z = torso_P_com[2]
        marker.pose.orientation.w = 1.0
        marker.scale.x = 0.015
        marker.scale.y = 0.015
        marker.scale.z = 0.015
        marker.color.a = 1.0
        marker.color.r = 1.0
        marker.color.g = 0.0
        marker.color.b = 0.1
        self.com_maker_pub.publish(marker)

def CalcPositionVectorFromCoM(plant:MultibodyPlant, context, target_frame_name:str):
    W_P_com = plant.CalcCenterOfMassPositionInWorld(context)
    target_frame = plant.GetFrameByName(target_frame_name) 
    W_P_target = target_frame.CalcPoseInWorld(context).translation()
    W_P_com_target = W_P_target - W_P_com
    return W_P_com_target

def CalcContactPointPositionsInCoM(plant, context, contact_frame_names):
    positions = []
    for frame_name in contact_frame_names:
        positions.append(CalcPositionVectorFromCoM(
            plant=plant,
            context=context,
            target_frame_name=frame_name
        ))
    return np.array(positions)
        
def IsInsideRectangle(point, rect):
    """
    Check if a point is inside a rectangle.

    Parameters:
        point: np.array([x, y])
        rect: np.array([x_min, y_min, x_max, y_max])

    Returns:
        True if point is inside or on the edge of the rectangle.
    """
    x, y = point
    x_min, y_min, x_max, y_max = rect
    return x_min <= x <= x_max and y_min <= y <= y_max
        
def DefinePlant(model_name:str,is_fixed:bool,fixed_frame:str)->MultibodyPlant:
    plant = MultibodyPlant(time_step=0.0)
    parser = Parser(plant)
    urdf = model_name+".urdf"
    dir = "/home/tanawatp/volta_ws/src/volta_controller/scripts/robot_model"
    robot_urdf_path = os.path.join(dir,urdf)
    robot_instant_index = parser.AddModels(robot_urdf_path)
    if is_fixed:
        robot_fixed_frame = plant.GetFrameByName(fixed_frame)
        init_pos = [0.0, 0.0, 0.0] 
        init_orien = np.asarray([0, 0, 0])
        X_WRobot = RigidTransform(
        RollPitchYaw(init_orien * np.pi / 180), p=init_pos)
        plant.WeldFrames(plant.world_frame(),robot_fixed_frame, X_WRobot)
    plant.Finalize()
    return plant, robot_instant_index

def main(args=None):
    rclpy.init(args=args)
    node = InverseDynamicsController()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()