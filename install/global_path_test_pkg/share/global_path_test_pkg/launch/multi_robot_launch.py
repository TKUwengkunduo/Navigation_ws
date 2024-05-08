import os
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    # Environment variable to set the ROS domain ID
    os.environ['ROS_DOMAIN_ID'] = '89'
    nodes = []

    # Create Node entries for each robot
    for i in range(1, 11):  # For 10 robots
        robot_id = f"{i}"
        node = Node(
            package='global_path_test_pkg',
            executable='robot_controller',
            name=f'robot_controller_{robot_id}',
            namespace=f'transporter{robot_id}',
            parameters=[{'robot_id': robot_id}],
            output='screen'
        )
        nodes.append(node)

    # Launch the robot navigator
    navigator_node = Node(
        package='global_path_test_pkg',
        executable='robot_navigator',
        name='robot_navigator',
        output='screen'
    )

    # Add the navigator to the list of nodes
    nodes.append(navigator_node)

    return LaunchDescription(nodes)
