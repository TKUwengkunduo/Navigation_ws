# 導入必要的模組
import sys
import carb
import numpy as np
from omni.isaac.kit import SimulationApp

# 路徑和配置變量的定義
TRANSPORTER_PATH = "/World/transporter1"
TRANSPORTER_USD_PATH = "/navigation/transporter.usd"
BACKGROUND_STAGE_PATH = "/World"
# BACKGROUND_USD_PATH = "/navigation/World.usd"
BACKGROUND_USD_PATH = "/navigation/warehouse_6x3.usd"
BACKGROUND_ENV_PATH = "/World/World"
CONFIG = {"renderer": "RayTracedLighting", "headless": False}
MALE_USD_PATH = "/navigation/male_adult_construction_05_new.usd"
MALE_PATH = "/World/male_adult_construction_05_new"
FEMALE_USD_PATH = "/navigation/F_Business_02.usd"
FEMALE_PATH = "/World/F_Business_02"
UWB_ACTIONGRAPH_PATH = "/navigation/UWB.usd"
ROBOT_CONTROLLER_ACTIONGRAPH_PATH = "/navigation/Robot_Controller.usd"
ROBOT_CAMERA_ACTIONGRAPH_PATH = "/navigation/Robot_Camera.usd"
PEOPLE_ACTIONGRAPH_PATH = "/navigation/people.usd"

# 初始化模擬應用程式
simulation_app = SimulationApp(CONFIG)
import omni.graph.core as og
from omni.isaac.core import SimulationContext
from omni.isaac.core.utils import extensions, prims, stage, xforms, viewports
from omni.isaac.core_nodes.scripts.utils import set_target_prims
from pxr import Gf
from omni.isaac.core.prims.xform_prim import XFormPrim




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
labels_to_pos = {label: pos for pos, label in labels.items()}


def pos_to_label(position):
    if position in labels:
        return labels[position]
    else:
        return None

def label_to_pos(label):
    if label in labels_to_pos:
        return topology_map[labels_to_pos[label][1]][labels_to_pos[label][0]]
    else:
        return None
    



import math
def euler_to_quaternion_2d(theta):
    """
        Convert a rotation given by an angle theta in 2D to a quaternion around the Z-axis.
        
        Args:
        theta (float): The rotation angle in radians.
        
        Returns:
        tuple: A tuple representing the quaternion (qw, qx, qy, qz).

                            N 0度(0,1) 
                            | (1,0,0,0)
                            |
        270度(-1,0)  W------o------E 90度(1,0)
        (-0.707,0,0,-0.707) |        (0.707,0,0,-0.707)
                            |
                            S 180度(0,-1)
                            (0,0,0,-1)
    """
    # Calculate the quaternion components
    qw = math.cos(theta / 2)
    qz = math.sin(theta / 2)  # Only z-component since rotation is around z-axis

    if theta==0:
        qw = 1.0
        qz = 0.0
    elif theta==90:
        qw = 0.707
        qz = -0.707
    elif theta==180:
        qw = 0.0
        qz = -1.0
    else:
        qw = -0.707
        qz = -0.707
    
    return [qw, 0.0, 0.0, qz]



def create_transporter(name, position, orientation):
    transporter_path = f"/World/{name}"
    stage.add_reference_to_stage(assets_root_path + TRANSPORTER_USD_PATH, transporter_path)
    XFormPrim(prim_path=transporter_path, name=name, position=np.array(position), orientation=np.array(orientation))

    # 加載動作圖
    # stage.add_reference_to_stage(assets_root_path + UWB_ACTIONGRAPH_PATH, transporter_path)
    # stage.add_reference_to_stage(assets_root_path + ROBOT_CAMERA_ACTIONGRAPH_PATH, transporter_path)
    # stage.add_reference_to_stage(assets_root_path + ROBOT_CONTROLLER_ACTIONGRAPH_PATH, transporter_path)

    

def setting_transporter_graph(name):
    transporter_path = f"/World/{name}/transporter"
    # set_target_prims(primPath="/World/" + name + "/Robot_Controller/articulation_controller", targetPrimPaths=[transporter_path])
    # set_target_prims(primPath="/World/" + name + "/UWB/ros2_publish_transform_tree", targetPrimPaths=[BACKGROUND_ENV_PATH], inputName="inputs:parentPrim")
    # set_target_prims(primPath="/World/" + name + "/UWB/ros2_publish_transform_tree", targetPrimPaths=[transporter_path + "/lift"], inputName="inputs:targetPrims")
    # set_target_prims(primPath="/World/" + name + "/Robot_Camera/isaac_create_render_product", targetPrimPaths=[transporter_path + "/lift/Camera"], inputName="inputs:cameraPrim")
    # set_target_prims(primPath="/World/" + name + "/Robot_Camera/ros2_camera_helper", targetPrimPaths=name+"_rgb", inputName="inputs:topicName")

    try:
        """ ========================================= Camera ========================================= """
        # og.Controller.edit(
        #     {"graph_path": "/World/"+name+"/Robot_Camera", "evaluator_name": "execution",},
        #     {
        #         og.Controller.Keys.CREATE_NODES: [
        #             ("on_playback_tick", "omni.graph.action.OnPlaybackTick"),
        #             ("ros2_context", "omni.isaac.ros2_bridge.ROS2Context"),
        #             ("isaac_create_render_product", "omni.isaac.core_nodes.IsaacCreateRenderProduct"),
        #             ("ros2_camera_helper", "omni.isaac.ros2_bridge.ROS2CameraHelper"),

        #         ],
        #         og.Controller.Keys.CONNECT: [
        #             ("on_playback_tick.outputs:tick", "isaac_create_render_product.inputs:execIn"),
        #             ("ros2_context.outputs:context", "ros2_camera_helper.inputs:context"),
        #             ("isaac_create_render_product.outputs:execOut", "ros2_camera_helper.inputs:execIn"),
        #             ("isaac_create_render_product.outputs:renderProductPath", "ros2_camera_helper.inputs:renderProductPath"),
        #         ],
        #         og.Controller.Keys.SET_VALUES: [
        #             ("isaac_create_render_product.inputs:cameraPrim", transporter_path + "/lift/Camera"),
        #             ("ros2_context.inputs:domain_id", 89),
        #             ("ros2_context.inputs:useDomainIDEnvVar", True),
        #             ("isaac_create_render_product.inputs:enabled", True),
        #             ("ros2_camera_helper.inputs:enabled", True),
        #             ("ros2_camera_helper.inputs:frameId", "sim_camera"),
        #             ("ros2_camera_helper.inputs:semanticLabelsTopicName", "semantic_labels"),
        #             ("ros2_camera_helper.inputs:renderProductPath", "/Render/RenderProduct_Isaac"),
        #             ("ros2_camera_helper.inputs:topicName", name+"/rgb"),
        #         ],
        #     },
        # )

        """ ========================================= UWB ========================================= """
        og.Controller.edit(
            {"graph_path": "/World/"+name+"/UWB", "evaluator_name": "execution"},
            {
                og.Controller.Keys.CREATE_NODES: [
                    ("on_playback_tick", "omni.graph.action.OnPlaybackTick"),
                    ("ros2_context", "omni.isaac.ros2_bridge.ROS2Context"),
                    ("ros2_publish_transform_free", "omni.isaac.ros2_bridge.ROS2PublishTransformTree"),
                    ("isaac_read_simulation_time", "omni.isaac.core_nodes.IsaacReadSimulationTime"),
                ],
                og.Controller.Keys.CONNECT: [
                    ("on_playback_tick.outputs:tick", "ros2_publish_transform_free.inputs:execIn"),
                    ("ros2_context.outputs:context", "ros2_publish_transform_free.inputs:context"),
                    (
                        "isaac_read_simulation_time.outputs:simulationTime",
                        "ros2_publish_transform_free.inputs:timeStamp",
                    ),
                ],
                og.Controller.Keys.SET_VALUES: [
                    ("ros2_context.inputs:domain_id", 89),
                    ("ros2_context.inputs:useDomainIDEnvVar", True),
                    ("ros2_publish_transform_free.inputs:parentPrim", BACKGROUND_ENV_PATH),
                    ("ros2_publish_transform_free.inputs:targetPrims", transporter_path + "/lift"),
                    ("ros2_publish_transform_free.inputs:topicName", name+"/tf"),
                ],
            },
        )

        """ ==================================== Robot_Controller ==================================== """
        og.Controller.edit(
            {"graph_path": "/World/"+name+"/Robot_Controller", "evaluator_name": "execution"},
            {
                og.Controller.Keys.CREATE_NODES: [
                    ("on_playback_tick", "omni.graph.action.OnPlaybackTick"),
                    ("ros2_context", "omni.isaac.ros2_bridge.ROS2Context"),
                    ("ros2_subscribe_twist", "omni.isaac.ros2_bridge.ROS2SubscribeTwist"),
                    ("scale_to_from_stage_units", "omni.isaac.core_nodes.OgnIsaacScaleToFromStageUnit"),
                    ("break_3_vector", "omni.graph.nodes.BreakVector3"),
                    ("break_3_vector_01", "omni.graph.nodes.BreakVector3"),
                    ("articulation_controller", "omni.isaac.core_nodes.IsaacArticulationController"),
                    ("differential_controller", "omni.isaac.wheeled_robots.DifferentialController"),

                ],
                og.Controller.Keys.CONNECT: [
                    ("on_playback_tick.outputs:tick", "ros2_subscribe_twist.inputs:execIn"),
                    ("on_playback_tick.outputs:tick", "articulation_controller.inputs:execIn"),
                    ("ros2_context.outputs:context", "ros2_subscribe_twist.inputs:context"),
                    ("ros2_subscribe_twist.outputs:execOut", "differential_controller.inputs:execIn"),
                    ("ros2_subscribe_twist.outputs:angularVelocity", "break_3_vector.inputs:tuple"),
                    ("ros2_subscribe_twist.outputs:linearVelocity", "scale_to_from_stage_units.inputs:value"),
                    ("scale_to_from_stage_units.outputs:result", "break_3_vector_01.inputs:tuple"),
                    ("break_3_vector_01.outputs:x", "differential_controller.inputs:linearVelocity"),
                    ("break_3_vector.outputs:z", "differential_controller.inputs:angularVelocity"),
                    ("differential_controller.outputs:velocityCommand", "articulation_controller.inputs:velocityCommand"),
                ],
                og.Controller.Keys.SET_VALUES: [
                    ("ros2_context.inputs:domain_id", 89),
                    ("ros2_context.inputs:useDomainIDEnvVar", True),
                    ("differential_controller.inputs:maxLinearSpeed", 2.2),
                    ("differential_controller.inputs:wheelDistance", 0.57926),
                    ("differential_controller.inputs:wheelRadius", 0.08),

                    ("articulation_controller.inputs:targetPrim", transporter_path),
                    ("articulation_controller.inputs:usePath", False),
                    ("articulation_controller.inputs:jointNames", ["left_wheel_joint", "right_wheel_joint"]),
                    ("ros2_subscribe_twist.inputs:topicName", name+"/cmd_vel"),

                ],
            }
        )
    except Exception as error:
        print(error)









if __name__ == "__main__":
    
    # 啟用ROS2橋接擴展
    extensions.enable_extension("omni.isaac.ros2_bridge")

    # 創建模擬上下文並設置場景單位
    simulation_context = SimulationContext(stage_units_in_meters=1.0)

    # 檢查資產路徑並準備關閉應用程式的條件
    assets_root_path = "omniverse://localhost/"
    if assets_root_path is None:
        carb.log_error("Could not find Isaac Sim assets folder")
        simulation_app.close()
        sys.exit()

    # 設置視角和加載環境場景
    viewports.set_camera_view(eye=np.array([-17.36425, -14.21905, 3.88039]), target=np.array([-8.69287, 5.65996, 0]))
    stage.add_reference_to_stage(assets_root_path + BACKGROUND_USD_PATH, BACKGROUND_STAGE_PATH)
    # stage.add_reference_to_stage(assets_root_path + TRANSPORTER_USD_PATH, BACKGROUND_STAGE_PATH)
    stage.add_reference_to_stage(assets_root_path + MALE_USD_PATH, BACKGROUND_STAGE_PATH)
    stage.add_reference_to_stage(assets_root_path + FEMALE_USD_PATH, BACKGROUND_STAGE_PATH)
    # stage.add_reference_to_stage(assets_root_path + TRANSPORTER_USD_PATH, BACKGROUND_STAGE_PATH)


    create_transporter("transporter1", label_to_pos(21), euler_to_quaternion_2d(270))
    create_transporter("transporter2", label_to_pos(1), euler_to_quaternion_2d(90))
    create_transporter("transporter3", [-32.0, -54.0, 0.0], euler_to_quaternion_2d(270))
    create_transporter("transporter4", [-16.33, -14.57, 0.0], euler_to_quaternion_2d(0))
    create_transporter("transporter5", label_to_pos(5), euler_to_quaternion_2d(90))
    create_transporter("transporter6", label_to_pos(6), euler_to_quaternion_2d(270))
    create_transporter("transporter7", label_to_pos(13), euler_to_quaternion_2d(270))
    create_transporter("transporter8", label_to_pos(14), euler_to_quaternion_2d(270))
    create_transporter("transporter9", label_to_pos(16), euler_to_quaternion_2d(270))
    create_transporter("transporter10", label_to_pos(7), euler_to_quaternion_2d(270))

    # 創建和配置場景中的物體
    # XFormPrim(prim_path=TRANSPORTER_PATH, name="transporter", position=np.array([-36.0, -52.0, 0.0]), orientation=np.array([1.0, 0.0, 0.0, 0.0]))
    XFormPrim(prim_path=MALE_PATH, name="male_adult_construction", position=np.array([-23.94327, -51.92124, 0.0]), orientation=np.array([1.0, 0.0, 0.0, 0.0]))
    XFormPrim(prim_path=FEMALE_PATH, name="F_Business", position=np.array([-19.59921, -51.71445, 0.0]), orientation=np.array([1.0, 0.0, 0.0, 0.0]))

    # 加載動作圖
    # stage.add_reference_to_stage(assets_root_path + UWB_ACTIONGRAPH_PATH, BACKGROUND_STAGE_PATH)
    # stage.add_reference_to_stage(assets_root_path + ROBOT_CAMERA_ACTIONGRAPH_PATH, BACKGROUND_STAGE_PATH)
    # stage.add_reference_to_stage(assets_root_path + ROBOT_CONTROLLER_ACTIONGRAPH_PATH, BACKGROUND_STAGE_PATH)
    stage.add_reference_to_stage(assets_root_path + PEOPLE_ACTIONGRAPH_PATH, BACKGROUND_STAGE_PATH)

    # 更新應用程式狀態
    simulation_app.update()

    # 設置目標物體並更新ROS2節點
    setting_transporter_graph("transporter1")
    setting_transporter_graph("transporter2")
    setting_transporter_graph("transporter3")
    setting_transporter_graph("transporter4")
    setting_transporter_graph("transporter5")
    setting_transporter_graph("transporter6")
    setting_transporter_graph("transporter7")
    setting_transporter_graph("transporter8")
    setting_transporter_graph("transporter9")
    setting_transporter_graph("transporter10")

    set_target_prims(primPath="/World/people/ros2_publish_transform_tree", targetPrimPaths=[BACKGROUND_ENV_PATH], inputName="inputs:parentPrim")
    set_target_prims(primPath="/World/people/ros2_publish_transform_tree", targetPrimPaths=[FEMALE_PATH + "/female_adult_business_02"], inputName="inputs:targetPrims")



    # 再次更新應用程式狀態
    simulation_app.update()


    # 初始化物理引擎並啟動模擬
    simulation_context.initialize_physics()
    simulation_context.play()

    # 模擬運行時的循環
    while simulation_app.is_running():
        simulation_context.step(render=True)

    # 停止模擬並關閉應用程式
    simulation_context.stop()
    simulation_app.close()