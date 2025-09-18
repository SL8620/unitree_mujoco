// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from robot_msgs:msg/MotorCommandArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "robot_msgs/msg/detail/motor_command_array__rosidl_typesupport_introspection_c.h"
#include "robot_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "robot_msgs/msg/detail/motor_command_array__functions.h"
#include "robot_msgs/msg/detail/motor_command_array__struct.h"


// Include directives for member types
// Member `commands`
#include "robot_msgs/msg/motor_command.h"
// Member `commands`
#include "robot_msgs/msg/detail/motor_command__rosidl_typesupport_introspection_c.h"
// Member `joint_names`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void robot_msgs__msg__MotorCommandArray__rosidl_typesupport_introspection_c__MotorCommandArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  robot_msgs__msg__MotorCommandArray__init(message_memory);
}

void robot_msgs__msg__MotorCommandArray__rosidl_typesupport_introspection_c__MotorCommandArray_fini_function(void * message_memory)
{
  robot_msgs__msg__MotorCommandArray__fini(message_memory);
}

size_t robot_msgs__msg__MotorCommandArray__rosidl_typesupport_introspection_c__size_function__MotorCommandArray__commands(
  const void * untyped_member)
{
  const robot_msgs__msg__MotorCommand__Sequence * member =
    (const robot_msgs__msg__MotorCommand__Sequence *)(untyped_member);
  return member->size;
}

const void * robot_msgs__msg__MotorCommandArray__rosidl_typesupport_introspection_c__get_const_function__MotorCommandArray__commands(
  const void * untyped_member, size_t index)
{
  const robot_msgs__msg__MotorCommand__Sequence * member =
    (const robot_msgs__msg__MotorCommand__Sequence *)(untyped_member);
  return &member->data[index];
}

void * robot_msgs__msg__MotorCommandArray__rosidl_typesupport_introspection_c__get_function__MotorCommandArray__commands(
  void * untyped_member, size_t index)
{
  robot_msgs__msg__MotorCommand__Sequence * member =
    (robot_msgs__msg__MotorCommand__Sequence *)(untyped_member);
  return &member->data[index];
}

void robot_msgs__msg__MotorCommandArray__rosidl_typesupport_introspection_c__fetch_function__MotorCommandArray__commands(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const robot_msgs__msg__MotorCommand * item =
    ((const robot_msgs__msg__MotorCommand *)
    robot_msgs__msg__MotorCommandArray__rosidl_typesupport_introspection_c__get_const_function__MotorCommandArray__commands(untyped_member, index));
  robot_msgs__msg__MotorCommand * value =
    (robot_msgs__msg__MotorCommand *)(untyped_value);
  *value = *item;
}

void robot_msgs__msg__MotorCommandArray__rosidl_typesupport_introspection_c__assign_function__MotorCommandArray__commands(
  void * untyped_member, size_t index, const void * untyped_value)
{
  robot_msgs__msg__MotorCommand * item =
    ((robot_msgs__msg__MotorCommand *)
    robot_msgs__msg__MotorCommandArray__rosidl_typesupport_introspection_c__get_function__MotorCommandArray__commands(untyped_member, index));
  const robot_msgs__msg__MotorCommand * value =
    (const robot_msgs__msg__MotorCommand *)(untyped_value);
  *item = *value;
}

bool robot_msgs__msg__MotorCommandArray__rosidl_typesupport_introspection_c__resize_function__MotorCommandArray__commands(
  void * untyped_member, size_t size)
{
  robot_msgs__msg__MotorCommand__Sequence * member =
    (robot_msgs__msg__MotorCommand__Sequence *)(untyped_member);
  robot_msgs__msg__MotorCommand__Sequence__fini(member);
  return robot_msgs__msg__MotorCommand__Sequence__init(member, size);
}

size_t robot_msgs__msg__MotorCommandArray__rosidl_typesupport_introspection_c__size_function__MotorCommandArray__joint_names(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * robot_msgs__msg__MotorCommandArray__rosidl_typesupport_introspection_c__get_const_function__MotorCommandArray__joint_names(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * robot_msgs__msg__MotorCommandArray__rosidl_typesupport_introspection_c__get_function__MotorCommandArray__joint_names(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void robot_msgs__msg__MotorCommandArray__rosidl_typesupport_introspection_c__fetch_function__MotorCommandArray__joint_names(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    robot_msgs__msg__MotorCommandArray__rosidl_typesupport_introspection_c__get_const_function__MotorCommandArray__joint_names(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void robot_msgs__msg__MotorCommandArray__rosidl_typesupport_introspection_c__assign_function__MotorCommandArray__joint_names(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    robot_msgs__msg__MotorCommandArray__rosidl_typesupport_introspection_c__get_function__MotorCommandArray__joint_names(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool robot_msgs__msg__MotorCommandArray__rosidl_typesupport_introspection_c__resize_function__MotorCommandArray__joint_names(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember robot_msgs__msg__MotorCommandArray__rosidl_typesupport_introspection_c__MotorCommandArray_message_member_array[2] = {
  {
    "commands",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_msgs__msg__MotorCommandArray, commands),  // bytes offset in struct
    NULL,  // default value
    robot_msgs__msg__MotorCommandArray__rosidl_typesupport_introspection_c__size_function__MotorCommandArray__commands,  // size() function pointer
    robot_msgs__msg__MotorCommandArray__rosidl_typesupport_introspection_c__get_const_function__MotorCommandArray__commands,  // get_const(index) function pointer
    robot_msgs__msg__MotorCommandArray__rosidl_typesupport_introspection_c__get_function__MotorCommandArray__commands,  // get(index) function pointer
    robot_msgs__msg__MotorCommandArray__rosidl_typesupport_introspection_c__fetch_function__MotorCommandArray__commands,  // fetch(index, &value) function pointer
    robot_msgs__msg__MotorCommandArray__rosidl_typesupport_introspection_c__assign_function__MotorCommandArray__commands,  // assign(index, value) function pointer
    robot_msgs__msg__MotorCommandArray__rosidl_typesupport_introspection_c__resize_function__MotorCommandArray__commands  // resize(index) function pointer
  },
  {
    "joint_names",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_msgs__msg__MotorCommandArray, joint_names),  // bytes offset in struct
    NULL,  // default value
    robot_msgs__msg__MotorCommandArray__rosidl_typesupport_introspection_c__size_function__MotorCommandArray__joint_names,  // size() function pointer
    robot_msgs__msg__MotorCommandArray__rosidl_typesupport_introspection_c__get_const_function__MotorCommandArray__joint_names,  // get_const(index) function pointer
    robot_msgs__msg__MotorCommandArray__rosidl_typesupport_introspection_c__get_function__MotorCommandArray__joint_names,  // get(index) function pointer
    robot_msgs__msg__MotorCommandArray__rosidl_typesupport_introspection_c__fetch_function__MotorCommandArray__joint_names,  // fetch(index, &value) function pointer
    robot_msgs__msg__MotorCommandArray__rosidl_typesupport_introspection_c__assign_function__MotorCommandArray__joint_names,  // assign(index, value) function pointer
    robot_msgs__msg__MotorCommandArray__rosidl_typesupport_introspection_c__resize_function__MotorCommandArray__joint_names  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers robot_msgs__msg__MotorCommandArray__rosidl_typesupport_introspection_c__MotorCommandArray_message_members = {
  "robot_msgs__msg",  // message namespace
  "MotorCommandArray",  // message name
  2,  // number of fields
  sizeof(robot_msgs__msg__MotorCommandArray),
  robot_msgs__msg__MotorCommandArray__rosidl_typesupport_introspection_c__MotorCommandArray_message_member_array,  // message members
  robot_msgs__msg__MotorCommandArray__rosidl_typesupport_introspection_c__MotorCommandArray_init_function,  // function to initialize message memory (memory has to be allocated)
  robot_msgs__msg__MotorCommandArray__rosidl_typesupport_introspection_c__MotorCommandArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t robot_msgs__msg__MotorCommandArray__rosidl_typesupport_introspection_c__MotorCommandArray_message_type_support_handle = {
  0,
  &robot_msgs__msg__MotorCommandArray__rosidl_typesupport_introspection_c__MotorCommandArray_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_robot_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robot_msgs, msg, MotorCommandArray)() {
  robot_msgs__msg__MotorCommandArray__rosidl_typesupport_introspection_c__MotorCommandArray_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robot_msgs, msg, MotorCommand)();
  if (!robot_msgs__msg__MotorCommandArray__rosidl_typesupport_introspection_c__MotorCommandArray_message_type_support_handle.typesupport_identifier) {
    robot_msgs__msg__MotorCommandArray__rosidl_typesupport_introspection_c__MotorCommandArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &robot_msgs__msg__MotorCommandArray__rosidl_typesupport_introspection_c__MotorCommandArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
