#!/usr/bin/env python3
import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, RegisterEventHandler
from launch.event_handlers import OnProcessExit
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, Command, FindExecutable
from launch.conditions import IfCondition
from launch_ros.parameter_descriptions import ParameterValue
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    use_sim_time = LaunchConfiguration('use_sim_time', default='true')
    gui = LaunchConfiguration('gui', default='false')
    start_commander = LaunchConfiguration('start_commander', default='false')
    hardware = LaunchConfiguration('hardware', default='gz')  # 'gz' or 'mock'

    this_pkg = get_package_share_directory('hexapod_gz')
    desc_pkg = get_package_share_directory('hexapod_modelling_team')
    gz_pkg = get_package_share_directory('ros_gz_sim')

    default_world = os.path.join(this_pkg, 'worlds', 'hexapod.sdf')
    world = LaunchConfiguration('world', default=default_world)

    # Gazebo resource paths for meshes/models
    model_path = os.path.join(desc_pkg, 'models')
    meshes_path = os.path.join(desc_pkg, 'meshes')
    pkg_share_path = desc_pkg
    ign_paths = os.pathsep.join(filter(None, [
        os.environ.get('IGN_GAZEBO_RESOURCE_PATH', ''),
        model_path,
        meshes_path,
        pkg_share_path,
    ]))
    os.environ['IGN_GAZEBO_RESOURCE_PATH'] = ign_paths
    os.environ['GZ_SIM_RESOURCE_PATH'] = os.pathsep.join(filter(None, [
        os.environ.get('GZ_SIM_RESOURCE_PATH', ''),
        model_path,
        meshes_path,
        pkg_share_path,
    ]))

    # Robot description from xacro
    xacro_file = os.path.join(this_pkg, 'urdf', 'hexapod_modelling_team.xacro')
    robot_description_content = Command([
        FindExecutable(name='xacro'), ' ', xacro_file, ' ', 'hardware:=', hardware
    ])
    robot_description_param = {
        'robot_description': ParameterValue(robot_description_content, value_type=str)
    }

    # Start Gazebo Sim
    gz_sim = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(os.path.join(gz_pkg, 'launch', 'gz_sim.launch.py')),
        launch_arguments={
            'gz_args': ['-r -v 1 ', world],
            'gui': gui
        }.items(),
    )

    # robot_state_publisher
    state_pub = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        name='robot_state_publisher',
        output='screen',
        parameters=[robot_description_param, {'use_sim_time': use_sim_time}],
    )

    # Minimal bridge for /clock
    bridge = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        output='screen',
        arguments=['/clock@rosgraph_msgs/msg/Clock[gz.msgs.Clock'],
        parameters=[{'use_sim_time': use_sim_time}],
    )

    # Controller manager
    controller_params_file = os.path.join(this_pkg, 'config', 'ros2_controllers.yaml')
    controller_manager = Node(
        package='controller_manager',
        executable='ros2_control_node',
        parameters=[
            robot_description_param,
            controller_params_file,
            {'use_sim_time': use_sim_time},
        ],
        output='screen',
    )

    # Spawn entity from robot_description
    spawn = Node(
        package='ros_gz_sim',
        executable='create',
        name='spawn_entity',
        output='screen',
        arguments=[
            '-topic', 'robot_description',
            '-name', 'hexapod',
            '-allow_renaming', 'true',
            '-x', '0.0', '-y', '0.0', '-z', '0.5'
        ],
    )

    # Spawners
    joint_state_broadcaster_spawner = Node(
        package='controller_manager',
        executable='spawner',
        arguments=['joint_state_broadcaster', '--controller-manager', '/controller_manager'],
        parameters=[{'use_sim_time': use_sim_time}],
        output='screen',
    )
    position_controller_spawner = Node(
        package='controller_manager',
        executable='spawner',
        arguments=['joint_position_controller', '--controller-manager', '/controller_manager'],
        parameters=[{'use_sim_time': use_sim_time}],
        output='screen',
    )

    # Optional demo commander to publish sine positions
    commander = Node(
        package='hexapod_gz',
        executable='joint_position_commander',
        name='joint_position_commander',
        parameters=[{'controller_name': 'joint_position_controller'}],
        condition=IfCondition(start_commander),
        output='screen',
    )

    return LaunchDescription([
        DeclareLaunchArgument('use_sim_time', default_value='true'),
        DeclareLaunchArgument('world', default_value=default_world),
        DeclareLaunchArgument('gui', default_value='false'),
        DeclareLaunchArgument('start_commander', default_value='false', description='Start sine-wave joint commander'),
        DeclareLaunchArgument('hardware', default_value='gz', description="ros2_control hardware: 'gz' (Gazebo Sim) or 'mock'"),
        gz_sim,
        state_pub,
        bridge,
        controller_manager,
        spawn,
        RegisterEventHandler(OnProcessExit(target_action=spawn, on_exit=[joint_state_broadcaster_spawner])),
        RegisterEventHandler(OnProcessExit(target_action=joint_state_broadcaster_spawner, on_exit=[position_controller_spawner])),
        # Optionally start commander after controller is active
        RegisterEventHandler(OnProcessExit(target_action=position_controller_spawner, on_exit=[commander])),
    ])
