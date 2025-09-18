#pragma once

#include <vector>
#include <string>
#include <memory>
#include <mutex>
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include "std_srvs/srv/trigger.hpp"

namespace robot_driver {

// motor command 用于 C++ 层
struct MotorCommand {
  double p = 0.0;
  double v = 0.0;
  double tau = 0.0;
  double kp = 0.0;
  double kd = 0.0;
};

struct JointState {
  std::vector<std::string> names;
  std::vector<double> position;
  std::vector<double> velocity;
  std::vector<double> effort;
};

struct ImuData {
  sensor_msgs::msg::Imu imu_msg;
};

// 抽象驱动
class RobotDriver : public rclcpp::Node {
public:
  RobotDriver(const std::string & name) : rclcpp::Node(name) {}
  virtual ~RobotDriver() = default;

  virtual void initialize() = 0;
  virtual void send_motor_commands(const std::vector<MotorCommand>& cmds) = 0;
  virtual std::vector<MotorCommand> get_last_sent_commands() = 0;
  virtual JointState get_joint_state() = 0;
  virtual ImuData get_imu() = 0;
  virtual void emergency_stop() = 0;
  virtual void reset() = 0;
  virtual void step_simulation(double dt) = 0;
};

using RobotDriverPtr = std::shared_ptr<RobotDriver>;

} // namespace robot_driver
