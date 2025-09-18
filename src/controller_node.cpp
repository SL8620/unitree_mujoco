#include "robot_driver_pkg/robot_driver.hpp"
#include <rclcpp/rclcpp.hpp>

using std::placeholders::_1;

class ControllerNode : public rclcpp::Node
{
public:
  ControllerNode()
  : Node("controller_node")
  {
    driver_ = std::make_shared<robot_driver::RobotDriverMujoco>();
    driver_->init(shared_from_this());

    sub_cmd_ = create_subscription<robot_msgs::msg::MotorCommandArray>(
      "motor_commands", 10, std::bind(&ControllerNode::command_callback, this, _1));

    pub_imu_ = create_publisher<sensor_msgs::msg::Imu>("imu", 10);

    timer_ = create_wall_timer(
      std::chrono::milliseconds(10), std::bind(&ControllerNode::publish_imu, this));
  }

private:
  void command_callback(const robot_msgs::msg::MotorCommandArray::SharedPtr msg)
  {
    driver_->sendMotorCommands(*msg);
  }

  void publish_imu()
  {
    sensor_msgs::msg::Imu imu_msg;
    driver_->readImu(imu_msg);
    pub_imu_->publish(imu_msg);
  }

  std::shared_ptr<robot_driver::RobotDriverBase> driver_;
  rclcpp::Subscription<robot_msgs::msg::MotorCommandArray>::SharedPtr sub_cmd_;
  rclcpp::Publisher<sensor_msgs::msg::Imu>::SharedPtr pub_imu_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ControllerNode>());
  rclcpp::shutdown();
  return 0;
}