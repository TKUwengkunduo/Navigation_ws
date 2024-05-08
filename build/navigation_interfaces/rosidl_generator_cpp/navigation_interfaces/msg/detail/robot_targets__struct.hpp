// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from navigation_interfaces:msg/RobotTargets.idl
// generated code does not contain a copyright notice

#ifndef NAVIGATION_INTERFACES__MSG__DETAIL__ROBOT_TARGETS__STRUCT_HPP_
#define NAVIGATION_INTERFACES__MSG__DETAIL__ROBOT_TARGETS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__navigation_interfaces__msg__RobotTargets __attribute__((deprecated))
#else
# define DEPRECATED__navigation_interfaces__msg__RobotTargets __declspec(deprecated)
#endif

namespace navigation_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RobotTargets_
{
  using Type = RobotTargets_<ContainerAllocator>;

  explicit RobotTargets_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_id = "";
      this->x = 0.0;
      this->y = 0.0;
    }
  }

  explicit RobotTargets_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : robot_id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_id = "";
      this->x = 0.0;
      this->y = 0.0;
    }
  }

  // field types and members
  using _robot_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _robot_id_type robot_id;
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;

  // setters for named parameter idiom
  Type & set__robot_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->robot_id = _arg;
    return *this;
  }
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    navigation_interfaces::msg::RobotTargets_<ContainerAllocator> *;
  using ConstRawPtr =
    const navigation_interfaces::msg::RobotTargets_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<navigation_interfaces::msg::RobotTargets_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<navigation_interfaces::msg::RobotTargets_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      navigation_interfaces::msg::RobotTargets_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<navigation_interfaces::msg::RobotTargets_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      navigation_interfaces::msg::RobotTargets_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<navigation_interfaces::msg::RobotTargets_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<navigation_interfaces::msg::RobotTargets_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<navigation_interfaces::msg::RobotTargets_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__navigation_interfaces__msg__RobotTargets
    std::shared_ptr<navigation_interfaces::msg::RobotTargets_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__navigation_interfaces__msg__RobotTargets
    std::shared_ptr<navigation_interfaces::msg::RobotTargets_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotTargets_ & other) const
  {
    if (this->robot_id != other.robot_id) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotTargets_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotTargets_

// alias to use template instance with default allocator
using RobotTargets =
  navigation_interfaces::msg::RobotTargets_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace navigation_interfaces

#endif  // NAVIGATION_INTERFACES__MSG__DETAIL__ROBOT_TARGETS__STRUCT_HPP_
