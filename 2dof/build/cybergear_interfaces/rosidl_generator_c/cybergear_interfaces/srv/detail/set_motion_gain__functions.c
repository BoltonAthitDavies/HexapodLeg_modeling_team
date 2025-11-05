// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cybergear_interfaces:srv/SetMotionGain.idl
// generated code does not contain a copyright notice
#include "cybergear_interfaces/srv/detail/set_motion_gain__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `param_name`
#include "rosidl_runtime_c/string_functions.h"

bool
cybergear_interfaces__srv__SetMotionGain_Request__init(cybergear_interfaces__srv__SetMotionGain_Request * msg)
{
  if (!msg) {
    return false;
  }
  // motor_id
  // param_name
  if (!rosidl_runtime_c__String__init(&msg->param_name)) {
    cybergear_interfaces__srv__SetMotionGain_Request__fini(msg);
    return false;
  }
  // position
  // velocity
  // effort
  // kp
  // kd
  return true;
}

void
cybergear_interfaces__srv__SetMotionGain_Request__fini(cybergear_interfaces__srv__SetMotionGain_Request * msg)
{
  if (!msg) {
    return;
  }
  // motor_id
  // param_name
  rosidl_runtime_c__String__fini(&msg->param_name);
  // position
  // velocity
  // effort
  // kp
  // kd
}

bool
cybergear_interfaces__srv__SetMotionGain_Request__are_equal(const cybergear_interfaces__srv__SetMotionGain_Request * lhs, const cybergear_interfaces__srv__SetMotionGain_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // motor_id
  if (lhs->motor_id != rhs->motor_id) {
    return false;
  }
  // param_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->param_name), &(rhs->param_name)))
  {
    return false;
  }
  // position
  if (lhs->position != rhs->position) {
    return false;
  }
  // velocity
  if (lhs->velocity != rhs->velocity) {
    return false;
  }
  // effort
  if (lhs->effort != rhs->effort) {
    return false;
  }
  // kp
  if (lhs->kp != rhs->kp) {
    return false;
  }
  // kd
  if (lhs->kd != rhs->kd) {
    return false;
  }
  return true;
}

bool
cybergear_interfaces__srv__SetMotionGain_Request__copy(
  const cybergear_interfaces__srv__SetMotionGain_Request * input,
  cybergear_interfaces__srv__SetMotionGain_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // motor_id
  output->motor_id = input->motor_id;
  // param_name
  if (!rosidl_runtime_c__String__copy(
      &(input->param_name), &(output->param_name)))
  {
    return false;
  }
  // position
  output->position = input->position;
  // velocity
  output->velocity = input->velocity;
  // effort
  output->effort = input->effort;
  // kp
  output->kp = input->kp;
  // kd
  output->kd = input->kd;
  return true;
}

cybergear_interfaces__srv__SetMotionGain_Request *
cybergear_interfaces__srv__SetMotionGain_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cybergear_interfaces__srv__SetMotionGain_Request * msg = (cybergear_interfaces__srv__SetMotionGain_Request *)allocator.allocate(sizeof(cybergear_interfaces__srv__SetMotionGain_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cybergear_interfaces__srv__SetMotionGain_Request));
  bool success = cybergear_interfaces__srv__SetMotionGain_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cybergear_interfaces__srv__SetMotionGain_Request__destroy(cybergear_interfaces__srv__SetMotionGain_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cybergear_interfaces__srv__SetMotionGain_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cybergear_interfaces__srv__SetMotionGain_Request__Sequence__init(cybergear_interfaces__srv__SetMotionGain_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cybergear_interfaces__srv__SetMotionGain_Request * data = NULL;

  if (size) {
    data = (cybergear_interfaces__srv__SetMotionGain_Request *)allocator.zero_allocate(size, sizeof(cybergear_interfaces__srv__SetMotionGain_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cybergear_interfaces__srv__SetMotionGain_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cybergear_interfaces__srv__SetMotionGain_Request__fini(&data[i - 1]);
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
cybergear_interfaces__srv__SetMotionGain_Request__Sequence__fini(cybergear_interfaces__srv__SetMotionGain_Request__Sequence * array)
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
      cybergear_interfaces__srv__SetMotionGain_Request__fini(&array->data[i]);
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

cybergear_interfaces__srv__SetMotionGain_Request__Sequence *
cybergear_interfaces__srv__SetMotionGain_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cybergear_interfaces__srv__SetMotionGain_Request__Sequence * array = (cybergear_interfaces__srv__SetMotionGain_Request__Sequence *)allocator.allocate(sizeof(cybergear_interfaces__srv__SetMotionGain_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cybergear_interfaces__srv__SetMotionGain_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cybergear_interfaces__srv__SetMotionGain_Request__Sequence__destroy(cybergear_interfaces__srv__SetMotionGain_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cybergear_interfaces__srv__SetMotionGain_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cybergear_interfaces__srv__SetMotionGain_Request__Sequence__are_equal(const cybergear_interfaces__srv__SetMotionGain_Request__Sequence * lhs, const cybergear_interfaces__srv__SetMotionGain_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cybergear_interfaces__srv__SetMotionGain_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cybergear_interfaces__srv__SetMotionGain_Request__Sequence__copy(
  const cybergear_interfaces__srv__SetMotionGain_Request__Sequence * input,
  cybergear_interfaces__srv__SetMotionGain_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cybergear_interfaces__srv__SetMotionGain_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cybergear_interfaces__srv__SetMotionGain_Request * data =
      (cybergear_interfaces__srv__SetMotionGain_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cybergear_interfaces__srv__SetMotionGain_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cybergear_interfaces__srv__SetMotionGain_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cybergear_interfaces__srv__SetMotionGain_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
cybergear_interfaces__srv__SetMotionGain_Response__init(cybergear_interfaces__srv__SetMotionGain_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    cybergear_interfaces__srv__SetMotionGain_Response__fini(msg);
    return false;
  }
  return true;
}

void
cybergear_interfaces__srv__SetMotionGain_Response__fini(cybergear_interfaces__srv__SetMotionGain_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
cybergear_interfaces__srv__SetMotionGain_Response__are_equal(const cybergear_interfaces__srv__SetMotionGain_Response * lhs, const cybergear_interfaces__srv__SetMotionGain_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
cybergear_interfaces__srv__SetMotionGain_Response__copy(
  const cybergear_interfaces__srv__SetMotionGain_Response * input,
  cybergear_interfaces__srv__SetMotionGain_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

cybergear_interfaces__srv__SetMotionGain_Response *
cybergear_interfaces__srv__SetMotionGain_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cybergear_interfaces__srv__SetMotionGain_Response * msg = (cybergear_interfaces__srv__SetMotionGain_Response *)allocator.allocate(sizeof(cybergear_interfaces__srv__SetMotionGain_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cybergear_interfaces__srv__SetMotionGain_Response));
  bool success = cybergear_interfaces__srv__SetMotionGain_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cybergear_interfaces__srv__SetMotionGain_Response__destroy(cybergear_interfaces__srv__SetMotionGain_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cybergear_interfaces__srv__SetMotionGain_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cybergear_interfaces__srv__SetMotionGain_Response__Sequence__init(cybergear_interfaces__srv__SetMotionGain_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cybergear_interfaces__srv__SetMotionGain_Response * data = NULL;

  if (size) {
    data = (cybergear_interfaces__srv__SetMotionGain_Response *)allocator.zero_allocate(size, sizeof(cybergear_interfaces__srv__SetMotionGain_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cybergear_interfaces__srv__SetMotionGain_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cybergear_interfaces__srv__SetMotionGain_Response__fini(&data[i - 1]);
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
cybergear_interfaces__srv__SetMotionGain_Response__Sequence__fini(cybergear_interfaces__srv__SetMotionGain_Response__Sequence * array)
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
      cybergear_interfaces__srv__SetMotionGain_Response__fini(&array->data[i]);
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

cybergear_interfaces__srv__SetMotionGain_Response__Sequence *
cybergear_interfaces__srv__SetMotionGain_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cybergear_interfaces__srv__SetMotionGain_Response__Sequence * array = (cybergear_interfaces__srv__SetMotionGain_Response__Sequence *)allocator.allocate(sizeof(cybergear_interfaces__srv__SetMotionGain_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cybergear_interfaces__srv__SetMotionGain_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cybergear_interfaces__srv__SetMotionGain_Response__Sequence__destroy(cybergear_interfaces__srv__SetMotionGain_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cybergear_interfaces__srv__SetMotionGain_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cybergear_interfaces__srv__SetMotionGain_Response__Sequence__are_equal(const cybergear_interfaces__srv__SetMotionGain_Response__Sequence * lhs, const cybergear_interfaces__srv__SetMotionGain_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cybergear_interfaces__srv__SetMotionGain_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cybergear_interfaces__srv__SetMotionGain_Response__Sequence__copy(
  const cybergear_interfaces__srv__SetMotionGain_Response__Sequence * input,
  cybergear_interfaces__srv__SetMotionGain_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cybergear_interfaces__srv__SetMotionGain_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cybergear_interfaces__srv__SetMotionGain_Response * data =
      (cybergear_interfaces__srv__SetMotionGain_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cybergear_interfaces__srv__SetMotionGain_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cybergear_interfaces__srv__SetMotionGain_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cybergear_interfaces__srv__SetMotionGain_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
