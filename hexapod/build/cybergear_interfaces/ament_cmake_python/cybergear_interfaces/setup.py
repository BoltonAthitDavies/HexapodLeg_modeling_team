from setuptools import find_packages
from setuptools import setup

setup(
    name='cybergear_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('cybergear_interfaces', 'cybergear_interfaces.*')),
)
