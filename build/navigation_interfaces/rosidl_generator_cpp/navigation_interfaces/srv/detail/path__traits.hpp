// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from navigation_interfaces:srv/Path.idl
// generated code does not contain a copyright notice

#ifndef NAVIGATION_INTERFACES__SRV__DETAIL__PATH__TRAITS_HPP_
#define NAVIGATION_INTERFACES__SRV__DETAIL__PATH__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "navigation_interfaces/srv/detail/path__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace navigation_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Path_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: positions
  {
    if (msg.positions.size() == 0) {
      out << "positions: []";
    } else {
      out << "positions: [";
      size_t pending_items = msg.positions.size();
      for (auto item : msg.positions) {
        rosidl_generator_traits::value_to_yaml(item, out);
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
  const Path_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: positions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.positions.size() == 0) {
      out << "positions: []\n";
    } else {
      out << "positions:\n";
      for (auto item : msg.positions) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Path_Request & msg, bool use_flow_style = false)
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
  const navigation_interfaces::srv::Path_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  navigation_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use navigation_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const navigation_interfaces::srv::Path_Request & msg)
{
  return navigation_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<navigation_interfaces::srv::Path_Request>()
{
  return "navigation_interfaces::srv::Path_Request";
}

template<>
inline const char * name<navigation_interfaces::srv::Path_Request>()
{
  return "navigation_interfaces/srv/Path_Request";
}

template<>
struct has_fixed_size<navigation_interfaces::srv::Path_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<navigation_interfaces::srv::Path_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<navigation_interfaces::srv::Path_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace navigation_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Path_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Path_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Path_Response & msg, bool use_flow_style = false)
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
  const navigation_interfaces::srv::Path_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  navigation_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use navigation_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const navigation_interfaces::srv::Path_Response & msg)
{
  return navigation_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<navigation_interfaces::srv::Path_Response>()
{
  return "navigation_interfaces::srv::Path_Response";
}

template<>
inline const char * name<navigation_interfaces::srv::Path_Response>()
{
  return "navigation_interfaces/srv/Path_Response";
}

template<>
struct has_fixed_size<navigation_interfaces::srv::Path_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<navigation_interfaces::srv::Path_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<navigation_interfaces::srv::Path_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<navigation_interfaces::srv::Path>()
{
  return "navigation_interfaces::srv::Path";
}

template<>
inline const char * name<navigation_interfaces::srv::Path>()
{
  return "navigation_interfaces/srv/Path";
}

template<>
struct has_fixed_size<navigation_interfaces::srv::Path>
  : std::integral_constant<
    bool,
    has_fixed_size<navigation_interfaces::srv::Path_Request>::value &&
    has_fixed_size<navigation_interfaces::srv::Path_Response>::value
  >
{
};

template<>
struct has_bounded_size<navigation_interfaces::srv::Path>
  : std::integral_constant<
    bool,
    has_bounded_size<navigation_interfaces::srv::Path_Request>::value &&
    has_bounded_size<navigation_interfaces::srv::Path_Response>::value
  >
{
};

template<>
struct is_service<navigation_interfaces::srv::Path>
  : std::true_type
{
};

template<>
struct is_service_request<navigation_interfaces::srv::Path_Request>
  : std::true_type
{
};

template<>
struct is_service_response<navigation_interfaces::srv::Path_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // NAVIGATION_INTERFACES__SRV__DETAIL__PATH__TRAITS_HPP_
