#!/usr/bin/env python3
import os

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    # Common args
    use_sim_time = LaunchConfiguration('use_sim_time', default='true')
    gui = LaunchConfiguration('gui', default='false')
    use_plotjuggler = LaunchConfiguration('use_plotjuggler', default='false')
    start_cmd = LaunchConfiguration('start_cmd', default='true')

    gazebo_pkg = get_package_share_directory('hexapod_gazebo')
    controller_pkg = get_package_share_directory('hexapod_controller')

    # Delegate to the existing simulation launch
    sim_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(os.path.join(gazebo_pkg, 'launch', 'sim.launch.py')),
        launch_arguments={
            'use_sim_time': use_sim_time,
            'gui': gui,
        }.items()
    )

    # Bring up the controller package (command publisher + optional PlotJuggler)
    controller_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(os.path.join(controller_pkg, 'launch', 'bringup.launch.py')),
        launch_arguments={
            'use_plotjuggler': use_plotjuggler,
            'start_cmd': start_cmd,
        }.items()
    )

    return LaunchDescription([
        DeclareLaunchArgument('use_sim_time', default_value='true'),
        DeclareLaunchArgument('gui', default_value='false'),
        DeclareLaunchArgument('use_plotjuggler', default_value='false'),
        DeclareLaunchArgument('start_cmd', default_value='true'),
        sim_launch,
        controller_launch,
    ])
