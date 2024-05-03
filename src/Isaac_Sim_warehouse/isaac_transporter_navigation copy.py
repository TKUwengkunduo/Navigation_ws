# 導入必要的模組
import sys
import carb
import numpy as np
from omni.isaac.kit import SimulationApp

# 路徑和配置變量的定義
TRANSPORTER_PATH = "/World/transporter"
TRANSPORTER_USD_PATH = "/navigation/transporter.usd"
BACKGROUND_STAGE_PATH = "/World"
BACKGROUND_USD_PATH = "/navigation/World.usd"
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



def create_transporters():
    # 車輛的位置和方向列表
    positions = [np.array([10, 0, 0]), np.array([20, 0, 0]), np.array([30, 0, 0])]
    orientations = [np.array([0, 0, 0, 1]), np.array([0, 0, 0, 1]), np.array([0, 0, 0, 1])]
    names = ["transporter1", "transporter2", "transporter3"]

    # 循环创建每一台车，并为每台车创建独立的 prim_path
    for name, position, orientation in zip(names, positions, orientations):
        individual_path = f"/World/{name}"  # 每台车有不同的路径
        # 为每台车添加USD文件的引用到其路径
        stage.add_reference_to_stage(assets_root_path + TRANSPORTER_USD_PATH, individual_path)
        XFormPrim(prim_path=individual_path, name=name, position=position, orientation=orientation)



def setting_ros_transporter(name):
    # 設置目標物體並更新ROS2節點
    set_target_prims(primPath="/World/Robot_Controller/articulation_controller", targetPrimPaths=[TRANSPORTER_PATH])
    set_target_prims(primPath="/World/UWB/ros2_publish_transform_tree", targetPrimPaths=[BACKGROUND_ENV_PATH], inputName="inputs:parentPrim")
    set_target_prims(primPath="/World/UWB/ros2_publish_transform_tree", targetPrimPaths=[TRANSPORTER_PATH + "/lift"], inputName="inputs:targetPrims")
    set_target_prims(primPath="/World/Robot_Camera/isaac_create_render_product", targetPrimPaths=[TRANSPORTER_PATH + "/lift/Camera"], inputName="inputs:cameraPrim")






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
stage.add_reference_to_stage(assets_root_path + TRANSPORTER_USD_PATH, BACKGROUND_STAGE_PATH)


create_transporters()

# 創建和配置場景中的物體
# XFormPrim(prim_path=TRANSPORTER_PATH, name="transporter", position=np.array([-36.0, -52.0, 0.0]), orientation=np.array([1.0, 0.0, 0.0, 0.0]))
XFormPrim(prim_path=MALE_PATH, name="male_adult_construction", position=np.array([-23.94327, -51.92124, 0.0]), orientation=np.array([1.0, 0.0, 0.0, 0.0]))
XFormPrim(prim_path=FEMALE_PATH, name="F_Business", position=np.array([-19.59921, -51.71445, 0.0]), orientation=np.array([1.0, 0.0, 0.0, 0.0]))

# 加載動作圖
stage.add_reference_to_stage(assets_root_path + UWB_ACTIONGRAPH_PATH, BACKGROUND_STAGE_PATH)
stage.add_reference_to_stage(assets_root_path + ROBOT_CAMERA_ACTIONGRAPH_PATH, BACKGROUND_STAGE_PATH)
stage.add_reference_to_stage(assets_root_path + ROBOT_CONTROLLER_ACTIONGRAPH_PATH, BACKGROUND_STAGE_PATH)
stage.add_reference_to_stage(assets_root_path + PEOPLE_ACTIONGRAPH_PATH, BACKGROUND_STAGE_PATH)

# 更新應用程式狀態
simulation_app.update()

# 設置目標物體並更新ROS2節點
setting_ros_transporter(1)
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
