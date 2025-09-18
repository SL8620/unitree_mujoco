#include "rclcpp/rclcpp.hpp"
#include "robot_driver_pkg/robot_driver.hpp"
#include "robot_msgs/msg/motor_command_array.hpp"
#include "sensor_msgs/msg/imu.hpp"

using std::placeholders::_1;

class ControllerNode : public rclcpp::Node
{
public:
  explicit ControllerNode(const rclcpp::NodeOptions & options = rclcpp::NodeOptions())
  : Node("controller_node", options)
  {
    // 参数决定使用哪个 driver
    std::string mode = this->declare_parameter<std::string>("mode", "mujoco");

    if (mode == "mujoco") {
      driver_ = std::make_shared<robot_driver::RobotDriverMujoco>();
    } else if (mode == "roshw") {
      driver_ = std::make_shared<robot_driver::RobotDriverROSHW>();
    } else {
      RCLCPP_ERROR(this->get_logger(), "Unknown mode: %s", mode.c_str());
      throw std::runtime_error("Invalid driver mode");
    }

    // 订阅电机命令
    sub_motor_cmd_ = this->create_subscription<robot_msgs::msg::MotorCommandArray>(
      "motor_commands", 10, std::bind(&ControllerNode::command_callback, this, _1));

    // 发布 IMU
    pub_imu_ = this->create_publisher<sensor_msgs::msg::Imu>("imu", 10);

    // 定时器周期发布 IMU
    timer_ = this->create_wall_timer(
      std::chrono::milliseconds(10),
      std::bind(&ControllerNode::publish_imu, this));
  }

  void init_driver()
  {
    // 在构造函数之外调用 init，避免 shared_from_this() 崩溃
    if (!driver_->init(shared_from_this())) {
      RCLCPP_ERROR(this->get_logger(), "Driver init failed");
      throw std::runtime_error("Driver init failed");
    }
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

  robot_driver::RobotDriverPtr driver_;
  rclcpp::Subscription<robot_msgs::msg::MotorCommandArray>::SharedPtr sub_motor_cmd_;
  rclcpp::Publisher<sensor_msgs::msg::Imu>::SharedPtr pub_imu_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<ControllerNode>();
  node->init_driver();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}