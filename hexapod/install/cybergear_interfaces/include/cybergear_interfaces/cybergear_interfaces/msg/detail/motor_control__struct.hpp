// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cybergear_interfaces:msg/MotorControl.idl
// generated code does not contain a copyright notice

#ifndef CYBERGEAR_INTERFACES__MSG__DETAIL__MOTOR_CONTROL__STRUCT_HPP_
#define CYBERGEAR_INTERFACES__MSG__DETAIL__MOTOR_CONTROL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'set_point'
#include "cybergear_interfaces/msg/detail/set_point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__cybergear_interfaces__msg__MotorControl __attribute__((deprecated))
#else
# define DEPRECATED__cybergear_interfaces__msg__MotorControl __declspec(deprecated)
#endif

namespace cybergear_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MotorControl_
{
  using Type = MotorControl_<ContainerAllocator>;

  explicit MotorControl_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : set_point(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->motor_id = 0;
      this->control_mode = 0;
    }
  }

  explicit MotorControl_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : set_point(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->motor_id = 0;
      this->control_mode = 0;
    }
  }

  // field types and members
  using _motor_id_type =
    int8_t;
  _motor_id_type motor_id;
  using _control_mode_type =
    uint8_t;
  _control_mode_type control_mode;
  using _set_point_type =
    cybergear_interfaces::msg::SetPoint_<ContainerAllocator>;
  _set_point_type set_point;

  // setters for named parameter idiom
  Type & set__motor_id(
    const int8_t & _arg)
  {
    this->motor_id = _arg;
    return *this;
  }
  Type & set__control_mode(
    const uint8_t & _arg)
  {
    this->control_mode = _arg;
    return *this;
  }
  Type & set__set_point(
    const cybergear_interfaces::msg::SetPoint_<ContainerAllocator> & _arg)
  {
    this->set_point = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cybergear_interfaces::msg::MotorControl_<ContainerAllocator> *;
  using ConstRawPtr =
    const cybergear_interfaces::msg::MotorControl_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cybergear_interfaces::msg::MotorControl_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cybergear_interfaces::msg::MotorControl_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cybergear_interfaces::msg::MotorControl_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cybergear_interfaces::msg::MotorControl_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cybergear_interfaces::msg::MotorControl_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cybergear_interfaces::msg::MotorControl_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cybergear_interfaces::msg::MotorControl_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cybergear_interfaces::msg::MotorControl_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cybergear_interfaces__msg__MotorControl
    std::shared_ptr<cybergear_interfaces::msg::MotorControl_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cybergear_interfaces__msg__MotorControl
    std::shared_ptr<cybergear_interfaces::msg::MotorControl_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MotorControl_ & other) const
  {
    if (this->motor_id != other.motor_id) {
      return false;
    }
    if (this->control_mode != other.control_mode) {
      return false;
    }
    if (this->set_point != other.set_point) {
      return false;
    }
    return true;
  }
  bool operator!=(const MotorControl_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MotorControl_

// alias to use template instance with default allocator
using MotorControl =
  cybergear_interfaces::msg::MotorControl_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace cybergear_interfaces

#endif  // CYBERGEAR_INTERFACES__MSG__DETAIL__MOTOR_CONTROL__STRUCT_HPP_
