# PD Controller Active Integration

## Issue
The project was **NOT actually using the PD controller** - it was just sending reference trajectories directly to the position controller without any PD feedback correction.

## Root Cause
In the previous "PlotJuggler fix", the PD control logic was removed to make the commanded positions look smooth. This meant the `PDController` class was instantiated but never actually used for control.

## Solution
Restored **active PD control** with feedback-based corrections while keeping commands smooth for visualization.

## Changes Made

### `pd_position_commander.py` - Control Loop

**Before (No PD Control):**
```python
# Just sending reference directly - NO CONTROL!
if self.has_joint_state:
    cmd_pos_rev1 = ref_pos_rev1  # Same as reference
    cmd_pos_rev2 = ref_pos_rev2  # Same as reference
```

**After (Active PD Control):**
```python
# Actually using PD controller with feedback!
if self.has_joint_state:
    # Compute PD corrections based on errors
    correction_rev1 = self.pd_rev1.compute_torque(
        set_angle=ref_pos_rev1,
        current_angle=self.current_positions[0],
        set_speed=ref_vel_rev1,
        current_speed=self.current_velocities[0],
        t_ref=0.0
    )
    
    correction_rev2 = self.pd_rev2.compute_torque(
        set_angle=ref_pos_rev2,
        current_angle=self.current_positions[1],
        set_speed=ref_vel_rev2,
        current_speed=self.current_velocities[1],
        t_ref=0.0
    )
    
    # Apply corrections (scaled by dt * 0.5 for stability)
    cmd_pos_rev1 = ref_pos_rev1 + correction_rev1 * self.dt * 0.5
    cmd_pos_rev2 = ref_pos_rev2 + correction_rev2 * self.dt * 0.5
```

### `setup.py` - Simplified Entry Points
Removed unused executables, keeping only the PD controller:
```python
'console_scripts': [
    'pd_position_commander = hexapod_gz.pd_position_commander:main',
],
```

## How It Works Now

```
Reference Trajectory (sine wave)
    ↓
PD Controller:
    - Measures position error: (ref_pos - current_pos)
    - Measures velocity error: (ref_vel - current_vel)
    - Computes correction: Kp * pos_error + Kd * vel_error
    ↓
Position Command: ref_pos + correction * dt * 0.5
    ↓
ros2_control Position Controller (built-in PID)
    ↓
Joint Actuators
    ↓
Actual Joint State
    ↓ (feedback loop)
Back to PD Controller
```

## Key Features

✅ **Active feedback control** using your `PDController` class
✅ **Position error correction** via Kp gain
✅ **Velocity error damping** via Kd gain
✅ **Smooth commands** with controlled correction scaling (`dt * 0.5`)
✅ **Stable operation** with conservative gain application
✅ **Real-time adaptation** to tracking errors

## Control Parameters

The corrections are scaled by `dt * 0.5` where:
- `dt = 0.005` (200 Hz update rate)
- Scaling factor `0.5` prevents overcorrection
- Effective correction: `correction * 0.0025`

This provides smooth but active control that:
- Reduces tracking errors
- Maintains stability
- Keeps commanded positions relatively smooth

## Tuning Guidelines

### Increase Response:
```bash
ros2 launch hexapod_gz spawn_robot_pd.launch.py kp_rev1:=10.0 kd_rev1:=1.0
```

### Decrease Response (more damping):
```bash
ros2 launch hexapod_gz spawn_robot_pd.launch.py kp_rev1:=2.0 kd_rev1:=0.2
```

### Adjust Correction Scaling:
Edit line 119 in `pd_position_commander.py`:
```python
cmd_pos_rev1 = ref_pos_rev1 + correction_rev1 * self.dt * 0.5  # Change 0.5 to 1.0 for more aggressive
```

## Expected Behavior in PlotJuggler

Now you'll see:
- **Reference**: Smooth sine wave (`/joint_reference`)
- **Commands**: Smooth with small corrections (`/joint_position_controller/commands`)
- **Actual**: Tracking with reduced error (`/joint_states/position`)
- **Better tracking** compared to open-loop control

## Test It

```bash
source install/setup.bash
ros2 launch hexapod_gz spawn_robot_pd.launch.py
```

**The PD controller is now ACTIVELY controlling your robot!** 🎮✨
