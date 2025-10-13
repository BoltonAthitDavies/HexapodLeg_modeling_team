#!/bin/bash
# Quick Start Script for Hexapod Robot in Gazebo

echo "=========================================="
echo "Hexapod Robot - Gazebo Quick Start"
echo "=========================================="
echo ""
echo "This script will:"
echo "1. Build your package"
echo "2. Launch Gazebo with your robot"
echo "3. The robot will move automatically!"
echo ""
echo "Press Enter to continue or Ctrl+C to cancel..."
read

# Build the package
echo "Building hexapod_gz package..."
cd ~/HexapodLeg_modeling_team/2dof
colcon build --packages-select hexapod_gz

if [ $? -ne 0 ]; then
    echo "❌ Build failed!"
    exit 1
fi

echo "✅ Build successful!"
echo ""
echo "Launching Gazebo with your robot..."
echo ""
echo "You should see:"
echo "  - Gazebo window opens"
echo "  - Your robot appears"
echo "  - Robot moves automatically (sine wave motion)"
echo ""
echo "To control manually, open another terminal and run:"
echo "  source install/setup.bash"
echo "  ros2 run hexapod_gz manual_joint_control"
echo ""
echo "Starting in 3 seconds..."
sleep 3

source install/setup.bash
ros2 launch hexapod_gz spawn_robot.launch.py
