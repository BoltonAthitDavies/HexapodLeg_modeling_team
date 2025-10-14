# Step Function Controller Guide

## Overview

The **PD Step Commander** (`pd_step_commander.py`) is an alternative to the sine wave trajectory controller. It uses **step function** inputs to test the step response of your PD controller.

## Key Differences from Sine Wave Controller

| Feature | Sine Wave Controller | Step Controller |
|---------|---------------------|-----------------|
| Trajectory | Continuous smooth motion | Discrete position steps |
| Reference Velocity | Non-zero (cosine) | Zero (hold position) |
| Use Case | Tracking performance | Step response, settling time |
| Motion Type | Dynamic | Point-to-point |

## Step Function Trajectory

The controller cycles through predefined position steps:

### rev1 Steps (within [0, 6.28] range):
```python
[2.0, 4.5, 1.5, 5.0, 3.14]  # radians
```
- Step 1: 2.0 rad (115°)
- Step 2: 4.5 rad (258°)
- Step 3: 1.5 rad (86°)
- Step 4: 5.0 rad (286°)
- Step 5: 3.14 rad (180°)

### rev_2 Steps (within [-1.47, 3.0] range):
```python
[-0.5, 1.5, 0.0, 2.0, 0.765]  # radians
```
- Step 1: -0.5 rad (-29°)
- Step 2: 1.5 rad (86°)
- Step 3: 0.0 rad (0°)
- Step 4: 2.0 rad (115°)
- Step 5: 0.765 rad (44°)

## Step Duration

Default: **5 seconds** per step
- Configurable via launch parameter `step_duration`
- Allows sufficient time to observe:
  - Rise time
  - Overshoot
  - Settling time
  - Steady-state error

## Launch Command

### Basic Launch:
```bash
source install/setup.bash
ros2 launch hexapod_gz spawn_robot_step.launch.py
```

### With Custom Step Duration:
```bash
ros2 launch hexapod_gz spawn_robot_step.launch.py step_duration:=3.0
```

### With Custom PD Gains:
```bash
ros2 launch hexapod_gz spawn_robot_step.launch.py \
    kp_rev1:=10.0 kd_rev1:=1.0 \
    kp_rev2:=8.0 kd_rev2:=0.8 \
    step_duration:=4.0
```

## Control Behavior

At each step:
1. **Reference position** changes instantly (step input)
2. **Reference velocity** = 0 (hold position)
3. **PD controller** computes torque:
   ```
   Torque = Kp × (step_position - current_position) + Kd × (0 - current_velocity)
   ```
4. **Large initial error** → Large torque
5. **As position approaches target** → Torque decreases
6. **Velocity damping** (Kd term) prevents overshoot

## PlotJuggler Analysis

### Topics to Plot:

**Reference (Step Function):**
- `/joint_reference/data[0]` - rev1 step reference
- `/joint_reference/data[1]` - rev_2 step reference

**Actual Response:**
- `/joint_states/position[0]` - rev1 actual position
- `/joint_states/position[1]` - rev_2 actual position
- `/joint_states/velocity[0]` - rev1 velocity
- `/joint_states/velocity[1]` - rev_2 velocity

**Control Effort:**
- `/joint_effort_controller/commands/data[0]` - rev1 commanded torque
- `/joint_effort_controller/commands/data[1]` - rev_2 commanded torque

### What to Observe:

#### 1. **Rise Time**
Time for response to go from 10% to 90% of step change
- Controlled by **Kp** (higher = faster)

#### 2. **Overshoot**
How much the response exceeds the target
- Controlled by **Kd** (higher = less overshoot)

#### 3. **Settling Time**
Time to reach and stay within ±2% of target
- Balance of **Kp** and **Kd**

#### 4. **Steady-State Error**
Final error between target and actual position
- Should be near zero with PD control
- May have small error due to friction/gravity

#### 5. **Torque Profile**
- Large spike at step instant
- Decays as position approaches target
- Oscillates if under-damped

## Step Response Characteristics

### Well-Tuned PD:
```
Position: ─────┐     ┌─────
               │    ╱│
               │  ╱  │
               │╱    │
               └─────┘
         [Smooth approach, minimal overshoot]

Torque:   ─────╥╥───╥╥────
               ║║   ║║
          ─────╨╨───╨╨────
         [Sharp peaks at steps, quick decay]
```

### Under-Damped (Kd too low):
```
Position: ─────┐  ╱╲╱╲
               │ ╱  ╲  ╲
               │╱      ╲
               └────────
         [Oscillations before settling]
```

### Over-Damped (Kd too high):
```
Position: ─────┐
               │    ╱────
               │  ╱
               │╱
               └────────
         [Slow, sluggish response]
```

## Tuning with Step Response

### If you see oscillations:
```bash
# Increase Kd (add more damping)
ros2 launch hexapod_gz spawn_robot_step.launch.py kd_rev1:=1.0 kd_rev2:=0.8
```

### If response is too slow:
```bash
# Increase Kp (stronger position correction)
ros2 launch hexapod_gz spawn_robot_step.launch.py kp_rev1:=10.0 kp_rev2:=8.0
```

### If overshoot is too large:
```bash
# Increase Kd and slightly reduce Kp
ros2 launch hexapod_gz spawn_robot_step.launch.py kp_rev1:=4.0 kd_rev1:=1.5
```

### For critical damping (ideal):
```bash
# Adjust ratio: Kd = 2 × sqrt(Kp × inertia)
# Start with Kd/Kp ≈ 0.2-0.3 and tune
ros2 launch hexapod_gz spawn_robot_step.launch.py kp_rev1:=8.0 kd_rev1:=2.0
```

## Custom Step Sequence

To modify the step positions, edit `pd_step_commander.py`:

```python
# Line ~72-73
self.rev1_steps = [2.0, 4.5, 1.5, 5.0, 3.14]  # Your custom positions
self.rev2_steps = [-0.5, 1.5, 0.0, 2.0, 0.765]  # Your custom positions
```

Make sure all positions are within joint limits:
- rev1: [0.0, 6.28]
- rev_2: [-1.47, 3.0]

Then rebuild:
```bash
colcon build --packages-select hexapod_gz
```

## Comparison: Sine vs Step

### Use Sine Wave Controller when:
- Testing continuous tracking
- Evaluating frequency response
- Measuring phase lag
- Demonstrating smooth motion

### Use Step Controller when:
- Measuring transient response
- Tuning for fast settling
- Evaluating overshoot/damping
- Testing point-to-point motion
- Identifying system dynamics

## Quick Commands

### Sine Wave (Smooth Tracking):
```bash
ros2 launch hexapod_gz spawn_robot_pd.launch.py
```

### Step Function (Response Analysis):
```bash
ros2 launch hexapod_gz spawn_robot_step.launch.py
```

### Fast Steps (3 seconds):
```bash
ros2 launch hexapod_gz spawn_robot_step.launch.py step_duration:=3.0
```

### Slow Steps (10 seconds):
```bash
ros2 launch hexapod_gz spawn_robot_step.launch.py step_duration:=10.0
```

---

**The step controller is perfect for analyzing and tuning your PD controller's transient response!** 📊✨
