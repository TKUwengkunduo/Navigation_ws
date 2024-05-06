import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from tf2_msgs.msg import TFMessage
from std_msgs.msg import Float64MultiArray
import math
import numpy as np

class RobotController(Node):
    def __init__(self):
        super().__init__('robot_controller')
        
        # Explicitly handle robot_id as a string parameter
        self.declare_parameter('robot_id', '01')
        robot_id = self.get_parameter('robot_id').get_parameter_value().string_value

        # Format topic strings to include the robot ID, ensuring it handles leading zeros
        tf_topic = f'/transporter{robot_id}/tf'
        target_topic = f'/transporter{robot_id}/target_position'
        cmd_vel_topic = f'/transporter{robot_id}/cmd_vel'

        # Subscriptions and publisher using robot-specific topics
        self.subscription_tf = self.create_subscription(TFMessage, tf_topic, self.tf_callback, 10)
        self.subscription_target = self.create_subscription(Float64MultiArray, target_topic, self.target_callback, 10)
        self.publisher_ = self.create_publisher(Twist, cmd_vel_topic, 10)

        self.current_target = None
        self.last_position_x = 0.0
        self.last_position_y = 0.0
        self.last_orientation = (0.0, 0.0, 0.0, 1.0)  # Quaternion

        # Control parameters
        self.max_speed = 2.2
        self.min_speed = 0.05
        self.max_rotation_speed = math.pi / 2
        self.reach_threshold = 2.5
        self.deceleration_distance = 2.4

    def target_callback(self, msg):
        self.current_target = (msg.data[0], msg.data[1])
        self.get_logger().info(f'New target received: {self.current_target}')
        self.navigate_to_target()  # Trigger navigation immediately upon receiving a new target


    def tf_callback(self, msg):
        # Update the robot's current position and orientation
        current_position = msg.transforms[0].transform.translation
        current_orientation = msg.transforms[0].transform.rotation
        self.last_position_x = current_position.x
        self.last_position_y = current_position.y
        self.last_orientation = (current_orientation.x, current_orientation.y, current_orientation.z, current_orientation.w)
        
        if self.current_target:
            self.navigate_to_target()

    def navigate_to_target(self):
        current_x, current_y = self.last_position_x, self.last_position_y
        target_x, target_y = self.current_target
        dx = target_x - current_x
        dy = target_y - current_y
        # distance = math.sqrt(dx**2 + dy**2)

        # if distance < self.reach_threshold:
        #     self.stop_robot()
        #     return

        desired_theta = math.atan2(dy, dx)
        current_orientation = self.get_current_orientation()
        angle_difference = (desired_theta - current_orientation + math.pi) % (2 * math.pi) - math.pi

        # if distance < self.deceleration_distance:
        #     speed = max((distance / self.deceleration_distance) * self.max_speed, self.min_speed)
        # else:
        #     speed = self.max_speed

        angular_speed = np.clip(angle_difference * 2, -self.max_rotation_speed, self.max_rotation_speed)
        self.publish_velocity(self.max_speed, angular_speed)

    def get_current_orientation(self):
        # Calculate yaw from the quaternion
        x, y, z, w = self.last_orientation
        t3 = +2.0 * (w * z + x * y)
        t4 = +1.0 - 2.0 * (y * y + z * z)
        yaw = math.atan2(t3, t4)
        return yaw

    def publish_velocity(self, linear, angular):
        velocity_msg = Twist()
        velocity_msg.linear.x = float(linear)
        velocity_msg.angular.z = float(angular)
        self.publisher_.publish(velocity_msg)

    def stop_robot(self):
        self.publish_velocity(0, 0)
        self.get_logger().info("Target reached and robot has been stopped.")

def main(args=None):
    rclpy.init(args=args)
    controller = RobotController()
    rclpy.spin(controller)
    controller.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()