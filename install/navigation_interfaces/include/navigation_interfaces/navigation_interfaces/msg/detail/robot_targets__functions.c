// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from navigation_interfaces:msg/RobotTargets.idl
// generated code does not contain a copyright notice
#include "navigation_interfaces/msg/detail/robot_targets__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `robot_id`
#include "rosidl_runtime_c/string_functions.h"

bool
navigation_interfaces__msg__RobotTargets__init(navigation_interfaces__msg__RobotTargets * msg)
{
  if (!msg) {
    return false;
  }
  // robot_id
  if (!rosidl_runtime_c__String__init(&msg->robot_id)) {
    navigation_interfaces__msg__RobotTargets__fini(msg);
    return false;
  }
  // x
  // y
  return true;
}

void
navigation_interfaces__msg__RobotTargets__fini(navigation_interfaces__msg__RobotTargets * msg)
{
  if (!msg) {
    return;
  }
  // robot_id
  rosidl_runtime_c__String__fini(&msg->robot_id);
  // x
  // y
}

bool
navigation_interfaces__msg__RobotTargets__are_equal(const navigation_interfaces__msg__RobotTargets * lhs, const navigation_interfaces__msg__RobotTargets * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // robot_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->robot_id), &(rhs->robot_id)))
  {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  return true;
}

bool
navigation_interfaces__msg__RobotTargets__copy(
  const navigation_interfaces__msg__RobotTargets * input,
  navigation_interfaces__msg__RobotTargets * output)
{
  if (!input || !output) {
    return false;
  }
  // robot_id
  if (!rosidl_runtime_c__String__copy(
      &(input->robot_id), &(output->robot_id)))
  {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  return true;
}

navigation_interfaces__msg__RobotTargets *
navigation_interfaces__msg__RobotTargets__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  navigation_interfaces__msg__RobotTargets * msg = (navigation_interfaces__msg__RobotTargets *)allocator.allocate(sizeof(navigation_interfaces__msg__RobotTargets), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(navigation_interfaces__msg__RobotTargets));
  bool success = navigation_interfaces__msg__RobotTargets__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
navigation_interfaces__msg__RobotTargets__destroy(navigation_interfaces__msg__RobotTargets * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    navigation_interfaces__msg__RobotTargets__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
navigation_interfaces__msg__RobotTargets__Sequence__init(navigation_interfaces__msg__RobotTargets__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  navigation_interfaces__msg__RobotTargets * data = NULL;

  if (size) {
    data = (navigation_interfaces__msg__RobotTargets *)allocator.zero_allocate(size, sizeof(navigation_interfaces__msg__RobotTargets), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = navigation_interfaces__msg__RobotTargets__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        navigation_interfaces__msg__RobotTargets__fini(&data[i - 1]);
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
navigation_interfaces__msg__RobotTargets__Sequence__fini(navigation_interfaces__msg__RobotTargets__Sequence * array)
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
      navigation_interfaces__msg__RobotTargets__fini(&array->data[i]);
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

navigation_interfaces__msg__RobotTargets__Sequence *
navigation_interfaces__msg__RobotTargets__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  navigation_interfaces__msg__RobotTargets__Sequence * array = (navigation_interfaces__msg__RobotTargets__Sequence *)allocator.allocate(sizeof(navigation_interfaces__msg__RobotTargets__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = navigation_interfaces__msg__RobotTargets__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
navigation_interfaces__msg__RobotTargets__Sequence__destroy(navigation_interfaces__msg__RobotTargets__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    navigation_interfaces__msg__RobotTargets__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
navigation_interfaces__msg__RobotTargets__Sequence__are_equal(const navigation_interfaces__msg__RobotTargets__Sequence * lhs, const navigation_interfaces__msg__RobotTargets__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!navigation_interfaces__msg__RobotTargets__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
navigation_interfaces__msg__RobotTargets__Sequence__copy(
  const navigation_interfaces__msg__RobotTargets__Sequence * input,
  navigation_interfaces__msg__RobotTargets__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(navigation_interfaces__msg__RobotTargets);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    navigation_interfaces__msg__RobotTargets * data =
      (navigation_interfaces__msg__RobotTargets *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!navigation_interfaces__msg__RobotTargets__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          navigation_interfaces__msg__RobotTargets__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!navigation_interfaces__msg__RobotTargets__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
