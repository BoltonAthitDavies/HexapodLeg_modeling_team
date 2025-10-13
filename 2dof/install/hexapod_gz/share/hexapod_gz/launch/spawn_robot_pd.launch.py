#!/usr/bin/env python3
import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, ExecuteProcess, RegisterEventHandler
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import Command, FindExecutable, LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from launch_ros.parameter_descriptions import ParameterValue
from launch.event_handlers import OnProcessExit


def generate_launch_description():
    # Declare arguments
    declared_arguments = []
    declared_arguments.append(
        DeclareLaunchArgument(
            "gui",
            default_value="true",
            description="Start Gazebo with GUI",
        )
    )
    declared_arguments.append(
        DeclareLaunchArgument(
            "use_sim_time",
            default_value="true",
            description="Use simulation time",
        )
    )
    declared_arguments.append(
        DeclareLaunchArgument(
            "use_pd_controller",
            default_value="true",
            description="Use PD controller instead of simple sine wave",
        )
    )
    declared_arguments.append(
        DeclareLaunchArgument(
            "kp_rev1",
            default_value="5.0",
            description="Proportional gain for rev1 joint",
        )
    )
    declared_arguments.append(
        DeclareLaunchArgument(
            "kd_rev1",
            default_value="0.5",
            description="Derivative gain for rev1 joint",
        )
    )
    declared_arguments.append(
        DeclareLaunchArgument(
            "kp_rev2",
            default_value="4.0",
            description="Proportional gain for rev_2 joint",
        )
    )
    declared_arguments.append(
        DeclareLaunchArgument(
            "kd_rev2",
            default_value="0.4",
            description="Derivative gain for rev_2 joint",
        )
    )

    # Initialize Arguments
    gui = LaunchConfiguration("gui")
    use_sim_time = LaunchConfiguration("use_sim_time")
    use_pd = LaunchConfiguration("use_pd_controller")
    kp_rev1 = LaunchConfiguration("kp_rev1")
    kd_rev1 = LaunchConfiguration("kd_rev1")
    kp_rev2 = LaunchConfiguration("kp_rev2")
    kd_rev2 = LaunchConfiguration("kd_rev2")

    # Get URDF via xacro
    pkg_hexapod_gz = FindPackageShare('hexapod_gz')
    
    robot_description_content = Command(
        [
            PathJoinSubstitution([FindExecutable(name="xacro")]),
            " ",
            PathJoinSubstitution([pkg_hexapod_gz, "urdf", "hexapod_modelling_team.xacro"]),
        ]
    )
    
    robot_description = {"robot_description": ParameterValue(robot_description_content, value_type=str)}

    # Robot State Publisher Node
    robot_state_publisher_node = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        output="both",
        parameters=[robot_description, {"use_sim_time": use_sim_time}],
    )

    # Gazebo Sim (Ignition Gazebo)
    world_file = PathJoinSubstitution([pkg_hexapod_gz, "worlds", "hexapod.sdf"])
    
    gazebo = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            [PathJoinSubstitution([FindPackageShare("ros_gz_sim"), "launch", "gz_sim.launch.py"])]
        ),
        launch_arguments={
            "gz_args": ["-r ", world_file],
            "on_exit_shutdown": "true"
        }.items(),
    )

    # Spawn the robot on top of the static base (height = 1.0m)
    spawn_entity = Node(
        package="ros_gz_sim",
        executable="create",
        arguments=[
            "-topic", "robot_description",
            "-name", "hexapod_robot",
            "-x", "0.0",
            "-y", "0.0",
            "-z", "1.1",  # Platform height (1.0) + clearance (0.1)
        ],
        output="screen",
    )

    # Load joint state broadcaster
    load_joint_state_broadcaster = ExecuteProcess(
        cmd=["ros2", "control", "load_controller", "--set-state", "active",
             "joint_state_broadcaster"],
        output="screen",
    )

    # Load joint position controller
    load_joint_position_controller = ExecuteProcess(
        cmd=["ros2", "control", "load_controller", "--set-state", "active",
             "joint_position_controller"],
        output="screen",
    )

    # Delay controller loading until spawn is complete
    delay_joint_state_broadcaster_after_spawn = RegisterEventHandler(
        event_handler=OnProcessExit(
            target_action=spawn_entity,
            on_exit=[load_joint_state_broadcaster],
        )
    )

    delay_joint_position_controller_after_joint_state_broadcaster = RegisterEventHandler(
        event_handler=OnProcessExit(
            target_action=load_joint_state_broadcaster,
            on_exit=[load_joint_position_controller],
        )
    )

    # PD Position Commander Node (NEW!)
    pd_commander_node = Node(
        package="hexapod_gz",
        executable="pd_position_commander",
        name="pd_position_commander",
        output="screen",
        parameters=[{
            "use_sim_time": use_sim_time,
            "kp_rev1": kp_rev1,
            "kd_rev1": kd_rev1,
            "kp_rev2": kp_rev2,
            "kd_rev2": kd_rev2,
            "update_rate": 100.0,
        }],
        condition=IfCondition(use_pd),
    )

    # Simple Joint Position Commander (for comparison)
    simple_commander_node = Node(
        package="hexapod_gz",
        executable="joint_position_commander",
        name="joint_position_commander",
        output="screen",
        parameters=[{"use_sim_time": use_sim_time}],
        condition=IfCondition(LaunchConfiguration("use_pd_controller", default="false")),
    )

    nodes = [
        robot_state_publisher_node,
        gazebo,
        spawn_entity,
        delay_joint_state_broadcaster_after_spawn,
        delay_joint_position_controller_after_joint_state_broadcaster,
        pd_commander_node,
    ]

    return LaunchDescription(declared_arguments + nodes)
