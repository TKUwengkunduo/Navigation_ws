import tensorflow as tf
import matplotlib.pyplot as plt
import numpy as np
import seaborn as sns

# 啟用即時執行模式
tf.compat.v1.enable_eager_execution()

# 設定 TFRecord 文件的路徑
log_dir = './runs/Apr28_08-02-31_weng-home/events.out.tfevents.1714291351.weng-home.763734.0'

# 初始化資料結構
data = {
    # 'Parameters/Entropy Coef': [],
    # 'Training/Average Entropy': [],
    'Training/Total Reward': []
    # 'Training/Average Reward': [],
    # 'Loss/Value': [],
    # 'Loss/Policy': [],
    # 'Parameters/Clip Param': []
}

steps = {
    # 'Parameters/Entropy Coef': [],
    # 'Training/Average Entropy': [],
    'Training/Total Reward': []
    # 'Training/Average Reward': [],
    # 'Loss/Value': [],
    # 'Loss/Policy': [],
    # 'Parameters/Clip Param': []
}

# 讀取 TFRecord 文件
for summary in tf.compat.v1.train.summary_iterator(log_dir):
    for value in summary.summary.value:
        if value.tag in data and summary.step <= 9700:
            steps[value.tag].append(summary.step)
            data[value.tag].append(value.simple_value)

# 定義平滑函數
def smooth(values, weight=0.998):
    smoothed_values = []
    last = values[0]
    for value in values:
        smoothed_value = last * weight + (1 - weight) * value
        smoothed_values.append(smoothed_value)
        last = smoothed_value
    return smoothed_values

# 設定 Seaborn 主題
sns.set(style="whitegrid")

# 繪製圖表
def plot_data(tag):
    plt.figure(figsize=(12, 6))
    smoothed_values = smooth(data[tag])
    plt.plot(steps[tag], smoothed_values, label=tag, color='b', linewidth=2)
    plt.fill_between(steps[tag], smoothed_values, alpha=0.1, color='b')
    plt.xlabel('Step', fontsize=14, fontweight='bold')
    plt.ylabel('Value', fontsize=14, fontweight='bold')
    plt.title('Total Reward', fontsize=16, fontweight='bold')
    plt.legend()
    plt.xlim([0, 9700])
    plt.xticks(np.arange(0, 9701, step=1000))  # 增加 x 軸網格密度
    plt.grid(True, linestyle='--', alpha=0.6, which='both')
    plt.minorticks_on()  # 打開次要網格線
    plt.show()

# 繪製每個參數的圖表
for tag in data:
    plot_data(tag)
