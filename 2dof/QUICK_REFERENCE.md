# Quick Reference: Torque-Based PD Control

## What Changed? ✨

Your system now implements **TORQUE control** instead of position control, matching your control diagram exactly!

### Control Diagram Match:
```
     Set angle ──┐
                 ├─(error)─> Kp ──┐
  Current angle ─┘                ├─(+)─┐
                                  │     │
      Set speed ──┐               │     ├─(+)──> Desired Torque ──> Joint
                  ├─(error)─> Kd ─┘     │
   Current speed ─┘                     │
                                        │
            Set torque (t_ref) ─────────┘
```

## Files Modified:

1. ✅ **ros2_controllers.yaml** - Changed to `joint_effort_controller`
2. ✅ **hexapod_modelling_team.xacro** - Changed command interface to `effort`
3. ✅ **pd_position_commander.py** - Now outputs **torque** directly
4. ✅ **spawn_robot_pd.launch.py** - Loads effort controller

## Key Code Change:

**Before (WRONG - Position adjustment):**
```python
correction = pd.compute_torque(...)
cmd_position = ref_position + correction * dt * 0.5  # ❌ Mixing paradigms
```

**After (CORRECT - Direct torque):**
```python
torque = pd.compute_torque(...)
cmd_torque = torque  # ✅ Direct torque as per diagram
```

## Control Formula:

```
Torque = Kp × (set_angle - current_angle) + Kd × (set_speed - current_speed) + t_ref
```

Where:
- **Kp**: Proportional gain (position error → torque)
- **Kd**: Derivative gain (velocity error → torque)
- **t_ref**: Feedforward torque (currently 0)

## Quick Test:

```bash
source install/setup.bash
ros2 launch hexapod_gz spawn_robot_pd.launch.py
```

## PlotJuggler Topics:

**Compare these:**
- `/joint_reference/data[0]` vs `/joint_states/position[0]` - See tracking
- `/joint_effort_controller/commands/data[0]` - Commanded torque
- `/joint_states/effort[0]` - Actual applied torque

## Tuning:

```bash
# More aggressive
ros2 launch hexapod_gz spawn_robot_pd.launch.py kp_rev1:=10.0 kd_rev1:=1.0

# More damped
ros2 launch hexapod_gz spawn_robot_pd.launch.py kp_rev1:=3.0 kd_rev1:=1.5
```

## Default Gains:

- **rev1**: Kp=5.0, Kd=0.5
- **rev2**: Kp=4.0, Kd=0.4

---

**Your control diagram is now correctly implemented!** 🎯✅
