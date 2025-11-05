// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cybergear_interfaces:msg/MotorControl.idl
// generated code does not contain a copyright notice

#ifndef CYBERGEAR_INTERFACES__MSG__DETAIL__MOTOR_CONTROL__BUILDER_HPP_
#define CYBERGEAR_INTERFACES__MSG__DETAIL__MOTOR_CONTROL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cybergear_interfaces/msg/detail/motor_control__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cybergear_interfaces
{

namespace msg
{

namespace builder
{

class Init_MotorControl_set_point
{
public:
  explicit Init_MotorControl_set_point(::cybergear_interfaces::msg::MotorControl & msg)
  : msg_(msg)
  {}
  ::cybergear_interfaces::msg::MotorControl set_point(::cybergear_interfaces::msg::MotorControl::_set_point_type arg)
  {
    msg_.set_point = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cybergear_interfaces::msg::MotorControl msg_;
};

class Init_MotorControl_control_mode
{
public:
  explicit Init_MotorControl_control_mode(::cybergear_interfaces::msg::MotorControl & msg)
  : msg_(msg)
  {}
  Init_MotorControl_set_point control_mode(::cybergear_interfaces::msg::MotorControl::_control_mode_type arg)
  {
    msg_.control_mode = std::move(arg);
    return Init_MotorControl_set_point(msg_);
  }

private:
  ::cybergear_interfaces::msg::MotorControl msg_;
};

class Init_MotorControl_motor_id
{
public:
  Init_MotorControl_motor_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotorControl_control_mode motor_id(::cybergear_interfaces::msg::MotorControl::_motor_id_type arg)
  {
    msg_.motor_id = std::move(arg);
    return Init_MotorControl_control_mode(msg_);
  }

private:
  ::cybergear_interfaces::msg::MotorControl msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cybergear_interfaces::msg::MotorControl>()
{
  return cybergear_interfaces::msg::builder::Init_MotorControl_motor_id();
}

}  // namespace cybergear_interfaces

#endif  // CYBERGEAR_INTERFACES__MSG__DETAIL__MOTOR_CONTROL__BUILDER_HPP_
