// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_msgs:msg/MotorCommandArray.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_MSGS__MSG__DETAIL__MOTOR_COMMAND_ARRAY__STRUCT_H_
#define ROBOT_MSGS__MSG__DETAIL__MOTOR_COMMAND_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'commands'
#include "robot_msgs/msg/detail/motor_command__struct.h"
// Member 'joint_names'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/MotorCommandArray in the package robot_msgs.
/**
  * msg/MotorCommandArray.msg
 */
typedef struct robot_msgs__msg__MotorCommandArray
{
  robot_msgs__msg__MotorCommand__Sequence commands;
  rosidl_runtime_c__String__Sequence joint_names;
} robot_msgs__msg__MotorCommandArray;

// Struct for a sequence of robot_msgs__msg__MotorCommandArray.
typedef struct robot_msgs__msg__MotorCommandArray__Sequence
{
  robot_msgs__msg__MotorCommandArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_msgs__msg__MotorCommandArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_MSGS__MSG__DETAIL__MOTOR_COMMAND_ARRAY__STRUCT_H_
