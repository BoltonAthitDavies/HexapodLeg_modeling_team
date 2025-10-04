
Converted your URDF to Xacro:

- Input:  hexapod_modelling_team.urdf
- Output: hexapod_modelling_team.xacro

The converter added the xacro namespace and a property:
  <xacro:property name="mesh_dir" value="package://hexapod_description/meshes"/>

It also rewrote mesh paths to use: filename="${mesh_dir}/<basename>.STL"

How to preview (ROS 2 Foxy/Humble+):
  ros2 run xacro xacro hexapod_modelling_team.xacro > hexapod_modelling_team.urdf   # expand xacro
  # Or override mesh_dir:
  ros2 run xacro xacro hexapod_modelling_team.xacro mesh_dir:=package://my_pkg/meshes > hexapod_modelling_team_resolved.urdf

Common fixes you may want to do manually in the .xacro:
  - Set inertial values (mass, inertia) for each link (xacro cannot infer them).
  - Verify origin tags and units (STL should be in meters).
  - Ensure your meshes are installed at the mesh_dir path.

Files are in /mnt/data.
