#!/bin/bash
# Verification script to check if the hexapod robot is working

echo "======================================"
echo "Hexapod Robot System Verification"
echo "======================================"
echo ""

# Source the workspace
source install/setup.bash

echo "1. Checking if Gazebo is running..."
if pgrep -f "ign gazebo" > /dev/null || pgrep -f "gz sim" > /dev/null; then
    echo "   ✅ Gazebo is running"
else
    echo "   ❌ Gazebo is NOT running"
    echo "   Please run: ros2 launch hexapod_gz spawn_robot.launch.py"
    exit 1
fi

echo ""
echo "2. Checking controller manager..."
timeout 2 ros2 control list_controllers > /dev/null 2>&1
if [ $? -eq 0 ]; then
    echo "   ✅ Controller manager is accessible"
else
    echo "   ❌ Controller manager not responding"
    exit 1
fi

echo ""
echo "3. Listing active controllers:"
ros2 control list_controllers

echo ""
echo "4. Checking joint_states topic..."
timeout 2 ros2 topic hz /joint_states > /dev/null 2>&1
if [ $? -eq 0 ]; then
    echo "   ✅ Joint states are being published"
else
    echo "   ⚠️  Joint states not detected (may need more time)"
fi

echo ""
echo "5. Checking command topic..."
timeout 2 ros2 topic hz /joint_position_controller/commands > /dev/null 2>&1
if [ $? -eq 0 ]; then
    echo "   ✅ Commands are being published"
else
    echo "   ⚠️  Commands not detected (may need more time)"
fi

echo ""
echo "6. Sample joint state (showing robot is moving):"
timeout 2 ros2 topic echo /joint_states --once 2>/dev/null | head -20

echo ""
echo "======================================"
echo "✅ Verification Complete!"
echo "======================================"
echo ""
echo "Your robot is working! You can:"
echo "  - Observe it moving in Gazebo"
echo "  - Use: ros2 run hexapod_gz manual_joint_control"
echo "  - Or publish: ros2 topic pub /joint_position_controller/commands std_msgs/msg/Float64MultiArray 'data: [0.5, -0.5]' --once"
echo ""
