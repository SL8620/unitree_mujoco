// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robot_msgs:msg/MotorCommandArray.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_MSGS__MSG__DETAIL__MOTOR_COMMAND_ARRAY__STRUCT_HPP_
#define ROBOT_MSGS__MSG__DETAIL__MOTOR_COMMAND_ARRAY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'commands'
#include "robot_msgs/msg/detail/motor_command__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robot_msgs__msg__MotorCommandArray __attribute__((deprecated))
#else
# define DEPRECATED__robot_msgs__msg__MotorCommandArray __declspec(deprecated)
#endif

namespace robot_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MotorCommandArray_
{
  using Type = MotorCommandArray_<ContainerAllocator>;

  explicit MotorCommandArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit MotorCommandArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _commands_type =
    std::vector<robot_msgs::msg::MotorCommand_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robot_msgs::msg::MotorCommand_<ContainerAllocator>>>;
  _commands_type commands;
  using _joint_names_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _joint_names_type joint_names;

  // setters for named parameter idiom
  Type & set__commands(
    const std::vector<robot_msgs::msg::MotorCommand_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robot_msgs::msg::MotorCommand_<ContainerAllocator>>> & _arg)
  {
    this->commands = _arg;
    return *this;
  }
  Type & set__joint_names(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->joint_names = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_msgs::msg::MotorCommandArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_msgs::msg::MotorCommandArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_msgs::msg::MotorCommandArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_msgs::msg::MotorCommandArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_msgs::msg::MotorCommandArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_msgs::msg::MotorCommandArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_msgs::msg::MotorCommandArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_msgs::msg::MotorCommandArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_msgs::msg::MotorCommandArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_msgs::msg::MotorCommandArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_msgs__msg__MotorCommandArray
    std::shared_ptr<robot_msgs::msg::MotorCommandArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_msgs__msg__MotorCommandArray
    std::shared_ptr<robot_msgs::msg::MotorCommandArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MotorCommandArray_ & other) const
  {
    if (this->commands != other.commands) {
      return false;
    }
    if (this->joint_names != other.joint_names) {
      return false;
    }
    return true;
  }
  bool operator!=(const MotorCommandArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MotorCommandArray_

// alias to use template instance with default allocator
using MotorCommandArray =
  robot_msgs::msg::MotorCommandArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace robot_msgs

#endif  // ROBOT_MSGS__MSG__DETAIL__MOTOR_COMMAND_ARRAY__STRUCT_HPP_
