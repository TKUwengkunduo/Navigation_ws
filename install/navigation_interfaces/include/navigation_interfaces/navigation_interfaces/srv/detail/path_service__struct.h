// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from navigation_interfaces:srv/PathService.idl
// generated code does not contain a copyright notice

#ifndef NAVIGATION_INTERFACES__SRV__DETAIL__PATH_SERVICE__STRUCT_H_
#define NAVIGATION_INTERFACES__SRV__DETAIL__PATH_SERVICE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'paths'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/PathService in the package navigation_interfaces.
typedef struct navigation_interfaces__srv__PathService_Request
{
  rosidl_runtime_c__String paths;
} navigation_interfaces__srv__PathService_Request;

// Struct for a sequence of navigation_interfaces__srv__PathService_Request.
typedef struct navigation_interfaces__srv__PathService_Request__Sequence
{
  navigation_interfaces__srv__PathService_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} navigation_interfaces__srv__PathService_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'confirmation'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/PathService in the package navigation_interfaces.
typedef struct navigation_interfaces__srv__PathService_Response
{
  rosidl_runtime_c__String confirmation;
} navigation_interfaces__srv__PathService_Response;

// Struct for a sequence of navigation_interfaces__srv__PathService_Response.
typedef struct navigation_interfaces__srv__PathService_Response__Sequence
{
  navigation_interfaces__srv__PathService_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} navigation_interfaces__srv__PathService_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NAVIGATION_INTERFACES__SRV__DETAIL__PATH_SERVICE__STRUCT_H_
