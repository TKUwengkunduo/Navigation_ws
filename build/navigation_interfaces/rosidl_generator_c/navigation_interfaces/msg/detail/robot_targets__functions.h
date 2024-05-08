// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from navigation_interfaces:msg/RobotTargets.idl
// generated code does not contain a copyright notice

#ifndef NAVIGATION_INTERFACES__MSG__DETAIL__ROBOT_TARGETS__FUNCTIONS_H_
#define NAVIGATION_INTERFACES__MSG__DETAIL__ROBOT_TARGETS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "navigation_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "navigation_interfaces/msg/detail/robot_targets__struct.h"

/// Initialize msg/RobotTargets message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * navigation_interfaces__msg__RobotTargets
 * )) before or use
 * navigation_interfaces__msg__RobotTargets__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_navigation_interfaces
bool
navigation_interfaces__msg__RobotTargets__init(navigation_interfaces__msg__RobotTargets * msg);

/// Finalize msg/RobotTargets message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_navigation_interfaces
void
navigation_interfaces__msg__RobotTargets__fini(navigation_interfaces__msg__RobotTargets * msg);

/// Create msg/RobotTargets message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * navigation_interfaces__msg__RobotTargets__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_navigation_interfaces
navigation_interfaces__msg__RobotTargets *
navigation_interfaces__msg__RobotTargets__create();

/// Destroy msg/RobotTargets message.
/**
 * It calls
 * navigation_interfaces__msg__RobotTargets__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_navigation_interfaces
void
navigation_interfaces__msg__RobotTargets__destroy(navigation_interfaces__msg__RobotTargets * msg);

/// Check for msg/RobotTargets message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_navigation_interfaces
bool
navigation_interfaces__msg__RobotTargets__are_equal(const navigation_interfaces__msg__RobotTargets * lhs, const navigation_interfaces__msg__RobotTargets * rhs);

/// Copy a msg/RobotTargets message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_navigation_interfaces
bool
navigation_interfaces__msg__RobotTargets__copy(
  const navigation_interfaces__msg__RobotTargets * input,
  navigation_interfaces__msg__RobotTargets * output);

/// Initialize array of msg/RobotTargets messages.
/**
 * It allocates the memory for the number of elements and calls
 * navigation_interfaces__msg__RobotTargets__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_navigation_interfaces
bool
navigation_interfaces__msg__RobotTargets__Sequence__init(navigation_interfaces__msg__RobotTargets__Sequence * array, size_t size);

/// Finalize array of msg/RobotTargets messages.
/**
 * It calls
 * navigation_interfaces__msg__RobotTargets__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_navigation_interfaces
void
navigation_interfaces__msg__RobotTargets__Sequence__fini(navigation_interfaces__msg__RobotTargets__Sequence * array);

/// Create array of msg/RobotTargets messages.
/**
 * It allocates the memory for the array and calls
 * navigation_interfaces__msg__RobotTargets__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_navigation_interfaces
navigation_interfaces__msg__RobotTargets__Sequence *
navigation_interfaces__msg__RobotTargets__Sequence__create(size_t size);

/// Destroy array of msg/RobotTargets messages.
/**
 * It calls
 * navigation_interfaces__msg__RobotTargets__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_navigation_interfaces
void
navigation_interfaces__msg__RobotTargets__Sequence__destroy(navigation_interfaces__msg__RobotTargets__Sequence * array);

/// Check for msg/RobotTargets message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_navigation_interfaces
bool
navigation_interfaces__msg__RobotTargets__Sequence__are_equal(const navigation_interfaces__msg__RobotTargets__Sequence * lhs, const navigation_interfaces__msg__RobotTargets__Sequence * rhs);

/// Copy an array of msg/RobotTargets messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_navigation_interfaces
bool
navigation_interfaces__msg__RobotTargets__Sequence__copy(
  const navigation_interfaces__msg__RobotTargets__Sequence * input,
  navigation_interfaces__msg__RobotTargets__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // NAVIGATION_INTERFACES__MSG__DETAIL__ROBOT_TARGETS__FUNCTIONS_H_
