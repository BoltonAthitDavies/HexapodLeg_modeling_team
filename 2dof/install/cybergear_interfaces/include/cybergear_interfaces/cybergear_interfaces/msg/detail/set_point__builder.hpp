// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cybergear_interfaces:msg/SetPoint.idl
// generated code does not contain a copyright notice

#ifndef CYBERGEAR_INTERFACES__MSG__DETAIL__SET_POINT__BUILDER_HPP_
#define CYBERGEAR_INTERFACES__MSG__DETAIL__SET_POINT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cybergear_interfaces/msg/detail/set_point__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cybergear_interfaces
{

namespace msg
{

namespace builder
{

class Init_SetPoint_kd
{
public:
  explicit Init_SetPoint_kd(::cybergear_interfaces::msg::SetPoint & msg)
  : msg_(msg)
  {}
  ::cybergear_interfaces::msg::SetPoint kd(::cybergear_interfaces::msg::SetPoint::_kd_type arg)
  {
    msg_.kd = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cybergear_interfaces::msg::SetPoint msg_;
};

class Init_SetPoint_kp
{
public:
  explicit Init_SetPoint_kp(::cybergear_interfaces::msg::SetPoint & msg)
  : msg_(msg)
  {}
  Init_SetPoint_kd kp(::cybergear_interfaces::msg::SetPoint::_kp_type arg)
  {
    msg_.kp = std::move(arg);
    return Init_SetPoint_kd(msg_);
  }

private:
  ::cybergear_interfaces::msg::SetPoint msg_;
};

class Init_SetPoint_effort
{
public:
  explicit Init_SetPoint_effort(::cybergear_interfaces::msg::SetPoint & msg)
  : msg_(msg)
  {}
  Init_SetPoint_kp effort(::cybergear_interfaces::msg::SetPoint::_effort_type arg)
  {
    msg_.effort = std::move(arg);
    return Init_SetPoint_kp(msg_);
  }

private:
  ::cybergear_interfaces::msg::SetPoint msg_;
};

class Init_SetPoint_velocity
{
public:
  explicit Init_SetPoint_velocity(::cybergear_interfaces::msg::SetPoint & msg)
  : msg_(msg)
  {}
  Init_SetPoint_effort velocity(::cybergear_interfaces::msg::SetPoint::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_SetPoint_effort(msg_);
  }

private:
  ::cybergear_interfaces::msg::SetPoint msg_;
};

class Init_SetPoint_position
{
public:
  Init_SetPoint_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetPoint_velocity position(::cybergear_interfaces::msg::SetPoint::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_SetPoint_velocity(msg_);
  }

private:
  ::cybergear_interfaces::msg::SetPoint msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cybergear_interfaces::msg::SetPoint>()
{
  return cybergear_interfaces::msg::builder::Init_SetPoint_position();
}

}  // namespace cybergear_interfaces

#endif  // CYBERGEAR_INTERFACES__MSG__DETAIL__SET_POINT__BUILDER_HPP_
