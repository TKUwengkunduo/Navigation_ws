
import matplotlib.colors as mcolors
import numpy as np
import torch
import torch.optim as optim
import torch.nn.functional as F
import random

from torch.utils.tensorboard import SummaryWriter

from GPP_environment import RobotPathSimulator
from Model_architecture import Actor, Critic


def set_seed(seed):
    random.seed(seed)
    np.random.seed(seed)
    torch.manual_seed(seed)
    torch.cuda.manual_seed_all(seed)



def ppo_update(ppo_epochs, mini_batch_size, states, actions, log_probs, returns, advantages, actor, critic, actor_optimizer, critic_optimizer, entropy_coef,clip_param=0.2):
    total = states.size(0)
    # print('total = ', total)
    batch_indices = torch.randperm(total)

    for _ in range(ppo_epochs):
        for i in range(0, total, mini_batch_size):
            indices = batch_indices[i:i+mini_batch_size]
            sampled_states = states[indices]
            sampled_actions = actions[indices]
            sampled_log_probs = log_probs[indices]
            sampled_returns = returns[indices]
            sampled_advantages = advantages[indices]

            # Normalize the advantages
            sampled_advantages = (sampled_advantages - sampled_advantages.mean()) / (sampled_advantages.std() + 1e-8)

            # Calculate the current probabilities
            dists, entropies = actor(sampled_states)
            if sampled_actions.dim() > 1:
                action_transpose = sampled_actions.t()  # Use transpose only if dimension is correct
            else:
                action_transpose = sampled_actions.unsqueeze(-1).t()  # Adjust dimensions if needed

            current_log_probs = torch.stack([dist.log_prob(a) for dist, a in zip(dists, action_transpose)], dim=1)

            # Calculate the ratio between new and old probabilities
            ratios = torch.exp(current_log_probs - sampled_log_probs)

            # Calculate Surrogate Loss
            surr1 = ratios * sampled_advantages
            surr2 = torch.clamp(ratios, 1.0 - clip_param, 1.0 + clip_param) * sampled_advantages
            policy_loss = -torch.min(surr1, surr2).mean()- entropy_coef * entropies.mean()

            # Update the actor
            actor_optimizer.zero_grad()
            policy_loss.backward()
            actor_optimizer.step()

            # Calculate value loss
            current_values = critic(sampled_states).squeeze(1)
            value_loss = F.mse_loss(current_values, sampled_returns)

            # Update the critic
            critic_optimizer.zero_grad()
            value_loss.backward()
            critic_optimizer.step()

    return policy_loss.item(), value_loss.item()



def compute_gae(next_value, rewards, masks, values, gamma=0.99, tau=0.95):
    values = values + [next_value]
    gae = 0
    returns = []
    for step in reversed(range(len(rewards))):
        delta = rewards[step] + gamma * values[step + 1] * masks[step] - values[step]
        gae = delta + gamma * tau * masks[step] * gae
        returns.insert(0, gae + values[step])
    return returns

def lambda_schedule(frame_idx):
    if frame_idx < 1000:
        return 1
    elif frame_idx < 10000:
        return 0.1
    else:
        return 0.01


def train():

    set_seed(seed=3)
    max_length = 12
    num_robots = 5
    k_paths = 3

    env = RobotPathSimulator(width=3, height=7, max_length=max_length, num_robots=num_robots, k_paths=k_paths)
    state_dim = max_length * num_robots * k_paths  # Adjusted as per your environment setup

    actor = Actor(state_dim, num_robots=num_robots, k_paths=k_paths)
    critic = Critic(state_dim)
    actor_optimizer = optim.Adam(actor.parameters(), lr=1e-4)
    critic_optimizer = optim.Adam(critic.parameters(), lr=1e-3)

    actor_scheduler = optim.lr_scheduler.LambdaLR(actor_optimizer, lr_lambda=lambda_schedule)
    critic_scheduler = optim.lr_scheduler.LambdaLR(critic_optimizer, lr_lambda=lambda_schedule)


    torch.save(actor.state_dict(), 'model/policy_net_initial.pth')
    torch.save(critic.state_dict(), 'model/value_net_initial.pth')

    # TensorBoard writer
    writer = SummaryWriter()

    max_frames = 1000000
    entropy_coef=0.001
    clip_param = 0.2
    frame_idx = 0
    

    all_rewards = []
    all_collisions = []
    all_lengths = []

    while frame_idx < max_frames:

        state = env.reset()

        # if frame_idx>5000:
        #     entropy_coef *= 0.99

        log_probs = []
        values = []
        states = []
        actions = []
        rewards = []
        masks = []
        entropies = []

        # print("Start of training cycle")

        for _ in range(16):
            state_tensor = torch.FloatTensor(state).view(1, -1)
            dists, entropy = actor(state_tensor)
            value = critic(state_tensor)

            action = [dist.sample() for dist in dists]
            log_prob = [dist.log_prob(a).unsqueeze(0) for dist, a in zip(dists, action)]

            entropies.append(entropy.item())

            next_state, reward, done, _ = env.step([a.item() for a in action])
            rewards.append(reward)
            next_state_tensor = torch.FloatTensor(next_state).unsqueeze(0)
            next_value = critic(next_state_tensor)

            for lp, v, s, a in zip(log_prob, value, state_tensor, action):
                log_probs.append(lp)
                values.append(v)
                states.append(s)
                actions.append(a.unsqueeze(0))

            masks.append(torch.FloatTensor([1 - done]))
            state = next_state
            
            if done:
                state = env.reset()

        frame_idx += 1
        
        actor_scheduler.step(frame_idx)
        critic_scheduler.step(frame_idx)

        total_reward = sum(rewards)
        all_rewards.append(total_reward)
        average_reward = np.mean(all_rewards[-100:])  # Average over the last 100 episodes

        returns = compute_gae(next_value, rewards, masks, values)
        returns = torch.cat(returns).detach()
        log_probs = torch.cat(log_probs).detach()
        values = torch.cat(values).detach()
        states = torch.cat(states).view(-1, state_dim)
        actions = torch.cat(actions)
        average_entropy = np.mean(entropies)
        advantages = returns - values

        policy_loss, value_loss = ppo_update(4, 16, states, actions, log_probs, returns, advantages, actor, critic, actor_optimizer, critic_optimizer, entropy_coef=entropy_coef, clip_param=clip_param)

        print(f"Cycle {frame_idx:<7}: Reward: {total_reward:4.3}, Avg Reward: {average_reward:4.3}, Policy Loss: {policy_loss:4.3}, Value Loss: {value_loss:4.3}")
        
        # Log metrics to TensorBoard
        writer.add_scalar('Training/Total Reward', total_reward, frame_idx)
        writer.add_scalar('Training/Average Reward', average_reward, frame_idx)
        writer.add_scalar('Training/Average Entropy', average_entropy, frame_idx)
        writer.add_scalar('Parameters/Entropy Coef', entropy_coef, frame_idx)
        writer.add_scalar('Parameters/Clip Param', clip_param, frame_idx)
        writer.add_scalar('Loss/Policy', policy_loss, frame_idx)
        writer.add_scalar('Loss/Value', value_loss, frame_idx)

        if frame_idx % 10000 == 0:
            torch.save(actor.state_dict(), f'model/policy_net_epoch_{frame_idx}.pth')
            torch.save(critic.state_dict(), f'model/value_net_epoch_{frame_idx}.pth')
        
    torch.save(actor.state_dict(), 'model/policy_net_final.pth')
    torch.save(critic.state_dict(), 'model/value_net_final.pth')
    writer.close()





import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt



def test_model():

    max_length = 12
    num_robots = 5
    k_paths = 3

    before2after_path_lengths = 0
    before2after_collisions = 0
    original_collisions = 0

    df_All_path_lengths_before = []
    df_Total_collisions_before = []
    df_All_path_lengths_after = []
    df_Total_collisions_after = []
   
    
    state_dim = max_length * num_robots * k_paths  # Adjusted as per your environment setup

    model_path_after = './model/policy_net_epoch_180000.pth'
    actor_after = Actor(state_dim, num_robots=num_robots, k_paths=k_paths)
    loaded_state_dict = torch.load(model_path_after)
    actor_after.load_state_dict(loaded_state_dict)

    # Initialize the test environment
    env = RobotPathSimulator(width=3, height=7, max_length=max_length, num_robots=num_robots, k_paths=k_paths)

    for episode in range(1000):
        state = env.reset()
        state_tensor = torch.FloatTensor(state).view(1, -1)

        print("\t========================= Before ========================")
        
        action = [0]*5

        next_state, reward_before, done, _ = env.step(action)
        print("\taction = ", action)
        all_paths = list(env.robot_paths.values())
        for i in range(len(action)):
            print(f"\tRobot {i+1}'s path : {all_paths[i][action[i]]}")
        collisions = env.detect_collisions()
        All_path_lengths_before, Total_collisions_before = env.show_results(collisions)


        print("\t========================= After =========================")
        dists, entropy = actor_after(state_tensor)
        action = [dist.sample() for dist in dists]
        next_state, reward_after, done, _ = env.step([a.item() for a in action])
        action_list = [a.item() for a in action]
        print("\taction = ", action_list)
        all_paths = list(env.robot_paths.values())
        for i in range(len(action)):
            print(f"\tRobot {i+1}'s path : {all_paths[i][action[i]]}")
        collisions = env.detect_collisions()
        All_path_lengths_after, Total_collisions_after = env.show_results(collisions)

        if All_path_lengths_after-All_path_lengths_before<0:
            before2after_path_lengths += All_path_lengths_after-All_path_lengths_before
        if Total_collisions_after-Total_collisions_before<0:
            before2after_collisions += Total_collisions_after-Total_collisions_before

        original_collisions += All_path_lengths_before
        # before2after_path_lengths += All_path_lengths_after-All_path_lengths_before
        # before2after_collisions += Total_collisions_after-Total_collisions_before

        print(f"Episode {episode+1}, Reward_before: {reward_before:3.3f}, Reward_after: {reward_after:3.3f}")

        df_All_path_lengths_before.append(All_path_lengths_before)
        df_Total_collisions_before.append(Total_collisions_before)
        df_All_path_lengths_after.append(All_path_lengths_after)
        df_Total_collisions_after.append(Total_collisions_after)

    print('before2after_path_lengths', before2after_path_lengths)
    print('before2after_collisions', before2after_collisions)
    print('Collision Reduction Rate = ', (before2after_collisions/original_collisions)*100, '%')

    df = pd.DataFrame({
        'Episode': range(1, 11),
        'All Path Lengths Before': df_All_path_lengths_before,
        'Total Collisions Before': df_Total_collisions_before,
        'All Path Lengths After': df_All_path_lengths_after,
        'Total Collisions After': df_Total_collisions_after
    })

    # Save DataFrame to CSV
    df.to_csv('./simulation_metrics.csv', index=False)
    print("Data has been saved to 'simulation_metrics.csv'")



if __name__ == "__main__":
    # train()
    test_model()