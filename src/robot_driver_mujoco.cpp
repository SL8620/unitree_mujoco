#include "robot_driver_pkg/robot_driver.hpp"

namespace robot_driver
{

RobotDriverMujoco::RobotDriverMujoco() {}
RobotDriverMujoco::~RobotDriverMujoco() {}

bool RobotDriverMujoco::init(rclcpp::Node::SharedPtr node)
{
  RCLCPP_INFO(node->get_logger(), "Mujoco driver initialized");
  return true;
}

void RobotDriverMujoco::sendMotorCommands(const robot_msgs::msg::MotorCommandArray & msg)
{
  (void)msg;  // TODO: 实际发送逻辑
}

void RobotDriverMujoco::readImu(sensor_msgs::msg::Imu & msg)
{
  msg.header.stamp = rclcpp::Clock().now();
  msg.header.frame_id = "imu_link";
  // TODO: 从仿真中读取数据
}

}  // namespace robot_driver