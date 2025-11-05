// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cybergear_interfaces:msg/MotorControl.idl
// generated code does not contain a copyright notice

#ifndef CYBERGEAR_INTERFACES__MSG__DETAIL__MOTOR_CONTROL__TRAITS_HPP_
#define CYBERGEAR_INTERFACES__MSG__DETAIL__MOTOR_CONTROL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cybergear_interfaces/msg/detail/motor_control__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'set_point'
#include "cybergear_interfaces/msg/detail/set_point__traits.hpp"

namespace cybergear_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const MotorControl & msg,
  std::ostream & out)
{
  out << "{";
  // member: motor_id
  {
    out << "motor_id: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_id, out);
    out << ", ";
  }

  // member: control_mode
  {
    out << "control_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.control_mode, out);
    out << ", ";
  }

  // member: set_point
  {
    out << "set_point: ";
    to_flow_style_yaml(msg.set_point, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MotorControl & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: motor_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "motor_id: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_id, out);
    out << "\n";
  }

  // member: control_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "control_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.control_mode, out);
    out << "\n";
  }

  // member: set_point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "set_point:\n";
    to_block_style_yaml(msg.set_point, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MotorControl & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace cybergear_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use cybergear_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cybergear_interfaces::msg::MotorControl & msg,
  std::ostream & out, size_t indentation = 0)
{
  cybergear_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cybergear_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const cybergear_interfaces::msg::MotorControl & msg)
{
  return cybergear_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<cybergear_interfaces::msg::MotorControl>()
{
  return "cybergear_interfaces::msg::MotorControl";
}

template<>
inline const char * name<cybergear_interfaces::msg::MotorControl>()
{
  return "cybergear_interfaces/msg/MotorControl";
}

template<>
struct has_fixed_size<cybergear_interfaces::msg::MotorControl>
  : std::integral_constant<bool, has_fixed_size<cybergear_interfaces::msg::SetPoint>::value> {};

template<>
struct has_bounded_size<cybergear_interfaces::msg::MotorControl>
  : std::integral_constant<bool, has_bounded_size<cybergear_interfaces::msg::SetPoint>::value> {};

template<>
struct is_message<cybergear_interfaces::msg::MotorControl>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CYBERGEAR_INTERFACES__MSG__DETAIL__MOTOR_CONTROL__TRAITS_HPP_
