// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from navigation_interfaces:srv/Path.idl
// generated code does not contain a copyright notice

#ifndef NAVIGATION_INTERFACES__SRV__DETAIL__PATH__BUILDER_HPP_
#define NAVIGATION_INTERFACES__SRV__DETAIL__PATH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "navigation_interfaces/srv/detail/path__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace navigation_interfaces
{

namespace srv
{

namespace builder
{

class Init_Path_Request_positions
{
public:
  Init_Path_Request_positions()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::navigation_interfaces::srv::Path_Request positions(::navigation_interfaces::srv::Path_Request::_positions_type arg)
  {
    msg_.positions = std::move(arg);
    return std::move(msg_);
  }

private:
  ::navigation_interfaces::srv::Path_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::navigation_interfaces::srv::Path_Request>()
{
  return navigation_interfaces::srv::builder::Init_Path_Request_positions();
}

}  // namespace navigation_interfaces


namespace navigation_interfaces
{

namespace srv
{

namespace builder
{

class Init_Path_Response_success
{
public:
  Init_Path_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::navigation_interfaces::srv::Path_Response success(::navigation_interfaces::srv::Path_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::navigation_interfaces::srv::Path_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::navigation_interfaces::srv::Path_Response>()
{
  return navigation_interfaces::srv::builder::Init_Path_Response_success();
}

}  // namespace navigation_interfaces

#endif  // NAVIGATION_INTERFACES__SRV__DETAIL__PATH__BUILDER_HPP_
