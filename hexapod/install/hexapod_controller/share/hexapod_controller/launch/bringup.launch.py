#!/usr/bin/env python3
import os

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch.conditions import IfCondition
from launch_ros.actions import Node
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    use_plotjuggler = LaunchConfiguration('use_plotjuggler', default='true')
    start_cmd = LaunchConfiguration('start_cmd', default='true')
    layout = LaunchConfiguration('layout', default=os.path.join(
        get_package_share_directory('hexapod_controller'), 'plots', 'hexapod.layout.xml'))

    nodes = []

    nodes.append(Node(
        package='hexapod_controller',
        executable='position_velocity_demo',
        name='position_velocity_demo',
        output='screen',
        parameters=[{'use_sim_time': True}],
        condition=IfCondition(start_cmd)
    ))

    nodes.append(Node(
        package='hexapod_controller',
        executable='start_plotjuggler',
        name='plotjuggler',
        output='screen',
        parameters=[{'layout_path': layout}],
        condition=IfCondition(use_plotjuggler)
    ))

    return LaunchDescription([
        DeclareLaunchArgument('use_plotjuggler', default_value='true'),
        DeclareLaunchArgument('start_cmd', default_value='true'),
        DeclareLaunchArgument('layout', default_value=os.path.join(
            get_package_share_directory('hexapod_controller'), 'plots', 'hexapod.layout.xml')),
        *nodes
    ])
