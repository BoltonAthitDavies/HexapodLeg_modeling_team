# Controller Comparison - Quick Reference

## Two Controllers Available ✨

### 1. PD Position Commander (Sine Wave)
**File:** `pd_position_commander.py`  
**Launch:** `spawn_robot_pd.launch.py`

**Trajectory:** Smooth sine wave
```
Position: ∿∿∿∿∿∿∿∿∿∿
          (continuous oscillation)
```

**Best For:**
- Continuous motion tracking
- Smooth trajectory following
- Frequency response testing
- Demonstrating fluid motion

**Launch:**
```bash
ros2 launch hexapod_gz spawn_robot_pd.launch.py
```

---

### 2. PD Step Commander (Step Function)
**File:** `pd_step_commander.py`  
**Launch:** `spawn_robot_step.launch.py`

**Trajectory:** Discrete position steps
```
Position: ───┐   ┌───┐   ┌───
             └───┘   └───┘
          (hold → jump → hold)
```

**Best For:**
- Step response analysis
- Measuring rise time, overshoot, settling time
- Point-to-point motion
- Tuning PD gains for transient response

**Launch:**
```bash
ros2 launch hexapod_gz spawn_robot_step.launch.py
```

---

## Side-by-Side Comparison

| Feature | Sine Wave | Step Function |
|---------|-----------|---------------|
| **Motion** | Continuous | Discrete |
| **Ref Velocity** | Non-zero | Zero (hold) |
| **Control Challenge** | Tracking moving target | Reaching fixed target |
| **Overshoot** | Hard to see | Very visible |
| **Settling Time** | N/A | Measurable |
| **Rise Time** | N/A | Measurable |
| **Torque Pattern** | Smooth oscillation | Spikes at steps |
| **Step Duration** | N/A | 5 sec (configurable) |

## Quick Launch Commands

### Sine Wave (Default gains):
```bash
ros2 launch hexapod_gz spawn_robot_pd.launch.py
```

### Step Function (Default gains):
```bash
ros2 launch hexapod_gz spawn_robot_step.launch.py
```

### Step with Custom Duration:
```bash
ros2 launch hexapod_gz spawn_robot_step.launch.py step_duration:=3.0
```

### Either with Custom Gains:
```bash
# Sine wave
ros2 launch hexapod_gz spawn_robot_pd.launch.py kp_rev1:=10.0 kd_rev1:=1.0

# Step function
ros2 launch hexapod_gz spawn_robot_step.launch.py kp_rev1:=10.0 kd_rev1:=1.0
```

## PlotJuggler - What to Expect

### Sine Wave Controller:
```
Reference:  ∿∿∿∿∿∿∿∿∿
Actual:     ∿∿∿∿∿∿∿∿∿  (follows with small lag)
Torque:     ∿∿∿∿∿∿∿∿∿  (smooth oscillation)
```

### Step Controller:
```
Reference:  ────┐    ┌────┐
                └────┘    └────
                
Actual:     ────╱────╲────╱────  (may overshoot)
                
Torque:     ────╥────╥────╥────  (spikes at steps)
```

## Tuning Strategy

### 1. Start with Step Controller
- Easy to see overshoot and settling
- Tune Kp and Kd for good step response
- Measure rise time and settling time

### 2. Then Test with Sine Wave
- Verify smooth tracking
- Check phase lag
- Ensure no instability at frequency

### 3. Iterate
- Adjust gains based on both responses
- Balance between fast response and stability

## Default Gains

```python
rev1: Kp = 5.0, Kd = 0.5
rev2: Kp = 4.0, Kd = 0.4
```

These provide a good starting point for both controllers!

---

**Both controllers available - choose based on your testing needs!** 🎯
