// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cybergear_interfaces:srv/SetParam.idl
// generated code does not contain a copyright notice

#ifndef CYBERGEAR_INTERFACES__SRV__DETAIL__SET_PARAM__STRUCT_H_
#define CYBERGEAR_INTERFACES__SRV__DETAIL__SET_PARAM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'param_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SetParam in the package cybergear_interfaces.
typedef struct cybergear_interfaces__srv__SetParam_Request
{
  /// Motor ID (0-255)
  int8_t motor_id;
  /// Mode (0: operation, 1: position, 2: speed, 3: current, 4: enable, 5: disable, 6:SetParam)
  uint8_t control_mode;
  rosidl_runtime_c__String param_name;
  /// Communication type (8: Table, 18:General ITEM)
  uint8_t communication_type;
  /// General parameter value
  float param_value;
  /// Current PID proportional gain of MIT mode
  float cur_kp;
  /// Current PID Integral gain of MIT mode
  float cur_ki;
  /// Speed PID proportional gain of Speed and Location mode
  float spd_kp;
  /// Speed PID Integral gain of Speed and Location mode
  float spd_ki;
  /// Location PID proportional gain of Location mode
  float loc_kp;
  /// Speed filter parameters
  float spd_filt_gain;
  /// Location mode         speed limit
  float limit_spd;
  /// Position, Speed mode  current limit
  float limit_cur;
} cybergear_interfaces__srv__SetParam_Request;

// Struct for a sequence of cybergear_interfaces__srv__SetParam_Request.
typedef struct cybergear_interfaces__srv__SetParam_Request__Sequence
{
  cybergear_interfaces__srv__SetParam_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cybergear_interfaces__srv__SetParam_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SetParam in the package cybergear_interfaces.
typedef struct cybergear_interfaces__srv__SetParam_Response
{
  bool success;
  rosidl_runtime_c__String message;
} cybergear_interfaces__srv__SetParam_Response;

// Struct for a sequence of cybergear_interfaces__srv__SetParam_Response.
typedef struct cybergear_interfaces__srv__SetParam_Response__Sequence
{
  cybergear_interfaces__srv__SetParam_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cybergear_interfaces__srv__SetParam_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CYBERGEAR_INTERFACES__SRV__DETAIL__SET_PARAM__STRUCT_H_
