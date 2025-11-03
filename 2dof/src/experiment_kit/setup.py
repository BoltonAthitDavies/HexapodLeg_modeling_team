from setuptools import setup

package_name = 'experiment_kit'

setup(
    name=package_name,
    version='0.1.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', ['launch/spawn_robot_step.launch.py', 'launch/spawn_robot_step_link1.launch.py', 'launch/spawn_robot_step_link2.launch.py']),
        ('share/' + package_name + '/config', ['config/ros2_controllers.yaml', 'config/ros2_controllers_link1.yaml', 'config/ros2_controllers_link2.yaml', 'config/plotjuggler_layout.xml']),
        ('share/' + package_name + '/urdf', ['urdf/hexapod_modelling_team.xacro', 'urdf/link1.xacro', 'urdf/link2.xacro', 'urdf/link1_vertical.xacro', 'urdf/link2_vertical.xacro']),
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
            'pd_position_commander = experiment_kit.pd_position_commander:main',
            'pd_step_commander = experiment_kit.pd_step_commander:main',
            'pd_step_commander_link1 = experiment_kit.pd_step_commander_link1:main',
            'pd_step_commander_link2 = experiment_kit.pd_step_commander_link2:main',
        ],
    },
)
