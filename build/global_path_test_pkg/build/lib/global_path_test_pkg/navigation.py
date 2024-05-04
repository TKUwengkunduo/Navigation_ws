"""
	========================= Before ========================
	action =  [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
     
	Robot 1's path : [21, 18, 15, 12, 11, 10, 7, 4, 1, 0, 0, 0]
	Robot 2's path : [1, 4, 7, 8, 9, 12, 0, 0, 0, 0, 0, 0]
	Robot 3's path : [21, 18, 15, 12, 0, 0, 0, 0, 0, 0, 0, 0]
	Robot 4's path : [5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
	Robot 5's path : [5, 8, 9, 12, 15, 18, 21, 0, 0, 0, 0, 0]
	Robot 6's path : [6, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
	Robot 7's path : [13, 10, 7, 4, 5, 2, 0, 0, 0, 0, 0, 0]
	Robot 8's path : [14, 11, 8, 5, 2, 0, 0, 0, 0, 0, 0, 0]
	Robot 9's path : [16, 13, 10, 7, 8, 5, 0, 0, 0, 0, 0, 0]
	Robot 10's path : [7, 4, 5, 6, 0, 0, 0, 0, 0, 0, 0, 0]


	Details of Collisions:
	# At time 0, at position 21, collision involved: Robot 1, Robot 3
	# At time 0, at position 5, collision involved: Robot 4, Robot 5
	At time 3, at position 18, collision involved: Robot 1, Robot 3
	At time 3, at position 4, collision involved: Robot 2, Robot 10
	At time 6, at position 15, collision involved: Robot 1, Robot 3
	At time 6, at position 7, collision involved: Robot 2, Robot 7
	At time 9, at position 12, collision involved: Robot 1, Robot 3
	At time 9, at position 5, collision involved: Robot 8, Robot 10
	# All path lengths: 147, Total collisions: 8
    All path lengths: 147, Total collisions: 6
     

	========================= After =========================
	action =  [2, 1, 0, 2, 1, 0, 2, 0, 1, 1]
     
	Robot 1's path : [21, 20, 19, 16, 13, 10, 7, 4, 1, 0, 0, 0]
	Robot 2's path : [1, 4, 7, 10, 11, 12, 0, 0, 0, 0, 0, 0]
	Robot 3's path : [21, 18, 15, 12, 0, 0, 0, 0, 0, 0, 0, 0]
	Robot 4's path : [5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
	Robot 5's path : [5, 8, 11, 14, 17, 20, 21, 0, 0, 0, 0, 0]
	Robot 6's path : [6, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
	Robot 7's path : [13, 14, 11, 8, 5, 2, 0, 0, 0, 0, 0, 0]
	Robot 8's path : [14, 11, 8, 5, 2, 0, 0, 0, 0, 0, 0, 0]
	Robot 9's path : [16, 13, 10, 7, 4, 5, 0, 0, 0, 0, 0, 0]
	Robot 10's path : [7, 4, 5, 6, 0, 0, 0, 0, 0, 0, 0, 0]

	Details of Collisions:
	# At time 0, at position 21, collision involved: Robot 1, Robot 3
	# At time 0, at position 5, collision involved: Robot 4, Robot 5
	At time 3, at position 4, collision involved: Robot 2, Robot 10
	At time 9, at position 5, collision involved: Robot 8, Robot 10
	# All path lengths: 147, Total collisions: 4
    All path lengths: 147, Total collisions: 2
     
"""



"""
	========================= Before ========================
	action =  [0, 0, 0, 0, 0]
	Robot 1's path : [20, 19, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0]
	Robot 2's path : [8, 9, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0]
	Robot 3's path : [14, 11, 12, 9, 6, 0, 0, 0, 0, 0, 0, 0]
	Robot 4's path : [5, 8, 7, 10, 13, 16, 0, 0, 0, 0, 0, 0]
	Robot 5's path : [3, 6, 9, 12, 15, 14, 13, 16, 0, 0, 0, 0]

	Details of Collisions:
	At time 6, at position 9, collision involved: Robot 2, Robot 5
	At time 9, at position 12, collision involved: Robot 3, Robot 5
	All path lengths: 78, Total collisions: 2
     
	========================= After =========================
	action =  [0, 0, 1, 1, 2]
	Robot 1's path : [20, 19, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0]
	Robot 2's path : [8, 9, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0]
	Robot 3's path : [14, 11, 8, 5, 6, 0, 0, 0, 0, 0, 0, 0]
	Robot 4's path : [5, 8, 11, 14, 17, 16, 0, 0, 0, 0, 0, 0]
	Robot 5's path : [3, 2, 1, 4, 7, 10, 13, 16, 0, 0, 0, 0]
     
	No collisions detected.
	All path lengths: 78, Total collisions: 0
"""
"""
	========================= Before ========================
	action =  [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
     
	Robot 1's path : [21, 18, 15, 12, 11, 10, 7, 4, 1, 0, 0, 0]
	Robot 2's path : [1, 4, 7, 8, 9, 12, 0, 0, 0, 0, 0, 0]
	Robot 3's path : [21, 18, 15, 12, 0, 0, 0, 0, 0, 0, 0, 0]
	Robot 4's path : [5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
	Robot 5's path : [5, 8, 9, 12, 15, 18, 21, 0, 0, 0, 0, 0]
	Robot 6's path : [6, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
	Robot 7's path : [13, 10, 7, 4, 5, 2, 0, 0, 0, 0, 0, 0]
	Robot 8's path : [14, 11, 8, 5, 2, 0, 0, 0, 0, 0, 0, 0]
	Robot 9's path : [16, 13, 10, 7, 8, 5, 0, 0, 0, 0, 0, 0]
	Robot 10's path : [7, 4, 5, 6, 0, 0, 0, 0, 0, 0, 0, 0]


	Details of Collisions:
	# At time 0, at position 21, collision involved: Robot 1, Robot 3
	# At time 0, at position 5, collision involved: Robot 4, Robot 5
	At time 3, at position 18, collision involved: Robot 1, Robot 3
	At time 3, at position 4, collision involved: Robot 2, Robot 10
	At time 6, at position 15, collision involved: Robot 1, Robot 3
	At time 6, at position 7, collision involved: Robot 2, Robot 7
	At time 9, at position 12, collision involved: Robot 1, Robot 3
	At time 9, at position 5, collision involved: Robot 8, Robot 10
	# All path lengths: 147, Total collisions: 8
    All path lengths: 147, Total collisions: 6
     

	========================= After =========================
	action =  [2, 1, 0, 2, 1, 0, 2, 0, 1, 1]
     
	Robot 1's path : [21, 20, 19, 16, 13, 10, 7, 4, 1, 0, 0, 0]
	Robot 2's path : [1, 4, 7, 10, 11, 12, 0, 0, 0, 0, 0, 0]
	Robot 3's path : [21, 18, 15, 12, 0, 0, 0, 0, 0, 0, 0, 0]
	Robot 4's path : [5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
	Robot 5's path : [5, 8, 11, 14, 17, 20, 21, 0, 0, 0, 0, 0]
	Robot 6's path : [6, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
	Robot 7's path : [13, 14, 11, 8, 5, 2, 0, 0, 0, 0, 0, 0]
	Robot 8's path : [14, 11, 8, 5, 2, 0, 0, 0, 0, 0, 0, 0]
	Robot 9's path : [16, 13, 10, 7, 4, 5, 0, 0, 0, 0, 0, 0]
	Robot 10's path : [7, 4, 5, 6, 0, 0, 0, 0, 0, 0, 0, 0]

	Details of Collisions:
	# At time 0, at position 21, collision involved: Robot 1, Robot 3
	# At time 0, at position 5, collision involved: Robot 4, Robot 5
	At time 3, at position 4, collision involved: Robot 2, Robot 10
	At time 9, at position 5, collision involved: Robot 8, Robot 10
	# All path lengths: 147, Total collisions: 4
    All path lengths: 147, Total collisions: 2
     
"""



"""
	========================= Before ========================
	action =  [0, 0, 0, 0, 0]
	Robot 1's path : [20, 19, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0]
	Robot 2's path : [8, 9, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0]
	Robot 3's path : [14, 11, 12, 9, 6, 0, 0, 0, 0, 0, 0, 0]
	Robot 4's path : [5, 8, 7, 10, 13, 16, 0, 0, 0, 0, 0, 0]
	Robot 5's path : [3, 6, 9, 12, 15, 14, 13, 16, 0, 0, 0, 0]

	Details of Collisions:
	At time 6, at position 9, collision involved: Robot 2, Robot 5
	At time 9, at position 12, collision involved: Robot 3, Robot 5
	All path lengths: 78, Total collisions: 2
     
	========================= After =========================
	action =  [0, 0, 1, 1, 2]
	Robot 1's path : [20, 19, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0]
	Robot 2's path : [8, 9, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0]
	Robot 3's path : [14, 11, 8, 5, 6, 0, 0, 0, 0, 0, 0, 0]
	Robot 4's path : [5, 8, 11, 14, 17, 16, 0, 0, 0, 0, 0, 0]
	Robot 5's path : [3, 2, 1, 4, 7, 10, 13, 16, 0, 0, 0, 0]
     
	No collisions detected.
	All path lengths: 78, Total collisions: 0
"""
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from tf2_msgs.msg import TFMessage
import math
import numpy as np

class RobotNavigator(Node):
    def __init__(self):
        super().__init__('robot_navigator')
        # 訂閱ROS主題以獲取機器人的當前位置和方向資訊
        self.subscription = self.create_subscription(TFMessage, '/transporter01/tf', self.tf_callback, 10)
        # 發布器，用於向機器人發送速度命令
        self.publisher_ = self.create_publisher(Twist, '/transporter01/cmd_vel', 10)
        # 預定的目標位置
        self.target_positions = [
            (-32.0, -44.0, 0.0), (-32.0, -36.0, 0.0),
            (-32.0, -28.0, 0.0), (-20.0, -28.0, 0.0), (-8.0, -28.0, 0.0),
            (-8.0, -20.0, 0.0), (-8.0, -12.0, 0.0), (-8.0, -4.0, 0.0)
        ]
        
        self.current_target_index = 0                   # 目前目標的索引
        self.reach_threshold = 2.5                      # 達到目標的距離閾值
        self.turning_threshold = math.pi / 6            # 轉彎的角度閾值
        self.obstacles = []                             # 障礙物列表，靜態障礙物
        self.safety_distance = 1.0                      # 安全距離設置
        self.max_speed = 2.2                            # 最大速度設置
        self.deceleration_distance = 2.4                # 減速距離
        self.min_speed_during_deceleration = 0.05       # 減速時的最小速度
        self.max_rotation_speed = math.pi / 4.0         # 最大旋轉速度
        self.last_orientation = (0.0, 0.0, 0.0, 1.0)    # 最後一次的方向四元數
        # 最後一次的位置
        self.last_position_x = 0.0
        self.last_position_y = 0.0

    def tf_callback(self, msg):
        # 當收到tf消息時更新機器人的位置和方向
        current_position = msg.transforms[0].transform.translation
        current_orientation = msg.transforms[0].transform.rotation
        self.last_position_x = current_position.x
        self.last_position_y = current_position.y
        self.last_orientation = (current_orientation.x, current_orientation.y,
                                 current_orientation.z, current_orientation.w)
        self.navigate_to_target(self.last_position_x, self.last_position_y)

    def get_current_orientation(self):
        # 從四元數轉換為歐拉角，返回偏航角
        x, y, z, w = self.last_orientation
        t3 = +2.0 * (w * z + x * y)
        t4 = +1.0 - 2.0 * (y * y + z * z)
        yaw = math.atan2(t3, t4)
        return yaw

    def navigate_to_target(self, current_x, current_y):
        # 導航到目標位置
        if self.current_target_index < len(self.target_positions):
            target_x, target_y, _ = self.target_positions[self.current_target_index]
            dx = target_x - current_x
            dy = target_y - current_y
            distance = math.sqrt(dx**2 + dy**2)

            if distance < self.reach_threshold:
                self.get_logger().info(f'Reached target {self.current_target_index + 1}')
                self.current_target_index += 1
                if self.current_target_index >= len(self.target_positions):
                    self.get_logger().info('All targets reached. Stopping robot.')
                    self.stop_robot()
                    return

            self.advance_to_target(current_x, current_y, target_x, target_y, distance)

    def advance_to_target(self, current_x, current_y, target_x, target_y, distance):
        # 根據目前位置與目標位置計算方向和速度
        desired_theta = math.atan2(target_y - current_y, target_x - current_x)
        current_orientation = self.get_current_orientation()
        angle_difference = (desired_theta - current_orientation + math.pi) % (2 * math.pi) - math.pi

        if distance < self.deceleration_distance:
            velocity = max((distance / self.deceleration_distance) * self.max_speed, self.min_speed_during_deceleration)
        else:
            velocity = self.max_speed

        angular_velocity = np.clip(angle_difference * 2, -self.max_rotation_speed, self.max_rotation_speed)
        self.publish_velocity(velocity, angular_velocity)

    def publish_velocity(self, linear, angular):
        # 發送速度命令
        velocity_msg = Twist()
        velocity_msg.linear.x = float(linear)  # 確保值為浮點型
        velocity_msg.angular.z = float(angular)  # 確保值為浮點型
        self.publisher_.publish(velocity_msg)

    def stop_robot(self):
        # 停止機器人
        self.publish_velocity(0, 0)
        self.get_logger().info("Robot has been stopped.")

def main(args=None):
    rclpy.init(args=args)
    navigator = RobotNavigator()
    rclpy.spin(navigator)
    navigator.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
