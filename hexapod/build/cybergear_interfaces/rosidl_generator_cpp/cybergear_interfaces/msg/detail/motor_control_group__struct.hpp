// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cybergear_interfaces:msg/MotorControlGroup.idl
// generated code does not contain a copyright notice

#ifndef CYBERGEAR_INTERFACES__MSG__DETAIL__MOTOR_CONTROL_GROUP__STRUCT_HPP_
#define CYBERGEAR_INTERFACES__MSG__DETAIL__MOTOR_CONTROL_GROUP__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'motor_controls'
#include "cybergear_interfaces/msg/detail/motor_control__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__cybergear_interfaces__msg__MotorControlGroup __attribute__((deprecated))
#else
# define DEPRECATED__cybergear_interfaces__msg__MotorControlGroup __declspec(deprecated)
#endif

namespace cybergear_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MotorControlGroup_
{
  using Type = MotorControlGroup_<ContainerAllocator>;

  explicit MotorControlGroup_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit MotorControlGroup_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _motor_controls_type =
    std::vector<cybergear_interfaces::msg::MotorControl_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<cybergear_interfaces::msg::MotorControl_<ContainerAllocator>>>;
  _motor_controls_type motor_controls;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__motor_controls(
    const std::vector<cybergear_interfaces::msg::MotorControl_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<cybergear_interfaces::msg::MotorControl_<ContainerAllocator>>> & _arg)
  {
    this->motor_controls = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cybergear_interfaces::msg::MotorControlGroup_<ContainerAllocator> *;
  using ConstRawPtr =
    const cybergear_interfaces::msg::MotorControlGroup_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cybergear_interfaces::msg::MotorControlGroup_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cybergear_interfaces::msg::MotorControlGroup_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cybergear_interfaces::msg::MotorControlGroup_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cybergear_interfaces::msg::MotorControlGroup_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cybergear_interfaces::msg::MotorControlGroup_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cybergear_interfaces::msg::MotorControlGroup_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cybergear_interfaces::msg::MotorControlGroup_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cybergear_interfaces::msg::MotorControlGroup_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cybergear_interfaces__msg__MotorControlGroup
    std::shared_ptr<cybergear_interfaces::msg::MotorControlGroup_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cybergear_interfaces__msg__MotorControlGroup
    std::shared_ptr<cybergear_interfaces::msg::MotorControlGroup_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MotorControlGroup_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->motor_controls != other.motor_controls) {
      return false;
    }
    return true;
  }
  bool operator!=(const MotorControlGroup_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MotorControlGroup_

// alias to use template instance with default allocator
using MotorControlGroup =
  cybergear_interfaces::msg::MotorControlGroup_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace cybergear_interfaces

#endif  // CYBERGEAR_INTERFACES__MSG__DETAIL__MOTOR_CONTROL_GROUP__STRUCT_HPP_
