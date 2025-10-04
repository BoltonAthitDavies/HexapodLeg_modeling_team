import pinocchio as pin, math
import os
from pinocchio.visualize import MeshcatVisualizer
import numpy as np

urdf_filename = "/home/kittinook/Documents/GitHub/volta_ws/src/volta_description/urdf/volta.urdf"
package_dir = os.path.dirname(os.path.dirname(urdf_filename))
robot = pin.RobotWrapper.BuildFromURDF(urdf_filename, package_dirs=[package_dir])#, root_joint=pin.JointModelFreeFlyer())
model = robot.model
visual_model = robot.visual_model
collision_model = robot.collision_model
data = model.createData()
viz = MeshcatVisualizer(model, collision_model, visual_model)
viz.initViewer(zmq_url="tcp://127.0.0.1:6000")
viz.loadViewerModel(rootNodeName="pinocchio_robot")     

q = np.zeros(6)
qdot = np.zeros(6)
qddot = np.zeros(6)