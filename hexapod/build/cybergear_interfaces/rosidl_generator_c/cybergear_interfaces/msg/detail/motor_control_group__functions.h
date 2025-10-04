// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from cybergear_interfaces:msg/MotorControlGroup.idl
// generated code does not contain a copyright notice

#ifndef CYBERGEAR_INTERFACES__MSG__DETAIL__MOTOR_CONTROL_GROUP__FUNCTIONS_H_
#define CYBERGEAR_INTERFACES__MSG__DETAIL__MOTOR_CONTROL_GROUP__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "cybergear_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "cybergear_interfaces/msg/detail/motor_control_group__struct.h"

/// Initialize msg/MotorControlGroup message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * cybergear_interfaces__msg__MotorControlGroup
 * )) before or use
 * cybergear_interfaces__msg__MotorControlGroup__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_cybergear_interfaces
bool
cybergear_interfaces__msg__MotorControlGroup__init(cybergear_interfaces__msg__MotorControlGroup * msg);

/// Finalize msg/MotorControlGroup message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cybergear_interfaces
void
cybergear_interfaces__msg__MotorControlGroup__fini(cybergear_interfaces__msg__MotorControlGroup * msg);

/// Create msg/MotorControlGroup message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * cybergear_interfaces__msg__MotorControlGroup__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cybergear_interfaces
cybergear_interfaces__msg__MotorControlGroup *
cybergear_interfaces__msg__MotorControlGroup__create();

/// Destroy msg/MotorControlGroup message.
/**
 * It calls
 * cybergear_interfaces__msg__MotorControlGroup__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cybergear_interfaces
void
cybergear_interfaces__msg__MotorControlGroup__destroy(cybergear_interfaces__msg__MotorControlGroup * msg);

/// Check for msg/MotorControlGroup message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cybergear_interfaces
bool
cybergear_interfaces__msg__MotorControlGroup__are_equal(const cybergear_interfaces__msg__MotorControlGroup * lhs, const cybergear_interfaces__msg__MotorControlGroup * rhs);

/// Copy a msg/MotorControlGroup message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_cybergear_interfaces
bool
cybergear_interfaces__msg__MotorControlGroup__copy(
  const cybergear_interfaces__msg__MotorControlGroup * input,
  cybergear_interfaces__msg__MotorControlGroup * output);

/// Initialize array of msg/MotorControlGroup messages.
/**
 * It allocates the memory for the number of elements and calls
 * cybergear_interfaces__msg__MotorControlGroup__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_cybergear_interfaces
bool
cybergear_interfaces__msg__MotorControlGroup__Sequence__init(cybergear_interfaces__msg__MotorControlGroup__Sequence * array, size_t size);

/// Finalize array of msg/MotorControlGroup messages.
/**
 * It calls
 * cybergear_interfaces__msg__MotorControlGroup__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cybergear_interfaces
void
cybergear_interfaces__msg__MotorControlGroup__Sequence__fini(cybergear_interfaces__msg__MotorControlGroup__Sequence * array);

/// Create array of msg/MotorControlGroup messages.
/**
 * It allocates the memory for the array and calls
 * cybergear_interfaces__msg__MotorControlGroup__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cybergear_interfaces
cybergear_interfaces__msg__MotorControlGroup__Sequence *
cybergear_interfaces__msg__MotorControlGroup__Sequence__create(size_t size);

/// Destroy array of msg/MotorControlGroup messages.
/**
 * It calls
 * cybergear_interfaces__msg__MotorControlGroup__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cybergear_interfaces
void
cybergear_interfaces__msg__MotorControlGroup__Sequence__destroy(cybergear_interfaces__msg__MotorControlGroup__Sequence * array);

/// Check for msg/MotorControlGroup message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cybergear_interfaces
bool
cybergear_interfaces__msg__MotorControlGroup__Sequence__are_equal(const cybergear_interfaces__msg__MotorControlGroup__Sequence * lhs, const cybergear_interfaces__msg__MotorControlGroup__Sequence * rhs);

/// Copy an array of msg/MotorControlGroup messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_cybergear_interfaces
bool
cybergear_interfaces__msg__MotorControlGroup__Sequence__copy(
  const cybergear_interfaces__msg__MotorControlGroup__Sequence * input,
  cybergear_interfaces__msg__MotorControlGroup__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // CYBERGEAR_INTERFACES__MSG__DETAIL__MOTOR_CONTROL_GROUP__FUNCTIONS_H_
