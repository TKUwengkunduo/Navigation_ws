// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from navigation_interfaces:msg/AllRobotTargets.idl
// generated code does not contain a copyright notice

#ifndef NAVIGATION_INTERFACES__MSG__DETAIL__ALL_ROBOT_TARGETS__TRAITS_HPP_
#define NAVIGATION_INTERFACES__MSG__DETAIL__ALL_ROBOT_TARGETS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "navigation_interfaces/msg/detail/all_robot_targets__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'targets'
#include "navigation_interfaces/msg/detail/robot_targets__traits.hpp"

namespace navigation_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const AllRobotTargets & msg,
  std::ostream & out)
{
  out << "{";
  // member: targets
  {
    if (msg.targets.size() == 0) {
      out << "targets: []";
    } else {
      out << "targets: [";
      size_t pending_items = msg.targets.size();
      for (auto item : msg.targets) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AllRobotTargets & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: targets
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.targets.size() == 0) {
      out << "targets: []\n";
    } else {
      out << "targets:\n";
      for (auto item : msg.targets) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AllRobotTargets & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace navigation_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use navigation_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const navigation_interfaces::msg::AllRobotTargets & msg,
  std::ostream & out, size_t indentation = 0)
{
  navigation_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use navigation_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const navigation_interfaces::msg::AllRobotTargets & msg)
{
  return navigation_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<navigation_interfaces::msg::AllRobotTargets>()
{
  return "navigation_interfaces::msg::AllRobotTargets";
}

template<>
inline const char * name<navigation_interfaces::msg::AllRobotTargets>()
{
  return "navigation_interfaces/msg/AllRobotTargets";
}

template<>
struct has_fixed_size<navigation_interfaces::msg::AllRobotTargets>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<navigation_interfaces::msg::AllRobotTargets>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<navigation_interfaces::msg::AllRobotTargets>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // NAVIGATION_INTERFACES__MSG__DETAIL__ALL_ROBOT_TARGETS__TRAITS_HPP_
