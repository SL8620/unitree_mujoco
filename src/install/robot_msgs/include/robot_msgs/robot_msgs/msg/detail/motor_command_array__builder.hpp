// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_msgs:msg/MotorCommandArray.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_MSGS__MSG__DETAIL__MOTOR_COMMAND_ARRAY__BUILDER_HPP_
#define ROBOT_MSGS__MSG__DETAIL__MOTOR_COMMAND_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_msgs/msg/detail/motor_command_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_msgs
{

namespace msg
{

namespace builder
{

class Init_MotorCommandArray_joint_names
{
public:
  explicit Init_MotorCommandArray_joint_names(::robot_msgs::msg::MotorCommandArray & msg)
  : msg_(msg)
  {}
  ::robot_msgs::msg::MotorCommandArray joint_names(::robot_msgs::msg::MotorCommandArray::_joint_names_type arg)
  {
    msg_.joint_names = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_msgs::msg::MotorCommandArray msg_;
};

class Init_MotorCommandArray_commands
{
public:
  Init_MotorCommandArray_commands()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotorCommandArray_joint_names commands(::robot_msgs::msg::MotorCommandArray::_commands_type arg)
  {
    msg_.commands = std::move(arg);
    return Init_MotorCommandArray_joint_names(msg_);
  }

private:
  ::robot_msgs::msg::MotorCommandArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_msgs::msg::MotorCommandArray>()
{
  return robot_msgs::msg::builder::Init_MotorCommandArray_commands();
}

}  // namespace robot_msgs

#endif  // ROBOT_MSGS__MSG__DETAIL__MOTOR_COMMAND_ARRAY__BUILDER_HPP_
