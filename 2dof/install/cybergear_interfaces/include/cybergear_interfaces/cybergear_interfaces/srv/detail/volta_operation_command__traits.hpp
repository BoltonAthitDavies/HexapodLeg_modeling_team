// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cybergear_interfaces:srv/VoltaOperationCommand.idl
// generated code does not contain a copyright notice

#ifndef CYBERGEAR_INTERFACES__SRV__DETAIL__VOLTA_OPERATION_COMMAND__TRAITS_HPP_
#define CYBERGEAR_INTERFACES__SRV__DETAIL__VOLTA_OPERATION_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cybergear_interfaces/srv/detail/volta_operation_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace cybergear_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const VoltaOperationCommand_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: operation_command
  {
    out << "operation_command: ";
    rosidl_generator_traits::value_to_yaml(msg.operation_command, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const VoltaOperationCommand_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: operation_command
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "operation_command: ";
    rosidl_generator_traits::value_to_yaml(msg.operation_command, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const VoltaOperationCommand_Request & msg, bool use_flow_style = false)
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
  const cybergear_interfaces::srv::VoltaOperationCommand_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  cybergear_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cybergear_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const cybergear_interfaces::srv::VoltaOperationCommand_Request & msg)
{
  return cybergear_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<cybergear_interfaces::srv::VoltaOperationCommand_Request>()
{
  return "cybergear_interfaces::srv::VoltaOperationCommand_Request";
}

template<>
inline const char * name<cybergear_interfaces::srv::VoltaOperationCommand_Request>()
{
  return "cybergear_interfaces/srv/VoltaOperationCommand_Request";
}

template<>
struct has_fixed_size<cybergear_interfaces::srv::VoltaOperationCommand_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<cybergear_interfaces::srv::VoltaOperationCommand_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<cybergear_interfaces::srv::VoltaOperationCommand_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace cybergear_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const VoltaOperationCommand_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: response
  {
    out << "response: ";
    rosidl_generator_traits::value_to_yaml(msg.response, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const VoltaOperationCommand_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "response: ";
    rosidl_generator_traits::value_to_yaml(msg.response, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const VoltaOperationCommand_Response & msg, bool use_flow_style = false)
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
  const cybergear_interfaces::srv::VoltaOperationCommand_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  cybergear_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cybergear_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const cybergear_interfaces::srv::VoltaOperationCommand_Response & msg)
{
  return cybergear_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<cybergear_interfaces::srv::VoltaOperationCommand_Response>()
{
  return "cybergear_interfaces::srv::VoltaOperationCommand_Response";
}

template<>
inline const char * name<cybergear_interfaces::srv::VoltaOperationCommand_Response>()
{
  return "cybergear_interfaces/srv/VoltaOperationCommand_Response";
}

template<>
struct has_fixed_size<cybergear_interfaces::srv::VoltaOperationCommand_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cybergear_interfaces::srv::VoltaOperationCommand_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<cybergear_interfaces::srv::VoltaOperationCommand_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<cybergear_interfaces::srv::VoltaOperationCommand>()
{
  return "cybergear_interfaces::srv::VoltaOperationCommand";
}

template<>
inline const char * name<cybergear_interfaces::srv::VoltaOperationCommand>()
{
  return "cybergear_interfaces/srv/VoltaOperationCommand";
}

template<>
struct has_fixed_size<cybergear_interfaces::srv::VoltaOperationCommand>
  : std::integral_constant<
    bool,
    has_fixed_size<cybergear_interfaces::srv::VoltaOperationCommand_Request>::value &&
    has_fixed_size<cybergear_interfaces::srv::VoltaOperationCommand_Response>::value
  >
{
};

template<>
struct has_bounded_size<cybergear_interfaces::srv::VoltaOperationCommand>
  : std::integral_constant<
    bool,
    has_bounded_size<cybergear_interfaces::srv::VoltaOperationCommand_Request>::value &&
    has_bounded_size<cybergear_interfaces::srv::VoltaOperationCommand_Response>::value
  >
{
};

template<>
struct is_service<cybergear_interfaces::srv::VoltaOperationCommand>
  : std::true_type
{
};

template<>
struct is_service_request<cybergear_interfaces::srv::VoltaOperationCommand_Request>
  : std::true_type
{
};

template<>
struct is_service_response<cybergear_interfaces::srv::VoltaOperationCommand_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CYBERGEAR_INTERFACES__SRV__DETAIL__VOLTA_OPERATION_COMMAND__TRAITS_HPP_
