import os
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    # Environment variable to set the ROS domain ID
    os.environ['ROS_DOMAIN_ID'] = '89'

    return LaunchDescription([
        # Launch the first robot controller
        Node(
            package='global_path_test_pkg',
            executable='robot_controller',
            name='robot_controller',  # Node name
            namespace='transporter01',
            parameters=[{'robot_id': '01'}],
            output='screen'
        ),

        # Launch the second robot controller
        Node(
            package='global_path_test_pkg',
            executable='robot_controller',
            name='robot_controller',  # Node name
            namespace='transporter03',
            parameters=[{'robot_id': '03'}],
            output='screen'
        ),


        # Launch the robot navigator
        Node(
            package='global_path_test_pkg',
            executable='robot_navigator',
            name='robot_navigator',
            output='screen'
        )

        
    ])
