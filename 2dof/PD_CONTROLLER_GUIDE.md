# PD Controller Integration Guide

## Overview

Your PD_Controller.py has been successfully integrated into the hexapod_gz project! You now have multiple ways to use PD control with your robot.

---

## 📁 Files Created

### 1. **PD_Controller.py** (Your original file)
- Location: `hexapod_gz/PD_Controller.py`
- Class: `PDController(Kp, Kd)`
- Method: `compute_torque(set_angle, current_angle, set_speed, current_speed, t_ref)`

### 2. **pd_position_commander.py** (NEW!)
- Location: `hexapod_gz/pd_position_commander.py`
- ROS 2 node that uses PD control for position tracking
- Works with existing position controller
- Publishes to: `/joint_position_controller/commands`

### 3. **pd_torque_controller_node.py** (NEW!)
- Location: `hexapod_gz/pd_torque_controller_node.py`
- ROS 2 node for direct torque control
- Requires effort/torque controller configuration
- Publishes to: `/effort_controller/commands`

### 4. **spawn_robot_pd.launch.py** (NEW!)
- Location: `launch/spawn_robot_pd.launch.py`
- Launch file with PD controller enabled
- Configurable Kp and Kd gains via launch arguments

---

## 🚀 How to Use

### Option 1: Position Control with PD (Recommended)

This uses your PD_Controller to compute better position commands:

```bash
cd ~/HexapodLeg_modeling_team/2dof
colcon build --packages-select hexapod_gz
source install/setup.bash

# Launch with default PD gains
ros2 launch hexapod_gz spawn_robot_pd.launch.py

# Launch with custom PD gains
ros2 launch hexapod_gz spawn_robot_pd.launch.py kp_rev1:=10.0 kd_rev1:=1.0 kp_rev2:=8.0 kd_rev2:=0.8
```

### Option 2: Run PD Controller Separately

```bash
# Terminal 1: Launch robot (standard)
ros2 launch hexapod_gz spawn_robot.launch.py

# Terminal 2: Run PD position commander
ros2 run hexapod_gz pd_position_commander --ros-param kp_rev1:=5.0 --ros-param kd_rev1:=0.5
```

### Option 3: Use Original Simple Controller

```bash
# Use the original sine wave controller (no PD)
ros2 launch hexapod_gz spawn_robot.launch.py
```

---

## 🎛️ PD Gain Tuning

### Default Gains:
```python
# rev1 (base joint)
Kp = 5.0
Kd = 0.5

# rev_2 (second joint)
Kp = 4.0
Kd = 0.4
```

### Tuning Guidelines:

#### Increase Kp when:
- ✅ Response is too slow
- ✅ Steady-state error is too large
- ✅ Tracking is not tight enough

#### Decrease Kp when:
- ⚠️ System oscillates
- ⚠️ Response overshoots too much
- ⚠️ System becomes unstable

#### Increase Kd when:
- ✅ Too much overshoot
- ✅ Oscillations present
- ✅ Need more damping

#### Decrease Kd when:
- ⚠️ Response is too sluggish
- ⚠️ Noise amplification is visible
- ⚠️ System feels overdamped

### Quick Tuning Steps:

1. **Start with Kp only** (Kd = 0):
   ```bash
   ros2 launch hexapod_gz spawn_robot_pd.launch.py kp_rev1:=3.0 kd_rev1:=0.0
   ```

2. **Increase Kp until oscillation starts**

3. **Back off Kp by 30-50%**

4. **Add Kd to reduce oscillation**:
   ```bash
   ros2 launch hexapod_gz spawn_robot_pd.launch.py kp_rev1:=5.0 kd_rev1:=0.5
   ```

5. **Fine-tune both gains** while watching PlotJuggler

---

## 📊 Visualize PD Performance in PlotJuggler

### Terminal 1: Launch robot with PD
```bash
ros2 launch hexapod_gz spawn_robot_pd.launch.py
```

### Terminal 2: Launch PlotJuggler
```bash
ros2 run plotjuggler plotjuggler
```

### In PlotJuggler:
1. **Streaming** → **ROS2 Topic Subscriber** → **Start**
2. Select topics:
   - ✅ `/joint_states`
   - ✅ `/joint_position_controller/commands`
3. **Plot these signals**:
   - Reference position: `/joint_position_controller/commands/data[0]`
   - Actual position: `/joint_states/position[0]`
   - Velocity: `/joint_states/velocity[0]`

### What to Look For:
- **Good tracking**: Actual closely follows reference
- **No overshoot**: Smooth approach to setpoint
- **No oscillation**: Clean curves without ripples
- **Fast response**: Quick convergence to target

---

## 🧪 Compare Controllers

### Test 1: Simple vs PD Controller

**Terminal 1 - Simple:**
```bash
ros2 launch hexapod_gz spawn_robot.launch.py
# Record data in PlotJuggler for 10 seconds
```

**Terminal 2 - PD Controller:**
```bash
ros2 launch hexapod_gz spawn_robot_pd.launch.py
# Record data in PlotJuggler for 10 seconds
```

**Compare**: PD should show better tracking and smoother response!

### Test 2: Different PD Gains

```bash
# Test 1: Low gains (underdamped)
ros2 launch hexapod_gz spawn_robot_pd.launch.py kp_rev1:=2.0 kd_rev1:=0.1

# Test 2: Medium gains (optimal)
ros2 launch hexapod_gz spawn_robot_pd.launch.py kp_rev1:=5.0 kd_rev1:=0.5

# Test 3: High gains (maybe overdamped)
ros2 launch hexapod_gz spawn_robot_pd.launch.py kp_rev1:=10.0 kd_rev1:=2.0
```

---

## 🔧 PD Controller Implementation Details

### How it Works:

```python
# Your PD_Controller computes:
torque = Kp * (desired_angle - actual_angle) + Kd * (desired_velocity - actual_velocity)

# In pd_position_commander.py:
# 1. Get desired trajectory (sine wave)
ref_position = 0.5 * sin(t)
ref_velocity = 0.5 * cos(t)

# 2. Get current state from /joint_states
current_position = msg.position[0]
current_velocity = msg.velocity[0]

# 3. Compute correction using PD
correction = pd_controller.compute_torque(
    ref_position, current_position,
    ref_velocity, current_velocity
)

# 4. Send corrected command
command = ref_position + correction * scale_factor
```

### Control Loop:
```
Reference Trajectory → PD Controller → Position Command → ros2_control → Gazebo
                           ↑                                                |
                           |                                                |
                           └────────── Feedback (joint_states) ←───────────┘
```

---

## 📈 Performance Expectations

### Without PD (Simple Controller):
- Open-loop sine wave
- No error correction
- Relies entirely on controller gains
- May have tracking error

### With PD Controller:
- Closed-loop control
- Active error correction
- Better tracking accuracy
- Adjustable response characteristics
- Reduced steady-state error

---

## 🎯 Practical Examples

### Example 1: Aggressive Tracking
```bash
# Fast response, tight tracking
ros2 launch hexapod_gz spawn_robot_pd.launch.py \
  kp_rev1:=15.0 kd_rev1:=1.5 \
  kp_rev2:=12.0 kd_rev2:=1.2
```

### Example 2: Smooth, Damped Motion
```bash
# Gentle response, heavily damped
ros2 launch hexapod_gz spawn_robot_pd.launch.py \
  kp_rev1:=3.0 kd_rev1:=1.0 \
  kp_rev2:=2.5 kd_rev2:=0.8
```

### Example 3: Balanced Performance
```bash
# Good all-around performance (default)
ros2 launch hexapod_gz spawn_robot_pd.launch.py \
  kp_rev1:=5.0 kd_rev1:=0.5 \
  kp_rev2:=4.0 kd_rev2:=0.4
```

---

## 🔍 Debugging

### Check if PD controller is running:
```bash
ros2 node list | grep pd
# Should show: /pd_position_commander
```

### Check published topics:
```bash
ros2 topic hz /joint_position_controller/commands
# Should show ~100 Hz
```

### Check joint states:
```bash
ros2 topic echo /joint_states --once
```

### Monitor gains:
```bash
ros2 param list /pd_position_commander
ros2 param get /pd_position_commander kp_rev1
```

---

## 🏆 Benefits of PD Control

✅ **Better Tracking**: Follows desired trajectory more accurately  
✅ **Reduced Error**: Active correction of position errors  
✅ **Tunable Response**: Adjust Kp/Kd for your needs  
✅ **Damping Control**: Kd prevents oscillations  
✅ **Velocity Feedback**: Uses both position and velocity  
✅ **Predictable Behavior**: Well-understood control theory  

---

## 📚 Theory Refresher

### PD Control Equation:
```
u(t) = Kp * e(t) + Kd * ė(t)

where:
  u(t) = control output (torque or position correction)
  e(t) = position error = desired - actual
  ė(t) = velocity error = desired_velocity - actual_velocity
  Kp = proportional gain
  Kd = derivative gain
```

### Physical Interpretation:
- **Kp term**: Like a spring - pulls toward target
- **Kd term**: Like a damper - resists motion, prevents overshoot

---

## 🎓 Next Steps

1. **Try the PD controller** and compare with the simple controller
2. **Tune the gains** using PlotJuggler visualization
3. **Record data** and analyze performance
4. **Experiment** with different gain combinations
5. **Extend** to create your own custom trajectories

---

**Your PD Controller is now fully integrated and ready to use! 🎉**

For questions or issues, check the logs and use PlotJuggler to visualize what's happening!
