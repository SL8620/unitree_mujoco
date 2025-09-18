// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from robot_msgs:msg/MotorCommandArray.idl
// generated code does not contain a copyright notice
#include "robot_msgs/msg/detail/motor_command_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `commands`
#include "robot_msgs/msg/detail/motor_command__functions.h"
// Member `joint_names`
#include "rosidl_runtime_c/string_functions.h"

bool
robot_msgs__msg__MotorCommandArray__init(robot_msgs__msg__MotorCommandArray * msg)
{
  if (!msg) {
    return false;
  }
  // commands
  if (!robot_msgs__msg__MotorCommand__Sequence__init(&msg->commands, 0)) {
    robot_msgs__msg__MotorCommandArray__fini(msg);
    return false;
  }
  // joint_names
  if (!rosidl_runtime_c__String__Sequence__init(&msg->joint_names, 0)) {
    robot_msgs__msg__MotorCommandArray__fini(msg);
    return false;
  }
  return true;
}

void
robot_msgs__msg__MotorCommandArray__fini(robot_msgs__msg__MotorCommandArray * msg)
{
  if (!msg) {
    return;
  }
  // commands
  robot_msgs__msg__MotorCommand__Sequence__fini(&msg->commands);
  // joint_names
  rosidl_runtime_c__String__Sequence__fini(&msg->joint_names);
}

bool
robot_msgs__msg__MotorCommandArray__are_equal(const robot_msgs__msg__MotorCommandArray * lhs, const robot_msgs__msg__MotorCommandArray * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // commands
  if (!robot_msgs__msg__MotorCommand__Sequence__are_equal(
      &(lhs->commands), &(rhs->commands)))
  {
    return false;
  }
  // joint_names
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->joint_names), &(rhs->joint_names)))
  {
    return false;
  }
  return true;
}

bool
robot_msgs__msg__MotorCommandArray__copy(
  const robot_msgs__msg__MotorCommandArray * input,
  robot_msgs__msg__MotorCommandArray * output)
{
  if (!input || !output) {
    return false;
  }
  // commands
  if (!robot_msgs__msg__MotorCommand__Sequence__copy(
      &(input->commands), &(output->commands)))
  {
    return false;
  }
  // joint_names
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->joint_names), &(output->joint_names)))
  {
    return false;
  }
  return true;
}

robot_msgs__msg__MotorCommandArray *
robot_msgs__msg__MotorCommandArray__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robot_msgs__msg__MotorCommandArray * msg = (robot_msgs__msg__MotorCommandArray *)allocator.allocate(sizeof(robot_msgs__msg__MotorCommandArray), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robot_msgs__msg__MotorCommandArray));
  bool success = robot_msgs__msg__MotorCommandArray__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robot_msgs__msg__MotorCommandArray__destroy(robot_msgs__msg__MotorCommandArray * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robot_msgs__msg__MotorCommandArray__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robot_msgs__msg__MotorCommandArray__Sequence__init(robot_msgs__msg__MotorCommandArray__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robot_msgs__msg__MotorCommandArray * data = NULL;

  if (size) {
    data = (robot_msgs__msg__MotorCommandArray *)allocator.zero_allocate(size, sizeof(robot_msgs__msg__MotorCommandArray), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robot_msgs__msg__MotorCommandArray__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robot_msgs__msg__MotorCommandArray__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
robot_msgs__msg__MotorCommandArray__Sequence__fini(robot_msgs__msg__MotorCommandArray__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      robot_msgs__msg__MotorCommandArray__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

robot_msgs__msg__MotorCommandArray__Sequence *
robot_msgs__msg__MotorCommandArray__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robot_msgs__msg__MotorCommandArray__Sequence * array = (robot_msgs__msg__MotorCommandArray__Sequence *)allocator.allocate(sizeof(robot_msgs__msg__MotorCommandArray__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robot_msgs__msg__MotorCommandArray__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robot_msgs__msg__MotorCommandArray__Sequence__destroy(robot_msgs__msg__MotorCommandArray__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robot_msgs__msg__MotorCommandArray__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robot_msgs__msg__MotorCommandArray__Sequence__are_equal(const robot_msgs__msg__MotorCommandArray__Sequence * lhs, const robot_msgs__msg__MotorCommandArray__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robot_msgs__msg__MotorCommandArray__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robot_msgs__msg__MotorCommandArray__Sequence__copy(
  const robot_msgs__msg__MotorCommandArray__Sequence * input,
  robot_msgs__msg__MotorCommandArray__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robot_msgs__msg__MotorCommandArray);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robot_msgs__msg__MotorCommandArray * data =
      (robot_msgs__msg__MotorCommandArray *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robot_msgs__msg__MotorCommandArray__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robot_msgs__msg__MotorCommandArray__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robot_msgs__msg__MotorCommandArray__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
