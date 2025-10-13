# Frequency Tuning Guide for Hexapod Robot

## Overview

The response speed of your robot is controlled by several frequency settings. I've increased them for faster, smoother response!

---

## 🚀 Updated Frequencies

### Before (Slow):
- **Command Publisher**: 20 Hz (0.05s interval)
- **Controller Update Rate**: 100 Hz

### After (Faster):
- **Command Publisher**: 100 Hz (0.01s interval) ⬆️ **5x faster**
- **Controller Update Rate**: 200 Hz ⬆️ **2x faster**

---

## What Each Setting Controls

### 1. Command Publisher Frequency
**File**: `hexapod_gz/joint_position_commander.py`
**Line**: `self.timer = self.create_timer(self.dt, self.on_timer)`

- **What it does**: How often new position commands are sent to the controller
- **Current**: 100 Hz (every 0.01 seconds)
- **Impact**: Smoother trajectory tracking, faster updates in PlotJuggler

```python
self.dt = 0.01  # Time step = 1/frequency
self.timer = self.create_timer(self.dt, self.on_timer)  # 100 Hz
```

### 2. Controller Update Rate
**File**: `config/ros2_controllers.yaml`
**Line**: `update_rate: 200  # Hz`

- **What it does**: How often the controller processes commands and updates joint states
- **Current**: 200 Hz
- **Impact**: Faster response, better tracking, smoother motion

```yaml
controller_manager:
  ros__parameters:
    update_rate: 200  # Hz
```

### 3. Gazebo Physics Rate
**File**: `worlds/hexapod.sdf`
**Line**: `<max_step_size>0.001</max_step_size>`

- **What it does**: Simulation timestep (currently 1ms = 1000 Hz)
- **Current**: 1000 Hz (very fast)
- **Note**: Already optimized, no need to change

---

## Frequency Recommendations

### For Different Use Cases:

#### Standard Operation (Current - Recommended):
```python
# joint_position_commander.py
self.dt = 0.01  # 100 Hz

# ros2_controllers.yaml
update_rate: 200  # Hz
```
✅ Good balance of performance and system load
✅ Smooth motion
✅ Fast PlotJuggler updates

#### Ultra-Fast Response (Maximum Performance):
```python
# joint_position_commander.py
self.dt = 0.005  # 200 Hz

# ros2_controllers.yaml
update_rate: 500  # Hz
```
⚡ Fastest response
⚠️ Higher CPU usage
⚠️ May stress your system

#### Low-Power Mode (If system is slow):
```python
# joint_position_commander.py
self.dt = 0.02  # 50 Hz

# ros2_controllers.yaml
update_rate: 100  # Hz
```
💻 Lower CPU usage
⚠️ Slower, less smooth motion

---

## How to Change Frequencies

### To Change Command Rate:

1. Edit `hexapod_gz/joint_position_commander.py`:
```python
self.dt = 1.0 / DESIRED_HZ  # e.g., 1.0/200 = 0.005 for 200Hz
self.timer = self.create_timer(self.dt, self.on_timer)
```

2. Also update the time increment to match:
```python
self.t += self.dt  # Keep time synchronized
```

### To Change Controller Rate:

1. Edit `config/ros2_controllers.yaml`:
```yaml
controller_manager:
  ros__parameters:
    update_rate: DESIRED_HZ  # e.g., 500
```

### After Changes:

```bash
# Rebuild
colcon build --packages-select hexapod_gz

# Source and launch
source install/setup.bash
ros2 launch hexapod_gz spawn_robot.launch.py
```

---

## Relationship Between Frequencies

### Optimal Hierarchy:
```
Gazebo Physics (1000 Hz)
    ↓
Controller Update (200 Hz)  ← Should be ≤ Physics rate
    ↓
Command Publisher (100 Hz)  ← Should be ≤ Controller rate
    ↓
PlotJuggler Display (~60 Hz)
```

### Key Rules:
1. **Controller rate ≤ Physics rate** (avoid warning messages)
2. **Command rate ≤ Controller rate** (for best tracking)
3. **All rates should be divisors of physics rate** (for synchronization)

---

## PlotJuggler Performance

With the new settings, PlotJuggler will show:
- ✅ **Smoother curves** (more data points per second)
- ✅ **Faster updates** (less delay in visualization)
- ✅ **Better tracking** (commands vs actual closely match)

### To verify in PlotJuggler:
```bash
# Check topic frequencies
ros2 topic hz /joint_states
ros2 topic hz /joint_position_controller/commands
```

Expected output:
```
/joint_states: ~200 Hz
/joint_position_controller/commands: ~100 Hz
```

---

## Troubleshooting

### If motion is jerky:
- Increase command publisher rate (decrease `self.dt`)
- Check system CPU usage

### If system is slow/lagging:
- Decrease controller update rate
- Decrease command publisher rate
- Check Gazebo performance

### If you see warning: "Desired controller update period is slower than simulation":
- This is OK! It just means controller is slower than physics
- If bothers you, increase controller rate or decrease physics rate

### To check current performance:
```bash
# Monitor topic rates
ros2 topic hz /joint_states

# Check controller info
ros2 control list_controllers

# Monitor system load
htop  # Look at CPU usage
```

---

## Performance Comparison

| Setting | Command Hz | Controller Hz | Response | CPU Load |
|---------|------------|---------------|----------|----------|
| **Original** | 20 | 100 | Slow | Low |
| **Current** | 100 | 200 | Fast | Medium |
| **Ultra** | 200 | 500 | Very Fast | High |

---

## Summary

Your robot is now configured for **faster response**:

✅ Commands sent **5x more frequently** (100 Hz vs 20 Hz)
✅ Controller updates **2x faster** (200 Hz vs 100 Hz)
✅ Smoother motion in Gazebo
✅ Better visualization in PlotJuggler
✅ Faster tracking of commanded positions

**The robot will now respond much more quickly to commands and show smoother motion in both Gazebo and PlotJuggler!** 🚀📈
