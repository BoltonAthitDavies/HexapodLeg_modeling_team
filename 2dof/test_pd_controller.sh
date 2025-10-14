#!/bin/bash
# Quick test of PD Controller integration

echo "=========================================="
echo "PD Controller Quick Test"
echo "=========================================="
echo ""
echo "This will launch your robot with PD control enabled!"
echo ""
echo "PD Controller features:"
echo "  ✓ Better trajectory tracking"
echo "  ✓ Active error correction"
echo "  ✓ Tunable response (Kp, Kd)"
echo "  ✓ Velocity feedback"
echo ""
echo "Default gains:"
echo "  rev1: Kp=5.0, Kd=0.5"
echo "  rev2: Kp=4.0, Kd=0.4"
echo ""
echo "Press Enter to launch..."
read

cd ~/HexapodLeg_modeling_team/2dof
source install/setup.bash

echo ""
echo "Launching robot with PD controller..."
echo ""
echo "To visualize in PlotJuggler:"
echo "  1. Open new terminal"
echo "  2. Run: ros2 run plotjuggler plotjuggler"
echo "  3. Compare commanded vs actual positions"
echo ""
echo "To test different gains:"
echo "  Ctrl+C to stop, then run:"
echo "  ros2 launch hexapod_gz spawn_robot_pd.launch.py kp_rev1:=10.0 kd_rev1:=1.0"
echo ""

ros2 launch hexapod_gz spawn_robot_pd.launch.py
