// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from navigation_interfaces:srv/Path.idl
// generated code does not contain a copyright notice

#ifndef NAVIGATION_INTERFACES__SRV__DETAIL__PATH__STRUCT_HPP_
#define NAVIGATION_INTERFACES__SRV__DETAIL__PATH__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__navigation_interfaces__srv__Path_Request __attribute__((deprecated))
#else
# define DEPRECATED__navigation_interfaces__srv__Path_Request __declspec(deprecated)
#endif

namespace navigation_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Path_Request_
{
  using Type = Path_Request_<ContainerAllocator>;

  explicit Path_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit Path_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _positions_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _positions_type positions;

  // setters for named parameter idiom
  Type & set__positions(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->positions = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    navigation_interfaces::srv::Path_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const navigation_interfaces::srv::Path_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<navigation_interfaces::srv::Path_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<navigation_interfaces::srv::Path_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      navigation_interfaces::srv::Path_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<navigation_interfaces::srv::Path_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      navigation_interfaces::srv::Path_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<navigation_interfaces::srv::Path_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<navigation_interfaces::srv::Path_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<navigation_interfaces::srv::Path_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__navigation_interfaces__srv__Path_Request
    std::shared_ptr<navigation_interfaces::srv::Path_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__navigation_interfaces__srv__Path_Request
    std::shared_ptr<navigation_interfaces::srv::Path_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Path_Request_ & other) const
  {
    if (this->positions != other.positions) {
      return false;
    }
    return true;
  }
  bool operator!=(const Path_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Path_Request_

// alias to use template instance with default allocator
using Path_Request =
  navigation_interfaces::srv::Path_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace navigation_interfaces


#ifndef _WIN32
# define DEPRECATED__navigation_interfaces__srv__Path_Response __attribute__((deprecated))
#else
# define DEPRECATED__navigation_interfaces__srv__Path_Response __declspec(deprecated)
#endif

namespace navigation_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Path_Response_
{
  using Type = Path_Response_<ContainerAllocator>;

  explicit Path_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit Path_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    navigation_interfaces::srv::Path_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const navigation_interfaces::srv::Path_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<navigation_interfaces::srv::Path_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<navigation_interfaces::srv::Path_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      navigation_interfaces::srv::Path_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<navigation_interfaces::srv::Path_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      navigation_interfaces::srv::Path_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<navigation_interfaces::srv::Path_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<navigation_interfaces::srv::Path_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<navigation_interfaces::srv::Path_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__navigation_interfaces__srv__Path_Response
    std::shared_ptr<navigation_interfaces::srv::Path_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__navigation_interfaces__srv__Path_Response
    std::shared_ptr<navigation_interfaces::srv::Path_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Path_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const Path_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Path_Response_

// alias to use template instance with default allocator
using Path_Response =
  navigation_interfaces::srv::Path_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace navigation_interfaces

namespace navigation_interfaces
{

namespace srv
{

struct Path
{
  using Request = navigation_interfaces::srv::Path_Request;
  using Response = navigation_interfaces::srv::Path_Response;
};

}  // namespace srv

}  // namespace navigation_interfaces

#endif  // NAVIGATION_INTERFACES__SRV__DETAIL__PATH__STRUCT_HPP_
