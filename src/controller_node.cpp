#include "rclcpp/rclcpp.hpp"
#include "robot_driver/robot_driver.hpp"
#include <memory>

using namespace std::chrono_literals;

class ControllerNode : public rclcpp::Node {
public:
  ControllerNode(): Node("controller_node") {
    this->declare_parameter<std::string>("backend", "mujoco");
    this->declare_parameter<std::vector<std::string>>("joint_names", std::vector<std::string>{});
    this->declare_parameter<double>("control_rate", 200.0);

    double rate = this->get_parameter("control_rate").as_double();
    control_timer_ = this->create_wall_timer(std::chrono::duration<double>(1.0/rate),
                                            std::bind(&ControllerNode::control_loop, this));
    auto backend = this->get_parameter("backend").as_string();
    if (backend == "mujoco") {
      driver_ = std::make_shared<robot_driver::RobotDriverMujoco>();
    } else {
      driver_ = std::make_shared<robot_driver::RobotDriverROSHW>();
    }
    driver_->initialize();
    joint_names_ = this->get_parameter("joint_names").as_string_array();
    RCLCPP_INFO(this->get_logger(), "ControllerNode started with backend=%s", backend.c_str());
  }

private:
  void control_loop() {
    size_t nj = joint_names_.size();
    std::vector<robot_driver::MotorCommand> cmds(nj);
    for (size_t i = 0; i < nj; ++i) {
      robot_driver::MotorCommand m;
      m.p = 0.0; m.v = 0.0; m.tau = 0.0; m.kp = 20.0; m.kd = 0.5;
      cmds[i] = m;
    }
    driver_->send_motor_commands(cmds);
    auto st = driver_->get_joint_state();
    (void)st;
  }

  rclcpp::TimerBase::SharedPtr control_timer_;
  std::shared_ptr<robot_driver::RobotDriver> driver_;
  std::vector<std::string> joint_names_;
};

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<ControllerNode>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
