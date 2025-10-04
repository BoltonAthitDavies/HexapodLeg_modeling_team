// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cybergear_interfaces:srv/VoltaOperationCommand.idl
// generated code does not contain a copyright notice
#include "cybergear_interfaces/srv/detail/volta_operation_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
cybergear_interfaces__srv__VoltaOperationCommand_Request__init(cybergear_interfaces__srv__VoltaOperationCommand_Request * msg)
{
  if (!msg) {
    return false;
  }
  // operation_command
  return true;
}

void
cybergear_interfaces__srv__VoltaOperationCommand_Request__fini(cybergear_interfaces__srv__VoltaOperationCommand_Request * msg)
{
  if (!msg) {
    return;
  }
  // operation_command
}

bool
cybergear_interfaces__srv__VoltaOperationCommand_Request__are_equal(const cybergear_interfaces__srv__VoltaOperationCommand_Request * lhs, const cybergear_interfaces__srv__VoltaOperationCommand_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // operation_command
  if (lhs->operation_command != rhs->operation_command) {
    return false;
  }
  return true;
}

bool
cybergear_interfaces__srv__VoltaOperationCommand_Request__copy(
  const cybergear_interfaces__srv__VoltaOperationCommand_Request * input,
  cybergear_interfaces__srv__VoltaOperationCommand_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // operation_command
  output->operation_command = input->operation_command;
  return true;
}

cybergear_interfaces__srv__VoltaOperationCommand_Request *
cybergear_interfaces__srv__VoltaOperationCommand_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cybergear_interfaces__srv__VoltaOperationCommand_Request * msg = (cybergear_interfaces__srv__VoltaOperationCommand_Request *)allocator.allocate(sizeof(cybergear_interfaces__srv__VoltaOperationCommand_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cybergear_interfaces__srv__VoltaOperationCommand_Request));
  bool success = cybergear_interfaces__srv__VoltaOperationCommand_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cybergear_interfaces__srv__VoltaOperationCommand_Request__destroy(cybergear_interfaces__srv__VoltaOperationCommand_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cybergear_interfaces__srv__VoltaOperationCommand_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cybergear_interfaces__srv__VoltaOperationCommand_Request__Sequence__init(cybergear_interfaces__srv__VoltaOperationCommand_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cybergear_interfaces__srv__VoltaOperationCommand_Request * data = NULL;

  if (size) {
    data = (cybergear_interfaces__srv__VoltaOperationCommand_Request *)allocator.zero_allocate(size, sizeof(cybergear_interfaces__srv__VoltaOperationCommand_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cybergear_interfaces__srv__VoltaOperationCommand_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cybergear_interfaces__srv__VoltaOperationCommand_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
cybergear_interfaces__srv__VoltaOperationCommand_Request__Sequence__fini(cybergear_interfaces__srv__VoltaOperationCommand_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      cybergear_interfaces__srv__VoltaOperationCommand_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

cybergear_interfaces__srv__VoltaOperationCommand_Request__Sequence *
cybergear_interfaces__srv__VoltaOperationCommand_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cybergear_interfaces__srv__VoltaOperationCommand_Request__Sequence * array = (cybergear_interfaces__srv__VoltaOperationCommand_Request__Sequence *)allocator.allocate(sizeof(cybergear_interfaces__srv__VoltaOperationCommand_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cybergear_interfaces__srv__VoltaOperationCommand_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cybergear_interfaces__srv__VoltaOperationCommand_Request__Sequence__destroy(cybergear_interfaces__srv__VoltaOperationCommand_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cybergear_interfaces__srv__VoltaOperationCommand_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cybergear_interfaces__srv__VoltaOperationCommand_Request__Sequence__are_equal(const cybergear_interfaces__srv__VoltaOperationCommand_Request__Sequence * lhs, const cybergear_interfaces__srv__VoltaOperationCommand_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cybergear_interfaces__srv__VoltaOperationCommand_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cybergear_interfaces__srv__VoltaOperationCommand_Request__Sequence__copy(
  const cybergear_interfaces__srv__VoltaOperationCommand_Request__Sequence * input,
  cybergear_interfaces__srv__VoltaOperationCommand_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cybergear_interfaces__srv__VoltaOperationCommand_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cybergear_interfaces__srv__VoltaOperationCommand_Request * data =
      (cybergear_interfaces__srv__VoltaOperationCommand_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cybergear_interfaces__srv__VoltaOperationCommand_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cybergear_interfaces__srv__VoltaOperationCommand_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cybergear_interfaces__srv__VoltaOperationCommand_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `response`
#include "rosidl_runtime_c/string_functions.h"

bool
cybergear_interfaces__srv__VoltaOperationCommand_Response__init(cybergear_interfaces__srv__VoltaOperationCommand_Response * msg)
{
  if (!msg) {
    return false;
  }
  // response
  if (!rosidl_runtime_c__String__init(&msg->response)) {
    cybergear_interfaces__srv__VoltaOperationCommand_Response__fini(msg);
    return false;
  }
  return true;
}

void
cybergear_interfaces__srv__VoltaOperationCommand_Response__fini(cybergear_interfaces__srv__VoltaOperationCommand_Response * msg)
{
  if (!msg) {
    return;
  }
  // response
  rosidl_runtime_c__String__fini(&msg->response);
}

bool
cybergear_interfaces__srv__VoltaOperationCommand_Response__are_equal(const cybergear_interfaces__srv__VoltaOperationCommand_Response * lhs, const cybergear_interfaces__srv__VoltaOperationCommand_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // response
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
cybergear_interfaces__srv__VoltaOperationCommand_Response__copy(
  const cybergear_interfaces__srv__VoltaOperationCommand_Response * input,
  cybergear_interfaces__srv__VoltaOperationCommand_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // response
  if (!rosidl_runtime_c__String__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

cybergear_interfaces__srv__VoltaOperationCommand_Response *
cybergear_interfaces__srv__VoltaOperationCommand_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cybergear_interfaces__srv__VoltaOperationCommand_Response * msg = (cybergear_interfaces__srv__VoltaOperationCommand_Response *)allocator.allocate(sizeof(cybergear_interfaces__srv__VoltaOperationCommand_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cybergear_interfaces__srv__VoltaOperationCommand_Response));
  bool success = cybergear_interfaces__srv__VoltaOperationCommand_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cybergear_interfaces__srv__VoltaOperationCommand_Response__destroy(cybergear_interfaces__srv__VoltaOperationCommand_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cybergear_interfaces__srv__VoltaOperationCommand_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cybergear_interfaces__srv__VoltaOperationCommand_Response__Sequence__init(cybergear_interfaces__srv__VoltaOperationCommand_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cybergear_interfaces__srv__VoltaOperationCommand_Response * data = NULL;

  if (size) {
    data = (cybergear_interfaces__srv__VoltaOperationCommand_Response *)allocator.zero_allocate(size, sizeof(cybergear_interfaces__srv__VoltaOperationCommand_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cybergear_interfaces__srv__VoltaOperationCommand_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cybergear_interfaces__srv__VoltaOperationCommand_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
cybergear_interfaces__srv__VoltaOperationCommand_Response__Sequence__fini(cybergear_interfaces__srv__VoltaOperationCommand_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      cybergear_interfaces__srv__VoltaOperationCommand_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

cybergear_interfaces__srv__VoltaOperationCommand_Response__Sequence *
cybergear_interfaces__srv__VoltaOperationCommand_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cybergear_interfaces__srv__VoltaOperationCommand_Response__Sequence * array = (cybergear_interfaces__srv__VoltaOperationCommand_Response__Sequence *)allocator.allocate(sizeof(cybergear_interfaces__srv__VoltaOperationCommand_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cybergear_interfaces__srv__VoltaOperationCommand_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cybergear_interfaces__srv__VoltaOperationCommand_Response__Sequence__destroy(cybergear_interfaces__srv__VoltaOperationCommand_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cybergear_interfaces__srv__VoltaOperationCommand_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cybergear_interfaces__srv__VoltaOperationCommand_Response__Sequence__are_equal(const cybergear_interfaces__srv__VoltaOperationCommand_Response__Sequence * lhs, const cybergear_interfaces__srv__VoltaOperationCommand_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cybergear_interfaces__srv__VoltaOperationCommand_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cybergear_interfaces__srv__VoltaOperationCommand_Response__Sequence__copy(
  const cybergear_interfaces__srv__VoltaOperationCommand_Response__Sequence * input,
  cybergear_interfaces__srv__VoltaOperationCommand_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cybergear_interfaces__srv__VoltaOperationCommand_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cybergear_interfaces__srv__VoltaOperationCommand_Response * data =
      (cybergear_interfaces__srv__VoltaOperationCommand_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cybergear_interfaces__srv__VoltaOperationCommand_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cybergear_interfaces__srv__VoltaOperationCommand_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cybergear_interfaces__srv__VoltaOperationCommand_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
