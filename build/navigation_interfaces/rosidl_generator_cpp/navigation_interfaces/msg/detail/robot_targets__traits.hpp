// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from navigation_interfaces:msg/RobotTargets.idl
// generated code does not contain a copyright notice

#ifndef NAVIGATION_INTERFACES__MSG__DETAIL__ROBOT_TARGETS__TRAITS_HPP_
#define NAVIGATION_INTERFACES__MSG__DETAIL__ROBOT_TARGETS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "navigation_interfaces/msg/detail/robot_targets__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace navigation_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const RobotTargets & msg,
  std::ostream & out)
{
  out << "{";
  // member: robot_id
  {
    out << "robot_id: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_id, out);
    out << ", ";
  }

  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotTargets & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: robot_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot_id: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_id, out);
    out << "\n";
  }

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotTargets & msg, bool use_flow_style = false)
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
  const navigation_interfaces::msg::RobotTargets & msg,
  std::ostream & out, size_t indentation = 0)
{
  navigation_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use navigation_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const navigation_interfaces::msg::RobotTargets & msg)
{
  return navigation_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<navigation_interfaces::msg::RobotTargets>()
{
  return "navigation_interfaces::msg::RobotTargets";
}

template<>
inline const char * name<navigation_interfaces::msg::RobotTargets>()
{
  return "navigation_interfaces/msg/RobotTargets";
}

template<>
struct has_fixed_size<navigation_interfaces::msg::RobotTargets>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<navigation_interfaces::msg::RobotTargets>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<navigation_interfaces::msg::RobotTargets>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // NAVIGATION_INTERFACES__MSG__DETAIL__ROBOT_TARGETS__TRAITS_HPP_
