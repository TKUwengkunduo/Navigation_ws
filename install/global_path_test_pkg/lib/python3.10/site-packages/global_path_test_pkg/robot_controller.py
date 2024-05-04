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
        self.subscription_tf = self.create_subscription(TFMessage, '/transporter01/tf', self.tf_callback, 10)
        self.subscription_target = self.create_subscription(Float64MultiArray, '/target_position', self.target_callback, 10)
        self.publisher_ = self.create_publisher(Twist, '/transporter01/cmd_vel', 10)
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
