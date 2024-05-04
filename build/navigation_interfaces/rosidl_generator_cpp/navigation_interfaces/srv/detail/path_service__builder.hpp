// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from navigation_interfaces:srv/PathService.idl
// generated code does not contain a copyright notice

#ifndef NAVIGATION_INTERFACES__SRV__DETAIL__PATH_SERVICE__BUILDER_HPP_
#define NAVIGATION_INTERFACES__SRV__DETAIL__PATH_SERVICE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "navigation_interfaces/srv/detail/path_service__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace navigation_interfaces
{

namespace srv
{

namespace builder
{

class Init_PathService_Request_paths
{
public:
  Init_PathService_Request_paths()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::navigation_interfaces::srv::PathService_Request paths(::navigation_interfaces::srv::PathService_Request::_paths_type arg)
  {
    msg_.paths = std::move(arg);
    return std::move(msg_);
  }

private:
  ::navigation_interfaces::srv::PathService_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::navigation_interfaces::srv::PathService_Request>()
{
  return navigation_interfaces::srv::builder::Init_PathService_Request_paths();
}

}  // namespace navigation_interfaces


namespace navigation_interfaces
{

namespace srv
{

namespace builder
{

class Init_PathService_Response_confirmation
{
public:
  Init_PathService_Response_confirmation()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::navigation_interfaces::srv::PathService_Response confirmation(::navigation_interfaces::srv::PathService_Response::_confirmation_type arg)
  {
    msg_.confirmation = std::move(arg);
    return std::move(msg_);
  }

private:
  ::navigation_interfaces::srv::PathService_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::navigation_interfaces::srv::PathService_Response>()
{
  return navigation_interfaces::srv::builder::Init_PathService_Response_confirmation();
}

}  // namespace navigation_interfaces

#endif  // NAVIGATION_INTERFACES__SRV__DETAIL__PATH_SERVICE__BUILDER_HPP_
