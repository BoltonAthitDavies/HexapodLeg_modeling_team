# hexapod_gazebo

Launch Gazebo (Gazebo Sim), spawn the hexapod model from xacro with ros2_control, and optionally plot joints in PlotJuggler.

## Run

- Build the workspace and source overlay.
- Launch:

```
# Terminal 1 (recommended: keep PlotJuggler separate)
ros2 launch hexapod_gazebo sim.launch.py use_plotjuggler:=false
```

Optional: start a small demo to command the two joints:

```
ros2 launch hexapod_gazebo sim.launch.py start_demo:=true use_plotjuggler:=false
```

To visualize and/or command from a separate package, use `hexapod_controller`:

```
# Terminal 2
ros2 launch hexapod_controller bringup.launch.py use_plotjuggler:=true start_cmd:=true
```

This starts a simple sine command publisher and opens PlotJuggler with a layout for joint positions and velocities.

## Notes
- Joint names: `rev1` and `rev_2`.
- Commands topic: `/joint_position_controller/commands` (Float64MultiArray for group controller; order: [rev1, rev_2]).
- Joint states: `/joint_states`.

Troubleshooting:
- If meshes don't load, ensure `GZ_SIM_RESOURCE_PATH` (and `IGN_GAZEBO_RESOURCE_PATH`) include the `hexapod_modelling_team` package. The launch file sets these automatically.
- If controllers don't start, check `/controller_manager/list_controllers` and the spawner output.