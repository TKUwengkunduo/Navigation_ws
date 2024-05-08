// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from navigation_interfaces:msg/RobotTargets.idl
// generated code does not contain a copyright notice

#ifndef NAVIGATION_INTERFACES__MSG__DETAIL__ROBOT_TARGETS__STRUCT_H_
#define NAVIGATION_INTERFACES__MSG__DETAIL__ROBOT_TARGETS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'robot_id'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/RobotTargets in the package navigation_interfaces.
typedef struct navigation_interfaces__msg__RobotTargets
{
  rosidl_runtime_c__String robot_id;
  double x;
  double y;
} navigation_interfaces__msg__RobotTargets;

// Struct for a sequence of navigation_interfaces__msg__RobotTargets.
typedef struct navigation_interfaces__msg__RobotTargets__Sequence
{
  navigation_interfaces__msg__RobotTargets * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} navigation_interfaces__msg__RobotTargets__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NAVIGATION_INTERFACES__MSG__DETAIL__ROBOT_TARGETS__STRUCT_H_
