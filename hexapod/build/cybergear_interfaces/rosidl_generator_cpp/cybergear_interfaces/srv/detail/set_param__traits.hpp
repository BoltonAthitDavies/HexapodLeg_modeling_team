// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cybergear_interfaces:srv/SetParam.idl
// generated code does not contain a copyright notice

#ifndef CYBERGEAR_INTERFACES__SRV__DETAIL__SET_PARAM__TRAITS_HPP_
#define CYBERGEAR_INTERFACES__SRV__DETAIL__SET_PARAM__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cybergear_interfaces/srv/detail/set_param__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace cybergear_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetParam_Request & msg,
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

  // member: param_name
  {
    out << "param_name: ";
    rosidl_generator_traits::value_to_yaml(msg.param_name, out);
    out << ", ";
  }

  // member: communication_type
  {
    out << "communication_type: ";
    rosidl_generator_traits::value_to_yaml(msg.communication_type, out);
    out << ", ";
  }

  // member: param_value
  {
    out << "param_value: ";
    rosidl_generator_traits::value_to_yaml(msg.param_value, out);
    out << ", ";
  }

  // member: cur_kp
  {
    out << "cur_kp: ";
    rosidl_generator_traits::value_to_yaml(msg.cur_kp, out);
    out << ", ";
  }

  // member: cur_ki
  {
    out << "cur_ki: ";
    rosidl_generator_traits::value_to_yaml(msg.cur_ki, out);
    out << ", ";
  }

  // member: spd_kp
  {
    out << "spd_kp: ";
    rosidl_generator_traits::value_to_yaml(msg.spd_kp, out);
    out << ", ";
  }

  // member: spd_ki
  {
    out << "spd_ki: ";
    rosidl_generator_traits::value_to_yaml(msg.spd_ki, out);
    out << ", ";
  }

  // member: loc_kp
  {
    out << "loc_kp: ";
    rosidl_generator_traits::value_to_yaml(msg.loc_kp, out);
    out << ", ";
  }

  // member: spd_filt_gain
  {
    out << "spd_filt_gain: ";
    rosidl_generator_traits::value_to_yaml(msg.spd_filt_gain, out);
    out << ", ";
  }

  // member: limit_spd
  {
    out << "limit_spd: ";
    rosidl_generator_traits::value_to_yaml(msg.limit_spd, out);
    out << ", ";
  }

  // member: limit_cur
  {
    out << "limit_cur: ";
    rosidl_generator_traits::value_to_yaml(msg.limit_cur, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetParam_Request & msg,
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

  // member: param_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "param_name: ";
    rosidl_generator_traits::value_to_yaml(msg.param_name, out);
    out << "\n";
  }

  // member: communication_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "communication_type: ";
    rosidl_generator_traits::value_to_yaml(msg.communication_type, out);
    out << "\n";
  }

  // member: param_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "param_value: ";
    rosidl_generator_traits::value_to_yaml(msg.param_value, out);
    out << "\n";
  }

  // member: cur_kp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cur_kp: ";
    rosidl_generator_traits::value_to_yaml(msg.cur_kp, out);
    out << "\n";
  }

  // member: cur_ki
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cur_ki: ";
    rosidl_generator_traits::value_to_yaml(msg.cur_ki, out);
    out << "\n";
  }

  // member: spd_kp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "spd_kp: ";
    rosidl_generator_traits::value_to_yaml(msg.spd_kp, out);
    out << "\n";
  }

  // member: spd_ki
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "spd_ki: ";
    rosidl_generator_traits::value_to_yaml(msg.spd_ki, out);
    out << "\n";
  }

  // member: loc_kp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "loc_kp: ";
    rosidl_generator_traits::value_to_yaml(msg.loc_kp, out);
    out << "\n";
  }

  // member: spd_filt_gain
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "spd_filt_gain: ";
    rosidl_generator_traits::value_to_yaml(msg.spd_filt_gain, out);
    out << "\n";
  }

  // member: limit_spd
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "limit_spd: ";
    rosidl_generator_traits::value_to_yaml(msg.limit_spd, out);
    out << "\n";
  }

  // member: limit_cur
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "limit_cur: ";
    rosidl_generator_traits::value_to_yaml(msg.limit_cur, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetParam_Request & msg, bool use_flow_style = false)
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
  const cybergear_interfaces::srv::SetParam_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  cybergear_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cybergear_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const cybergear_interfaces::srv::SetParam_Request & msg)
{
  return cybergear_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<cybergear_interfaces::srv::SetParam_Request>()
{
  return "cybergear_interfaces::srv::SetParam_Request";
}

template<>
inline const char * name<cybergear_interfaces::srv::SetParam_Request>()
{
  return "cybergear_interfaces/srv/SetParam_Request";
}

template<>
struct has_fixed_size<cybergear_interfaces::srv::SetParam_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cybergear_interfaces::srv::SetParam_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<cybergear_interfaces::srv::SetParam_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace cybergear_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetParam_Response & msg,
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
  const SetParam_Response & msg,
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

inline std::string to_yaml(const SetParam_Response & msg, bool use_flow_style = false)
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
  const cybergear_interfaces::srv::SetParam_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  cybergear_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cybergear_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const cybergear_interfaces::srv::SetParam_Response & msg)
{
  return cybergear_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<cybergear_interfaces::srv::SetParam_Response>()
{
  return "cybergear_interfaces::srv::SetParam_Response";
}

template<>
inline const char * name<cybergear_interfaces::srv::SetParam_Response>()
{
  return "cybergear_interfaces/srv/SetParam_Response";
}

template<>
struct has_fixed_size<cybergear_interfaces::srv::SetParam_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cybergear_interfaces::srv::SetParam_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<cybergear_interfaces::srv::SetParam_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<cybergear_interfaces::srv::SetParam>()
{
  return "cybergear_interfaces::srv::SetParam";
}

template<>
inline const char * name<cybergear_interfaces::srv::SetParam>()
{
  return "cybergear_interfaces/srv/SetParam";
}

template<>
struct has_fixed_size<cybergear_interfaces::srv::SetParam>
  : std::integral_constant<
    bool,
    has_fixed_size<cybergear_interfaces::srv::SetParam_Request>::value &&
    has_fixed_size<cybergear_interfaces::srv::SetParam_Response>::value
  >
{
};

template<>
struct has_bounded_size<cybergear_interfaces::srv::SetParam>
  : std::integral_constant<
    bool,
    has_bounded_size<cybergear_interfaces::srv::SetParam_Request>::value &&
    has_bounded_size<cybergear_interfaces::srv::SetParam_Response>::value
  >
{
};

template<>
struct is_service<cybergear_interfaces::srv::SetParam>
  : std::true_type
{
};

template<>
struct is_service_request<cybergear_interfaces::srv::SetParam_Request>
  : std::true_type
{
};

template<>
struct is_service_response<cybergear_interfaces::srv::SetParam_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CYBERGEAR_INTERFACES__SRV__DETAIL__SET_PARAM__TRAITS_HPP_
