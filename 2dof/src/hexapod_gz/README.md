# hexapod_gz

Spawn the 2-DOF RR hexapod model in Gazebo Sim (Ignition Gazebo) and control its joints using ros2_control position controllers.

## ✅ System Status - WORKING!

**The robot IS working and controllable!** The system successfully:
- ✅ Spawns robot in Gazebo
- ✅ Loads ros2_control with gz_ros2_control plugin  
- ✅ Activates joint_state_broadcaster and joint_position_controller
- ✅ Both joints (rev1 and rev_2) respond to position commands
- ✅ Robot moves in Gazebo - **YOU CAN SEE IT MOVE!**

## Quick Start

### 1. Build the workspace
```bash
cd ~/HexapodLeg_modeling_team/2dof
colcon build --packages-select hexapod_gz
source install/setup.bash
```

### 2. Launch robot in Gazebo (with automatic motion)
```bash
ros2 launch hexapod_gz spawn_robot.launch.py
```

This automatically:
- Starts Gazebo with GUI
- Spawns the robot
- Loads controllers
- Starts sine wave motion on both joints

### 3. Verify it's working

Open a new terminal and check:
```bash
source install/setup.bash

# Watch joint states change (proves robot is moving)
ros2 topic echo /joint_states

# See commanded positions
ros2 topic echo /joint_position_controller/commands
```

## Manual Control Options

### Option 1: Interactive Manual Control
```bash
ros2 run hexapod_gz manual_joint_control
# Then enter: 0.5 -0.5 (or any values you want)
```

### Option 2: Command Line
```bash
# Send specific positions [rev1, rev_2]
ros2 topic pub /joint_position_controller/commands std_msgs/msg/Float64MultiArray "data: [0.5, -0.5]" --once

# Move to different position
ros2 topic pub /joint_position_controller/commands std_msgs/msg/Float64MultiArray "data: [1.0, 0.3]" --once

# Reset to zero
ros2 topic pub /joint_position_controller/commands std_msgs/msg/Float64MultiArray "data: [0.0, 0.0]" --once
```

## Robot Configuration

- **Robot Type**: 2-DOF RR manipulator
- **Joints**: 
  - `rev1`: Base revolute joint (vertical axis)
  - `rev_2`: Second revolute joint
- **Control**: Position control via ros2_control
- **Controllers**: 
  - `joint_state_broadcaster` (active)
  - `joint_position_controller` (active)
- **Update Rate**: 100 Hz
- **Physics Rate**: 1000 Hz

## Success Indicators

When launched successfully, you'll see:
```
[INFO] [gz_ros2_control]: Loading joint: rev1
[INFO] [gz_ros2_control]: Loading joint: rev_2
Successfully loaded controller joint_state_broadcaster into state active
Successfully loaded controller joint_position_controller into state active
[INFO] [joint_position_commander]: Publishing joint positions...
```

## Troubleshooting

**Note**: You may see mesh file warnings - these are cosmetic only and don't affect functionality:
```
[Err] [SystemPaths.cc:378] Unable to find file with URI [model://hexapod_gz/meshes/...]
```
The robot still works perfectly - collision and physics are fine!

### Check if robot is moving:
```bash
ros2 topic echo /joint_states
```
You should see position values changing for rev1 and rev_2.

### Check controllers:
```bash
ros2 control list_controllers
```
Both should show "active".

## Files

- `launch/spawn_robot.launch.py` - Main launch file
- `config/ros2_controllers.yaml` - Controller configuration  
- `urdf/hexapod_modelling_team.xacro` - Robot URDF with ros2_control
- `hexapod_gz/joint_position_commander.py` - Automatic sine motion
- `hexapod_gz/manual_joint_control.py` - Interactive control

## Next Steps

1. Observe the robot moving in Gazebo
2. Try manual control to command specific positions
3. Modify the motion pattern in `joint_position_commander.py`
4. Extend to full hexapod with multiple legs
