import rclpy
from rclpy.node import Node
from navigation_interfaces.srv import PathService

class GPPService(Node):
    def __init__(self):
        super().__init__('gpp_service')
        self.srv = self.create_service(PathService, 'GPP/validate_path', self.handle_service)

    def handle_service(self, request, response):
        response.confirmation = "OK"
        self.get_logger().info(f"Received path: {request.paths}")
        return response

def main(args=None):
    rclpy.init(args=args)
    node = GPPService()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
