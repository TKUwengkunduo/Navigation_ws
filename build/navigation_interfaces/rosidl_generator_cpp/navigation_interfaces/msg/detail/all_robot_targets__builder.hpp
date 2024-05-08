// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from navigation_interfaces:msg/AllRobotTargets.idl
// generated code does not contain a copyright notice

#ifndef NAVIGATION_INTERFACES__MSG__DETAIL__ALL_ROBOT_TARGETS__BUILDER_HPP_
#define NAVIGATION_INTERFACES__MSG__DETAIL__ALL_ROBOT_TARGETS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "navigation_interfaces/msg/detail/all_robot_targets__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace navigation_interfaces
{

namespace msg
{

namespace builder
{

class Init_AllRobotTargets_targets
{
public:
  Init_AllRobotTargets_targets()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::navigation_interfaces::msg::AllRobotTargets targets(::navigation_interfaces::msg::AllRobotTargets::_targets_type arg)
  {
    msg_.targets = std::move(arg);
    return std::move(msg_);
  }

private:
  ::navigation_interfaces::msg::AllRobotTargets msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::navigation_interfaces::msg::AllRobotTargets>()
{
  return navigation_interfaces::msg::builder::Init_AllRobotTargets_targets();
}

}  // namespace navigation_interfaces

#endif  // NAVIGATION_INTERFACES__MSG__DETAIL__ALL_ROBOT_TARGETS__BUILDER_HPP_
