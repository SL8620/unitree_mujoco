#include "robot_driver/robot_driver.hpp"
#include "robot_driver_pkg/msg/motor_command_array.hpp"
#include "rclcpp_components/register_node_macro.hpp"
#include <std_msgs/msg/bool.hpp>

namespace rd = robot_driver;

class RobotDriverROSHW : public rd::RobotDriver {
public:
  RobotDriverROSHW() : rd::RobotDriver("robot_driver_roshw") {
    this->declare_parameter<std::vector<std::string>>("joint_names", std::vector<std::string>{});

    hw_cmd_pub_ = this->create_publisher<robot_driver_pkg::msg::MotorCommandArray>("/hw/motor_commands", 10);

    hw_state_sub_ = this->create_subscription<sensor_msgs::msg::JointState>(
      "/hw/joint_states", 10, std::bind(&RobotDriverROSHW::hw_state_cb, this, std::placeholders::_1)
    );

    imu_sub_ = this->create_subscription<sensor_msgs::msg::Imu>(
      "/hw/imu", 10, std::bind(&RobotDriverROSHW::imu_cb, this, std::placeholders::_1)
    );

    estop_sub_ = this->create_subscription<std_msgs::msg::Bool>(
      "/robot/estop", 10, [this](const std_msgs::msg::Bool::SharedPtr msg){ if (msg->data) emergency_stop(); }
    );

    reset_srv_ = this->create_service<std_srvs::srv::Trigger>(
      "/robot/reset",
      [this](auto, auto res){ this->reset(); res->success=true; res->message="roshw reset called"; }
    );
  }

  void initialize() override {
    joint_names_ = this->get_parameter("joint_names").as_string_array();
    last_state_.names = joint_names_;
    last_state_.position.assign(joint_names_.size(), 0.0);
    last_state_.velocity.assign(joint_names_.size(), 0.0);
    last_state_.effort.assign(joint_names_.size(), 0.0);
    RCLCPP_INFO(this->get_logger(), "RobotDriverROSHW initialized with %zu joints", joint_names_.size());
  }

  void send_motor_commands(const std::vector<rd::MotorCommand>& cmds) override {
    robot_driver_pkg::msg::MotorCommandArray msg;
    msg.joint_names = joint_names_;
    msg.commands.reserve(cmds.size());
    for (const auto &c : cmds) {
      robot_driver_pkg::msg::MotorCommand mc;
      mc.p = c.p; mc.v = c.v; mc.tau = c.tau; mc.kp = c.kp; mc.kd = c.kd;
      msg.commands.push_back(mc);
    }
    {
      std::lock_guard<std::mutex> lk(cmd_mutex_);
      last_sent_commands_ = cmds;
    }
    hw_cmd_pub_->publish(msg);
  }

  std::vector<rd::MotorCommand> get_last_sent_commands() override {
    std::lock_guard<std::mutex> lk(cmd_mutex_);
    return last_sent_commands_;
  }

  rd::JointState get_joint_state() override {
    std::lock_guard<std::mutex> lk(state_mutex_);
    return last_state_;
  }

  rd::ImuData get_imu() override {
    std::lock_guard<std::mutex> lk(imu_mutex_);
    rd::ImuData d; d.imu_msg = last_imu_; return d;
  }

  void emergency_stop() override {
    RCLCPP_ERROR(this->get_logger(), "Emergency stop on hardware backend! Publishing zero commands.");
    std::vector<rd::MotorCommand> zero_cmds(joint_names_.size());
    send_motor_commands(zero_cmds);
  }

  void reset() override {
    RCLCPP_INFO(this->get_logger(), "Hardware reset requested (stub).");
  }

  void step_simulation(double) override {}

private:
  void hw_state_cb(const sensor_msgs::msg::JointState::SharedPtr msg) {
    std::lock_guard<std::mutex> lk(state_mutex_);
    last_state_.names = msg->name;
    last_state_.position = msg->position;
    last_state_.velocity = msg->velocity;
    last_state_.effort = msg->effort;
  }

  void imu_cb(const sensor_msgs::msg::Imu::SharedPtr msg) {
    std::lock_guard<std::mutex> lk(imu_mutex_);
    last_imu_ = *msg;
  }

  rclcpp::Publisher<robot_driver_pkg::msg::MotorCommandArray>::SharedPtr hw_cmd_pub_;
  rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr hw_state_sub_;
  rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imu_sub_;
  rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr estop_sub_;
  rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr reset_srv_;

  std::vector<std::string> joint_names_;
  rd::JointState last_state_;
  std::mutex state_mutex_;

  sensor_msgs::msg::Imu last_imu_;
  std::mutex imu_mutex_;

  std::vector<rd::MotorCommand> last_sent_commands_;
  std::mutex cmd_mutex_;
};

RCLCPP_COMPONENTS_REGISTER_NODE(RobotDriverROSHW)
