// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from navigation_interfaces:msg/AllRobotTargets.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "navigation_interfaces/msg/detail/all_robot_targets__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace navigation_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void AllRobotTargets_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) navigation_interfaces::msg::AllRobotTargets(_init);
}

void AllRobotTargets_fini_function(void * message_memory)
{
  auto typed_message = static_cast<navigation_interfaces::msg::AllRobotTargets *>(message_memory);
  typed_message->~AllRobotTargets();
}

size_t size_function__AllRobotTargets__targets(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<navigation_interfaces::msg::RobotTargets> *>(untyped_member);
  return member->size();
}

const void * get_const_function__AllRobotTargets__targets(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<navigation_interfaces::msg::RobotTargets> *>(untyped_member);
  return &member[index];
}

void * get_function__AllRobotTargets__targets(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<navigation_interfaces::msg::RobotTargets> *>(untyped_member);
  return &member[index];
}

void fetch_function__AllRobotTargets__targets(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const navigation_interfaces::msg::RobotTargets *>(
    get_const_function__AllRobotTargets__targets(untyped_member, index));
  auto & value = *reinterpret_cast<navigation_interfaces::msg::RobotTargets *>(untyped_value);
  value = item;
}

void assign_function__AllRobotTargets__targets(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<navigation_interfaces::msg::RobotTargets *>(
    get_function__AllRobotTargets__targets(untyped_member, index));
  const auto & value = *reinterpret_cast<const navigation_interfaces::msg::RobotTargets *>(untyped_value);
  item = value;
}

void resize_function__AllRobotTargets__targets(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<navigation_interfaces::msg::RobotTargets> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember AllRobotTargets_message_member_array[1] = {
  {
    "targets",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<navigation_interfaces::msg::RobotTargets>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(navigation_interfaces::msg::AllRobotTargets, targets),  // bytes offset in struct
    nullptr,  // default value
    size_function__AllRobotTargets__targets,  // size() function pointer
    get_const_function__AllRobotTargets__targets,  // get_const(index) function pointer
    get_function__AllRobotTargets__targets,  // get(index) function pointer
    fetch_function__AllRobotTargets__targets,  // fetch(index, &value) function pointer
    assign_function__AllRobotTargets__targets,  // assign(index, value) function pointer
    resize_function__AllRobotTargets__targets  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers AllRobotTargets_message_members = {
  "navigation_interfaces::msg",  // message namespace
  "AllRobotTargets",  // message name
  1,  // number of fields
  sizeof(navigation_interfaces::msg::AllRobotTargets),
  AllRobotTargets_message_member_array,  // message members
  AllRobotTargets_init_function,  // function to initialize message memory (memory has to be allocated)
  AllRobotTargets_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t AllRobotTargets_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &AllRobotTargets_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace navigation_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<navigation_interfaces::msg::AllRobotTargets>()
{
  return &::navigation_interfaces::msg::rosidl_typesupport_introspection_cpp::AllRobotTargets_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, navigation_interfaces, msg, AllRobotTargets)() {
  return &::navigation_interfaces::msg::rosidl_typesupport_introspection_cpp::AllRobotTargets_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
