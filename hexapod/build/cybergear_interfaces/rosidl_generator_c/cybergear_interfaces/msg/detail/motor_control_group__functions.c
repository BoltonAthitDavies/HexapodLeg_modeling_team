// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cybergear_interfaces:msg/MotorControlGroup.idl
// generated code does not contain a copyright notice
#include "cybergear_interfaces/msg/detail/motor_control_group__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `motor_controls`
#include "cybergear_interfaces/msg/detail/motor_control__functions.h"

bool
cybergear_interfaces__msg__MotorControlGroup__init(cybergear_interfaces__msg__MotorControlGroup * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    cybergear_interfaces__msg__MotorControlGroup__fini(msg);
    return false;
  }
  // motor_controls
  if (!cybergear_interfaces__msg__MotorControl__Sequence__init(&msg->motor_controls, 0)) {
    cybergear_interfaces__msg__MotorControlGroup__fini(msg);
    return false;
  }
  return true;
}

void
cybergear_interfaces__msg__MotorControlGroup__fini(cybergear_interfaces__msg__MotorControlGroup * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // motor_controls
  cybergear_interfaces__msg__MotorControl__Sequence__fini(&msg->motor_controls);
}

bool
cybergear_interfaces__msg__MotorControlGroup__are_equal(const cybergear_interfaces__msg__MotorControlGroup * lhs, const cybergear_interfaces__msg__MotorControlGroup * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // motor_controls
  if (!cybergear_interfaces__msg__MotorControl__Sequence__are_equal(
      &(lhs->motor_controls), &(rhs->motor_controls)))
  {
    return false;
  }
  return true;
}

bool
cybergear_interfaces__msg__MotorControlGroup__copy(
  const cybergear_interfaces__msg__MotorControlGroup * input,
  cybergear_interfaces__msg__MotorControlGroup * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // motor_controls
  if (!cybergear_interfaces__msg__MotorControl__Sequence__copy(
      &(input->motor_controls), &(output->motor_controls)))
  {
    return false;
  }
  return true;
}

cybergear_interfaces__msg__MotorControlGroup *
cybergear_interfaces__msg__MotorControlGroup__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cybergear_interfaces__msg__MotorControlGroup * msg = (cybergear_interfaces__msg__MotorControlGroup *)allocator.allocate(sizeof(cybergear_interfaces__msg__MotorControlGroup), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cybergear_interfaces__msg__MotorControlGroup));
  bool success = cybergear_interfaces__msg__MotorControlGroup__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cybergear_interfaces__msg__MotorControlGroup__destroy(cybergear_interfaces__msg__MotorControlGroup * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cybergear_interfaces__msg__MotorControlGroup__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cybergear_interfaces__msg__MotorControlGroup__Sequence__init(cybergear_interfaces__msg__MotorControlGroup__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cybergear_interfaces__msg__MotorControlGroup * data = NULL;

  if (size) {
    data = (cybergear_interfaces__msg__MotorControlGroup *)allocator.zero_allocate(size, sizeof(cybergear_interfaces__msg__MotorControlGroup), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cybergear_interfaces__msg__MotorControlGroup__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cybergear_interfaces__msg__MotorControlGroup__fini(&data[i - 1]);
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
cybergear_interfaces__msg__MotorControlGroup__Sequence__fini(cybergear_interfaces__msg__MotorControlGroup__Sequence * array)
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
      cybergear_interfaces__msg__MotorControlGroup__fini(&array->data[i]);
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

cybergear_interfaces__msg__MotorControlGroup__Sequence *
cybergear_interfaces__msg__MotorControlGroup__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cybergear_interfaces__msg__MotorControlGroup__Sequence * array = (cybergear_interfaces__msg__MotorControlGroup__Sequence *)allocator.allocate(sizeof(cybergear_interfaces__msg__MotorControlGroup__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cybergear_interfaces__msg__MotorControlGroup__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cybergear_interfaces__msg__MotorControlGroup__Sequence__destroy(cybergear_interfaces__msg__MotorControlGroup__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cybergear_interfaces__msg__MotorControlGroup__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cybergear_interfaces__msg__MotorControlGroup__Sequence__are_equal(const cybergear_interfaces__msg__MotorControlGroup__Sequence * lhs, const cybergear_interfaces__msg__MotorControlGroup__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cybergear_interfaces__msg__MotorControlGroup__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cybergear_interfaces__msg__MotorControlGroup__Sequence__copy(
  const cybergear_interfaces__msg__MotorControlGroup__Sequence * input,
  cybergear_interfaces__msg__MotorControlGroup__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cybergear_interfaces__msg__MotorControlGroup);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cybergear_interfaces__msg__MotorControlGroup * data =
      (cybergear_interfaces__msg__MotorControlGroup *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cybergear_interfaces__msg__MotorControlGroup__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cybergear_interfaces__msg__MotorControlGroup__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cybergear_interfaces__msg__MotorControlGroup__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
