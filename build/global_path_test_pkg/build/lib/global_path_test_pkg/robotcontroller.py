import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist, Point
from std_msgs.msg import Bool, Float64MultiArray
import numpy as np

class RobotController(Node):
    def __init__(self):
        super().__init__('robot_controller')
        self.publisher_ = self.create_publisher(Twist, 'cmd_vel', 10)
        self.target_subscriber = self.create_subscription(Point, 'target_position', self.target_callback, 10)
        self.obstacle_subscriber = self.create_subscription(Float64MultiArray, 'obstacle_data', self.obstacle_callback, 10)
        self.ack_publisher = self.create_publisher(Bool, 'target_reached', 10)
        self.current_target = None
        self.obstacles = None

    def target_callback(self, msg):
        self.current_target = np.array([msg.x, msg.y])
        self.navigate_to_target()

    def obstacle_callback(self, msg):
        self.obstacles = np.array(msg.data).reshape(-1, 2)  # Assuming each obstacle is represented by (x, y)
        self.navigate_to_target()

    def navigate_to_target(self):
        if self.current_target is None or self.obstacles is None:
            return

        # Dummy navigation logic (replace with actual logic)
        arrived = self.dummy_navigation_logic(self.current_target, self.obstacles)
        if arrived:
            self.ack_publisher.publish(Bool(data=True))
            self.get_logger().info("Target reached, waiting for the next target.")

    def dummy_navigation_logic(self, target, obstacles):
        # Implement navigation logic here
        # For simplicity, we just pretend we've reached the target
        return True

def main(args=None):
    rclpy.init(args=args)
    robot_controller = RobotController()
    rclpy.spin(robot_controller)
    robot_controller.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
