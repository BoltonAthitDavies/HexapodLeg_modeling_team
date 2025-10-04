// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cybergear_interfaces:msg/SetPoint.idl
// generated code does not contain a copyright notice

#ifndef CYBERGEAR_INTERFACES__MSG__DETAIL__SET_POINT__STRUCT_H_
#define CYBERGEAR_INTERFACES__MSG__DETAIL__SET_POINT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/SetPoint in the package cybergear_interfaces.
typedef struct cybergear_interfaces__msg__SetPoint
{
  float position;
  float velocity;
  float effort;
  float kp;
  float kd;
} cybergear_interfaces__msg__SetPoint;

// Struct for a sequence of cybergear_interfaces__msg__SetPoint.
typedef struct cybergear_interfaces__msg__SetPoint__Sequence
{
  cybergear_interfaces__msg__SetPoint * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cybergear_interfaces__msg__SetPoint__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CYBERGEAR_INTERFACES__MSG__DETAIL__SET_POINT__STRUCT_H_
