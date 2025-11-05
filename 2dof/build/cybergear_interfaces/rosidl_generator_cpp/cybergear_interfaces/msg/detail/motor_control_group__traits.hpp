// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cybergear_interfaces:msg/MotorControlGroup.idl
// generated code does not contain a copyright notice

#ifndef CYBERGEAR_INTERFACES__MSG__DETAIL__MOTOR_CONTROL_GROUP__TRAITS_HPP_
#define CYBERGEAR_INTERFACES__MSG__DETAIL__MOTOR_CONTROL_GROUP__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cybergear_interfaces/msg/detail/motor_control_group__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'motor_controls'
#include "cybergear_interfaces/msg/detail/motor_control__traits.hpp"

namespace cybergear_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const MotorControlGroup & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: motor_controls
  {
    if (msg.motor_controls.size() == 0) {
      out << "motor_controls: []";
    } else {
      out << "motor_controls: [";
      size_t pending_items = msg.motor_controls.size();
      for (auto item : msg.motor_controls) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MotorControlGroup & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: motor_controls
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.motor_controls.size() == 0) {
      out << "motor_controls: []\n";
    } else {
      out << "motor_controls:\n";
      for (auto item : msg.motor_controls) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MotorControlGroup & msg, bool use_flow_style = false)
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
  const cybergear_interfaces::msg::MotorControlGroup & msg,
  std::ostream & out, size_t indentation = 0)
{
  cybergear_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cybergear_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const cybergear_interfaces::msg::MotorControlGroup & msg)
{
  return cybergear_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<cybergear_interfaces::msg::MotorControlGroup>()
{
  return "cybergear_interfaces::msg::MotorControlGroup";
}

template<>
inline const char * name<cybergear_interfaces::msg::MotorControlGroup>()
{
  return "cybergear_interfaces/msg/MotorControlGroup";
}

template<>
struct has_fixed_size<cybergear_interfaces::msg::MotorControlGroup>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cybergear_interfaces::msg::MotorControlGroup>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<cybergear_interfaces::msg::MotorControlGroup>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CYBERGEAR_INTERFACES__MSG__DETAIL__MOTOR_CONTROL_GROUP__TRAITS_HPP_
