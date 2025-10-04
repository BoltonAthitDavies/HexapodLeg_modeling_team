// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cybergear_interfaces:srv/SetMotionGain.idl
// generated code does not contain a copyright notice

#ifndef CYBERGEAR_INTERFACES__SRV__DETAIL__SET_MOTION_GAIN__BUILDER_HPP_
#define CYBERGEAR_INTERFACES__SRV__DETAIL__SET_MOTION_GAIN__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cybergear_interfaces/srv/detail/set_motion_gain__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cybergear_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetMotionGain_Request_kd
{
public:
  explicit Init_SetMotionGain_Request_kd(::cybergear_interfaces::srv::SetMotionGain_Request & msg)
  : msg_(msg)
  {}
  ::cybergear_interfaces::srv::SetMotionGain_Request kd(::cybergear_interfaces::srv::SetMotionGain_Request::_kd_type arg)
  {
    msg_.kd = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cybergear_interfaces::srv::SetMotionGain_Request msg_;
};

class Init_SetMotionGain_Request_kp
{
public:
  explicit Init_SetMotionGain_Request_kp(::cybergear_interfaces::srv::SetMotionGain_Request & msg)
  : msg_(msg)
  {}
  Init_SetMotionGain_Request_kd kp(::cybergear_interfaces::srv::SetMotionGain_Request::_kp_type arg)
  {
    msg_.kp = std::move(arg);
    return Init_SetMotionGain_Request_kd(msg_);
  }

private:
  ::cybergear_interfaces::srv::SetMotionGain_Request msg_;
};

class Init_SetMotionGain_Request_effort
{
public:
  explicit Init_SetMotionGain_Request_effort(::cybergear_interfaces::srv::SetMotionGain_Request & msg)
  : msg_(msg)
  {}
  Init_SetMotionGain_Request_kp effort(::cybergear_interfaces::srv::SetMotionGain_Request::_effort_type arg)
  {
    msg_.effort = std::move(arg);
    return Init_SetMotionGain_Request_kp(msg_);
  }

private:
  ::cybergear_interfaces::srv::SetMotionGain_Request msg_;
};

class Init_SetMotionGain_Request_velocity
{
public:
  explicit Init_SetMotionGain_Request_velocity(::cybergear_interfaces::srv::SetMotionGain_Request & msg)
  : msg_(msg)
  {}
  Init_SetMotionGain_Request_effort velocity(::cybergear_interfaces::srv::SetMotionGain_Request::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_SetMotionGain_Request_effort(msg_);
  }

private:
  ::cybergear_interfaces::srv::SetMotionGain_Request msg_;
};

class Init_SetMotionGain_Request_position
{
public:
  explicit Init_SetMotionGain_Request_position(::cybergear_interfaces::srv::SetMotionGain_Request & msg)
  : msg_(msg)
  {}
  Init_SetMotionGain_Request_velocity position(::cybergear_interfaces::srv::SetMotionGain_Request::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_SetMotionGain_Request_velocity(msg_);
  }

private:
  ::cybergear_interfaces::srv::SetMotionGain_Request msg_;
};

class Init_SetMotionGain_Request_param_name
{
public:
  explicit Init_SetMotionGain_Request_param_name(::cybergear_interfaces::srv::SetMotionGain_Request & msg)
  : msg_(msg)
  {}
  Init_SetMotionGain_Request_position param_name(::cybergear_interfaces::srv::SetMotionGain_Request::_param_name_type arg)
  {
    msg_.param_name = std::move(arg);
    return Init_SetMotionGain_Request_position(msg_);
  }

private:
  ::cybergear_interfaces::srv::SetMotionGain_Request msg_;
};

class Init_SetMotionGain_Request_motor_id
{
public:
  Init_SetMotionGain_Request_motor_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetMotionGain_Request_param_name motor_id(::cybergear_interfaces::srv::SetMotionGain_Request::_motor_id_type arg)
  {
    msg_.motor_id = std::move(arg);
    return Init_SetMotionGain_Request_param_name(msg_);
  }

private:
  ::cybergear_interfaces::srv::SetMotionGain_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::cybergear_interfaces::srv::SetMotionGain_Request>()
{
  return cybergear_interfaces::srv::builder::Init_SetMotionGain_Request_motor_id();
}

}  // namespace cybergear_interfaces


namespace cybergear_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetMotionGain_Response_message
{
public:
  explicit Init_SetMotionGain_Response_message(::cybergear_interfaces::srv::SetMotionGain_Response & msg)
  : msg_(msg)
  {}
  ::cybergear_interfaces::srv::SetMotionGain_Response message(::cybergear_interfaces::srv::SetMotionGain_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cybergear_interfaces::srv::SetMotionGain_Response msg_;
};

class Init_SetMotionGain_Response_success
{
public:
  Init_SetMotionGain_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetMotionGain_Response_message success(::cybergear_interfaces::srv::SetMotionGain_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_SetMotionGain_Response_message(msg_);
  }

private:
  ::cybergear_interfaces::srv::SetMotionGain_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::cybergear_interfaces::srv::SetMotionGain_Response>()
{
  return cybergear_interfaces::srv::builder::Init_SetMotionGain_Response_success();
}

}  // namespace cybergear_interfaces

#endif  // CYBERGEAR_INTERFACES__SRV__DETAIL__SET_MOTION_GAIN__BUILDER_HPP_
