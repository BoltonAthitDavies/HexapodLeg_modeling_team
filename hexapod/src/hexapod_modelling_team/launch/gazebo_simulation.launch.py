#!/usr/bin/env python3
import os

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, RegisterEventHandler
from launch.event_handlers import OnProcessExit
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import Command, FindExecutable, LaunchConfiguration, PathJoinSubstitution

from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from launch_ros.parameter_descriptions import ParameterValue
from ament_index_python.packages import get_package_share_directory
import xacro


def generate_launch_description():
    # Use simulated time
    use_sim_time = LaunchConfiguration('use_sim_time', default='true')

    # Package shares
    desc_pkg = get_package_share_directory('hexapod_modelling_team')
    sim_pkg = get_package_share_directory('hexapod_modelling_team')

    # Set environment variables for Gazebo
    model_path = os.path.join(desc_pkg, 'models')
    if 'IGN_GAZEBO_RESOURCE_PATH' in os.environ:
        os.environ['IGN_GAZEBO_RESOURCE_PATH'] = os.environ['IGN_GAZEBO_RESOURCE_PATH'] + os.pathsep + model_path
    else:
        os.environ['IGN_GAZEBO_RESOURCE_PATH'] = model_path

    # Robot description (xacro)
    xacro_file = os.path.join(desc_pkg, 'urdf', 'hexapod_modelling_team.xacro')
    doc = xacro.parse(open(xacro_file))
    xacro.process_doc(doc, mappings={'use_sim_time': str(use_sim_time)})
    robot_description_content = doc.toxml()
    robot_description_param = {'robot_description': robot_description_content}

    # Gazebo simulation launch
    gz_sim = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            [os.path.join(get_package_share_directory('ros_gz_sim'), 'launch', 'gz_sim.launch.py')]
        ),
        launch_arguments={'gz_args': '-r -v 1 empty.sdf'}.items()
    )

    # Robot state publisher
    state_pub = Node(
        package='robot_state_publisher', 
        executable='robot_state_publisher',
        name='robot_state_publisher', 
        output='screen',
        parameters=[
            robot_description_param,
            {'use_sim_time': use_sim_time}
        ]
    )

    # Spawn entity in Gazebo
    spawn_entity = Node(
        package='ros_gz_sim', 
        executable='create', 
        name='spawn_entity', 
        output='screen',
        arguments=[
            '-topic', 'robot_description',
            '-name', 'hexapod',
            '-allow_renaming', 'true',
            '-x', '0.0', '-y', '0.0', '-z', '0.5'
        ]
    )

    # Controller manager spawners
    jsb_spawner = Node(
        package='controller_manager', 
        executable='spawner', 
        name='spawner_joint_state_broadcaster',
        arguments=['joint_state_broadcaster', '--controller-manager', '/controller_manager'],
        parameters=[{'use_sim_time': use_sim_time}]
    )

    effort_spawner = Node(
        package='controller_manager', 
        executable='spawner', 
        name='spawner_effort_controller',
        arguments=['effort_controller', '--controller-manager', '/controller_manager'],
        parameters=[{'use_sim_time': use_sim_time}]
    )

    # ROS <-> Gazebo bridge
    bridge = Node(
        package='ros_gz_bridge', 
        executable='parameter_bridge', 
        output='screen',
        arguments=[
            '/clock@rosgraph_msgs/msg/Clock[gz.msgs.Clock',
            '/imu_data@sensor_msgs/msg/Imu[gz.msgs.IMU'
        ],
        parameters=[{'use_sim_time': use_sim_time}]
    )

    # RViz
    rviz_config = PathJoinSubstitution([FindPackageShare('hexapod_modelling_team'), 'rviz', 'display.rviz'])
    rviz = Node(
        package='rviz2', 
        executable='rviz2', 
        name='rviz', 
        output='screen',
        arguments=['-d', rviz_config],
        parameters=[{'use_sim_time': use_sim_time}]
    )

    # Load controllers
    controller_params_file = os.path.join(desc_pkg, 'config', 'ros2_controllers.yaml')
    controller_manager = Node(
        package="controller_manager",
        executable="ros2_control_node",
        parameters=[
            {'robot_description': robot_description_content},
            controller_params_file,
            {'use_sim_time': use_sim_time}
        ]
    )

    # Load controllers
    load_joint_state_broadcaster = Node(
        package='controller_manager',
        executable='spawner',
        arguments=['joint_state_broadcaster', '--controller-manager', '/controller_manager'],
    )

    load_position_controller = Node(
        package='controller_manager',
        executable='spawner',
        arguments=['joint_position_controller', '--controller-manager', '/controller_manager'],
    )

    return LaunchDescription([
        DeclareLaunchArgument(
            'use_sim_time', 
            default_value='true',
            description='Use simulation (Gazebo) clock'
        ),
        gz_sim,
        controller_manager,
        state_pub,
        spawn_entity,
        bridge,
        # After spawning the robot, start the joint_state_broadcaster
        RegisterEventHandler(
            event_handler=OnProcessExit(
                target_action=spawn_entity,
                on_exit=[load_joint_state_broadcaster]
            )
        ),
        # After joint_state_broadcaster is active, start the position controller
        RegisterEventHandler(
            event_handler=OnProcessExit(
                target_action=load_joint_state_broadcaster,
                on_exit=[load_position_controller]
            )
        ),
        rviz
    ])