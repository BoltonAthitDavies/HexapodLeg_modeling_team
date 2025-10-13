# Static Base Platform Setup

## Overview

Your robot now stands on a **static base platform** with the following specifications:

### Platform Specifications:
- **Height**: 1.0 meter
- **Size**: 1.0m × 1.0m × 1.0m (width × depth × height)
- **Position**: Centered at (0, 0, 0.5) - bottom at z=0, top at z=1.0
- **Type**: Static (non-moving, fixed in place)
- **Color**: Blue-gray appearance

### Robot Position:
- **Spawn height**: z = 1.1 meters
  - Platform top: 1.0m
  - Clearance: 0.1m
  - Robot base at: 1.1m above ground

## Visual Layout

```
                    ╔═══════════╗
                    ║   ROBOT   ║  ← z = 1.1m (robot base)
                    ╚═══════════╝
    ┌───────────────────────────────────┐
    │                                   │
    │        STATIC BASE PLATFORM       │  ← Height = 1.0m
    │         (1.0m × 1.0m × 1.0m)      │     (Blue-gray)
    │                                   │
    └───────────────────────────────────┘  ← z = 0 (ground)
═══════════════════════════════════════════
              GROUND PLANE
```

## How to Launch

### Standard Launch:
```bash
cd ~/HexapodLeg_modeling_team/2dof
source install/setup.bash
ros2 launch hexapod_gz spawn_robot.launch.py
```

### With PlotJuggler Visualization:
```bash
source install/setup.bash
ros2 launch hexapod_gz spawn_robot_with_viz.launch.py plotjuggler:=true
```

## What You'll See in Gazebo

1. **Ground plane** (gray) at z = 0
2. **Blue-gray platform** (1m × 1m × 1m) standing on the ground
3. **Your robot** spawned on top of the platform at z = 1.1m
4. **Robot moving** with sine wave motion on the platform

## Customizing the Platform

The platform is defined in `worlds/hexapod.sdf`. You can modify:

### Change Platform Size:
```xml
<geometry>
  <box>
    <size>2.0 2.0 1.0</size>  <!-- width depth height -->
  </box>
</geometry>
```

### Change Platform Height:
To make a 1.5m tall platform:
```xml
<pose>0 0 0.75 0 0 0</pose>  <!-- z = height/2 -->
<geometry>
  <box>
    <size>1.0 1.0 1.5</size>  <!-- height -->
  </box>
</geometry>
```

Then update the robot spawn position in the launch file:
```python
"-z", "1.6",  # Platform height (1.5) + clearance (0.1)
```

### Change Platform Color:
```xml
<material>
  <ambient>1.0 0.5 0.0 1</ambient>  <!-- Orange -->
  <diffuse>1.0 0.5 0.0 1</diffuse>
  <specular>0.3 0.3 0.3 1</specular>
</material>
```

### Change Platform Position:
```xml
<pose>2.0 3.0 0.5 0 0 0</pose>  <!-- x y z roll pitch yaw -->
```
(Don't forget to update robot spawn position accordingly)

## File Locations

- **World file**: `src/hexapod_gz/worlds/hexapod.sdf`
- **Launch file**: `src/hexapod_gz/launch/spawn_robot.launch.py`
- **Launch with viz**: `src/hexapod_gz/launch/spawn_robot_with_viz.launch.py`

## Notes

- The platform is **static** (cannot move or fall)
- The robot can move its joints while standing on the platform
- Platform provides a clear elevated working surface
- All physics interactions work normally
- Robot spawn height is automatically set to platform_height + 0.1m clearance

## Verifying the Setup

Once launched, in Gazebo you should see:
1. Ground plane (gray, infinite)
2. Static platform (blue-gray box, 1m tall)
3. Robot on top of platform (at 1.1m height)
4. Robot joints moving in sine wave pattern

## Troubleshooting

### Robot falls through platform:
- Check robot spawn height in launch file
- Ensure platform has collision geometry
- Verify platform is marked as `<static>true</static>`

### Can't see platform:
- Check Gazebo view - may need to zoom out
- Verify world file was rebuilt (`colcon build`)
- Look at coordinates (0, 0, 0.5)

### Want different height:
1. Edit `worlds/hexapod.sdf`:
   - Change `<pose>0 0 NEW_HEIGHT/2 0 0 0</pose>`
   - Change `<size>1.0 1.0 NEW_HEIGHT</size>`
2. Edit `launch/spawn_robot.launch.py`:
   - Change `-z` value to `NEW_HEIGHT + 0.1`
3. Rebuild: `colcon build --packages-select hexapod_gz`

---

**Your robot now has a proper elevated platform to work on! 🎉**
