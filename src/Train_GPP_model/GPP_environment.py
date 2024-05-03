import random
import networkx as nx

class RobotPathSimulator:
    def __init__(self, width, height, max_length, num_robots, k_paths):
        self.grid_width = width
        self.grid_height = height
        self.num_robots = num_robots
        self.k_paths = k_paths
        self.G, self.labels = self.create_grid_graph()
        self.positions = nx.get_node_attributes(self.G, 'pos')
        self.robot_paths = {}
        self.chosen_paths = {}
        self.max_length = max_length  # 定義每條路徑的最大長度

    def reset(self):
        self.initialize_robot_paths()
        self.convert_paths_with_padding()  # 確保所有路徑都先轉換和填充
        return self.get_obs()

    def get_obs(self):
        all_paths = [path for paths in self.robot_paths.values() for path in paths]
        # 展平 all_paths 以形成單一長度的列表
        flat_paths = [node for path in all_paths for node in path]
        return flat_paths


    def step(self, action):
        done = 0

        standard_action = [0]*len(action)
        self.chosen_path(standard_action)
        collisions = self.detect_collisions()
        standard_path_lengths, standard_collisions = self.report_results(collisions)

        self.chosen_path(action)
        collisions = self.detect_collisions()
        All_path_lengths, Total_collisions = self.report_results(collisions)
        # reward = Total_collisions*-1.0
        reward = float(standard_collisions - Total_collisions)
        # reward = ( ((100-All_path_lengths)/100)*0.3+((5-Total_collisions)/5)*0.7 ) / 2 * 100 / 16

        return self.get_obs(), reward, done, {}


    def render(self):
        self.display_converted_paths()
        # collisions = self.detect_collisions()
        # self.report_results(collisions)

    def create_grid_graph(self):
        G = nx.grid_2d_graph(self.grid_height, self.grid_width)
        labels = {node: i + 1 for i, node in enumerate(G.nodes())}  # 生成標籤
        nx.set_node_attributes(G, {node: node for node in G.nodes()}, 'pos')
        nx.set_edge_attributes(G, 1, 'weight')
        return G, labels

    def initialize_robot_paths(self):
        self.robot_positions = [(random.choice(list(self.G.nodes())), random.choice(list(self.G.nodes())))
                                for _ in range(self.num_robots)]
        self.find_paths()

    # def find_paths(self):
    #     for i, (start, end) in enumerate(self.robot_positions, 1):
    #         paths = list(nx.shortest_simple_paths(self.G, start, end, weight='weight'))
    #         limited_paths = paths[:self.k_paths]  # 取前 k_paths 条路径
    #         if len(limited_paths) < self.k_paths:
    #             # 如果路径数量不足 k_paths, 则复制已有路径直至满足数量
    #             limited_paths += [limited_paths[0]] * (self.k_paths - len(limited_paths))
    #         self.robot_paths[f'Robot {i}'] = [[self.labels[node] for node in path] for path in limited_paths]  # 转换路径

    def find_paths(self):
        for i, (start, end) in enumerate(self.robot_positions, 1):
            # Initialize paths list
            paths = []
            
            # 1. Shortest path
            shortest_path = nx.shortest_path(self.G, start, end, weight='weight')
            paths.append(shortest_path)
            
            # 2. Path that moves in X-direction first, then Y-direction
            x_first_path = []
            # Move in x-direction
            x_first_path.extend([(x, start[1]) for x in range(start[0], end[0], (1 if end[0] > start[0] else -1))])
            # Move in y-direction
            x_first_path.extend([(end[0], y) for y in range(start[1], end[1] + (1 if end[1] > start[1] else -1), (1 if end[1] > start[1] else -1))])
            paths.append(x_first_path)
            
            # 3. Path that moves in Y-direction first, then X-direction
            y_first_path = []
            # Move in y-direction
            y_first_path.extend([(start[0], y) for y in range(start[1], end[1], (1 if end[1] > start[1] else -1))])
            # Move in x-direction
            y_first_path.extend([(x, end[1]) for x in range(start[0], end[0] + (1 if end[0] > start[0] else -1), (1 if end[0] > start[0] else -1))])
            paths.append(y_first_path)

            # Convert all paths from node coordinates to labels
            labeled_paths = [[self.labels[node] for node in path if node in self.labels] for path in paths]

            # Store the paths
            self.robot_paths[f'Robot {i}'] = labeled_paths
            # self.labeled_robot_paths[f'Robot {i}'] = labeled_paths


    def convert_paths_with_padding(self):
        for robot, paths in self.robot_paths.items():
            self.robot_paths[robot] = [path + [0] * (self.max_length - len(path)) for path in paths]

    def chosen_path(self, choose_num):
        for i, robot in enumerate(self.robot_paths, 1):
            # Extract integer index from the tensor
            index = choose_num[i-1]
            self.chosen_paths[f'Robot {i}'] = self.robot_paths[robot][index]





    def expand_path(self, path):
        node_timings = []
        total_time = 0
        if len(path) == 1:
            node_timings.append((path[0], 0))
        else:
            time = 0
            for i in range(len(path) - 1):
                if path[i]==0:
                    length = 0
                    time=-1
                elif abs(path[i+1] - path[i]) == 1:
                    length = 6
                else:
                    length = 3
                node_timings.append((path[i], time))
                time += length
            total_time = time

        return node_timings, total_time

    def detect_collisions(self):
        expanded_paths = {robot: self.expand_path(self.chosen_paths[robot])[0] for robot in self.chosen_paths}
        positions = {}
        for robot, path in expanded_paths.items():
            for pos, time in path:
                if time == -1:
                    continue
                if time not in positions:
                    positions[time] = {}
                if pos in positions[time]:
                    positions[time][pos].append(robot)
                else:
                    positions[time][pos] = [robot]
        
        collisions = []
        for time in positions:
            for pos in positions[time]:
                if len(positions[time][pos]) > 1:
                    collisions.append((time, pos, positions[time][pos]))
        
        return collisions

    def display_converted_paths(self):
        for robot, paths in self.robot_paths.items():
            print(f"{robot} possible paths:")
            for idx, path in enumerate(paths):
                print(f"  Path {idx + 1}: {path}")

    def report_results(self, collisions):
        # Calculate path lengths for each robot by processing only up to the first zero in the path
        path_lengths = {}
        All_path_lengths = 0
        for robot, path in self.chosen_paths.items():
            # Find the first index of 0 which signifies the end of the actual path
            try:
                index = path.index(0)
                real_path = path[:index]  # Extract path until the first 0
            except ValueError:
                real_path = path  # If no 0, use the full path

            # Compute the length based on real_path, summing specific lengths
            total_length = 0
            for i in range(len(real_path) - 1):
                if abs(real_path[i+1] - real_path[i]) == 1:
                    total_length += 6
                else:
                    total_length += 3
            path_lengths[robot] = total_length
            All_path_lengths += total_length
 
        # Report the number of collisions
        Total_collisions = len(collisions)

        return All_path_lengths, Total_collisions
    

    def show_results(self, collisions):
        # Calculate path lengths for each robot by processing only up to the first zero in the path
        path_lengths = {}
        All_path_lengths = 0
        for robot, path in self.chosen_paths.items():
            # Find the first index of 0 which signifies the end of the actual path
            try:
                index = path.index(0)
                real_path = path[:index]  # Extract path until the first 0
            except ValueError:
                real_path = path  # If no 0, use the full path

            # Compute the length based on real_path, summing specific lengths
            total_length = 0
            for i in range(len(real_path) - 1):
                if abs(real_path[i+1] - real_path[i]) == 1:
                    total_length += 6
                else:
                    total_length += 3
            path_lengths[robot] = total_length
            All_path_lengths += total_length

        # Report path lengths
        print("\tPath lengths for each robot:")
        for robot, length in path_lengths.items():
            print(f"\t{robot}: {length} units")
 
        # Report the number of collisions
        Total_collisions = len(collisions)
        # print(f"\n\tTotal collisions detected: {Total_collisions}")

        # Detailed collision report
        if collisions:
            print("\n\tDetails of Collisions:")
            for time, pos, robots in collisions:
                print(f"\tAt time {time}, at position {pos}, collision involved: {', '.join(robots)}")
        else:
            print("\n\tNo collisions detected.")

        print(f"\tAll path lengths: {All_path_lengths}, Total collisions: {Total_collisions}")

        return All_path_lengths, Total_collisions