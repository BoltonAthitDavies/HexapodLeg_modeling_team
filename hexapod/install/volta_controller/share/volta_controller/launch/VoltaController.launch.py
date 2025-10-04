from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():

    # motor_group_config_node = Node(
    #     package='volta_controller',
    #     executable='MotorGroupConfig.py',
    #     output='screen'
    # )

    desired_joints_state_node = Node(
        package='volta_controller',
        executable='DesiredJointsState.py',
        output='screen'
    )

    inverse_dynamics_controller_node = Node(
        package='volta_controller',
        executable='InverseDynamicsController.py',
        output='screen'
    )

    return LaunchDescription([#motor_group_config_node,
                              desired_joints_state_node,
                              inverse_dynamics_controller_node])
