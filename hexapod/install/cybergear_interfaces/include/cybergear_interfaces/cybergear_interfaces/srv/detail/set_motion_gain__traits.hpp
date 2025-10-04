// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cybergear_interfaces:srv/SetMotionGain.idl
// generated code does not contain a copyright notice

#ifndef CYBERGEAR_INTERFACES__SRV__DETAIL__SET_MOTION_GAIN__TRAITS_HPP_
#define CYBERGEAR_INTERFACES__SRV__DETAIL__SET_MOTION_GAIN__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cybergear_interfaces/srv/detail/set_motion_gain__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace cybergear_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetMotionGain_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: motor_id
  {
    out << "motor_id: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_id, out);
    out << ", ";
  }

  // member: param_name
  {
    out << "param_name: ";
    rosidl_generator_traits::value_to_yaml(msg.param_name, out);
    out << ", ";
  }

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
  const SetMotionGain_Request & msg,
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

  // member: param_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "param_name: ";
    rosidl_generator_traits::value_to_yaml(msg.param_name, out);
    out << "\n";
  }

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

inline std::string to_yaml(const SetMotionGain_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace cybergear_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use cybergear_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cybergear_interfaces::srv::SetMotionGain_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  cybergear_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cybergear_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const cybergear_interfaces::srv::SetMotionGain_Request & msg)
{
  return cybergear_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<cybergear_interfaces::srv::SetMotionGain_Request>()
{
  return "cybergear_interfaces::srv::SetMotionGain_Request";
}

template<>
inline const char * name<cybergear_interfaces::srv::SetMotionGain_Request>()
{
  return "cybergear_interfaces/srv/SetMotionGain_Request";
}

template<>
struct has_fixed_size<cybergear_interfaces::srv::SetMotionGain_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cybergear_interfaces::srv::SetMotionGain_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<cybergear_interfaces::srv::SetMotionGain_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace cybergear_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetMotionGain_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetMotionGain_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetMotionGain_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace cybergear_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use cybergear_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cybergear_interfaces::srv::SetMotionGain_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  cybergear_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cybergear_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const cybergear_interfaces::srv::SetMotionGain_Response & msg)
{
  return cybergear_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<cybergear_interfaces::srv::SetMotionGain_Response>()
{
  return "cybergear_interfaces::srv::SetMotionGain_Response";
}

template<>
inline const char * name<cybergear_interfaces::srv::SetMotionGain_Response>()
{
  return "cybergear_interfaces/srv/SetMotionGain_Response";
}

template<>
struct has_fixed_size<cybergear_interfaces::srv::SetMotionGain_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cybergear_interfaces::srv::SetMotionGain_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<cybergear_interfaces::srv::SetMotionGain_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<cybergear_interfaces::srv::SetMotionGain>()
{
  return "cybergear_interfaces::srv::SetMotionGain";
}

template<>
inline const char * name<cybergear_interfaces::srv::SetMotionGain>()
{
  return "cybergear_interfaces/srv/SetMotionGain";
}

template<>
struct has_fixed_size<cybergear_interfaces::srv::SetMotionGain>
  : std::integral_constant<
    bool,
    has_fixed_size<cybergear_interfaces::srv::SetMotionGain_Request>::value &&
    has_fixed_size<cybergear_interfaces::srv::SetMotionGain_Response>::value
  >
{
};

template<>
struct has_bounded_size<cybergear_interfaces::srv::SetMotionGain>
  : std::integral_constant<
    bool,
    has_bounded_size<cybergear_interfaces::srv::SetMotionGain_Request>::value &&
    has_bounded_size<cybergear_interfaces::srv::SetMotionGain_Response>::value
  >
{
};

template<>
struct is_service<cybergear_interfaces::srv::SetMotionGain>
  : std::true_type
{
};

template<>
struct is_service_request<cybergear_interfaces::srv::SetMotionGain_Request>
  : std::true_type
{
};

template<>
struct is_service_response<cybergear_interfaces::srv::SetMotionGain_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CYBERGEAR_INTERFACES__SRV__DETAIL__SET_MOTION_GAIN__TRAITS_HPP_
