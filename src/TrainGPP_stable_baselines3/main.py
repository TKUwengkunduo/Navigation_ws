import gymnasium as gym
from stable_baselines3 import PPO
from stable_baselines3.common.env_checker import check_env
from GPP_environment import GPPEnv

log_dir = "./log"

env = GPPEnv()

# Check the environment
check_env(env)

# Create the model
model = PPO(
    "MlpPolicy",
    env,
    verbose=1,
    n_steps=20,
    batch_size=64,
    learning_rate=0.000125,
    gamma=0.9,
    ent_coef=7.5e-08,
    clip_range=0.3,
    n_epochs=5,
    gae_lambda=1.0,
    max_grad_norm=0.9,
    vf_coef=0.95,
    device="cuda:0",
    tensorboard_log=log_dir,
)

# Train the model
model.learn(total_timesteps=1000000)

# Save the model
model.save("ppo_gpp")

# Load the model
model = PPO.load("ppo_gpp")

# Test the model
for _ in range(2):  # 進行兩次迴圈，每次迴圈中進行五次 step
    obs, _ = env.reset()
    for _ in range(5):
        action, _states = model.predict(obs)
        obs, rewards, done, truncated, info = env.step(action)
        env.render()
        if done:
            break
