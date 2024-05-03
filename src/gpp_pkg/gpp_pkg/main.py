from .GPP_environment import RobotPathSimulator
from .Model_architecture import Actor, Critic

import rclpy
from rclpy.node import Node
from navigation_interfaces.srv import PathService
import torch
# from example_interfaces.srv import SetBool  # 修改为正确的服务类型，例如您创建的PathService

class GPPClient(Node):
    def __init__(self):
        super().__init__('gpp_client')
        # 创建客户端而不是发布者
        self.client = self.create_client(PathService, '/GPP/validate_path')  # 更改为您定义的服务名称
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Service not available, waiting again...')
        
        self.req = PathService.Request()  # 修改为您定义的请求类型

        # 加载模型和环境
        self.model_path = './install/gpp_pkg/share/gpp_pkg/model/policy_net_initial.pth'
        self.state_dim = 21 * 5 * 10
        self.num_actions_per_robot = 10
        self.num_robots = 5
        self.actor = self.load_model()
        self.env = RobotPathSimulator(width=3, height=7, num_robots=self.num_robots, k_paths=self.num_actions_per_robot)

    def send_request(self):
        self.req.paths = str(self.plan())  # 将计算出的路径设置为请求的数据
        self.future = self.client.call_async(self.req)

    def planning_callback(self):
        self.send_request()
        rclpy.spin_until_future_complete(self, self.future)
        if self.future.result() is not None:
            self.get_logger().info('Received: "%s"' % self.future.result().confirmation)  # 输出服务端的确认信息
        else:
            self.get_logger().error('Service call failed %r' % (self.future.exception(),))
        rclpy.shutdown()

    def load_model(self):
        actor = Actor(self.state_dim, self.num_robots, k_paths=self.num_actions_per_robot)
        loaded_state_dict = torch.load(self.model_path)
        actor.load_state_dict(loaded_state_dict)
        return actor
    
    def plan(self):
        state = self.env.reset()
        state_tensor = torch.FloatTensor(state).view(1, -1)
        dists, entropy = self.actor(state_tensor)
        action = [dist.sample() for dist in dists]
        next_state, reward, done, _ = self.env.step([a.item() for a in action])
        return self.env.chosen_paths

def main(args=None):
    rclpy.init(args=args)
    gpp_client = GPPClient()
    gpp_client.planning_callback()

if __name__ == '__main__':
    main()
