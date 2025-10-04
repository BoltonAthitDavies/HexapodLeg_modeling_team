// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cybergear_interfaces:msg/MotorControl.idl
// generated code does not contain a copyright notice

#ifndef CYBERGEAR_INTERFACES__MSG__DETAIL__MOTOR_CONTROL__STRUCT_H_
#define CYBERGEAR_INTERFACES__MSG__DETAIL__MOTOR_CONTROL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'set_point'
#include "cybergear_interfaces/msg/detail/set_point__struct.h"

/// Struct defined in msg/MotorControl in the package cybergear_interfaces.
typedef struct cybergear_interfaces__msg__MotorControl
{
  /// หมายเลขมอเตอร์ที่ต้องการควบคุม
  int8_t motor_id;
  /// โหมดการควบคุม (0: operation, 1: current, 2: speed, 3: position)
  uint8_t control_mode;
  cybergear_interfaces__msg__SetPoint set_point;
} cybergear_interfaces__msg__MotorControl;

// Struct for a sequence of cybergear_interfaces__msg__MotorControl.
typedef struct cybergear_interfaces__msg__MotorControl__Sequence
{
  cybergear_interfaces__msg__MotorControl * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cybergear_interfaces__msg__MotorControl__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CYBERGEAR_INTERFACES__MSG__DETAIL__MOTOR_CONTROL__STRUCT_H_
