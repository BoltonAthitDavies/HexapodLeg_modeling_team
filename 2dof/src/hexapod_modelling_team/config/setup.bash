#!/bin/bash

# Get the package share directory
PACKAGE_SHARE=$(ros2 pkg prefix --share hexapod_modelling_team)

# Set Gazebo model path
export IGN_GAZEBO_RESOURCE_PATH=$IGN_GAZEBO_RESOURCE_PATH:$PACKAGE_SHARE/meshes
export GAZEBO_MODEL_PATH=$GAZEBO_MODEL_PATH:$PACKAGE_SHARE/meshes

# Set other environment variables if needed
export IGN_FILE_PATH=$IGN_FILE_PATH:$PACKAGE_SHARE