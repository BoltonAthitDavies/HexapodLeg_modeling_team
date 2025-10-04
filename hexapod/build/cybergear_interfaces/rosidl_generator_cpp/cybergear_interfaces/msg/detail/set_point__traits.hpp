// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cybergear_interfaces:msg/SetPoint.idl
// generated code does not contain a copyright notice

#ifndef CYBERGEAR_INTERFACES__MSG__DETAIL__SET_POINT__TRAITS_HPP_
#define CYBERGEAR_INTERFACES__MSG__DETAIL__SET_POINT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cybergear_interfaces/msg/detail/set_point__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace cybergear_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const SetPoint & msg,
  std::ostream & out)
{
  out << "{";
  // member: position
  {
    out << "position: ";
    rosidl_generator_traits::value_to_yaml(msg.position, out);
    out << ", ";
  }

  // member: velocity
  {
    out << "velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.velocity, out);
    out << ", ";
  }

  // member: effort
  {
    out << "effort: ";
    rosidl_generator_traits::value_to_yaml(msg.effort, out);
    out << ", ";
  }

  // member: kp
  {
    out << "kp: ";
    rosidl_generator_traits::value_to_yaml(msg.kp, out);
    out << ", ";
  }

  // member: kd
  {
    out << "kd: ";
    rosidl_generator_traits::value_to_yaml(msg.kd, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetPoint & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position: ";
    rosidl_generator_traits::value_to_yaml(msg.position, out);
    out << "\n";
  }

  // member: velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.velocity, out);
    out << "\n";
  }

  // member: effort
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "effort: ";
    rosidl_generator_traits::value_to_yaml(msg.effort, out);
    out << "\n";
  }

  // member: kp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "kp: ";
    rosidl_generator_traits::value_to_yaml(msg.kp, out);
    out << "\n";
  }

  // member: kd
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "kd: ";
    rosidl_generator_traits::value_to_yaml(msg.kd, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetPoint & msg, bool use_flow_style = false)
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
  const cybergear_interfaces::msg::SetPoint & msg,
  std::ostream & out, size_t indentation = 0)
{
  cybergear_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cybergear_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const cybergear_interfaces::msg::SetPoint & msg)
{
  return cybergear_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<cybergear_interfaces::msg::SetPoint>()
{
  return "cybergear_interfaces::msg::SetPoint";
}

template<>
inline const char * name<cybergear_interfaces::msg::SetPoint>()
{
  return "cybergear_interfaces/msg/SetPoint";
}

template<>
struct has_fixed_size<cybergear_interfaces::msg::SetPoint>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<cybergear_interfaces::msg::SetPoint>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<cybergear_interfaces::msg::SetPoint>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CYBERGEAR_INTERFACES__MSG__DETAIL__SET_POINT__TRAITS_HPP_
