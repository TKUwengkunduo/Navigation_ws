import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError
import cv2

class ImageSubscriber(Node):
    def __init__(self):
        super().__init__('record')
        self.subscription = self.create_subscription(
            Image,
            '/rgb',
            self.image_callback,
            10)
        self.bridge = CvBridge()
        self.is_recording = False  # Flag to control recording
        self.video_writer = None   # Initialize video writer as None

    def image_callback(self, msg):
        cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        cv2.imshow("Camera Image", cv_image)
        # self.get_logger().info(f'{len(cv_image)}')
        key = cv2.waitKey(1) & 0xFF  # Key capture needs an OpenCV window

        if key == ord('r') and not self.is_recording:
            # Initialize video writer when 'r' is pressed and recording hasn't started
            self.video_writer = cv2.VideoWriter('./output_video.avi', cv2.VideoWriter_fourcc(*'XVID'), 30, (1280, 720))
            # self.video_writer = cv2.VideoWriter('./output_video.avi', cv2.VideoWriter_fourcc(*'MJPG'), 30, (2048, 1080))

            if not self.video_writer.isOpened():
                self.get_logger().error('Failed to open video writer.')
                return
            self.is_recording = True
            self.get_logger().info("Recording started.")

        elif key == ord('q') and self.is_recording:
            # Stop recording when 'q' is pressed
            self.video_writer.release()
            self.is_recording = False
            self.video_writer = None
            self.get_logger().info("Recording stopped.")

        if self.is_recording:
            self.video_writer.write(cv_image)
            self.get_logger().info("Frame written.")

    def destroy_node(self):
        if self.video_writer and self.video_writer.isOpened():
            self.video_writer.release()
        cv2.destroyAllWindows()
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    image_subscriber = ImageSubscriber()
    rclpy.spin(image_subscriber)
    # Explicitly destroy the node
    image_subscriber.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
