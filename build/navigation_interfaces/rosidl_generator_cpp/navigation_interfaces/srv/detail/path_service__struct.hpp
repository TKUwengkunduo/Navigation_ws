// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from navigation_interfaces:srv/PathService.idl
// generated code does not contain a copyright notice

#ifndef NAVIGATION_INTERFACES__SRV__DETAIL__PATH_SERVICE__STRUCT_HPP_
#define NAVIGATION_INTERFACES__SRV__DETAIL__PATH_SERVICE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__navigation_interfaces__srv__PathService_Request __attribute__((deprecated))
#else
# define DEPRECATED__navigation_interfaces__srv__PathService_Request __declspec(deprecated)
#endif

namespace navigation_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct PathService_Request_
{
  using Type = PathService_Request_<ContainerAllocator>;

  explicit PathService_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->paths = "";
    }
  }

  explicit PathService_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : paths(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->paths = "";
    }
  }

  // field types and members
  using _paths_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _paths_type paths;

  // setters for named parameter idiom
  Type & set__paths(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->paths = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    navigation_interfaces::srv::PathService_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const navigation_interfaces::srv::PathService_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<navigation_interfaces::srv::PathService_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<navigation_interfaces::srv::PathService_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      navigation_interfaces::srv::PathService_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<navigation_interfaces::srv::PathService_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      navigation_interfaces::srv::PathService_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<navigation_interfaces::srv::PathService_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<navigation_interfaces::srv::PathService_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<navigation_interfaces::srv::PathService_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__navigation_interfaces__srv__PathService_Request
    std::shared_ptr<navigation_interfaces::srv::PathService_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__navigation_interfaces__srv__PathService_Request
    std::shared_ptr<navigation_interfaces::srv::PathService_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PathService_Request_ & other) const
  {
    if (this->paths != other.paths) {
      return false;
    }
    return true;
  }
  bool operator!=(const PathService_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PathService_Request_

// alias to use template instance with default allocator
using PathService_Request =
  navigation_interfaces::srv::PathService_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace navigation_interfaces


#ifndef _WIN32
# define DEPRECATED__navigation_interfaces__srv__PathService_Response __attribute__((deprecated))
#else
# define DEPRECATED__navigation_interfaces__srv__PathService_Response __declspec(deprecated)
#endif

namespace navigation_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct PathService_Response_
{
  using Type = PathService_Response_<ContainerAllocator>;

  explicit PathService_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->confirmation = "";
    }
  }

  explicit PathService_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : confirmation(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->confirmation = "";
    }
  }

  // field types and members
  using _confirmation_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _confirmation_type confirmation;

  // setters for named parameter idiom
  Type & set__confirmation(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->confirmation = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    navigation_interfaces::srv::PathService_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const navigation_interfaces::srv::PathService_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<navigation_interfaces::srv::PathService_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<navigation_interfaces::srv::PathService_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      navigation_interfaces::srv::PathService_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<navigation_interfaces::srv::PathService_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      navigation_interfaces::srv::PathService_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<navigation_interfaces::srv::PathService_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<navigation_interfaces::srv::PathService_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<navigation_interfaces::srv::PathService_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__navigation_interfaces__srv__PathService_Response
    std::shared_ptr<navigation_interfaces::srv::PathService_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__navigation_interfaces__srv__PathService_Response
    std::shared_ptr<navigation_interfaces::srv::PathService_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PathService_Response_ & other) const
  {
    if (this->confirmation != other.confirmation) {
      return false;
    }
    return true;
  }
  bool operator!=(const PathService_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PathService_Response_

// alias to use template instance with default allocator
using PathService_Response =
  navigation_interfaces::srv::PathService_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace navigation_interfaces

namespace navigation_interfaces
{

namespace srv
{

struct PathService
{
  using Request = navigation_interfaces::srv::PathService_Request;
  using Response = navigation_interfaces::srv::PathService_Response;
};

}  // namespace srv

}  // namespace navigation_interfaces

#endif  // NAVIGATION_INTERFACES__SRV__DETAIL__PATH_SERVICE__STRUCT_HPP_
