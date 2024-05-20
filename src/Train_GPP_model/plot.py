import matplotlib.pyplot as plt
import numpy as np
from matplotlib.colors import LinearSegmentedColormap

# Define paths for each planning result
paths_plan_1 = {
    1: [8, 11, 10, 13, 16, 19, 0, 0, 0, 0, 0, 0],
    2: [6, 9, 12, 15, 18, 21, 0, 0, 0, 0, 0, 0],
    3: [16, 17, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    4: [15, 18, 17, 16, 19, 0, 0, 0, 0, 0, 0, 0],
    5: [21, 18, 15, 14, 0, 0, 0, 0, 0, 0, 0, 0],
    6: [2, 5, 8, 11, 14, 0, 0, 0, 0, 0, 0, 0],
    7: [12, 9, 6, 3, 0, 0, 0, 0, 0, 0, 0, 0],
    8: [9, 8, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    9: [2, 5, 8, 7, 10, 13, 16, 0, 0, 0, 0, 0],
    10: [12, 11, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0]
}

paths_plan_2 = {
    1: [8, 11, 10, 13, 16, 19, 0, 0, 0, 0, 0, 0],
    2: [6, 9, 12, 15, 18, 21, 0, 0, 0, 0, 0, 0],
    3: [16, 17, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    4: [15, 18, 21, 20, 19, 0, 0, 0, 0, 0, 0, 0],
    5: [21, 20, 17, 14, 0, 0, 0, 0, 0, 0, 0, 0],
    6: [2, 5, 8, 11, 14, 0, 0, 0, 0, 0, 0, 0],
    7: [12, 9, 6, 3, 0, 0, 0, 0, 0, 0, 0, 0],
    8: [9, 8, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    9: [2, 1, 4, 7, 10, 13, 16, 0, 0, 0, 0, 0],
    10: [12, 11, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0]
}

# Define grid size and function to create occupancy grid
def create_occupancy_grid(paths, grid_width, grid_height):
    occupancy_grid = np.zeros((grid_height, grid_width))
    for path in paths.values():
        for position in path:
            if position != 0:
                x = (position - 1) % grid_width
                y = (position - 1) // grid_width
                occupancy_grid[y, x] += 1
    return occupancy_grid

def calculate_statistics(grid):
    flattened_grid = grid.flatten()
    average_occupancy = np.mean(flattened_grid)
    std_dev_occupancy = np.std(flattened_grid)
    return average_occupancy, std_dev_occupancy

grid_width = 7
grid_height = 3

# Create occupancy grids for each plan
occupancy_grid_1 = create_occupancy_grid(paths_plan_1, grid_width, grid_height)
occupancy_grid_2 = create_occupancy_grid(paths_plan_2, grid_width, grid_height)

# Calculate statistics for each grid
average_occupancy_1, std_dev_occupancy_1 = calculate_statistics(occupancy_grid_1)
average_occupancy_2, std_dev_occupancy_2 = calculate_statistics(occupancy_grid_2)

# Custom colormap from green to red
colors = ["green", "lightgreen", "white", "lightcoral", "red"]
cmap = LinearSegmentedColormap.from_list("custom_green_red", colors, N=256)

# Plot the heatmaps
fig, ax = plt.subplots(1, 2, figsize=(14, 6), sharey=True)
heatmap1 = ax[0].imshow(occupancy_grid_1, cmap=cmap, interpolation='nearest')
ax[0].set_title(f'Plan 1: Avg={average_occupancy_1:.2f}, Std Dev={std_dev_occupancy_1:.2f}')
ax[0].invert_yaxis()
heatmap2 = ax[1].imshow(occupancy_grid_2, cmap=cmap, interpolation='nearest')
ax[1].set_title(f'Plan 2: Avg={average_occupancy_2:.2f}, Std Dev={std_dev_occupancy_2:.2f}')
ax[1].invert_yaxis()

# Adding colorbars and labels
fig.colorbar(heatmap1, ax=ax[0], fraction=0.046, pad=0.04)
fig.colorbar(heatmap2, ax=ax[1], fraction=0.046, pad=0.04)
fig.suptitle('Comparison of Robot Occupancy Between Two Plans')
plt.show()
