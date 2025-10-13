from setuptools import setup

package_name = 'hexapod_gz'

setup(
    name=package_name,
    version='0.1.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', ['launch/spawn_robot.launch.py', 'launch/spawn_robot_with_viz.launch.py', 'launch/spawn_robot_pd.launch.py']),
        ('share/' + package_name + '/config', ['config/ros2_controllers.yaml', 'config/plotjuggler_layout.xml']),
        ('share/' + package_name + '/urdf', ['urdf/hexapod_modelling_team.xacro']),
        ('share/' + package_name + '/worlds', ['worlds/hexapod.sdf']),
        ('share/' + package_name + '/meshes', ['meshes/base_link.STL', 'meshes/Link1.STL', 'meshes/Link_2.STL']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='hexapod_dev',
    maintainer_email='you@example.com',
    description='Gazebo Sim spawning and position control for hexapod.',
    license='BSD-3-Clause',
    entry_points={
        'console_scripts': [
            'joint_position_commander = hexapod_gz.joint_position_commander:main',
            'manual_joint_control = hexapod_gz.manual_joint_control:main',
            'pd_position_commander = hexapod_gz.pd_position_commander:main',
            'pd_torque_controller = hexapod_gz.pd_torque_controller_node:main',
        ],
    },
)
