import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import json

class RobotNavigator(Node):
    def __init__(self):
        super().__init__('robot_navigator')
        # Publishers for each robot controller
        self.robot_targets_publishers = {
            'robot1': self.create_publisher(String, '/robot1/target', 10),
            'robot2': self.create_publisher(String, '/robot2/target', 10)
        }
        # Subscribers for feedback from each robot controller
        self.robot_feedback_subscribers = {
            'robot1': self.create_subscription(String, '/robot1/feedback', self.feedback_callback, 10),
            'robot2': self.create_subscription(String, '/robot2/feedback', self.feedback_callback, 10)
        }
        # Targets defined for each robot
        self.targets = {
            'robot1': [(-32.0, -44.0), (-32.0, -36.0), (-32.0, -28.0), (-20.0, -28.0), (-8.0, -28.0), (-8.0, -20.0), (-8.0, -12.0), (-8.0, -4.0)],
            'robot2': [(-32.0, -44.0), (-32.0, -36.0), (-32.0, -28.0), (-20.0, -28.0), (-8.0, -28.0), (-8.0, -20.0), (-8.0, -12.0), (-8.0, -4.0)]
        }
        self.current_targets = {
            'robot1': 0,
            'robot2': 0
        }

    def feedback_callback(self, msg):
        data = json.loads(msg.data)
        robot_id = data['robot_id']
        if self.current_targets[robot_id] < len(self.targets[robot_id]):
            self.current_targets[robot_id] += 1
            self.send_next_target(robot_id)

    def send_next_target(self, robot_id):
        if self.current_targets[robot_id] < len(self.targets[robot_id]):
            target = self.targets[robot_id][self.current_targets[robot_id]]
            msg = String()
            msg.data = json.dumps({'target': target})
            self.robot_targets_publishers[robot_id].publish(msg)
        else:
            self.get_logger().info(f'{robot_id} has reached all its targets.')

def main(args=None):
    rclpy.init(args=args)
    navigator = RobotNavigator()
    rclpy.spin(navigator)
    navigator.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
