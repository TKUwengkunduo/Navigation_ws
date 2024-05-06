import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64MultiArray
from tf2_msgs.msg import TFMessage
import math

class RobotNavigator(Node):
    def __init__(self):
        super().__init__('robot_navigator')
        # Subscriptions for two robots
        self.subscription_robot1 = self.create_subscription(TFMessage, '/transporter01/tf', self.tf_callback_robot1, 10)
        self.subscription_robot2 = self.create_subscription(TFMessage, '/transporter03/tf', self.tf_callback_robot2, 10)
        
        # Publishers for two robots
        self.publisher_robot1 = self.create_publisher(Float64MultiArray, '/transporter01/target_position', 10)
        self.publisher_robot2 = self.create_publisher(Float64MultiArray, '/transporter03/target_position', 10)
        
        # Target positions, assuming both robots have the same sequence
        self.target_positions = [
            (-32.0, -44.0), (-32.0, -36.0), (-32.0, -28.0), (-20.0, -28.0),
            (-8.0, -28.0), (-8.0, -20.0), (-8.0, -12.0), (-8.0, -4.0)
        ]
        self.current_target_index = [0, 0]  # Separate target indices for each robot
        self.reach_threshold = 2.0
        self.current_robot_position = [(0.0, 0.0), (0.0, 0.0)]  # Separate current positions for each robot

    def tf_callback_robot1(self, msg):
        self.update_position(0, msg)

    def tf_callback_robot2(self, msg):
        self.update_position(1, msg)

    def update_position(self, robot_index, msg):
        current_position = msg.transforms[0].transform.translation
        self.current_robot_position[robot_index] = (current_position.x, current_position.y)

        if self.current_target_index[robot_index] < len(self.target_positions):
            target = self.target_positions[self.current_target_index[robot_index]]
            if self.is_target_reached(self.current_robot_position[robot_index], target):
                self.get_logger().info(f'Robot {robot_index + 1}: Target {self.current_target_index[robot_index] + 1} reached: {target}. Moving to next target.')
                self.current_target_index[robot_index] += 1
                if self.current_target_index[robot_index] < len(self.target_positions):
                    self.publish_current_target(robot_index)
                else:
                    self.get_logger().info(f'Robot {robot_index + 1}: All targets have been published. No more targets to process.')
            else:
                self.publish_current_target(robot_index)
        else:
            self.get_logger().info(f'Robot {robot_index + 1}: No more targets to publish.')

    def is_target_reached(self, current_pos, target_pos):
        distance = math.sqrt((current_pos[0] - target_pos[0]) ** 2 + (current_pos[1] - target_pos[1]) ** 2)
        return distance <= self.reach_threshold

    def publish_current_target(self, robot_index):
        if self.current_target_index[robot_index] < len(self.target_positions):
            current_target = Float64MultiArray()
            current_target.data = self.target_positions[self.current_target_index[robot_index]]
            if robot_index == 0:
                self.publisher_robot1.publish(current_target)
            else:
                self.publisher_robot2.publish(current_target)
            self.get_logger().info(f'Robot {robot_index + 1}: Continuously publishing current target position {current_target.data} to target_position.')

def main(args=None):
    rclpy.init(args=args)
    navigator = RobotNavigator()
    rclpy.spin(navigator)
    navigator.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()