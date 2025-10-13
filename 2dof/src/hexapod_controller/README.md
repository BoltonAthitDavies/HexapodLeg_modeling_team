# hexapod_controller

A small Python package to command joint positions/velocities and launch PlotJuggler.

## Build & Run

```
colcon build --packages-select hexapod_controller
source install/setup.bash
ros2 launch hexapod_controller bringup.launch.py use_plotjuggler:=false
```
