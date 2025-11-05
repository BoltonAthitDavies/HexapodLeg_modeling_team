// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cybergear_interfaces:msg/MotorControlGroup.idl
// generated code does not contain a copyright notice

#ifndef CYBERGEAR_INTERFACES__MSG__DETAIL__MOTOR_CONTROL_GROUP__BUILDER_HPP_
#define CYBERGEAR_INTERFACES__MSG__DETAIL__MOTOR_CONTROL_GROUP__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cybergear_interfaces/msg/detail/motor_control_group__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cybergear_interfaces
{

namespace msg
{

namespace builder
{

class Init_MotorControlGroup_motor_controls
{
public:
  explicit Init_MotorControlGroup_motor_controls(::cybergear_interfaces::msg::MotorControlGroup & msg)
  : msg_(msg)
  {}
  ::cybergear_interfaces::msg::MotorControlGroup motor_controls(::cybergear_interfaces::msg::MotorControlGroup::_motor_controls_type arg)
  {
    msg_.motor_controls = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cybergear_interfaces::msg::MotorControlGroup msg_;
};

class Init_MotorControlGroup_header
{
public:
  Init_MotorControlGroup_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotorControlGroup_motor_controls header(::cybergear_interfaces::msg::MotorControlGroup::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_MotorControlGroup_motor_controls(msg_);
  }

private:
  ::cybergear_interfaces::msg::MotorControlGroup msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cybergear_interfaces::msg::MotorControlGroup>()
{
  return cybergear_interfaces::msg::builder::Init_MotorControlGroup_header();
}

}  // namespace cybergear_interfaces

#endif  // CYBERGEAR_INTERFACES__MSG__DETAIL__MOTOR_CONTROL_GROUP__BUILDER_HPP_
