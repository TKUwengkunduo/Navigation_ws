import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64MultiArray
from tf2_msgs.msg import TFMessage
import math

class RobotNavigator(Node):
    def __init__(self):
        super().__init__('robot_navigator')
        self.subscription = self.create_subscription(TFMessage, '/transporter01/tf', self.tf_callback, 10)
        self.publisher_ = self.create_publisher(Float64MultiArray, '/target_position', 10)
        self.target_positions = [
            (-32.0, -44.0), (-32.0, -36.0), (-32.0, -28.0), (-20.0, -28.0),
            (-8.0, -28.0), (-8.0, -20.0), (-8.0, -12.0), (-8.0, -4.0)
        ]
        self.current_target_index = 0
        self.reach_threshold = 2.0  # Threshold to determine if the target is reached
        self.current_robot_position = (0.0, 0.0)  # Initialize robot's current position

    def tf_callback(self, msg):
        # Update robot's current position
        current_position = msg.transforms[0].transform.translation
        self.current_robot_position = (current_position.x, current_position.y)

        # Check if there are still targets to handle
        if self.current_target_index < len(self.target_positions):
            target = self.target_positions[self.current_target_index]
            # Check if the current target is reached
            if self.is_target_reached(self.current_robot_position, target):
                self.get_logger().info(f'Target {self.current_target_index + 1} reached: {target}. Moving to next target.')
                self.current_target_index += 1  # Move to the next target
                if self.current_target_index < len(self.target_positions):
                    # Publish next target if available
                    self.publish_current_target()
                else:
                    self.get_logger().info('All targets have been published. No more targets to process.')
            else:
                # Continuously publish current target if not reached
                self.publish_current_target()
        else:
            self.get_logger().info('No more targets to publish.')

    def is_target_reached(self, current_pos, target_pos):
        """Check if the current position is within the reach threshold of the target position."""
        distance = math.sqrt((current_pos[0] - target_pos[0]) ** 2 + (current_pos[1] - target_pos[1]) ** 2)
        return distance <= self.reach_threshold

    def publish_current_target(self):
        """Publish the current target position to the /target_position topic."""
        if self.current_target_index < len(self.target_positions):
            current_target = Float64MultiArray()
            current_target.data = self.target_positions[self.current_target_index]
            self.publisher_.publish(current_target)
            self.get_logger().info(f'Continuously publishing current target position {current_target.data} to /target_position.')

def main(args=None):
    rclpy.init(args=args)
    navigator = RobotNavigator()
    rclpy.spin(navigator)
    navigator.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
