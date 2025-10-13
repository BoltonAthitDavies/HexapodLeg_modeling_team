#!/bin/bash
# Launch PlotJuggler with automatic configuration for hexapod joint visualization

echo "=========================================="
echo "Starting PlotJuggler for Hexapod Robot"
echo "=========================================="
echo ""
echo "This will launch PlotJuggler to visualize:"
echo "  - Joint positions (rev1, rev_2)"
echo "  - Joint velocities (rev1, rev_2)"
echo "  - Joint commands"
echo ""
echo "Make sure your robot is running first:"
echo "  ros2 launch hexapod_gz spawn_robot.launch.py"
echo ""

cd ~/HexapodLeg_modeling_team/2dof
source install/setup.bash

# Launch PlotJuggler with ROS 2 plugin
ros2 run plotjuggler plotjuggler --ros2
