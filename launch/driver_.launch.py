from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    joint_names = [
        "joint_1","joint_2","joint_3","joint_4","joint_5","joint_6",
        "joint_7","joint_8","joint_9","joint_10","joint_11","joint_12"
    ]
    return LaunchDescription([
        Node(
            package='robot_driver_pkg',
            executable='mujoco_sim_node',
            name='mujoco_sim_node',
            output='screen',
            parameters=[{"mjcf_path": "/path/to/your/model.mjcf", "timestep": 0.001, "joint_names": joint_names}]
        ),

        Node(
            package='robot_driver_pkg',
            executable='controller_node',
            name='controller_node',
            output='screen',
            parameters=[{"backend":"mujoco", "joint_names": joint_names, "control_rate": 200.0}]
        )
    ])
