// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cybergear_interfaces:srv/VoltaOperationCommand.idl
// generated code does not contain a copyright notice

#ifndef CYBERGEAR_INTERFACES__SRV__DETAIL__VOLTA_OPERATION_COMMAND__BUILDER_HPP_
#define CYBERGEAR_INTERFACES__SRV__DETAIL__VOLTA_OPERATION_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cybergear_interfaces/srv/detail/volta_operation_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cybergear_interfaces
{

namespace srv
{

namespace builder
{

class Init_VoltaOperationCommand_Request_operation_command
{
public:
  Init_VoltaOperationCommand_Request_operation_command()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::cybergear_interfaces::srv::VoltaOperationCommand_Request operation_command(::cybergear_interfaces::srv::VoltaOperationCommand_Request::_operation_command_type arg)
  {
    msg_.operation_command = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cybergear_interfaces::srv::VoltaOperationCommand_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::cybergear_interfaces::srv::VoltaOperationCommand_Request>()
{
  return cybergear_interfaces::srv::builder::Init_VoltaOperationCommand_Request_operation_command();
}

}  // namespace cybergear_interfaces


namespace cybergear_interfaces
{

namespace srv
{

namespace builder
{

class Init_VoltaOperationCommand_Response_response
{
public:
  Init_VoltaOperationCommand_Response_response()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::cybergear_interfaces::srv::VoltaOperationCommand_Response response(::cybergear_interfaces::srv::VoltaOperationCommand_Response::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cybergear_interfaces::srv::VoltaOperationCommand_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::cybergear_interfaces::srv::VoltaOperationCommand_Response>()
{
  return cybergear_interfaces::srv::builder::Init_VoltaOperationCommand_Response_response();
}

}  // namespace cybergear_interfaces

#endif  // CYBERGEAR_INTERFACES__SRV__DETAIL__VOLTA_OPERATION_COMMAND__BUILDER_HPP_
