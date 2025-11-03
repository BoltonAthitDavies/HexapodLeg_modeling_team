# PlotJuggler Visualization Guide for Hexapod Robot

This guide explains how to visualize your robot's joint positions and velocities using PlotJuggler.

## Quick Start

### Step 1: Launch Your Robot
First terminal:
```bash
cd ~/HexapodLeg_modeling_team/2dof
source install/setup.bash
ros2 launch hexapod_gz spawn_robot.launch.py
```

### Step 2: Launch PlotJuggler
Second terminal:
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

## Setting Up PlotJuggler Manually

Once PlotJuggler opens:

### 1. Load ROS 2 Topics

1. Click **"Streaming"** in the toolbar
2. Select **"ROS2 Topic Subscriber"**
3. Click **"Start"**
4. In the topic list, select these topics:
   - ✅ `/joint_states`
   - ✅ `/joint_position_controller/commands`
5. Click **"OK"**

### 2. Add Plots

#### For Joint Positions:
1. In the left panel, expand `/joint_states`
2. Expand `position`
3. Drag `/joint_states/position[0]` to the plot area (this is **rev1** position)
4. Drag `/joint_states/position[1]` to the same plot (this is **rev_2** position)

#### For Joint Velocities:
1. In the left panel, expand `/joint_states`
2. Expand `velocity`
3. Drag `/joint_states/velocity[0]` to a new plot area (this is **rev1** velocity)
4. Drag `/joint_states/velocity[1]` to the same plot (this is **rev_2** velocity)

#### For Joint Commands:
1. In the left panel, expand `/joint_position_controller/commands`
2. Expand `data`
3. Drag `data[0]` to a new plot area (commanded **rev1** position)
4. Drag `data[1]` to the same plot (commanded **rev_2** position)

### 3. Organize Your View

- **Split plots vertically**: Right-click in plot area → Split Vertical
- **Split plots horizontally**: Right-click in plot area → Split Horizontal
- **Rename plots**: Double-click the plot title
- **Change colors**: Right-click on curve name → Change color
- **Auto-scale**: Right-click in plot → Zoom Options → Auto scale

## Available Data to Plot

### From `/joint_states` topic:
- **Positions** (radians):
  - `position[0]` = rev1 joint position
  - `position[1]` = rev_2 joint position
- **Velocities** (rad/s):
  - `velocity[0]` = rev1 joint velocity
  - `velocity[1]` = rev_2 joint velocity
- **Effort** (Nm):
  - `effort[0]` = rev1 joint effort
  - `effort[1]` = rev_2 joint effort

### From `/joint_position_controller/commands` topic:
- **Commands** (radians):
  - `data[0]` = commanded rev1 position
  - `data[1]` = commanded rev_2 position

## Useful PlotJuggler Features

### Time Window Control
- **Adjust time range**: Use the slider at the bottom
- **Follow mode**: Enable to always show latest data
- **Fixed window**: Disable follow to examine a specific time range

### Cursor and Measurements
- **Add cursor**: Right-click → Cursors → Add cursor
- **Measure difference**: Add two cursors and see the delta

### Export Data
- **File → Export Data** to save plots as CSV or other formats

### Save Layout
- **App → Save Layout** to save your current plot arrangement
- **App → Load Layout** to reload your saved configuration

## Common Scenarios

### 1. Compare Command vs Actual Position
Create two plots:
- Plot 1: `/joint_position_controller/commands/data[0]` (commanded)
- Plot 1: `/joint_states/position[0]` (actual)

This shows how well the controller tracks the commanded position.

### 2. Monitor Joint Velocities
Plot both velocity channels to see the motion profile:
- `/joint_states/velocity[0]` (rev1)
- `/joint_states/velocity[1]` (rev_2)

### 3. Full System Overview
Create a 2x2 grid:
- **Top-left**: Both position commands
- **Top-right**: Both actual positions
- **Bottom-left**: Both velocities
- **Bottom-right**: Both efforts

## Tips

1. **Streaming buffer**: Increase buffer size in settings if you want to see more history
2. **Performance**: If plot is slow, reduce the number of plotted signals
3. **Zoom**: 
   - Mouse wheel to zoom in/out
   - Drag with middle mouse to pan
   - Right-click → Zoom → Zoom Max to see all data
4. **Legend**: Toggle with keyboard shortcut or right-click menu
5. **Grid**: Right-click → Show Grid

## Troubleshooting

### No data appearing:
1. Check robot is running: `ros2 topic list`
2. Check topics are publishing: `ros2 topic hz /joint_states`
3. In PlotJuggler, make sure "Start" is clicked in the streaming dialog

### Topics not showing:
1. Make sure ROS 2 domain matches: `echo $ROS_DOMAIN_ID`
2. Source your workspace: `source install/setup.bash`
3. Restart PlotJuggler

### Plots look choppy:
1. The robot publishes at ~100 Hz, which should be smooth
2. Check system load: `top`
3. Try reducing Gazebo graphics quality

## Example Use Cases

### 1. Verify Sine Wave Motion
With the automatic motion running, you should see:
- **Position plots**: Smooth sine waves at different frequencies
- **Velocity plots**: Smooth cosine waves (derivative of position)

### 2. Test Step Response
Use manual control and send step commands:
```bash
ros2 topic pub /joint_position_controller/commands std_msgs/msg/Float64MultiArray "data: [1.0, 0.0]" --once
```
Watch how quickly the actual position reaches the commanded value.

### 3. Analyze Controller Performance
Compare commanded vs actual positions to see:
- **Tracking error**: Difference between command and actual
- **Response time**: How quickly robot responds to commands
- **Steady-state error**: Final error after settling

## Keyboard Shortcuts

- **Space**: Play/Pause streaming
- **Ctrl + Mouse Wheel**: Zoom in/out
- **Shift + Mouse Wheel**: Pan left/right
- **R**: Reset zoom to show all data
- **G**: Toggle grid

## Advanced: Custom Time Series

You can create custom calculations:
1. Click **"Custom Time Series"** button
2. Create formulas like:
   - Error: `command[0] - position[0]`
   - Total velocity: `sqrt(velocity[0]^2 + velocity[1]^2)`

## Save and Share

1. **Save layout**: App → Save Layout → Choose location
2. **Share layout**: Send the `.xml` file to teammates
3. **Load layout**: App → Load Layout → Select saved file

---

## Quick Reference

**Start Robot:**
```bash
ros2 launch hexapod_gz spawn_robot.launch.py
```

**Start PlotJuggler:**
```bash
ros2 run plotjuggler plotjuggler
```

**Check if data is publishing:**
```bash
ros2 topic echo /joint_states --once
ros2 topic hz /joint_states
```

**List all available topics:**
```bash
ros2 topic list
```

---

Enjoy visualizing your robot's motion! 📊🤖
