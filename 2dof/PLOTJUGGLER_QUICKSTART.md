# 📊 PlotJuggler Setup Complete!

## Overview

You can now visualize your hexapod robot's joint positions and velocities in real-time using PlotJuggler!

---

## 🚀 Quick Start Options

### Option 1: Automatic Launch (EASIEST)
Launch robot AND PlotJuggler together:
```bash
cd ~/HexapodLeg_modeling_team/2dof
source install/setup.bash
ros2 launch hexapod_gz spawn_robot_with_viz.launch.py plotjuggler:=true
```

Or use the script:
```bash
./demo_with_plotjuggler.sh
```

### Option 2: Separate Terminals (MORE CONTROL)

**Terminal 1 - Robot:**
```bash
cd ~/HexapodLeg_modeling_team/2dof
source install/setup.bash
ros2 launch hexapod_gz spawn_robot.launch.py
```

**Terminal 2 - PlotJuggler:**
```bash
cd ~/HexapodLeg_modeling_team/2dof
source install/setup.bash
./src/hexapod_gz/scripts/plot_joints.sh
```

Or directly:
```bash
source install/setup.bash
ros2 run plotjuggler plotjuggler
```

---

## 📈 Using PlotJuggler

### Step-by-Step Setup

1. **Open Data Streaming:**
   - Click `Streaming` in the toolbar
   - Select `ROS2 Topic Subscriber`
   - Click `Start`

2. **Select Topics:**
   - ✅ Check `/joint_states`
   - ✅ Check `/joint_position_controller/commands`
   - Click `OK`

3. **Create Plots:**
   
   **For Positions:**
   - Expand `/joint_states` → `position` in left panel
   - Drag `position[0]` to plot area → This is **rev1**
   - Drag `position[1]` to same plot → This is **rev_2**
   
   **For Velocities:**
   - Expand `/joint_states` → `velocity`
   - Drag `velocity[0]` to new plot area → This is **rev1 velocity**
   - Drag `velocity[1]` to same plot → This is **rev_2 velocity**
   
   **For Commands:**
   - Expand `/joint_position_controller/commands` → `data`
   - Drag `data[0]` to new plot → Commanded **rev1**
   - Drag `data[1]` to same plot → Commanded **rev_2**

### What You'll See

With the automatic motion running, you should see:
- **Position plots**: Smooth sine waves oscillating between ±0.5 radians
- **Velocity plots**: Smooth curves (derivatives of positions)
- **Commands vs Actual**: Commands and actual positions should match closely

---

## 📊 Available Data

### Joint States (`/joint_states`)
- `position[0]` - rev1 joint position (radians)
- `position[1]` - rev_2 joint position (radians)
- `velocity[0]` - rev1 joint velocity (rad/s)
- `velocity[1]` - rev_2 joint velocity (rad/s)
- `effort[0]` - rev1 joint effort/torque (Nm)
- `effort[1]` - rev_2 joint effort/torque (Nm)

### Commands (`/joint_position_controller/commands`)
- `data[0]` - Commanded rev1 position (radians)
- `data[1]` - Commanded rev_2 position (radians)

---

## 🎨 PlotJuggler Tips

### Layout Management
- **Split plots**: Right-click → Split Vertical/Horizontal
- **Rename plots**: Double-click title
- **Change colors**: Right-click curve → Change color
- **Auto-scale**: Right-click plot → Zoom → Auto scale

### Time Control
- **Follow mode**: Enable to always show latest data
- **Time window**: Adjust slider at bottom
- **Zoom**: Mouse wheel or drag with middle button

### Save Your Work
- **Save layout**: App → Save Layout
- **Load layout**: App → Load Layout
- Pre-configured layout at: `config/plotjuggler_layout.xml`

---

## 🔍 Analysis Examples

### 1. Controller Performance
Compare commanded vs actual:
```
Plot commanded position (data[0])
Plot actual position (position[0])
```
They should track closely - any difference is tracking error.

### 2. Motion Profile
Watch the smooth sine wave:
```
Plot both positions: position[0] and position[1]
```
You'll see coordinated motion at different frequencies.

### 3. Velocity Analysis
```
Plot velocity[0] and velocity[1]
```
Should be smooth curves, derivatives of the position sine waves.

---

## 🛠️ Troubleshooting

### No data appearing?
```bash
# Check if topics are publishing
ros2 topic list
ros2 topic hz /joint_states

# Check if robot is running
ros2 control list_controllers
```

### PlotJuggler not starting?
```bash
# Check installation
dpkg -l | grep plotjuggler

# If not installed:
sudo apt install ros-humble-plotjuggler-ros
```

### Topics not showing in PlotJuggler?
1. Make sure you clicked "Start" in streaming dialog
2. Source your workspace: `source install/setup.bash`
3. Check ROS_DOMAIN_ID matches between terminals

---

## 📁 Files Created

- `launch/spawn_robot_with_viz.launch.py` - Launch with PlotJuggler
- `scripts/plot_joints.sh` - PlotJuggler launcher
- `config/plotjuggler_layout.xml` - Pre-configured layout
- `PLOTJUGGLER_GUIDE.md` - Detailed documentation
- `demo_with_plotjuggler.sh` - One-command demo

---

## 🎯 Common Use Cases

### Test Manual Commands
```bash
# Terminal 1: Robot + PlotJuggler
ros2 launch hexapod_gz spawn_robot_with_viz.launch.py plotjuggler:=true

# Terminal 2: Send commands
ros2 topic pub /joint_position_controller/commands std_msgs/msg/Float64MultiArray "data: [1.0, -0.5]" --once
```

Watch the plots respond to your commands!

### Record Data
In PlotJuggler:
1. Let it run for a while
2. File → Export to File
3. Save as CSV for analysis in Excel, Python, MATLAB, etc.

### Compare Different Motions
1. Record baseline motion
2. Change parameters in `joint_position_commander.py`
3. Rebuild and run again
4. Compare plots

---

## 🎬 Quick Demo

For the fastest demo experience:
```bash
cd ~/HexapodLeg_modeling_team/2dof
./demo_with_plotjuggler.sh
```

This launches everything and provides step-by-step instructions!

---

## 📚 More Information

See `PLOTJUGGLER_GUIDE.md` for:
- Detailed PlotJuggler features
- Keyboard shortcuts
- Advanced plotting techniques
- Custom time series calculations
- Export and sharing options

---

## ✅ Summary

You now have:
- ✅ Robot running in Gazebo
- ✅ PlotJuggler ready to visualize
- ✅ Real-time position and velocity plots
- ✅ Comparison of commanded vs actual
- ✅ Easy launch scripts

**Enjoy visualizing your robot! 📊🤖**
