// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cybergear_interfaces:srv/SetParam.idl
// generated code does not contain a copyright notice

#ifndef CYBERGEAR_INTERFACES__SRV__DETAIL__SET_PARAM__BUILDER_HPP_
#define CYBERGEAR_INTERFACES__SRV__DETAIL__SET_PARAM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cybergear_interfaces/srv/detail/set_param__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cybergear_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetParam_Request_limit_cur
{
public:
  explicit Init_SetParam_Request_limit_cur(::cybergear_interfaces::srv::SetParam_Request & msg)
  : msg_(msg)
  {}
  ::cybergear_interfaces::srv::SetParam_Request limit_cur(::cybergear_interfaces::srv::SetParam_Request::_limit_cur_type arg)
  {
    msg_.limit_cur = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cybergear_interfaces::srv::SetParam_Request msg_;
};

class Init_SetParam_Request_limit_spd
{
public:
  explicit Init_SetParam_Request_limit_spd(::cybergear_interfaces::srv::SetParam_Request & msg)
  : msg_(msg)
  {}
  Init_SetParam_Request_limit_cur limit_spd(::cybergear_interfaces::srv::SetParam_Request::_limit_spd_type arg)
  {
    msg_.limit_spd = std::move(arg);
    return Init_SetParam_Request_limit_cur(msg_);
  }

private:
  ::cybergear_interfaces::srv::SetParam_Request msg_;
};

class Init_SetParam_Request_spd_filt_gain
{
public:
  explicit Init_SetParam_Request_spd_filt_gain(::cybergear_interfaces::srv::SetParam_Request & msg)
  : msg_(msg)
  {}
  Init_SetParam_Request_limit_spd spd_filt_gain(::cybergear_interfaces::srv::SetParam_Request::_spd_filt_gain_type arg)
  {
    msg_.spd_filt_gain = std::move(arg);
    return Init_SetParam_Request_limit_spd(msg_);
  }

private:
  ::cybergear_interfaces::srv::SetParam_Request msg_;
};

class Init_SetParam_Request_loc_kp
{
public:
  explicit Init_SetParam_Request_loc_kp(::cybergear_interfaces::srv::SetParam_Request & msg)
  : msg_(msg)
  {}
  Init_SetParam_Request_spd_filt_gain loc_kp(::cybergear_interfaces::srv::SetParam_Request::_loc_kp_type arg)
  {
    msg_.loc_kp = std::move(arg);
    return Init_SetParam_Request_spd_filt_gain(msg_);
  }

private:
  ::cybergear_interfaces::srv::SetParam_Request msg_;
};

class Init_SetParam_Request_spd_ki
{
public:
  explicit Init_SetParam_Request_spd_ki(::cybergear_interfaces::srv::SetParam_Request & msg)
  : msg_(msg)
  {}
  Init_SetParam_Request_loc_kp spd_ki(::cybergear_interfaces::srv::SetParam_Request::_spd_ki_type arg)
  {
    msg_.spd_ki = std::move(arg);
    return Init_SetParam_Request_loc_kp(msg_);
  }

private:
  ::cybergear_interfaces::srv::SetParam_Request msg_;
};

class Init_SetParam_Request_spd_kp
{
public:
  explicit Init_SetParam_Request_spd_kp(::cybergear_interfaces::srv::SetParam_Request & msg)
  : msg_(msg)
  {}
  Init_SetParam_Request_spd_ki spd_kp(::cybergear_interfaces::srv::SetParam_Request::_spd_kp_type arg)
  {
    msg_.spd_kp = std::move(arg);
    return Init_SetParam_Request_spd_ki(msg_);
  }

private:
  ::cybergear_interfaces::srv::SetParam_Request msg_;
};

class Init_SetParam_Request_cur_ki
{
public:
  explicit Init_SetParam_Request_cur_ki(::cybergear_interfaces::srv::SetParam_Request & msg)
  : msg_(msg)
  {}
  Init_SetParam_Request_spd_kp cur_ki(::cybergear_interfaces::srv::SetParam_Request::_cur_ki_type arg)
  {
    msg_.cur_ki = std::move(arg);
    return Init_SetParam_Request_spd_kp(msg_);
  }

private:
  ::cybergear_interfaces::srv::SetParam_Request msg_;
};

class Init_SetParam_Request_cur_kp
{
public:
  explicit Init_SetParam_Request_cur_kp(::cybergear_interfaces::srv::SetParam_Request & msg)
  : msg_(msg)
  {}
  Init_SetParam_Request_cur_ki cur_kp(::cybergear_interfaces::srv::SetParam_Request::_cur_kp_type arg)
  {
    msg_.cur_kp = std::move(arg);
    return Init_SetParam_Request_cur_ki(msg_);
  }

private:
  ::cybergear_interfaces::srv::SetParam_Request msg_;
};

class Init_SetParam_Request_param_value
{
public:
  explicit Init_SetParam_Request_param_value(::cybergear_interfaces::srv::SetParam_Request & msg)
  : msg_(msg)
  {}
  Init_SetParam_Request_cur_kp param_value(::cybergear_interfaces::srv::SetParam_Request::_param_value_type arg)
  {
    msg_.param_value = std::move(arg);
    return Init_SetParam_Request_cur_kp(msg_);
  }

private:
  ::cybergear_interfaces::srv::SetParam_Request msg_;
};

class Init_SetParam_Request_communication_type
{
public:
  explicit Init_SetParam_Request_communication_type(::cybergear_interfaces::srv::SetParam_Request & msg)
  : msg_(msg)
  {}
  Init_SetParam_Request_param_value communication_type(::cybergear_interfaces::srv::SetParam_Request::_communication_type_type arg)
  {
    msg_.communication_type = std::move(arg);
    return Init_SetParam_Request_param_value(msg_);
  }

private:
  ::cybergear_interfaces::srv::SetParam_Request msg_;
};

class Init_SetParam_Request_param_name
{
public:
  explicit Init_SetParam_Request_param_name(::cybergear_interfaces::srv::SetParam_Request & msg)
  : msg_(msg)
  {}
  Init_SetParam_Request_communication_type param_name(::cybergear_interfaces::srv::SetParam_Request::_param_name_type arg)
  {
    msg_.param_name = std::move(arg);
    return Init_SetParam_Request_communication_type(msg_);
  }

private:
  ::cybergear_interfaces::srv::SetParam_Request msg_;
};

class Init_SetParam_Request_control_mode
{
public:
  explicit Init_SetParam_Request_control_mode(::cybergear_interfaces::srv::SetParam_Request & msg)
  : msg_(msg)
  {}
  Init_SetParam_Request_param_name control_mode(::cybergear_interfaces::srv::SetParam_Request::_control_mode_type arg)
  {
    msg_.control_mode = std::move(arg);
    return Init_SetParam_Request_param_name(msg_);
  }

private:
  ::cybergear_interfaces::srv::SetParam_Request msg_;
};

class Init_SetParam_Request_motor_id
{
public:
  Init_SetParam_Request_motor_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetParam_Request_control_mode motor_id(::cybergear_interfaces::srv::SetParam_Request::_motor_id_type arg)
  {
    msg_.motor_id = std::move(arg);
    return Init_SetParam_Request_control_mode(msg_);
  }

private:
  ::cybergear_interfaces::srv::SetParam_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::cybergear_interfaces::srv::SetParam_Request>()
{
  return cybergear_interfaces::srv::builder::Init_SetParam_Request_motor_id();
}

}  // namespace cybergear_interfaces


namespace cybergear_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetParam_Response_message
{
public:
  explicit Init_SetParam_Response_message(::cybergear_interfaces::srv::SetParam_Response & msg)
  : msg_(msg)
  {}
  ::cybergear_interfaces::srv::SetParam_Response message(::cybergear_interfaces::srv::SetParam_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cybergear_interfaces::srv::SetParam_Response msg_;
};

class Init_SetParam_Response_success
{
public:
  Init_SetParam_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetParam_Response_message success(::cybergear_interfaces::srv::SetParam_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_SetParam_Response_message(msg_);
  }

private:
  ::cybergear_interfaces::srv::SetParam_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::cybergear_interfaces::srv::SetParam_Response>()
{
  return cybergear_interfaces::srv::builder::Init_SetParam_Response_success();
}

}  // namespace cybergear_interfaces

#endif  // CYBERGEAR_INTERFACES__SRV__DETAIL__SET_PARAM__BUILDER_HPP_
