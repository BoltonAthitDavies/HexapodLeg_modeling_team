// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cybergear_interfaces:msg/MotorControlGroup.idl
// generated code does not contain a copyright notice

#ifndef CYBERGEAR_INTERFACES__MSG__DETAIL__MOTOR_CONTROL_GROUP__STRUCT_H_
#define CYBERGEAR_INTERFACES__MSG__DETAIL__MOTOR_CONTROL_GROUP__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'motor_controls'
#include "cybergear_interfaces/msg/detail/motor_control__struct.h"

/// Struct defined in msg/MotorControlGroup in the package cybergear_interfaces.
/**
  * MotorGroupControl.msg
  * ใช้สำหรับส่งคำสั่งควบคุมมอเตอร์หลายตัวพร้อมกัน
  * รวม header สำหรับข้อมูลเวลาและการ sync คำสั่งด้วย
 */
typedef struct cybergear_interfaces__msg__MotorControlGroup
{
  std_msgs__msg__Header header;
  cybergear_interfaces__msg__MotorControl__Sequence motor_controls;
} cybergear_interfaces__msg__MotorControlGroup;

// Struct for a sequence of cybergear_interfaces__msg__MotorControlGroup.
typedef struct cybergear_interfaces__msg__MotorControlGroup__Sequence
{
  cybergear_interfaces__msg__MotorControlGroup * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cybergear_interfaces__msg__MotorControlGroup__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CYBERGEAR_INTERFACES__MSG__DETAIL__MOTOR_CONTROL_GROUP__STRUCT_H_
