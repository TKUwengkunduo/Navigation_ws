// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from navigation_interfaces:msg/RobotTargets.idl
// generated code does not contain a copyright notice

#ifndef NAVIGATION_INTERFACES__MSG__DETAIL__ROBOT_TARGETS__BUILDER_HPP_
#define NAVIGATION_INTERFACES__MSG__DETAIL__ROBOT_TARGETS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "navigation_interfaces/msg/detail/robot_targets__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace navigation_interfaces
{

namespace msg
{

namespace builder
{

class Init_RobotTargets_y
{
public:
  explicit Init_RobotTargets_y(::navigation_interfaces::msg::RobotTargets & msg)
  : msg_(msg)
  {}
  ::navigation_interfaces::msg::RobotTargets y(::navigation_interfaces::msg::RobotTargets::_y_type arg)
  {
    msg_.y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::navigation_interfaces::msg::RobotTargets msg_;
};

class Init_RobotTargets_x
{
public:
  explicit Init_RobotTargets_x(::navigation_interfaces::msg::RobotTargets & msg)
  : msg_(msg)
  {}
  Init_RobotTargets_y x(::navigation_interfaces::msg::RobotTargets::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_RobotTargets_y(msg_);
  }

private:
  ::navigation_interfaces::msg::RobotTargets msg_;
};

class Init_RobotTargets_robot_id
{
public:
  Init_RobotTargets_robot_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotTargets_x robot_id(::navigation_interfaces::msg::RobotTargets::_robot_id_type arg)
  {
    msg_.robot_id = std::move(arg);
    return Init_RobotTargets_x(msg_);
  }

private:
  ::navigation_interfaces::msg::RobotTargets msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::navigation_interfaces::msg::RobotTargets>()
{
  return navigation_interfaces::msg::builder::Init_RobotTargets_robot_id();
}

}  // namespace navigation_interfaces

#endif  // NAVIGATION_INTERFACES__MSG__DETAIL__ROBOT_TARGETS__BUILDER_HPP_
