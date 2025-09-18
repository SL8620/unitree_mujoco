from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os


def generate_launch_description():
    pkg_share = get_package_share_directory("robot_driver_pkg")

    # 配置文件路径（机器人模型、地形、仿真参数）
    default_model = os.path.join(pkg_share, "models", "bruce_mj.xml")
    default_terrain = os.path.join(pkg_share, "models", "scene.xml")
    default_params = os.path.join(pkg_share, "models", "mujoco_params.yaml")

    model_arg = DeclareLaunchArgument(
        "robot_model", default_value=default_model, description="Path to MuJoCo robot model XML"
    )

    terrain_arg = DeclareLaunchArgument(
        "terrain", default_value=default_terrain, description="Path to MuJoCo terrain XML"
    )

    params_arg = DeclareLaunchArgument(
        "params_file", default_value=default_params, description="YAML config file for MuJoCo node"
    )

    mujoco_node = Node(
        package="robot_driver_pkg",
        executable="mujoco_sim_node",
        name="mujoco_sim_node",
        output="screen",
        parameters=[LaunchConfiguration("params_file")],
        arguments=[
            "--robot_model", LaunchConfiguration("robot_model"),
            "--terrain", LaunchConfiguration("terrain"),
        ],
    )

    return LaunchDescription([
        model_arg,
        terrain_arg,
        params_arg,
        mujoco_node
    ])