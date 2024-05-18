import gymnasium as gym
from gymnasium import spaces
import numpy as np
import networkx as nx
import random

class GPPEnv(gym.Env):
    metadata = {'render.modes': ['human']}

    def __init__(self):
        super(GPPEnv, self).__init__()
        self.grid_width = 3
        self.grid_height = 7
        self.num_robots = 10
        self.k_paths = 3
        self.max_length = 12

        self.step_count = 0
        self.max_steps = 5

        self.G, self.labels = self.create_grid_graph()
        self.positions = nx.get_node_attributes(self.G, 'pos')
        self.robot_paths = {}
        self.chosen_paths = {}

        # Use Box space to represent actions in the range [0, k_paths - 1]
        self.action_space = spaces.Box(low=0, high=self.k_paths - 1, shape=(self.num_robots,), dtype=np.float32)
        self.observation_space = spaces.Box(low=0, high=21, shape=(self.num_robots * self.k_paths * self.max_length,), dtype=np.int32)

    def reset(self, seed=None, options=None):
        super().reset(seed=seed)
        if seed is not None:
            np.random.seed(seed)
            random.seed(seed)
        self.step_count = 0
        self.initialize_robot_paths()
        self.convert_paths_with_padding()
        return self.get_obs().astype(np.int32), {}

    def step(self, action):
        self.step_count += 1
        done = self.step_count >= self.max_steps
        truncated = False

        # Convert continuous actions to discrete actions
        action = np.round(action).astype(int)
        action = np.clip(action, 0, self.k_paths - 1)

        standard_action = [0] * len(action)
        self.chosen_path(standard_action)
        collisions = self.detect_collisions()
        standard_path_lengths, standard_collisions = self.report_results(collisions)

        self.chosen_path(action)
        collisions = self.detect_collisions()
        all_path_lengths, total_collisions = self.report_results(collisions)
        reward = float(standard_collisions - total_collisions)
        
        return self.get_obs().astype(np.int32), reward, done, truncated, {}

    def render(self, mode='human'):
        self.display_converted_paths()

    def create_grid_graph(self):
        G = nx.grid_2d_graph(self.grid_height, self.grid_width)
        labels = {node: i + 1 for i, node in enumerate(G.nodes())}
        nx.set_node_attributes(G, {node: node for node in G.nodes()}, 'pos')
        nx.set_edge_attributes(G, 1, 'weight')
        return G, labels

    def initialize_robot_paths(self):
        self.robot_positions = [(random.choice(list(self.G.nodes())), random.choice(list(self.G.nodes())))
                                for _ in range(self.num_robots)]
        self.find_paths()

    def find_paths(self):
        for i, (start, end) in enumerate(self.robot_positions, 1):
            paths = []

            shortest_path = nx.shortest_path(self.G, start, end, weight='weight')
            paths.append(shortest_path)

            x_first_path = [(x, start[1]) for x in range(start[0], end[0], (1 if end[0] > start[0] else -1))]
            x_first_path.extend([(end[0], y) for y in range(start[1], end[1] + (1 if end[1] > start[1] else -1), (1 if end[1] > start[1] else -1))])
            paths.append(x_first_path)

            y_first_path = [(start[0], y) for y in range(start[1], end[1], (1 if end[1] > start[1] else -1))]
            y_first_path.extend([(x, end[1]) for x in range(start[0], end[0] + (1 if end[0] > start[0] else -1), (1 if end[0] > start[0] else -1))])
            paths.append(y_first_path)

            labeled_paths = [[self.labels[node] for node in path if node in self.labels] for path in paths]
            self.robot_paths[f'Robot {i}'] = labeled_paths

    def convert_paths_with_padding(self):
        for robot, paths in self.robot_paths.items():
            self.robot_paths[robot] = [path + [0] * (self.max_length - len(path)) for path in paths]

    def get_obs(self):
        all_paths = [path for paths in self.robot_paths.values() for path in paths]
        flat_paths = [node for path in all_paths for node in path]
        return np.array(flat_paths)

    def chosen_path(self, choose_num):
        for i, robot in enumerate(self.robot_paths, 1):
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
                if path[i] == 0:
                    length = 0
                    time = -1
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
        path_lengths = {}
        all_path_lengths = 0
        for robot, path in self.chosen_paths.items():
            try:
                index = path.index(0)
                real_path = path[:index]
            except ValueError:
                real_path = path

            total_length = 0
            for i in range(len(real_path) - 1):
                if abs(real_path[i+1] - real_path[i]) == 1:
                    total_length += 6
                else:
                    total_length += 3
            path_lengths[robot] = total_length
            all_path_lengths += total_length
 
        total_collisions = len(collisions)
        return all_path_lengths, total_collisions
