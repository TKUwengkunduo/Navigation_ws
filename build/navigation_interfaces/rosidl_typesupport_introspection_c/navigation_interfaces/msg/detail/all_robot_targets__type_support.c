// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from navigation_interfaces:msg/AllRobotTargets.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "navigation_interfaces/msg/detail/all_robot_targets__rosidl_typesupport_introspection_c.h"
#include "navigation_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "navigation_interfaces/msg/detail/all_robot_targets__functions.h"
#include "navigation_interfaces/msg/detail/all_robot_targets__struct.h"


// Include directives for member types
// Member `targets`
#include "navigation_interfaces/msg/robot_targets.h"
// Member `targets`
#include "navigation_interfaces/msg/detail/robot_targets__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void navigation_interfaces__msg__AllRobotTargets__rosidl_typesupport_introspection_c__AllRobotTargets_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  navigation_interfaces__msg__AllRobotTargets__init(message_memory);
}

void navigation_interfaces__msg__AllRobotTargets__rosidl_typesupport_introspection_c__AllRobotTargets_fini_function(void * message_memory)
{
  navigation_interfaces__msg__AllRobotTargets__fini(message_memory);
}

size_t navigation_interfaces__msg__AllRobotTargets__rosidl_typesupport_introspection_c__size_function__AllRobotTargets__targets(
  const void * untyped_member)
{
  const navigation_interfaces__msg__RobotTargets__Sequence * member =
    (const navigation_interfaces__msg__RobotTargets__Sequence *)(untyped_member);
  return member->size;
}

const void * navigation_interfaces__msg__AllRobotTargets__rosidl_typesupport_introspection_c__get_const_function__AllRobotTargets__targets(
  const void * untyped_member, size_t index)
{
  const navigation_interfaces__msg__RobotTargets__Sequence * member =
    (const navigation_interfaces__msg__RobotTargets__Sequence *)(untyped_member);
  return &member->data[index];
}

void * navigation_interfaces__msg__AllRobotTargets__rosidl_typesupport_introspection_c__get_function__AllRobotTargets__targets(
  void * untyped_member, size_t index)
{
  navigation_interfaces__msg__RobotTargets__Sequence * member =
    (navigation_interfaces__msg__RobotTargets__Sequence *)(untyped_member);
  return &member->data[index];
}

void navigation_interfaces__msg__AllRobotTargets__rosidl_typesupport_introspection_c__fetch_function__AllRobotTargets__targets(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const navigation_interfaces__msg__RobotTargets * item =
    ((const navigation_interfaces__msg__RobotTargets *)
    navigation_interfaces__msg__AllRobotTargets__rosidl_typesupport_introspection_c__get_const_function__AllRobotTargets__targets(untyped_member, index));
  navigation_interfaces__msg__RobotTargets * value =
    (navigation_interfaces__msg__RobotTargets *)(untyped_value);
  *value = *item;
}

void navigation_interfaces__msg__AllRobotTargets__rosidl_typesupport_introspection_c__assign_function__AllRobotTargets__targets(
  void * untyped_member, size_t index, const void * untyped_value)
{
  navigation_interfaces__msg__RobotTargets * item =
    ((navigation_interfaces__msg__RobotTargets *)
    navigation_interfaces__msg__AllRobotTargets__rosidl_typesupport_introspection_c__get_function__AllRobotTargets__targets(untyped_member, index));
  const navigation_interfaces__msg__RobotTargets * value =
    (const navigation_interfaces__msg__RobotTargets *)(untyped_value);
  *item = *value;
}

bool navigation_interfaces__msg__AllRobotTargets__rosidl_typesupport_introspection_c__resize_function__AllRobotTargets__targets(
  void * untyped_member, size_t size)
{
  navigation_interfaces__msg__RobotTargets__Sequence * member =
    (navigation_interfaces__msg__RobotTargets__Sequence *)(untyped_member);
  navigation_interfaces__msg__RobotTargets__Sequence__fini(member);
  return navigation_interfaces__msg__RobotTargets__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember navigation_interfaces__msg__AllRobotTargets__rosidl_typesupport_introspection_c__AllRobotTargets_message_member_array[1] = {
  {
    "targets",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(navigation_interfaces__msg__AllRobotTargets, targets),  // bytes offset in struct
    NULL,  // default value
    navigation_interfaces__msg__AllRobotTargets__rosidl_typesupport_introspection_c__size_function__AllRobotTargets__targets,  // size() function pointer
    navigation_interfaces__msg__AllRobotTargets__rosidl_typesupport_introspection_c__get_const_function__AllRobotTargets__targets,  // get_const(index) function pointer
    navigation_interfaces__msg__AllRobotTargets__rosidl_typesupport_introspection_c__get_function__AllRobotTargets__targets,  // get(index) function pointer
    navigation_interfaces__msg__AllRobotTargets__rosidl_typesupport_introspection_c__fetch_function__AllRobotTargets__targets,  // fetch(index, &value) function pointer
    navigation_interfaces__msg__AllRobotTargets__rosidl_typesupport_introspection_c__assign_function__AllRobotTargets__targets,  // assign(index, value) function pointer
    navigation_interfaces__msg__AllRobotTargets__rosidl_typesupport_introspection_c__resize_function__AllRobotTargets__targets  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers navigation_interfaces__msg__AllRobotTargets__rosidl_typesupport_introspection_c__AllRobotTargets_message_members = {
  "navigation_interfaces__msg",  // message namespace
  "AllRobotTargets",  // message name
  1,  // number of fields
  sizeof(navigation_interfaces__msg__AllRobotTargets),
  navigation_interfaces__msg__AllRobotTargets__rosidl_typesupport_introspection_c__AllRobotTargets_message_member_array,  // message members
  navigation_interfaces__msg__AllRobotTargets__rosidl_typesupport_introspection_c__AllRobotTargets_init_function,  // function to initialize message memory (memory has to be allocated)
  navigation_interfaces__msg__AllRobotTargets__rosidl_typesupport_introspection_c__AllRobotTargets_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t navigation_interfaces__msg__AllRobotTargets__rosidl_typesupport_introspection_c__AllRobotTargets_message_type_support_handle = {
  0,
  &navigation_interfaces__msg__AllRobotTargets__rosidl_typesupport_introspection_c__AllRobotTargets_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_navigation_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, navigation_interfaces, msg, AllRobotTargets)() {
  navigation_interfaces__msg__AllRobotTargets__rosidl_typesupport_introspection_c__AllRobotTargets_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, navigation_interfaces, msg, RobotTargets)();
  if (!navigation_interfaces__msg__AllRobotTargets__rosidl_typesupport_introspection_c__AllRobotTargets_message_type_support_handle.typesupport_identifier) {
    navigation_interfaces__msg__AllRobotTargets__rosidl_typesupport_introspection_c__AllRobotTargets_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &navigation_interfaces__msg__AllRobotTargets__rosidl_typesupport_introspection_c__AllRobotTargets_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
