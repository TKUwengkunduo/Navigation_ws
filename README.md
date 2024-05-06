# Robot Navigation Workspace

This repository contains the ROS 2 packages for a multi-robot navigation system. It includes two main components: `robot_controller` and `robot_navigator`. These components work together to manage and direct the movements of robots in a simulated or physical environment.

## Features

- **Robot Controller**: Handles the motion control of individual robots, receiving target positions and calculating the necessary velocity commands to reach these positions.
- **Robot Navigator**: Manages the sequence of target positions for each robot, ensuring that each unit navigates through all designated waypoints.

## Prerequisites

Before you begin, ensure you have ROS 2 installed on your system. This project has been tested with ROS 2 Humble Hawksbill, but it should be compatible with other ROS 2 releases that support Python 3.8 or newer.

## Installation

To install and run the navigation system, follow these steps:

1. Clone the repository:
   ```bash
   git clone https://github.com/TKUwengkunduo/navigation_ws.git
   cd navigation_ws
   colcon build
   ```

## Start the Isaac Sim Environment
1. Copy all USD in the "/navigation_ws/src/Isaac_Sim_warehouse/usd_file" folder to your localhost

2. Start isaac sim
   ```bash
   source /opt/ros/humble/setup.bash
   export FASTRTPS_DEFAULT_PROFILES_FILE=/home/weng/wkd_ws/navigation_ws/src/Isaac_Sim_warehouse/fastdds.xml
   export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$HOME/.local/share/ov/pkg/isaac_sim-2023.1.1/exts/omni.isaac.ros2_bridge/humble/lib
   ./python.sh /home/weng/wkd_ws/navigation_ws/src/Isaac_Sim_warehouse/isaac_transporter_navigation.py
   ```

## Running the System
1. Start the Robot Controllers for Robot 01:
   ```bash
   . install/setup.bash
   export ROS_DOMAIN_ID=89
   ros2 run global_path_test_pkg robot_controller --ros-args -p robot_id:="'01'"
   ```

2. Start the Robot Controllers for Robot 03:
   ```bash
   . install/setup.bash
   export ROS_DOMAIN_ID=89
   ros2 run global_path_test_pkg robot_controller --ros-args -p robot_id:="'03'"
   ```

3. Start the Robot Navigator:
   ```bash
   . install/setup.bash
   export ROS_DOMAIN_ID=89
   ros2 run global_path_test_pkg robot_navigator
   ```