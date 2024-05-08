// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from navigation_interfaces:msg/AllRobotTargets.idl
// generated code does not contain a copyright notice

#ifndef NAVIGATION_INTERFACES__MSG__DETAIL__ALL_ROBOT_TARGETS__STRUCT_H_
#define NAVIGATION_INTERFACES__MSG__DETAIL__ALL_ROBOT_TARGETS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'targets'
#include "navigation_interfaces/msg/detail/robot_targets__struct.h"

/// Struct defined in msg/AllRobotTargets in the package navigation_interfaces.
typedef struct navigation_interfaces__msg__AllRobotTargets
{
  navigation_interfaces__msg__RobotTargets__Sequence targets;
} navigation_interfaces__msg__AllRobotTargets;

// Struct for a sequence of navigation_interfaces__msg__AllRobotTargets.
typedef struct navigation_interfaces__msg__AllRobotTargets__Sequence
{
  navigation_interfaces__msg__AllRobotTargets * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} navigation_interfaces__msg__AllRobotTargets__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NAVIGATION_INTERFACES__MSG__DETAIL__ALL_ROBOT_TARGETS__STRUCT_H_
