import torch
import torch.nn as nn
import matplotlib.patches as patches
from torch.distributions import Categorical


class Actor(nn.Module):
    def __init__(self, input_dim, num_robots, k_paths):
        super(Actor, self).__init__()
        self.num_robots = num_robots
        self.k_paths = k_paths
        self.network = nn.Sequential(
            nn.Linear(input_dim, 256),
            nn.LeakyReLU(),
            nn.LayerNorm(256),

            nn.Linear(256, 128),
            nn.LeakyReLU(),
            nn.LayerNorm(128),

            nn.Linear(128, num_robots * k_paths)
        )
    
    def forward(self, state):
        logits = self.network(state)
        logits = logits.view(-1, self.num_robots, self.k_paths)
        dists = [Categorical(logits=logits[0][i]) for i in range(self.num_robots)]
        return dists, torch.stack([dist.entropy() for dist in dists]).mean()  # Return entropy as well


class Critic(nn.Module):
    def __init__(self, input_dim):
        super(Critic, self).__init__()
        self.network = nn.Sequential(
            nn.Linear(input_dim, 256),
            nn.LeakyReLU(),
            nn.LayerNorm(256),

            nn.Linear(256, 128),
            nn.LeakyReLU(),
            nn.LayerNorm(128),

            nn.Linear(128, 1)
        )
    
    def forward(self, state):
        return self.network(state)
