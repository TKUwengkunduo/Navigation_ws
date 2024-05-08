// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from navigation_interfaces:msg/AllRobotTargets.idl
// generated code does not contain a copyright notice

#ifndef NAVIGATION_INTERFACES__MSG__DETAIL__ALL_ROBOT_TARGETS__STRUCT_HPP_
#define NAVIGATION_INTERFACES__MSG__DETAIL__ALL_ROBOT_TARGETS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'targets'
#include "navigation_interfaces/msg/detail/robot_targets__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__navigation_interfaces__msg__AllRobotTargets __attribute__((deprecated))
#else
# define DEPRECATED__navigation_interfaces__msg__AllRobotTargets __declspec(deprecated)
#endif

namespace navigation_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct AllRobotTargets_
{
  using Type = AllRobotTargets_<ContainerAllocator>;

  explicit AllRobotTargets_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit AllRobotTargets_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _targets_type =
    std::vector<navigation_interfaces::msg::RobotTargets_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<navigation_interfaces::msg::RobotTargets_<ContainerAllocator>>>;
  _targets_type targets;

  // setters for named parameter idiom
  Type & set__targets(
    const std::vector<navigation_interfaces::msg::RobotTargets_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<navigation_interfaces::msg::RobotTargets_<ContainerAllocator>>> & _arg)
  {
    this->targets = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    navigation_interfaces::msg::AllRobotTargets_<ContainerAllocator> *;
  using ConstRawPtr =
    const navigation_interfaces::msg::AllRobotTargets_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<navigation_interfaces::msg::AllRobotTargets_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<navigation_interfaces::msg::AllRobotTargets_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      navigation_interfaces::msg::AllRobotTargets_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<navigation_interfaces::msg::AllRobotTargets_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      navigation_interfaces::msg::AllRobotTargets_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<navigation_interfaces::msg::AllRobotTargets_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<navigation_interfaces::msg::AllRobotTargets_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<navigation_interfaces::msg::AllRobotTargets_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__navigation_interfaces__msg__AllRobotTargets
    std::shared_ptr<navigation_interfaces::msg::AllRobotTargets_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__navigation_interfaces__msg__AllRobotTargets
    std::shared_ptr<navigation_interfaces::msg::AllRobotTargets_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AllRobotTargets_ & other) const
  {
    if (this->targets != other.targets) {
      return false;
    }
    return true;
  }
  bool operator!=(const AllRobotTargets_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AllRobotTargets_

// alias to use template instance with default allocator
using AllRobotTargets =
  navigation_interfaces::msg::AllRobotTargets_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace navigation_interfaces

#endif  // NAVIGATION_INTERFACES__MSG__DETAIL__ALL_ROBOT_TARGETS__STRUCT_HPP_
