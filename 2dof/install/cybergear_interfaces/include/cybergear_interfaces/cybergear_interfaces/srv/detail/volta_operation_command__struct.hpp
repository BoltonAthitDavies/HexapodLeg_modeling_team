// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cybergear_interfaces:srv/VoltaOperationCommand.idl
// generated code does not contain a copyright notice

#ifndef CYBERGEAR_INTERFACES__SRV__DETAIL__VOLTA_OPERATION_COMMAND__STRUCT_HPP_
#define CYBERGEAR_INTERFACES__SRV__DETAIL__VOLTA_OPERATION_COMMAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__cybergear_interfaces__srv__VoltaOperationCommand_Request __attribute__((deprecated))
#else
# define DEPRECATED__cybergear_interfaces__srv__VoltaOperationCommand_Request __declspec(deprecated)
#endif

namespace cybergear_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct VoltaOperationCommand_Request_
{
  using Type = VoltaOperationCommand_Request_<ContainerAllocator>;

  explicit VoltaOperationCommand_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->operation_command = 0;
    }
  }

  explicit VoltaOperationCommand_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->operation_command = 0;
    }
  }

  // field types and members
  using _operation_command_type =
    int16_t;
  _operation_command_type operation_command;

  // setters for named parameter idiom
  Type & set__operation_command(
    const int16_t & _arg)
  {
    this->operation_command = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cybergear_interfaces::srv::VoltaOperationCommand_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const cybergear_interfaces::srv::VoltaOperationCommand_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cybergear_interfaces::srv::VoltaOperationCommand_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cybergear_interfaces::srv::VoltaOperationCommand_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cybergear_interfaces::srv::VoltaOperationCommand_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cybergear_interfaces::srv::VoltaOperationCommand_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cybergear_interfaces::srv::VoltaOperationCommand_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cybergear_interfaces::srv::VoltaOperationCommand_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cybergear_interfaces::srv::VoltaOperationCommand_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cybergear_interfaces::srv::VoltaOperationCommand_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cybergear_interfaces__srv__VoltaOperationCommand_Request
    std::shared_ptr<cybergear_interfaces::srv::VoltaOperationCommand_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cybergear_interfaces__srv__VoltaOperationCommand_Request
    std::shared_ptr<cybergear_interfaces::srv::VoltaOperationCommand_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const VoltaOperationCommand_Request_ & other) const
  {
    if (this->operation_command != other.operation_command) {
      return false;
    }
    return true;
  }
  bool operator!=(const VoltaOperationCommand_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct VoltaOperationCommand_Request_

// alias to use template instance with default allocator
using VoltaOperationCommand_Request =
  cybergear_interfaces::srv::VoltaOperationCommand_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace cybergear_interfaces


#ifndef _WIN32
# define DEPRECATED__cybergear_interfaces__srv__VoltaOperationCommand_Response __attribute__((deprecated))
#else
# define DEPRECATED__cybergear_interfaces__srv__VoltaOperationCommand_Response __declspec(deprecated)
#endif

namespace cybergear_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct VoltaOperationCommand_Response_
{
  using Type = VoltaOperationCommand_Response_<ContainerAllocator>;

  explicit VoltaOperationCommand_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->response = "";
    }
  }

  explicit VoltaOperationCommand_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : response(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->response = "";
    }
  }

  // field types and members
  using _response_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__response(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cybergear_interfaces::srv::VoltaOperationCommand_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const cybergear_interfaces::srv::VoltaOperationCommand_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cybergear_interfaces::srv::VoltaOperationCommand_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cybergear_interfaces::srv::VoltaOperationCommand_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cybergear_interfaces::srv::VoltaOperationCommand_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cybergear_interfaces::srv::VoltaOperationCommand_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cybergear_interfaces::srv::VoltaOperationCommand_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cybergear_interfaces::srv::VoltaOperationCommand_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cybergear_interfaces::srv::VoltaOperationCommand_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cybergear_interfaces::srv::VoltaOperationCommand_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cybergear_interfaces__srv__VoltaOperationCommand_Response
    std::shared_ptr<cybergear_interfaces::srv::VoltaOperationCommand_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cybergear_interfaces__srv__VoltaOperationCommand_Response
    std::shared_ptr<cybergear_interfaces::srv::VoltaOperationCommand_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const VoltaOperationCommand_Response_ & other) const
  {
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const VoltaOperationCommand_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct VoltaOperationCommand_Response_

// alias to use template instance with default allocator
using VoltaOperationCommand_Response =
  cybergear_interfaces::srv::VoltaOperationCommand_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace cybergear_interfaces

namespace cybergear_interfaces
{

namespace srv
{

struct VoltaOperationCommand
{
  using Request = cybergear_interfaces::srv::VoltaOperationCommand_Request;
  using Response = cybergear_interfaces::srv::VoltaOperationCommand_Response;
};

}  // namespace srv

}  // namespace cybergear_interfaces

#endif  // CYBERGEAR_INTERFACES__SRV__DETAIL__VOLTA_OPERATION_COMMAND__STRUCT_HPP_
