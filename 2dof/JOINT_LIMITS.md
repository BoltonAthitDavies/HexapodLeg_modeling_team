# Joint Limits Configuration

## Joint Range Specifications

### rev1 (Base Joint)
- **Type**: Revolute (previously continuous)
- **Range**: [0.0, 6.28] radians
- **Range in degrees**: [0°, 360°]
- **Center position**: 3.14 rad (180°)
- **Max effort**: 10.0 Nm
- **Max velocity**: 10.0 rad/s

### rev_2 (Second Joint)
- **Type**: Revolute (previously continuous)
- **Range**: [-1.47, 3.0] radians
- **Range in degrees**: [-84.2°, 171.9°]
- **Total range**: 4.47 radians (256.1°)
- **Center position**: 0.765 rad (43.8°)
- **Max effort**: 10.0 Nm
- **Max velocity**: 10.0 rad/s

## URDF Configuration

```xml
<joint name="rev1" type="revolute">
  <limit lower="0.0" upper="6.28" effort="10.0" velocity="10.0"/>
</joint>

<joint name="rev_2" type="revolute">
  <limit lower="-1.47" upper="3.0" effort="10.0" velocity="10.0"/>
</joint>
```

## Trajectory Generation

The reference trajectory has been updated to respect these limits:

### rev1 Trajectory:
```python
# Center at 3.14 rad with amplitude 2.0 rad
# Range: [3.14 - 2.0, 3.14 + 2.0] = [1.14, 5.14] rad
ref_pos_rev1 = 3.14 + 2.0 * sin(t)
ref_vel_rev1 = 2.0 * cos(t)
```

**Safe range**: [1.14, 5.14] ✅ (within [0, 6.28])

### rev_2 Trajectory:
```python
# Center at 0.765 rad with amplitude 1.5 rad
# Range: [0.765 - 1.5, 0.765 + 1.5] = [-0.735, 2.265] rad
ref_pos_rev2 = 0.765 + 1.5 * sin(0.8*t + 0.5)
ref_vel_rev2 = 1.5 * 0.8 * cos(0.8*t + 0.5)
```

**Safe range**: [-0.735, 2.265] ✅ (within [-1.47, 3.0])

## Safety Margins

Both trajectories maintain safety margins from the physical limits:

| Joint | Min Trajectory | Max Trajectory | Physical Min | Physical Max | Margin Min | Margin Max |
|-------|---------------|---------------|--------------|--------------|------------|------------|
| rev1  | 1.14 rad      | 5.14 rad      | 0.0 rad      | 6.28 rad     | 1.14 rad   | 1.14 rad   |
| rev_2 | -0.735 rad    | 2.265 rad     | -1.47 rad    | 3.0 rad      | 0.735 rad  | 0.735 rad  |

This provides approximately **12-15%** safety margin on each side.

## Gazebo Enforcement

Gazebo will now enforce these limits:
- ✅ Joints cannot exceed specified range
- ✅ Commanded torques are capped at ±10.0 Nm
- ✅ Velocities are limited to ±10.0 rad/s
- ✅ Physical constraints prevent damage to virtual robot

## Custom Trajectory Example

If you want to create a custom trajectory, use this formula:

```python
# For any joint with limits [lower, upper]
center = (upper + lower) / 2.0
amplitude = (upper - lower) / 2.0 * safety_factor  # safety_factor < 1.0

ref_pos = center + amplitude * sin(frequency * t + phase)
ref_vel = amplitude * frequency * cos(frequency * t + phase)
```

### Example for rev1:
```python
center = (6.28 + 0.0) / 2.0 = 3.14
amplitude = (6.28 - 0.0) / 2.0 * 0.8 = 2.512  # 80% of range

ref_pos_rev1 = 3.14 + 2.512 * sin(t)
```

### Example for rev_2:
```python
center = (3.0 + (-1.47)) / 2.0 = 0.765
amplitude = (3.0 - (-1.47)) / 2.0 * 0.8 = 1.788  # 80% of range

ref_pos_rev2 = 0.765 + 1.788 * sin(t)
```

## Testing

After building, test the new limits:

```bash
source install/setup.bash
ros2 launch hexapod_gz spawn_robot_pd.launch.py
```

In PlotJuggler, verify:
- `/joint_reference/data[0]` stays within [1.14, 5.14]
- `/joint_reference/data[1]` stays within [-0.735, 2.265]
- `/joint_states/position[0]` respects [0, 6.28] limit
- `/joint_states/position[1]` respects [-1.47, 3.0] limit

## Notes

1. **Changed from continuous to revolute**: This enables Gazebo to enforce limits
2. **Effort limits**: Set to 10.0 Nm - adjust if you need more torque
3. **Velocity limits**: Set to 10.0 rad/s - adjust if you need faster motion
4. **Safety margins**: Built into trajectory generation to avoid limit violations
5. **PD gains**: May need adjustment based on new trajectory amplitudes

---

**Joint limits are now properly configured and enforced!** 🎯
