#pragma once

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/imu.hpp>
#include <robot_msgs/msg/motor_command_array.hpp>

namespace robot_driver
{

class RobotDriverBase
{
public:
  virtual ~RobotDriverBase() = default;

  virtual bool init(rclcpp::Node::SharedPtr node) = 0;
  virtual void sendMotorCommands(const robot_msgs::msg::MotorCommandArray & msg) = 0;
  virtual void readImu(sensor_msgs::msg::Imu & msg) = 0;
};

/// ===== Mujoco 驱动 =====
class RobotDriverMujoco : public RobotDriverBase
{
public:
  RobotDriverMujoco();
  ~RobotDriverMujoco() override;

  bool init(rclcpp::Node::SharedPtr node) override;
  void sendMotorCommands(const robot_msgs::msg::MotorCommandArray & msg) override;
  void readImu(sensor_msgs::msg::Imu & msg) override;
};

/// ===== 硬件驱动 =====
class RobotDriverROSHW : public RobotDriverBase
{
public:
  RobotDriverROSHW();
  ~RobotDriverROSHW() override;

  bool init(rclcpp::Node::SharedPtr node) override;
  void sendMotorCommands(const robot_msgs::msg::MotorCommandArray & msg) override;
  void readImu(sensor_msgs::msg::Imu & msg) override;
};

}  // namespace robot_driver