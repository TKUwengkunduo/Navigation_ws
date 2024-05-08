import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64MultiArray
from tf2_msgs.msg import TFMessage
import math

class RobotNavigator(Node):
    def __init__(self):
        super().__init__('robot_navigator')  # Initialize the parent class first

        # Mapping from index to coordinates
        index_to_coords = {
            1: (-8, -4), 2: (-20, -4), 3: (-32, -4),
            4: (-8, -12), 5: (-20, -12), 6: (-32, -12),
            7: (-8, -20), 8: (-20, -20), 9: (-32, -20),
            10: (-8, -28), 11: (-20, -28), 12: (-32, -28),
            13: (-8, -36), 14: (-20, -36), 15: (-32, -36),
            16: (-8, -44), 17: (-20, -44), 18: (-32, -44),
            19: (-8, -52), 20: (-20, -52), 21: (-32, -52)
        }

        # Paths for each robot
        robot_paths = [
            [21, 18, 15, 12, 11, 10, 7, 4, 1],
            [1, 4, 7, 8, 9, 12],
            [21, 18, 15, 12, 11],
            [5],
            [5, 8, 9, 12, 15, 18, 21],
            [6, 3],
            [13, 10, 7, 4, 5, 2],
            [14, 11, 8, 5, 2],
            [16, 13, 10, 7, 8, 5],
            [7, 4, 5, 6]
        ]

        self.target_positions = [
            [index_to_coords.get(idx, (0, 0)) for idx in path] for path in robot_paths
        ]

        self.num_robots = 10
        self.robot_publishers = []
        self.robot_subscriptions = []  # Renamed from 'subscriptions' to avoid attribute conflict
        self.current_target_indices = [0] * self.num_robots
        self.current_robot_positions = [(0.0, 0.0)] * self.num_robots
        self.reach_threshold = 2.0

        # Setup publishers and subscriptions for each robot
        for i in range(self.num_robots):
            robot_id = f'transporter{i+1}'
            # Fix potential lambda capture issue by using a separate function or passing the index directly
            callback = lambda msg, idx=i: self.tf_callback(msg, idx)
            self.robot_subscriptions.append(
                self.create_subscription(TFMessage, f'/{robot_id}/tf', callback, 10)
            )
            self.robot_publishers.append(
                self.create_publisher(Float64MultiArray, f'/{robot_id}/target_position', 10)
            )


        self.timer = self.create_timer(0.005, self.update_navigation)

    def tf_callback(self, msg, robot_index):
        position = msg.transforms[0].transform.translation
        self.current_robot_positions[robot_index] = (position.x, position.y)

    def update_navigation(self):
        for i in range(self.num_robots):
            if self.current_target_indices[i] < len(self.target_positions[i]):
                current_pos = self.current_robot_positions[i]
                target_pos = self.target_positions[i][self.current_target_indices[i]]
                if self.is_target_reached(current_pos, target_pos):
                    self.get_logger().info(f'Robot {i+1}: Target {self.current_target_indices[i]+1} reached: {target_pos}.')
                    self.current_target_indices[i] += 1
                    self.publish_current_target(i)
                else:
                    self.publish_current_target(i)

    def is_target_reached(self, current_pos, target_pos):
        return math.sqrt((current_pos[0] - target_pos[0]) ** 2 + (current_pos[1] - target_pos[1]) ** 2) <= self.reach_threshold

    def publish_current_target(self, robot_index):
        if self.current_target_indices[robot_index] < len(self.target_positions[robot_index]):
            target = self.target_positions[robot_index][self.current_target_indices[robot_index]]
            msg = Float64MultiArray()
            # Ensure the target is a flat list of floats
            msg.data = [float(coord) for coord in target]
            self.robot_publishers[robot_index].publish(msg)
            self.get_logger().info(f'Robot {robot_index + 1}: Publishing target position {target}.')
        else:
            # Optionally handle the case where all targets have been published
            self.get_logger().info(f'Robot {robot_index + 1}: All targets have been reached.')


def main(args=None):
    rclpy.init(args=args)
    navigator = RobotNavigator()
    rclpy.spin(navigator)
    navigator.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
