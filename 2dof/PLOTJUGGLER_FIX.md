# PlotJuggler Display Fix

## Problem
The commanded positions (`data[0]` and `data[1]`) were showing strange, noisy behavior in PlotJuggler because the PD corrections were being added directly to position commands, creating erratic-looking trajectories.

## Solution
Modified `pd_position_commander.py` to:

1. **Send smooth reference trajectories** directly to the position controller
2. **Added `/joint_reference` topic** for visualization of the desired trajectory
3. **Let the built-in position controller handle servo control** instead of adding PD corrections

## What Changed

### Before:
```python
# Added PD corrections to commands → noisy appearance
cmd_pos_rev1 = ref_pos_rev1 + correction_rev1
```

### After:
```python
# Send smooth reference directly
cmd_pos_rev1 = ref_pos_rev1

# Publish reference separately for visualization
ref_msg.data = [ref_pos_rev1, ref_pos_rev2]
self.reference_pub.publish(ref_msg)
```

## PlotJuggler Topics to Plot

Now you can plot these clean signals:

### **Commanded Positions (Smooth Reference)**
- `/joint_position_controller/commands/data[0]` - rev1 commanded
- `/joint_position_controller/commands/data[1]` - rev_2 commanded

### **Reference Trajectory (Same as commanded, for comparison)**
- `/joint_reference/data[0]` - rev1 reference
- `/joint_reference/data[1]` - rev_2 reference

### **Actual Positions (From joint states)**
- `/joint_states/position[0]` - rev1 actual
- `/joint_states/position[1]` - rev_2 actual

### **Velocities**
- `/joint_states/velocity[0]` - rev1 velocity
- `/joint_states/velocity[1]` - rev_2 velocity

## Expected Behavior

✅ **Commanded positions**: Smooth sine waves
✅ **Reference trajectory**: Identical smooth sine waves  
✅ **Actual positions**: Following commanded with small tracking error
✅ **No more strange jumps or noise**

## How the Control Works Now

```
Reference Trajectory (smooth sine) 
    ↓
Position Commands (/joint_position_controller/commands)
    ↓
Built-in Position Controller (handles PID servo control)
    ↓
Joint Actuators
    ↓
Actual Joint Positions (/joint_states)
```

The underlying position controller in `ros2_control` already has built-in PID control running at 200 Hz, so we just need to send it smooth position references!

## Test It

```bash
source install/setup.bash
ros2 launch hexapod_gz spawn_robot_pd.launch.py
```

Then open PlotJuggler and you'll see smooth commanded positions! 📈✨
