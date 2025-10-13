# hexapod_gz

Spawn the hexapod model in Gazebo Sim (ros_gz_sim) and control its joints using ros2_control position controllers.

## Run

1. Build the workspace with colcon, then source the install setup.
2. Launch simulation without GUI:

   ros2 launch hexapod_gz sim.launch.py gui:=false

3. In another terminal, send joint position commands (sine pattern) to the controller:

   ros2 run hexapod_gz joint_position_commander

If you prefer manual commands:

   ros2 topic pub --rate 20 /joint_position_controller/commands std_msgs/Float64MultiArray "{data: [0.5, -0.4]}"
