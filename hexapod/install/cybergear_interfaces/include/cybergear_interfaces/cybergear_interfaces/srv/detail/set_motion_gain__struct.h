// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cybergear_interfaces:srv/SetMotionGain.idl
// generated code does not contain a copyright notice

#ifndef CYBERGEAR_INTERFACES__SRV__DETAIL__SET_MOTION_GAIN__STRUCT_H_
#define CYBERGEAR_INTERFACES__SRV__DETAIL__SET_MOTION_GAIN__STRUCT_H_

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

/// Struct defined in srv/SetMotionGain in the package cybergear_interfaces.
typedef struct cybergear_interfaces__srv__SetMotionGain_Request
{
  /// Motor ID (0-255)
  int8_t motor_id;
  rosidl_runtime_c__String param_name;
  float position;
  float velocity;
  float effort;
  float kp;
  float kd;
} cybergear_interfaces__srv__SetMotionGain_Request;

// Struct for a sequence of cybergear_interfaces__srv__SetMotionGain_Request.
typedef struct cybergear_interfaces__srv__SetMotionGain_Request__Sequence
{
  cybergear_interfaces__srv__SetMotionGain_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cybergear_interfaces__srv__SetMotionGain_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SetMotionGain in the package cybergear_interfaces.
typedef struct cybergear_interfaces__srv__SetMotionGain_Response
{
  bool success;
  rosidl_runtime_c__String message;
} cybergear_interfaces__srv__SetMotionGain_Response;

// Struct for a sequence of cybergear_interfaces__srv__SetMotionGain_Response.
typedef struct cybergear_interfaces__srv__SetMotionGain_Response__Sequence
{
  cybergear_interfaces__srv__SetMotionGain_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cybergear_interfaces__srv__SetMotionGain_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CYBERGEAR_INTERFACES__SRV__DETAIL__SET_MOTION_GAIN__STRUCT_H_
