// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from navigation_interfaces:srv/PathService.idl
// generated code does not contain a copyright notice

#ifndef NAVIGATION_INTERFACES__SRV__DETAIL__PATH_SERVICE__TRAITS_HPP_
#define NAVIGATION_INTERFACES__SRV__DETAIL__PATH_SERVICE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "navigation_interfaces/srv/detail/path_service__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace navigation_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const PathService_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: paths
  {
    out << "paths: ";
    rosidl_generator_traits::value_to_yaml(msg.paths, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PathService_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: paths
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "paths: ";
    rosidl_generator_traits::value_to_yaml(msg.paths, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PathService_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace navigation_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use navigation_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const navigation_interfaces::srv::PathService_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  navigation_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use navigation_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const navigation_interfaces::srv::PathService_Request & msg)
{
  return navigation_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<navigation_interfaces::srv::PathService_Request>()
{
  return "navigation_interfaces::srv::PathService_Request";
}

template<>
inline const char * name<navigation_interfaces::srv::PathService_Request>()
{
  return "navigation_interfaces/srv/PathService_Request";
}

template<>
struct has_fixed_size<navigation_interfaces::srv::PathService_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<navigation_interfaces::srv::PathService_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<navigation_interfaces::srv::PathService_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace navigation_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const PathService_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: confirmation
  {
    out << "confirmation: ";
    rosidl_generator_traits::value_to_yaml(msg.confirmation, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PathService_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: confirmation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "confirmation: ";
    rosidl_generator_traits::value_to_yaml(msg.confirmation, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PathService_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace navigation_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use navigation_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const navigation_interfaces::srv::PathService_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  navigation_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use navigation_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const navigation_interfaces::srv::PathService_Response & msg)
{
  return navigation_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<navigation_interfaces::srv::PathService_Response>()
{
  return "navigation_interfaces::srv::PathService_Response";
}

template<>
inline const char * name<navigation_interfaces::srv::PathService_Response>()
{
  return "navigation_interfaces/srv/PathService_Response";
}

template<>
struct has_fixed_size<navigation_interfaces::srv::PathService_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<navigation_interfaces::srv::PathService_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<navigation_interfaces::srv::PathService_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<navigation_interfaces::srv::PathService>()
{
  return "navigation_interfaces::srv::PathService";
}

template<>
inline const char * name<navigation_interfaces::srv::PathService>()
{
  return "navigation_interfaces/srv/PathService";
}

template<>
struct has_fixed_size<navigation_interfaces::srv::PathService>
  : std::integral_constant<
    bool,
    has_fixed_size<navigation_interfaces::srv::PathService_Request>::value &&
    has_fixed_size<navigation_interfaces::srv::PathService_Response>::value
  >
{
};

template<>
struct has_bounded_size<navigation_interfaces::srv::PathService>
  : std::integral_constant<
    bool,
    has_bounded_size<navigation_interfaces::srv::PathService_Request>::value &&
    has_bounded_size<navigation_interfaces::srv::PathService_Response>::value
  >
{
};

template<>
struct is_service<navigation_interfaces::srv::PathService>
  : std::true_type
{
};

template<>
struct is_service_request<navigation_interfaces::srv::PathService_Request>
  : std::true_type
{
};

template<>
struct is_service_response<navigation_interfaces::srv::PathService_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // NAVIGATION_INTERFACES__SRV__DETAIL__PATH_SERVICE__TRAITS_HPP_
