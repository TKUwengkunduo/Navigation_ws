import argparse
import gymnasium as gym
import yaml
from stable_baselines3 import PPO, A2C, DDPG, SAC, TD3, DQN
from stable_baselines3.common.env_checker import check_env
from GPP_environment import GPPEnv

log_dir = "./log"

def get_model(algorithm, env, config):
    if algorithm == 'PPO':
        return PPO(
            "MlpPolicy",
            env,
            verbose=1,
            n_steps=config['n_steps'],
            batch_size=config['batch_size'],
            learning_rate=config['learning_rate'],
            gamma=config['gamma'],
            ent_coef=config['ent_coef'],
            clip_range=config['clip_range'],
            n_epochs=config['n_epochs'],
            gae_lambda=config['gae_lambda'],
            max_grad_norm=config['max_grad_norm'],
            vf_coef=config['vf_coef'],
            device=config['device'],
            tensorboard_log=log_dir,
        )
    elif algorithm == 'A2C':
        return A2C(
            "MlpPolicy",
            env,
            verbose=1,
            n_steps=config['n_steps'],
            learning_rate=config['learning_rate'],
            gamma=config['gamma'],
            gae_lambda=config['gae_lambda'],
            ent_coef=config['ent_coef'],
            vf_coef=config['vf_coef'],
            max_grad_norm=config['max_grad_norm'],
            device=config['device'],
            tensorboard_log=log_dir,
        )
    elif algorithm == 'DDPG':
        return DDPG(
            "MlpPolicy",
            env,
            verbose=1,
            learning_rate=config['learning_rate'],
            buffer_size=config['buffer_size'],
            learning_starts=config['learning_starts'],
            batch_size=config['batch_size'],
            tau=config['tau'],
            gamma=config['gamma'],
            train_freq=config['train_freq'],
            gradient_steps=config['gradient_steps'],
            action_noise=None,
            optimize_memory_usage=config['optimize_memory_usage'],
            tensorboard_log=log_dir,
            device=config['device'],
        )
    elif algorithm == 'SAC':
        return SAC(
            "MlpPolicy",
            env,
            verbose=1,
            learning_rate=config['learning_rate'],
            buffer_size=config['buffer_size'],
            learning_starts=config['learning_starts'],
            batch_size=config['batch_size'],
            tau=config['tau'],
            gamma=config['gamma'],
            train_freq=config['train_freq'],
            gradient_steps=config['gradient_steps'],
            action_noise=None,
            tensorboard_log=log_dir,
            device=config['device'],
        )
    elif algorithm == 'TD3':
        return TD3(
            "MlpPolicy",
            env,
            verbose=1,
            learning_rate=config['learning_rate'],
            buffer_size=config['buffer_size'],
            learning_starts=config['learning_starts'],
            batch_size=config['batch_size'],
            tau=config['tau'],
            gamma=config['gamma'],
            train_freq=config['train_freq'],
            gradient_steps=config['gradient_steps'],
            action_noise=None,
            tensorboard_log=log_dir,
            device=config['device'],
        )
    elif algorithm == 'DQN':
        if not isinstance(env.action_space, gym.spaces.Discrete):
            raise ValueError("DQN only supports discrete action spaces.")
        return DQN(
            "MlpPolicy",
            env,
            verbose=1,
            learning_rate=config['learning_rate'],
            buffer_size=config['buffer_size'],
            learning_starts=config['learning_starts'],
            batch_size=config['batch_size'],
            gamma=config['gamma'],
            train_freq=config['train_freq'],
            gradient_steps=config['gradient_steps'],
            target_update_interval=config['target_update_interval'],
            exploration_fraction=config['exploration_fraction'],
            exploration_final_eps=config['exploration_final_eps'],
            tensorboard_log=log_dir,
            device=config['device'],
        )
    else:
        raise ValueError(f"Unknown algorithm: {algorithm}")

def main():
    parser = argparse.ArgumentParser(description="Choose a reinforcement learning algorithm.")
    parser.add_argument("--algorithm", type=str, required=True, choices=['PPO', 'A2C', 'DDPG', 'SAC', 'TD3', 'DQN'],
                        help="The algorithm to use for training.")
    parser.add_argument("--config", type=str, required=True, help="Path to the YAML configuration file.")
    args = parser.parse_args()

    with open(args.config, 'r') as file:
        config = yaml.safe_load(file)

    env = GPPEnv()

    # Check the environment
    check_env(env)

    # Create the model
    try:
        model = get_model(args.algorithm, env, config)
    except ValueError as e:
        print(e)
        return

    # Train the model
    model.learn(total_timesteps=config['total_timesteps'])

    # Save the model
    model.save(f"{args.algorithm.lower()}_gpp")

    # Load the model
    model = model.__class__.load(f"{args.algorithm.lower()}_gpp")

    # Test the model
    obs, _ = env.reset()
    
    # Print 30 pre-selected paths for each robot
    print("30 pre-selected paths for each robot:")
    for robot, paths in env.robot_paths.items():
        print(f"{robot} pre-selected paths:")
        for path in paths:
            print(path)

    # Get the selected paths by the model
    selected_paths = []
    for _ in range(5):
        action, _states = model.predict(obs)
        obs, rewards, done, truncated, info = env.step(action)
        selected_paths.append(env.chosen_paths.copy())
        if done:
            break

    # Print the selected paths
    print("Selected paths by the model:")
    for i, paths in enumerate(selected_paths):
        print(f"Step {i+1}:")
        for robot, path in paths.items():
            print(f"{robot}: {path}")
        print()

    env.render()

if __name__ == "__main__":
    main()
