// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cybergear_interfaces:msg/MotorControl.idl
// generated code does not contain a copyright notice
#include "cybergear_interfaces/msg/detail/motor_control__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `set_point`
#include "cybergear_interfaces/msg/detail/set_point__functions.h"

bool
cybergear_interfaces__msg__MotorControl__init(cybergear_interfaces__msg__MotorControl * msg)
{
  if (!msg) {
    return false;
  }
  // motor_id
  // control_mode
  // set_point
  if (!cybergear_interfaces__msg__SetPoint__init(&msg->set_point)) {
    cybergear_interfaces__msg__MotorControl__fini(msg);
    return false;
  }
  return true;
}

void
cybergear_interfaces__msg__MotorControl__fini(cybergear_interfaces__msg__MotorControl * msg)
{
  if (!msg) {
    return;
  }
  // motor_id
  // control_mode
  // set_point
  cybergear_interfaces__msg__SetPoint__fini(&msg->set_point);
}

bool
cybergear_interfaces__msg__MotorControl__are_equal(const cybergear_interfaces__msg__MotorControl * lhs, const cybergear_interfaces__msg__MotorControl * rhs)
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
  // set_point
  if (!cybergear_interfaces__msg__SetPoint__are_equal(
      &(lhs->set_point), &(rhs->set_point)))
  {
    return false;
  }
  return true;
}

bool
cybergear_interfaces__msg__MotorControl__copy(
  const cybergear_interfaces__msg__MotorControl * input,
  cybergear_interfaces__msg__MotorControl * output)
{
  if (!input || !output) {
    return false;
  }
  // motor_id
  output->motor_id = input->motor_id;
  // control_mode
  output->control_mode = input->control_mode;
  // set_point
  if (!cybergear_interfaces__msg__SetPoint__copy(
      &(input->set_point), &(output->set_point)))
  {
    return false;
  }
  return true;
}

cybergear_interfaces__msg__MotorControl *
cybergear_interfaces__msg__MotorControl__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cybergear_interfaces__msg__MotorControl * msg = (cybergear_interfaces__msg__MotorControl *)allocator.allocate(sizeof(cybergear_interfaces__msg__MotorControl), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cybergear_interfaces__msg__MotorControl));
  bool success = cybergear_interfaces__msg__MotorControl__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cybergear_interfaces__msg__MotorControl__destroy(cybergear_interfaces__msg__MotorControl * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cybergear_interfaces__msg__MotorControl__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cybergear_interfaces__msg__MotorControl__Sequence__init(cybergear_interfaces__msg__MotorControl__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cybergear_interfaces__msg__MotorControl * data = NULL;

  if (size) {
    data = (cybergear_interfaces__msg__MotorControl *)allocator.zero_allocate(size, sizeof(cybergear_interfaces__msg__MotorControl), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cybergear_interfaces__msg__MotorControl__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cybergear_interfaces__msg__MotorControl__fini(&data[i - 1]);
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
cybergear_interfaces__msg__MotorControl__Sequence__fini(cybergear_interfaces__msg__MotorControl__Sequence * array)
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
      cybergear_interfaces__msg__MotorControl__fini(&array->data[i]);
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

cybergear_interfaces__msg__MotorControl__Sequence *
cybergear_interfaces__msg__MotorControl__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cybergear_interfaces__msg__MotorControl__Sequence * array = (cybergear_interfaces__msg__MotorControl__Sequence *)allocator.allocate(sizeof(cybergear_interfaces__msg__MotorControl__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cybergear_interfaces__msg__MotorControl__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cybergear_interfaces__msg__MotorControl__Sequence__destroy(cybergear_interfaces__msg__MotorControl__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cybergear_interfaces__msg__MotorControl__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cybergear_interfaces__msg__MotorControl__Sequence__are_equal(const cybergear_interfaces__msg__MotorControl__Sequence * lhs, const cybergear_interfaces__msg__MotorControl__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cybergear_interfaces__msg__MotorControl__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cybergear_interfaces__msg__MotorControl__Sequence__copy(
  const cybergear_interfaces__msg__MotorControl__Sequence * input,
  cybergear_interfaces__msg__MotorControl__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cybergear_interfaces__msg__MotorControl);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cybergear_interfaces__msg__MotorControl * data =
      (cybergear_interfaces__msg__MotorControl *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cybergear_interfaces__msg__MotorControl__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cybergear_interfaces__msg__MotorControl__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cybergear_interfaces__msg__MotorControl__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
