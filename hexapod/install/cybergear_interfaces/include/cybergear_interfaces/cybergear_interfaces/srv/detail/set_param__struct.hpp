// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cybergear_interfaces:srv/SetParam.idl
// generated code does not contain a copyright notice

#ifndef CYBERGEAR_INTERFACES__SRV__DETAIL__SET_PARAM__STRUCT_HPP_
#define CYBERGEAR_INTERFACES__SRV__DETAIL__SET_PARAM__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__cybergear_interfaces__srv__SetParam_Request __attribute__((deprecated))
#else
# define DEPRECATED__cybergear_interfaces__srv__SetParam_Request __declspec(deprecated)
#endif

namespace cybergear_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetParam_Request_
{
  using Type = SetParam_Request_<ContainerAllocator>;

  explicit SetParam_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->motor_id = 0;
      this->control_mode = 0;
      this->param_name = "";
      this->communication_type = 0;
      this->param_value = 0.0f;
      this->cur_kp = 0.0f;
      this->cur_ki = 0.0f;
      this->spd_kp = 0.0f;
      this->spd_ki = 0.0f;
      this->loc_kp = 0.0f;
      this->spd_filt_gain = 0.0f;
      this->limit_spd = 0.0f;
      this->limit_cur = 0.0f;
    }
  }

  explicit SetParam_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : param_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->motor_id = 0;
      this->control_mode = 0;
      this->param_name = "";
      this->communication_type = 0;
      this->param_value = 0.0f;
      this->cur_kp = 0.0f;
      this->cur_ki = 0.0f;
      this->spd_kp = 0.0f;
      this->spd_ki = 0.0f;
      this->loc_kp = 0.0f;
      this->spd_filt_gain = 0.0f;
      this->limit_spd = 0.0f;
      this->limit_cur = 0.0f;
    }
  }

  // field types and members
  using _motor_id_type =
    int8_t;
  _motor_id_type motor_id;
  using _control_mode_type =
    uint8_t;
  _control_mode_type control_mode;
  using _param_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _param_name_type param_name;
  using _communication_type_type =
    uint8_t;
  _communication_type_type communication_type;
  using _param_value_type =
    float;
  _param_value_type param_value;
  using _cur_kp_type =
    float;
  _cur_kp_type cur_kp;
  using _cur_ki_type =
    float;
  _cur_ki_type cur_ki;
  using _spd_kp_type =
    float;
  _spd_kp_type spd_kp;
  using _spd_ki_type =
    float;
  _spd_ki_type spd_ki;
  using _loc_kp_type =
    float;
  _loc_kp_type loc_kp;
  using _spd_filt_gain_type =
    float;
  _spd_filt_gain_type spd_filt_gain;
  using _limit_spd_type =
    float;
  _limit_spd_type limit_spd;
  using _limit_cur_type =
    float;
  _limit_cur_type limit_cur;

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
  Type & set__param_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->param_name = _arg;
    return *this;
  }
  Type & set__communication_type(
    const uint8_t & _arg)
  {
    this->communication_type = _arg;
    return *this;
  }
  Type & set__param_value(
    const float & _arg)
  {
    this->param_value = _arg;
    return *this;
  }
  Type & set__cur_kp(
    const float & _arg)
  {
    this->cur_kp = _arg;
    return *this;
  }
  Type & set__cur_ki(
    const float & _arg)
  {
    this->cur_ki = _arg;
    return *this;
  }
  Type & set__spd_kp(
    const float & _arg)
  {
    this->spd_kp = _arg;
    return *this;
  }
  Type & set__spd_ki(
    const float & _arg)
  {
    this->spd_ki = _arg;
    return *this;
  }
  Type & set__loc_kp(
    const float & _arg)
  {
    this->loc_kp = _arg;
    return *this;
  }
  Type & set__spd_filt_gain(
    const float & _arg)
  {
    this->spd_filt_gain = _arg;
    return *this;
  }
  Type & set__limit_spd(
    const float & _arg)
  {
    this->limit_spd = _arg;
    return *this;
  }
  Type & set__limit_cur(
    const float & _arg)
  {
    this->limit_cur = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cybergear_interfaces::srv::SetParam_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const cybergear_interfaces::srv::SetParam_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cybergear_interfaces::srv::SetParam_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cybergear_interfaces::srv::SetParam_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cybergear_interfaces::srv::SetParam_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cybergear_interfaces::srv::SetParam_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cybergear_interfaces::srv::SetParam_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cybergear_interfaces::srv::SetParam_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cybergear_interfaces::srv::SetParam_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cybergear_interfaces::srv::SetParam_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cybergear_interfaces__srv__SetParam_Request
    std::shared_ptr<cybergear_interfaces::srv::SetParam_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cybergear_interfaces__srv__SetParam_Request
    std::shared_ptr<cybergear_interfaces::srv::SetParam_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetParam_Request_ & other) const
  {
    if (this->motor_id != other.motor_id) {
      return false;
    }
    if (this->control_mode != other.control_mode) {
      return false;
    }
    if (this->param_name != other.param_name) {
      return false;
    }
    if (this->communication_type != other.communication_type) {
      return false;
    }
    if (this->param_value != other.param_value) {
      return false;
    }
    if (this->cur_kp != other.cur_kp) {
      return false;
    }
    if (this->cur_ki != other.cur_ki) {
      return false;
    }
    if (this->spd_kp != other.spd_kp) {
      return false;
    }
    if (this->spd_ki != other.spd_ki) {
      return false;
    }
    if (this->loc_kp != other.loc_kp) {
      return false;
    }
    if (this->spd_filt_gain != other.spd_filt_gain) {
      return false;
    }
    if (this->limit_spd != other.limit_spd) {
      return false;
    }
    if (this->limit_cur != other.limit_cur) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetParam_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetParam_Request_

// alias to use template instance with default allocator
using SetParam_Request =
  cybergear_interfaces::srv::SetParam_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace cybergear_interfaces


#ifndef _WIN32
# define DEPRECATED__cybergear_interfaces__srv__SetParam_Response __attribute__((deprecated))
#else
# define DEPRECATED__cybergear_interfaces__srv__SetParam_Response __declspec(deprecated)
#endif

namespace cybergear_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetParam_Response_
{
  using Type = SetParam_Response_<ContainerAllocator>;

  explicit SetParam_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit SetParam_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    cybergear_interfaces::srv::SetParam_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const cybergear_interfaces::srv::SetParam_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cybergear_interfaces::srv::SetParam_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cybergear_interfaces::srv::SetParam_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cybergear_interfaces::srv::SetParam_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cybergear_interfaces::srv::SetParam_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cybergear_interfaces::srv::SetParam_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cybergear_interfaces::srv::SetParam_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cybergear_interfaces::srv::SetParam_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cybergear_interfaces::srv::SetParam_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cybergear_interfaces__srv__SetParam_Response
    std::shared_ptr<cybergear_interfaces::srv::SetParam_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cybergear_interfaces__srv__SetParam_Response
    std::shared_ptr<cybergear_interfaces::srv::SetParam_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetParam_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetParam_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetParam_Response_

// alias to use template instance with default allocator
using SetParam_Response =
  cybergear_interfaces::srv::SetParam_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace cybergear_interfaces

namespace cybergear_interfaces
{

namespace srv
{

struct SetParam
{
  using Request = cybergear_interfaces::srv::SetParam_Request;
  using Response = cybergear_interfaces::srv::SetParam_Response;
};

}  // namespace srv

}  // namespace cybergear_interfaces

#endif  // CYBERGEAR_INTERFACES__SRV__DETAIL__SET_PARAM__STRUCT_HPP_
