// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from cybergear_interfaces:srv/VoltaOperationCommand.idl
// generated code does not contain a copyright notice

#ifndef CYBERGEAR_INTERFACES__SRV__DETAIL__VOLTA_OPERATION_COMMAND__FUNCTIONS_H_
#define CYBERGEAR_INTERFACES__SRV__DETAIL__VOLTA_OPERATION_COMMAND__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "cybergear_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "cybergear_interfaces/srv/detail/volta_operation_command__struct.h"

/// Initialize srv/VoltaOperationCommand message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * cybergear_interfaces__srv__VoltaOperationCommand_Request
 * )) before or use
 * cybergear_interfaces__srv__VoltaOperationCommand_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_cybergear_interfaces
bool
cybergear_interfaces__srv__VoltaOperationCommand_Request__init(cybergear_interfaces__srv__VoltaOperationCommand_Request * msg);

/// Finalize srv/VoltaOperationCommand message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cybergear_interfaces
void
cybergear_interfaces__srv__VoltaOperationCommand_Request__fini(cybergear_interfaces__srv__VoltaOperationCommand_Request * msg);

/// Create srv/VoltaOperationCommand message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * cybergear_interfaces__srv__VoltaOperationCommand_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cybergear_interfaces
cybergear_interfaces__srv__VoltaOperationCommand_Request *
cybergear_interfaces__srv__VoltaOperationCommand_Request__create();

/// Destroy srv/VoltaOperationCommand message.
/**
 * It calls
 * cybergear_interfaces__srv__VoltaOperationCommand_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cybergear_interfaces
void
cybergear_interfaces__srv__VoltaOperationCommand_Request__destroy(cybergear_interfaces__srv__VoltaOperationCommand_Request * msg);

/// Check for srv/VoltaOperationCommand message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cybergear_interfaces
bool
cybergear_interfaces__srv__VoltaOperationCommand_Request__are_equal(const cybergear_interfaces__srv__VoltaOperationCommand_Request * lhs, const cybergear_interfaces__srv__VoltaOperationCommand_Request * rhs);

/// Copy a srv/VoltaOperationCommand message.
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
cybergear_interfaces__srv__VoltaOperationCommand_Request__copy(
  const cybergear_interfaces__srv__VoltaOperationCommand_Request * input,
  cybergear_interfaces__srv__VoltaOperationCommand_Request * output);

/// Initialize array of srv/VoltaOperationCommand messages.
/**
 * It allocates the memory for the number of elements and calls
 * cybergear_interfaces__srv__VoltaOperationCommand_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_cybergear_interfaces
bool
cybergear_interfaces__srv__VoltaOperationCommand_Request__Sequence__init(cybergear_interfaces__srv__VoltaOperationCommand_Request__Sequence * array, size_t size);

/// Finalize array of srv/VoltaOperationCommand messages.
/**
 * It calls
 * cybergear_interfaces__srv__VoltaOperationCommand_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cybergear_interfaces
void
cybergear_interfaces__srv__VoltaOperationCommand_Request__Sequence__fini(cybergear_interfaces__srv__VoltaOperationCommand_Request__Sequence * array);

/// Create array of srv/VoltaOperationCommand messages.
/**
 * It allocates the memory for the array and calls
 * cybergear_interfaces__srv__VoltaOperationCommand_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cybergear_interfaces
cybergear_interfaces__srv__VoltaOperationCommand_Request__Sequence *
cybergear_interfaces__srv__VoltaOperationCommand_Request__Sequence__create(size_t size);

/// Destroy array of srv/VoltaOperationCommand messages.
/**
 * It calls
 * cybergear_interfaces__srv__VoltaOperationCommand_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cybergear_interfaces
void
cybergear_interfaces__srv__VoltaOperationCommand_Request__Sequence__destroy(cybergear_interfaces__srv__VoltaOperationCommand_Request__Sequence * array);

/// Check for srv/VoltaOperationCommand message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cybergear_interfaces
bool
cybergear_interfaces__srv__VoltaOperationCommand_Request__Sequence__are_equal(const cybergear_interfaces__srv__VoltaOperationCommand_Request__Sequence * lhs, const cybergear_interfaces__srv__VoltaOperationCommand_Request__Sequence * rhs);

/// Copy an array of srv/VoltaOperationCommand messages.
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
cybergear_interfaces__srv__VoltaOperationCommand_Request__Sequence__copy(
  const cybergear_interfaces__srv__VoltaOperationCommand_Request__Sequence * input,
  cybergear_interfaces__srv__VoltaOperationCommand_Request__Sequence * output);

/// Initialize srv/VoltaOperationCommand message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * cybergear_interfaces__srv__VoltaOperationCommand_Response
 * )) before or use
 * cybergear_interfaces__srv__VoltaOperationCommand_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_cybergear_interfaces
bool
cybergear_interfaces__srv__VoltaOperationCommand_Response__init(cybergear_interfaces__srv__VoltaOperationCommand_Response * msg);

/// Finalize srv/VoltaOperationCommand message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cybergear_interfaces
void
cybergear_interfaces__srv__VoltaOperationCommand_Response__fini(cybergear_interfaces__srv__VoltaOperationCommand_Response * msg);

/// Create srv/VoltaOperationCommand message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * cybergear_interfaces__srv__VoltaOperationCommand_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cybergear_interfaces
cybergear_interfaces__srv__VoltaOperationCommand_Response *
cybergear_interfaces__srv__VoltaOperationCommand_Response__create();

/// Destroy srv/VoltaOperationCommand message.
/**
 * It calls
 * cybergear_interfaces__srv__VoltaOperationCommand_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cybergear_interfaces
void
cybergear_interfaces__srv__VoltaOperationCommand_Response__destroy(cybergear_interfaces__srv__VoltaOperationCommand_Response * msg);

/// Check for srv/VoltaOperationCommand message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cybergear_interfaces
bool
cybergear_interfaces__srv__VoltaOperationCommand_Response__are_equal(const cybergear_interfaces__srv__VoltaOperationCommand_Response * lhs, const cybergear_interfaces__srv__VoltaOperationCommand_Response * rhs);

/// Copy a srv/VoltaOperationCommand message.
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
cybergear_interfaces__srv__VoltaOperationCommand_Response__copy(
  const cybergear_interfaces__srv__VoltaOperationCommand_Response * input,
  cybergear_interfaces__srv__VoltaOperationCommand_Response * output);

/// Initialize array of srv/VoltaOperationCommand messages.
/**
 * It allocates the memory for the number of elements and calls
 * cybergear_interfaces__srv__VoltaOperationCommand_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_cybergear_interfaces
bool
cybergear_interfaces__srv__VoltaOperationCommand_Response__Sequence__init(cybergear_interfaces__srv__VoltaOperationCommand_Response__Sequence * array, size_t size);

/// Finalize array of srv/VoltaOperationCommand messages.
/**
 * It calls
 * cybergear_interfaces__srv__VoltaOperationCommand_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cybergear_interfaces
void
cybergear_interfaces__srv__VoltaOperationCommand_Response__Sequence__fini(cybergear_interfaces__srv__VoltaOperationCommand_Response__Sequence * array);

/// Create array of srv/VoltaOperationCommand messages.
/**
 * It allocates the memory for the array and calls
 * cybergear_interfaces__srv__VoltaOperationCommand_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cybergear_interfaces
cybergear_interfaces__srv__VoltaOperationCommand_Response__Sequence *
cybergear_interfaces__srv__VoltaOperationCommand_Response__Sequence__create(size_t size);

/// Destroy array of srv/VoltaOperationCommand messages.
/**
 * It calls
 * cybergear_interfaces__srv__VoltaOperationCommand_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cybergear_interfaces
void
cybergear_interfaces__srv__VoltaOperationCommand_Response__Sequence__destroy(cybergear_interfaces__srv__VoltaOperationCommand_Response__Sequence * array);

/// Check for srv/VoltaOperationCommand message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cybergear_interfaces
bool
cybergear_interfaces__srv__VoltaOperationCommand_Response__Sequence__are_equal(const cybergear_interfaces__srv__VoltaOperationCommand_Response__Sequence * lhs, const cybergear_interfaces__srv__VoltaOperationCommand_Response__Sequence * rhs);

/// Copy an array of srv/VoltaOperationCommand messages.
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
cybergear_interfaces__srv__VoltaOperationCommand_Response__Sequence__copy(
  const cybergear_interfaces__srv__VoltaOperationCommand_Response__Sequence * input,
  cybergear_interfaces__srv__VoltaOperationCommand_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // CYBERGEAR_INTERFACES__SRV__DETAIL__VOLTA_OPERATION_COMMAND__FUNCTIONS_H_
