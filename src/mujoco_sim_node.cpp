#include "rclcpp/rclcpp.hpp"
#include "robot_driver_pkg/msg/motor_command_array.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include "std_srvs/srv/trigger.hpp"
#include <chrono>

using namespace std::chrono_literals;

class MujocoSimNode : public rclcpp::Node {
public:
  MujocoSimNode(): Node("mujoco_sim_node") {
    this->declare_parameter<std::string>("mjcf_path", "");
    this->declare_parameter<double>("timestep", 0.001);
    this->declare_parameter<std::vector<std::string>>("joint_names", std::vector<std::string>{});

    joint_state_pub_ = this->create_publisher<sensor_msgs::msg::JointState>("/mujoco/joint_states", 10);
    imu_pub_ = this->create_publisher<sensor_msgs::msg::Imu>("/mujoco/imu", 10);
    cmd_sub_ = this->create_subscription<robot_driver_pkg::msg::MotorCommandArray>(
      "/mujoco/motor_commands", 10, std::bind(&MujocoSimNode::cmd_cb, this, std::placeholders::_1)
    );
    reset_srv_ = this->create_service<std_srvs::srv::Trigger>(
      "/mujoco/reset",
      [this](auto, auto res){ this->reset_sim(); res->success=true; res->message="reset"; }
    );

    joint_names_ = this->get_parameter("joint_names").as_string_array();
    double dt = this->get_parameter("timestep").as_double();
    sim_timer_ = this->create_wall_timer(std::chrono::duration<double>(dt),
                                        std::bind(&MujocoSimNode::sim_step, this));
    RCLCPP_INFO(this->get_logger(), "MujocoSimNode started (stub). Fill in libmujoco calls).");
  }

private:
  void sim_step() {
    sensor_msgs::msg::JointState st;
    st.header.stamp = now();
    st.name = joint_names_;
    st.position.assign(joint_names_.size(), 0.0);
    st.velocity.assign(joint_names_.size(), 0.0);
    st.effort.assign(joint_names_.size(), 0.0);
    joint_state_pub_->publish(st);

    sensor_msgs::msg::Imu imu;
    imu.header.stamp = now();
    imu_pub_->publish(imu);
  }

  void cmd_cb(const robot_driver_pkg::msg::MotorCommandArray::SharedPtr msg) {
    std::lock_guard<std::mutex> lk(cmd_mutex_);
    last_cmd_ = *msg;
  }

  void reset_sim() {}

  rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_state_pub_;
  rclcpp::Publisher<sensor_msgs::msg::Imu>::SharedPtr imu_pub_;
  rclcpp::Subscription<robot_driver_pkg::msg::MotorCommandArray>::SharedPtr cmd_sub_;
  rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr reset_srv_;
  rclcpp::TimerBase::SharedPtr sim_timer_;

  std::vector<std::string> joint_names_;
  robot_driver_pkg::msg::MotorCommandArray last_cmd_;
  std::mutex cmd_mutex_;
};

#include "rclcpp_components/register_node_macro.hpp"
RCLCPP_COMPONENTS_REGISTER_NODE(MujocoSimNode)
