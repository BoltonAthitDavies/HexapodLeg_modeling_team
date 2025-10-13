#!/bin/bash
# Complete demo: Launch robot with PlotJuggler visualization

echo "================================================"
echo "Hexapod Robot with PlotJuggler Visualization"
echo "================================================"
echo ""
echo "This will launch:"
echo "  1. Gazebo with your robot"
echo "  2. ros2_control controllers"
echo "  3. Automatic sine wave motion"
echo "  4. PlotJuggler for data visualization"
echo ""
echo "Press Enter to continue..."
read

cd ~/HexapodLeg_modeling_team/2dof
source install/setup.bash

echo ""
echo "Launching system..."
echo ""
echo "PlotJuggler will open automatically."
echo "To visualize data:"
echo "  1. Click 'Streaming' → 'ROS2 Topic Subscriber'"
echo "  2. Click 'Start'"
echo "  3. Select topics:"
echo "     - /joint_states"
echo "     - /joint_position_controller/commands"
echo "  4. Click 'OK'"
echo "  5. Drag signals to plot area:"
echo "     - /joint_states/position[0] (rev1 position)"
echo "     - /joint_states/position[1] (rev_2 position)"
echo "     - /joint_states/velocity[0] (rev1 velocity)"
echo "     - /joint_states/velocity[1] (rev_2 velocity)"
echo ""

ros2 launch hexapod_gz spawn_robot_with_viz.launch.py plotjuggler:=true
