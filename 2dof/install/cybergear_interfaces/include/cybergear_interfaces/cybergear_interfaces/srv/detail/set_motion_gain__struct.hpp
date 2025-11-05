// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cybergear_interfaces:srv/SetMotionGain.idl
// generated code does not contain a copyright notice

#ifndef CYBERGEAR_INTERFACES__SRV__DETAIL__SET_MOTION_GAIN__STRUCT_HPP_
#define CYBERGEAR_INTERFACES__SRV__DETAIL__SET_MOTION_GAIN__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__cybergear_interfaces__srv__SetMotionGain_Request __attribute__((deprecated))
#else
# define DEPRECATED__cybergear_interfaces__srv__SetMotionGain_Request __declspec(deprecated)
#endif

namespace cybergear_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetMotionGain_Request_
{
  using Type = SetMotionGain_Request_<ContainerAllocator>;

  explicit SetMotionGain_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->motor_id = 0;
      this->param_name = "";
      this->position = 0.0f;
      this->velocity = 0.0f;
      this->effort = 0.0f;
      this->kp = 0.0f;
      this->kd = 0.0f;
    }
  }

  explicit SetMotionGain_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : param_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->motor_id = 0;
      this->param_name = "";
      this->position = 0.0f;
      this->velocity = 0.0f;
      this->effort = 0.0f;
      this->kp = 0.0f;
      this->kd = 0.0f;
    }
  }

  // field types and members
  using _motor_id_type =
    int8_t;
  _motor_id_type motor_id;
  using _param_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _param_name_type param_name;
  using _position_type =
    float;
  _position_type position;
  using _velocity_type =
    float;
  _velocity_type velocity;
  using _effort_type =
    float;
  _effort_type effort;
  using _kp_type =
    float;
  _kp_type kp;
  using _kd_type =
    float;
  _kd_type kd;

  // setters for named parameter idiom
  Type & set__motor_id(
    const int8_t & _arg)
  {
    this->motor_id = _arg;
    return *this;
  }
  Type & set__param_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->param_name = _arg;
    return *this;
  }
  Type & set__position(
    const float & _arg)
  {
    this->position = _arg;
    return *this;
  }
  Type & set__velocity(
    const float & _arg)
  {
    this->velocity = _arg;
    return *this;
  }
  Type & set__effort(
    const float & _arg)
  {
    this->effort = _arg;
    return *this;
  }
  Type & set__kp(
    const float & _arg)
  {
    this->kp = _arg;
    return *this;
  }
  Type & set__kd(
    const float & _arg)
  {
    this->kd = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cybergear_interfaces::srv::SetMotionGain_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const cybergear_interfaces::srv::SetMotionGain_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cybergear_interfaces::srv::SetMotionGain_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cybergear_interfaces::srv::SetMotionGain_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cybergear_interfaces::srv::SetMotionGain_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cybergear_interfaces::srv::SetMotionGain_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cybergear_interfaces::srv::SetMotionGain_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cybergear_interfaces::srv::SetMotionGain_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cybergear_interfaces::srv::SetMotionGain_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cybergear_interfaces::srv::SetMotionGain_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cybergear_interfaces__srv__SetMotionGain_Request
    std::shared_ptr<cybergear_interfaces::srv::SetMotionGain_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cybergear_interfaces__srv__SetMotionGain_Request
    std::shared_ptr<cybergear_interfaces::srv::SetMotionGain_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetMotionGain_Request_ & other) const
  {
    if (this->motor_id != other.motor_id) {
      return false;
    }
    if (this->param_name != other.param_name) {
      return false;
    }
    if (this->position != other.position) {
      return false;
    }
    if (this->velocity != other.velocity) {
      return false;
    }
    if (this->effort != other.effort) {
      return false;
    }
    if (this->kp != other.kp) {
      return false;
    }
    if (this->kd != other.kd) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetMotionGain_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetMotionGain_Request_

// alias to use template instance with default allocator
using SetMotionGain_Request =
  cybergear_interfaces::srv::SetMotionGain_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace cybergear_interfaces


#ifndef _WIN32
# define DEPRECATED__cybergear_interfaces__srv__SetMotionGain_Response __attribute__((deprecated))
#else
# define DEPRECATED__cybergear_interfaces__srv__SetMotionGain_Response __declspec(deprecated)
#endif

namespace cybergear_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetMotionGain_Response_
{
  using Type = SetMotionGain_Response_<ContainerAllocator>;

  explicit SetMotionGain_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit SetMotionGain_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cybergear_interfaces::srv::SetMotionGain_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const cybergear_interfaces::srv::SetMotionGain_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cybergear_interfaces::srv::SetMotionGain_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cybergear_interfaces::srv::SetMotionGain_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cybergear_interfaces::srv::SetMotionGain_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cybergear_interfaces::srv::SetMotionGain_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cybergear_interfaces::srv::SetMotionGain_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cybergear_interfaces::srv::SetMotionGain_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cybergear_interfaces::srv::SetMotionGain_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cybergear_interfaces::srv::SetMotionGain_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cybergear_interfaces__srv__SetMotionGain_Response
    std::shared_ptr<cybergear_interfaces::srv::SetMotionGain_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cybergear_interfaces__srv__SetMotionGain_Response
    std::shared_ptr<cybergear_interfaces::srv::SetMotionGain_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetMotionGain_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetMotionGain_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetMotionGain_Response_

// alias to use template instance with default allocator
using SetMotionGain_Response =
  cybergear_interfaces::srv::SetMotionGain_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace cybergear_interfaces

namespace cybergear_interfaces
{

namespace srv
{

struct SetMotionGain
{
  using Request = cybergear_interfaces::srv::SetMotionGain_Request;
  using Response = cybergear_interfaces::srv::SetMotionGain_Response;
};

}  // namespace srv

}  // namespace cybergear_interfaces

#endif  // CYBERGEAR_INTERFACES__SRV__DETAIL__SET_MOTION_GAIN__STRUCT_HPP_
