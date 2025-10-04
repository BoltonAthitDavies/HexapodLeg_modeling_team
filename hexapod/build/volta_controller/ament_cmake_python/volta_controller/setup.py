from setuptools import find_packages
from setuptools import setup

setup(
    name='volta_controller',
    version='0.0.0',
    packages=find_packages(
        include=('volta_controller', 'volta_controller.*')),
)
