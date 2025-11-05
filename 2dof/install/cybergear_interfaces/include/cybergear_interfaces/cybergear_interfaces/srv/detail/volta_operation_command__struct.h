// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cybergear_interfaces:srv/VoltaOperationCommand.idl
// generated code does not contain a copyright notice

#ifndef CYBERGEAR_INTERFACES__SRV__DETAIL__VOLTA_OPERATION_COMMAND__STRUCT_H_
#define CYBERGEAR_INTERFACES__SRV__DETAIL__VOLTA_OPERATION_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/VoltaOperationCommand in the package cybergear_interfaces.
typedef struct cybergear_interfaces__srv__VoltaOperationCommand_Request
{
  int16_t operation_command;
} cybergear_interfaces__srv__VoltaOperationCommand_Request;

// Struct for a sequence of cybergear_interfaces__srv__VoltaOperationCommand_Request.
typedef struct cybergear_interfaces__srv__VoltaOperationCommand_Request__Sequence
{
  cybergear_interfaces__srv__VoltaOperationCommand_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cybergear_interfaces__srv__VoltaOperationCommand_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'response'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/VoltaOperationCommand in the package cybergear_interfaces.
typedef struct cybergear_interfaces__srv__VoltaOperationCommand_Response
{
  rosidl_runtime_c__String response;
} cybergear_interfaces__srv__VoltaOperationCommand_Response;

// Struct for a sequence of cybergear_interfaces__srv__VoltaOperationCommand_Response.
typedef struct cybergear_interfaces__srv__VoltaOperationCommand_Response__Sequence
{
  cybergear_interfaces__srv__VoltaOperationCommand_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cybergear_interfaces__srv__VoltaOperationCommand_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CYBERGEAR_INTERFACES__SRV__DETAIL__VOLTA_OPERATION_COMMAND__STRUCT_H_
