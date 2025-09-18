#include "robot_driver_pkg/robot_driver.hpp"

namespace robot_driver
{

RobotDriverROSHW::RobotDriverROSHW() {}
RobotDriverROSHW::~RobotDriverROSHW() {}

bool RobotDriverROSHW::init(rclcpp::Node::SharedPtr node)
{
  RCLCPP_INFO(node->get_logger(), "Hardware driver initialized");
  return true;
}

void RobotDriverROSHW::sendMotorCommands(const robot_msgs::msg::MotorCommandArray & msg)
{
  (void)msg;  // TODO: 实际硬件通信
}

void RobotDriverROSHW::readImu(sensor_msgs::msg::Imu & msg)
{
  msg.header.stamp = rclcpp::Clock().now();
  msg.header.frame_id = "imu_link";
  // TODO: 从硬件读取数据
}

}  // namespace robot_driver