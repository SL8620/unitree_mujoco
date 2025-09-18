#include <rclcpp/rclcpp.hpp>
#include "robot_driver_pkg/robot_driver.hpp"
#include "robot_msgs/msg/motor_command_array.hpp"
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

class MujocoSimNode : public rclcpp::Node {
public:
    MujocoSimNode()
        : Node("mujoco_sim_node")
    {
        driver_ = std::make_shared<robot_driver::RobotDriverMujoco>();

        // 初始化 driver
        if (!driver_->init(shared_from_this())) {
            RCLCPP_ERROR(this->get_logger(), "Failed to initialize Mujoco driver");
            rclcpp::shutdown();
        }

        // 订阅电机命令
        motor_sub_ = this->create_subscription<robot_msgs::msg::MotorCommandArray>(
            "motor_commands", 10,
            std::bind(&MujocoSimNode::motorCallback, this, std::placeholders::_1));

        // 发布 imu
        imu_pub_ = this->create_publisher<sensor_msgs::msg::Imu>("imu", 10);

        // 启动仿真循环
        sim_thread_ = std::thread([this]() { simLoop(); });
    }

    ~MujocoSimNode() {
        if (sim_thread_.joinable()) sim_thread_.join();
    }

private:
    void motorCallback(const robot_msgs::msg::MotorCommandArray::SharedPtr msg) {
        driver_->sendMotorCommands(*msg);
    }

    void simLoop() {
        rclcpp::Rate loop_rate(1000); // 1 kHz 仿真循环
        while (rclcpp::ok() && driver_->isRunning()) {
            driver_->step();        // 推进物理
            driver_->render();      // 渲染窗口

            // 发布 IMU
            sensor_msgs::msg::Imu imu_msg;
            driver_->readImu(imu_msg);
            imu_pub_->publish(imu_msg);

            loop_rate.sleep();
        }
        driver_->shutdown();
    }

    std::shared_ptr<robot_driver::RobotDriverMujoco> driver_;
    rclcpp::Subscription<robot_msgs::msg::MotorCommandArray>::SharedPtr motor_sub_;
    rclcpp::Publisher<sensor_msgs::msg::Imu>::SharedPtr imu_pub_;
    std::thread sim_thread_;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MujocoSimNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}