"""
	========================= Before ========================
	action =  [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
     
	Robot 1's path : [21, 18, 15, 12, 11, 10, 7, 4, 1, 0, 0, 0]
	Robot 2's path : [1, 4, 7, 8, 9, 12, 0, 0, 0, 0, 0, 0]
	Robot 3's path : [21, 18, 15, 12, 0, 0, 0, 0, 0, 0, 0, 0]
	Robot 4's path : [5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
	Robot 5's path : [5, 8, 9, 12, 15, 18, 21, 0, 0, 0, 0, 0]
	Robot 6's path : [6, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
	Robot 7's path : [13, 10, 7, 4, 5, 2, 0, 0, 0, 0, 0, 0]
	Robot 8's path : [14, 11, 8, 5, 2, 0, 0, 0, 0, 0, 0, 0]
	Robot 9's path : [16, 13, 10, 7, 8, 5, 0, 0, 0, 0, 0, 0]
	Robot 10's path : [7, 4, 5, 6, 0, 0, 0, 0, 0, 0, 0, 0]


	Details of Collisions:
	# At time 0, at position 21, collision involved: Robot 1, Robot 3
	# At time 0, at position 5, collision involved: Robot 4, Robot 5
	At time 3, at position 18, collision involved: Robot 1, Robot 3
	At time 3, at position 4, collision involved: Robot 2, Robot 10
	At time 6, at position 15, collision involved: Robot 1, Robot 3
	At time 6, at position 7, collision involved: Robot 2, Robot 7
	At time 9, at position 12, collision involved: Robot 1, Robot 3
	At time 9, at position 5, collision involved: Robot 8, Robot 10
	# All path lengths: 147, Total collisions: 8
    All path lengths: 147, Total collisions: 6
     

	========================= After =========================
	action =  [2, 1, 0, 2, 1, 0, 2, 0, 1, 1]
     
	Robot 1's path : [21, 20, 19, 16, 13, 10, 7, 4, 1, 0, 0, 0]
	Robot 2's path : [1, 4, 7, 10, 11, 12, 0, 0, 0, 0, 0, 0]
	Robot 3's path : [21, 18, 15, 12, 0, 0, 0, 0, 0, 0, 0, 0]
	Robot 4's path : [5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
	Robot 5's path : [5, 8, 11, 14, 17, 20, 21, 0, 0, 0, 0, 0]
	Robot 6's path : [6, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
	Robot 7's path : [13, 14, 11, 8, 5, 2, 0, 0, 0, 0, 0, 0]
	Robot 8's path : [14, 11, 8, 5, 2, 0, 0, 0, 0, 0, 0, 0]
	Robot 9's path : [16, 13, 10, 7, 4, 5, 0, 0, 0, 0, 0, 0]
	Robot 10's path : [7, 4, 5, 6, 0, 0, 0, 0, 0, 0, 0, 0]

	Details of Collisions:
	# At time 0, at position 21, collision involved: Robot 1, Robot 3
	# At time 0, at position 5, collision involved: Robot 4, Robot 5
	At time 3, at position 4, collision involved: Robot 2, Robot 10
	At time 9, at position 5, collision involved: Robot 8, Robot 10
	# All path lengths: 147, Total collisions: 4
    All path lengths: 147, Total collisions: 2
     
"""



"""
	========================= Before ========================
	action =  [0, 0, 0, 0, 0]
	Robot 1's path : [20, 19, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0]
	Robot 2's path : [8, 9, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0]
	Robot 3's path : [14, 11, 12, 9, 6, 0, 0, 0, 0, 0, 0, 0]
	Robot 4's path : [5, 8, 7, 10, 13, 16, 0, 0, 0, 0, 0, 0]
	Robot 5's path : [3, 6, 9, 12, 15, 14, 13, 16, 0, 0, 0, 0]

	Details of Collisions:
	At time 6, at position 9, collision involved: Robot 2, Robot 5
	At time 9, at position 12, collision involved: Robot 3, Robot 5
	All path lengths: 78, Total collisions: 2
     
	========================= After =========================
	action =  [0, 0, 1, 1, 2]
	Robot 1's path : [20, 19, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0]
	Robot 2's path : [8, 9, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0]
	Robot 3's path : [14, 11, 8, 5, 6, 0, 0, 0, 0, 0, 0, 0]
	Robot 4's path : [5, 8, 11, 14, 17, 16, 0, 0, 0, 0, 0, 0]
	Robot 5's path : [3, 2, 1, 4, 7, 10, 13, 16, 0, 0, 0, 0]
     
	No collisions detected.
	All path lengths: 78, Total collisions: 0
"""


import networkx as nx


topology_map = ((( -8.0, -4.0, 0.0), ( -8.0,-12.0, 0.0), ( -8.0,-20.0, 0.0), ( -8.0,-28.0, 0.0), ( -8.0,-36.0, 0.0), ( -8.0,-44.0, 0.0), ( -8.0,-52.0, 0.0)),
                ((-20.0, -4.0, 0.0), (-20.0,-12.0, 0.0), (-20.0,-20.0, 0.0), (-20.0,-28.0, 0.0), (-20.0,-36.0, 0.0), (-20.0,-44.0, 0.0), (-20.0,-52.0, 0.0)),
                ((-32.0, -4.0, 0.0), (-32.0,-12.0, 0.0), (-32.0,-20.0, 0.0), (-32.0,-28.0, 0.0), (-32.0,-36.0, 0.0), (-32.0,-44.0, 0.0), (-32.0,-52.0, 0.0))  )


def create_grid_graph(grid_height, grid_width):
        G = nx.grid_2d_graph(grid_height, grid_width)
        labels = {node: i + 1 for i, node in enumerate(G.nodes())}  # 生成標籤
        nx.set_node_attributes(G, {node: node for node in G.nodes()}, 'pos')
        nx.set_edge_attributes(G, 1, 'weight')
        return G, labels


G, labels = create_grid_graph(7, 3)

# 創建反向查找字典：從標籤到座標
labels_to_pos = {label: pos for pos, label in labels.items()}

# 函式：座標到標籤的轉換
def pos_to_label(position):
    if position in labels:
        return labels[position]
    else:
        return None

# 函式：標籤到座標的轉換
def label_to_pos(label):
    if label in labels_to_pos:
        return topology_map[labels_to_pos[label][1]][labels_to_pos[label][0]]
    else:
        return None

# 示例使用
position = (1, 0)
label = pos_to_label(position)
print("座標 {} 對應的標籤是：{}".format(position, label))

label_position = 20
position = label_to_pos(label_position)
print("標籤 {} 對應的座標是：{}".format(label_position, position))

