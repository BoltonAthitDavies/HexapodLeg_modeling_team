// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cybergear_interfaces:srv/SetParam.idl
// generated code does not contain a copyright notice
#include "cybergear_interfaces/srv/detail/set_param__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `param_name`
#include "rosidl_runtime_c/string_functions.h"

bool
cybergear_interfaces__srv__SetParam_Request__init(cybergear_interfaces__srv__SetParam_Request * msg)
{
  if (!msg) {
    return false;
  }
  // motor_id
  // control_mode
  // param_name
  if (!rosidl_runtime_c__String__init(&msg->param_name)) {
    cybergear_interfaces__srv__SetParam_Request__fini(msg);
    return false;
  }
  // communication_type
  // param_value
  // cur_kp
  // cur_ki
  // spd_kp
  // spd_ki
  // loc_kp
  // spd_filt_gain
  // limit_spd
  // limit_cur
  return true;
}

void
cybergear_interfaces__srv__SetParam_Request__fini(cybergear_interfaces__srv__SetParam_Request * msg)
{
  if (!msg) {
    return;
  }
  // motor_id
  // control_mode
  // param_name
  rosidl_runtime_c__String__fini(&msg->param_name);
  // communication_type
  // param_value
  // cur_kp
  // cur_ki
  // spd_kp
  // spd_ki
  // loc_kp
  // spd_filt_gain
  // limit_spd
  // limit_cur
}

bool
cybergear_interfaces__srv__SetParam_Request__are_equal(const cybergear_interfaces__srv__SetParam_Request * lhs, const cybergear_interfaces__srv__SetParam_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // motor_id
  if (lhs->motor_id != rhs->motor_id) {
    return false;
  }
  // control_mode
  if (lhs->control_mode != rhs->control_mode) {
    return false;
  }
  // param_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->param_name), &(rhs->param_name)))
  {
    return false;
  }
  // communication_type
  if (lhs->communication_type != rhs->communication_type) {
    return false;
  }
  // param_value
  if (lhs->param_value != rhs->param_value) {
    return false;
  }
  // cur_kp
  if (lhs->cur_kp != rhs->cur_kp) {
    return false;
  }
  // cur_ki
  if (lhs->cur_ki != rhs->cur_ki) {
    return false;
  }
  // spd_kp
  if (lhs->spd_kp != rhs->spd_kp) {
    return false;
  }
  // spd_ki
  if (lhs->spd_ki != rhs->spd_ki) {
    return false;
  }
  // loc_kp
  if (lhs->loc_kp != rhs->loc_kp) {
    return false;
  }
  // spd_filt_gain
  if (lhs->spd_filt_gain != rhs->spd_filt_gain) {
    return false;
  }
  // limit_spd
  if (lhs->limit_spd != rhs->limit_spd) {
    return false;
  }
  // limit_cur
  if (lhs->limit_cur != rhs->limit_cur) {
    return false;
  }
  return true;
}

bool
cybergear_interfaces__srv__SetParam_Request__copy(
  const cybergear_interfaces__srv__SetParam_Request * input,
  cybergear_interfaces__srv__SetParam_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // motor_id
  output->motor_id = input->motor_id;
  // control_mode
  output->control_mode = input->control_mode;
  // param_name
  if (!rosidl_runtime_c__String__copy(
      &(input->param_name), &(output->param_name)))
  {
    return false;
  }
  // communication_type
  output->communication_type = input->communication_type;
  // param_value
  output->param_value = input->param_value;
  // cur_kp
  output->cur_kp = input->cur_kp;
  // cur_ki
  output->cur_ki = input->cur_ki;
  // spd_kp
  output->spd_kp = input->spd_kp;
  // spd_ki
  output->spd_ki = input->spd_ki;
  // loc_kp
  output->loc_kp = input->loc_kp;
  // spd_filt_gain
  output->spd_filt_gain = input->spd_filt_gain;
  // limit_spd
  output->limit_spd = input->limit_spd;
  // limit_cur
  output->limit_cur = input->limit_cur;
  return true;
}

cybergear_interfaces__srv__SetParam_Request *
cybergear_interfaces__srv__SetParam_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cybergear_interfaces__srv__SetParam_Request * msg = (cybergear_interfaces__srv__SetParam_Request *)allocator.allocate(sizeof(cybergear_interfaces__srv__SetParam_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cybergear_interfaces__srv__SetParam_Request));
  bool success = cybergear_interfaces__srv__SetParam_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cybergear_interfaces__srv__SetParam_Request__destroy(cybergear_interfaces__srv__SetParam_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cybergear_interfaces__srv__SetParam_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cybergear_interfaces__srv__SetParam_Request__Sequence__init(cybergear_interfaces__srv__SetParam_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cybergear_interfaces__srv__SetParam_Request * data = NULL;

  if (size) {
    data = (cybergear_interfaces__srv__SetParam_Request *)allocator.zero_allocate(size, sizeof(cybergear_interfaces__srv__SetParam_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cybergear_interfaces__srv__SetParam_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cybergear_interfaces__srv__SetParam_Request__fini(&data[i - 1]);
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
cybergear_interfaces__srv__SetParam_Request__Sequence__fini(cybergear_interfaces__srv__SetParam_Request__Sequence * array)
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
      cybergear_interfaces__srv__SetParam_Request__fini(&array->data[i]);
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

cybergear_interfaces__srv__SetParam_Request__Sequence *
cybergear_interfaces__srv__SetParam_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cybergear_interfaces__srv__SetParam_Request__Sequence * array = (cybergear_interfaces__srv__SetParam_Request__Sequence *)allocator.allocate(sizeof(cybergear_interfaces__srv__SetParam_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cybergear_interfaces__srv__SetParam_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cybergear_interfaces__srv__SetParam_Request__Sequence__destroy(cybergear_interfaces__srv__SetParam_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cybergear_interfaces__srv__SetParam_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cybergear_interfaces__srv__SetParam_Request__Sequence__are_equal(const cybergear_interfaces__srv__SetParam_Request__Sequence * lhs, const cybergear_interfaces__srv__SetParam_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cybergear_interfaces__srv__SetParam_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cybergear_interfaces__srv__SetParam_Request__Sequence__copy(
  const cybergear_interfaces__srv__SetParam_Request__Sequence * input,
  cybergear_interfaces__srv__SetParam_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cybergear_interfaces__srv__SetParam_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cybergear_interfaces__srv__SetParam_Request * data =
      (cybergear_interfaces__srv__SetParam_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cybergear_interfaces__srv__SetParam_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cybergear_interfaces__srv__SetParam_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cybergear_interfaces__srv__SetParam_Request__copy(
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
cybergear_interfaces__srv__SetParam_Response__init(cybergear_interfaces__srv__SetParam_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    cybergear_interfaces__srv__SetParam_Response__fini(msg);
    return false;
  }
  return true;
}

void
cybergear_interfaces__srv__SetParam_Response__fini(cybergear_interfaces__srv__SetParam_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
cybergear_interfaces__srv__SetParam_Response__are_equal(const cybergear_interfaces__srv__SetParam_Response * lhs, const cybergear_interfaces__srv__SetParam_Response * rhs)
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
cybergear_interfaces__srv__SetParam_Response__copy(
  const cybergear_interfaces__srv__SetParam_Response * input,
  cybergear_interfaces__srv__SetParam_Response * output)
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

cybergear_interfaces__srv__SetParam_Response *
cybergear_interfaces__srv__SetParam_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cybergear_interfaces__srv__SetParam_Response * msg = (cybergear_interfaces__srv__SetParam_Response *)allocator.allocate(sizeof(cybergear_interfaces__srv__SetParam_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cybergear_interfaces__srv__SetParam_Response));
  bool success = cybergear_interfaces__srv__SetParam_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cybergear_interfaces__srv__SetParam_Response__destroy(cybergear_interfaces__srv__SetParam_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cybergear_interfaces__srv__SetParam_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cybergear_interfaces__srv__SetParam_Response__Sequence__init(cybergear_interfaces__srv__SetParam_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cybergear_interfaces__srv__SetParam_Response * data = NULL;

  if (size) {
    data = (cybergear_interfaces__srv__SetParam_Response *)allocator.zero_allocate(size, sizeof(cybergear_interfaces__srv__SetParam_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cybergear_interfaces__srv__SetParam_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cybergear_interfaces__srv__SetParam_Response__fini(&data[i - 1]);
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
cybergear_interfaces__srv__SetParam_Response__Sequence__fini(cybergear_interfaces__srv__SetParam_Response__Sequence * array)
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
      cybergear_interfaces__srv__SetParam_Response__fini(&array->data[i]);
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

cybergear_interfaces__srv__SetParam_Response__Sequence *
cybergear_interfaces__srv__SetParam_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cybergear_interfaces__srv__SetParam_Response__Sequence * array = (cybergear_interfaces__srv__SetParam_Response__Sequence *)allocator.allocate(sizeof(cybergear_interfaces__srv__SetParam_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cybergear_interfaces__srv__SetParam_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cybergear_interfaces__srv__SetParam_Response__Sequence__destroy(cybergear_interfaces__srv__SetParam_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cybergear_interfaces__srv__SetParam_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cybergear_interfaces__srv__SetParam_Response__Sequence__are_equal(const cybergear_interfaces__srv__SetParam_Response__Sequence * lhs, const cybergear_interfaces__srv__SetParam_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cybergear_interfaces__srv__SetParam_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cybergear_interfaces__srv__SetParam_Response__Sequence__copy(
  const cybergear_interfaces__srv__SetParam_Response__Sequence * input,
  cybergear_interfaces__srv__SetParam_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cybergear_interfaces__srv__SetParam_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cybergear_interfaces__srv__SetParam_Response * data =
      (cybergear_interfaces__srv__SetParam_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cybergear_interfaces__srv__SetParam_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cybergear_interfaces__srv__SetParam_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cybergear_interfaces__srv__SetParam_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
