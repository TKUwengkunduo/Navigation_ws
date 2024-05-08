// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from navigation_interfaces:srv/Path.idl
// generated code does not contain a copyright notice

#ifndef NAVIGATION_INTERFACES__SRV__DETAIL__PATH__STRUCT_H_
#define NAVIGATION_INTERFACES__SRV__DETAIL__PATH__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'positions'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/Path in the package navigation_interfaces.
typedef struct navigation_interfaces__srv__Path_Request
{
  /// List of positions encoded as x1, y1, x2, y2, ...
  rosidl_runtime_c__double__Sequence positions;
} navigation_interfaces__srv__Path_Request;

// Struct for a sequence of navigation_interfaces__srv__Path_Request.
typedef struct navigation_interfaces__srv__Path_Request__Sequence
{
  navigation_interfaces__srv__Path_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} navigation_interfaces__srv__Path_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Path in the package navigation_interfaces.
typedef struct navigation_interfaces__srv__Path_Response
{
  /// Confirmation of receipt
  bool success;
} navigation_interfaces__srv__Path_Response;

// Struct for a sequence of navigation_interfaces__srv__Path_Response.
typedef struct navigation_interfaces__srv__Path_Response__Sequence
{
  navigation_interfaces__srv__Path_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} navigation_interfaces__srv__Path_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NAVIGATION_INTERFACES__SRV__DETAIL__PATH__STRUCT_H_
