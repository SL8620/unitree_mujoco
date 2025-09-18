from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
import os

from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    pkg_share = get_package_share_directory("robot_driver_pkg")

    config_file = os.path.join(pkg_share, "config", "robot_driver.yaml")

    return LaunchDescription([
        DeclareLaunchArgument(
            "config_file",
            default_value=config_file,
            description="YAML config file for robot driver"
        ),

        Node(
            package="robot_driver_pkg",
            executable="controller_node",
            name="controller_node",
            output="screen",
            parameters=[LaunchConfiguration("config_file")]
        )
    ])