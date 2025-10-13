from setuptools import setup
from glob import glob
import os

package_name = 'hexapod_controller'

setup(
    name=package_name,
    version='0.1.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', glob(os.path.join('launch', '*.py'))),
        ('share/' + package_name + '/plots', glob(os.path.join('plots', '*'))),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='hexapod',
    maintainer_email='user@example.com',
    description='Control node and PlotJuggler setup for hexapod',
    license='Apache-2.0',
    tests_require=['pytest'],
    scripts=[
        'scripts/position_velocity_demo_shim',
        'scripts/start_plotjuggler_shim',
    ],
    entry_points={
        'console_scripts': [
            'position_velocity_demo = hexapod_controller.position_velocity_demo:main',
            'start_plotjuggler = hexapod_controller.start_plotjuggler:main',
        ],
    },
)
