// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cybergear_interfaces:msg/SetPoint.idl
// generated code does not contain a copyright notice
#include "cybergear_interfaces/msg/detail/set_point__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
cybergear_interfaces__msg__SetPoint__init(cybergear_interfaces__msg__SetPoint * msg)
{
  if (!msg) {
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
cybergear_interfaces__msg__SetPoint__fini(cybergear_interfaces__msg__SetPoint * msg)
{
  if (!msg) {
    return;
  }
  // position
  // velocity
  // effort
  // kp
  // kd
}

bool
cybergear_interfaces__msg__SetPoint__are_equal(const cybergear_interfaces__msg__SetPoint * lhs, const cybergear_interfaces__msg__SetPoint * rhs)
{
  if (!lhs || !rhs) {
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
cybergear_interfaces__msg__SetPoint__copy(
  const cybergear_interfaces__msg__SetPoint * input,
  cybergear_interfaces__msg__SetPoint * output)
{
  if (!input || !output) {
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

cybergear_interfaces__msg__SetPoint *
cybergear_interfaces__msg__SetPoint__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cybergear_interfaces__msg__SetPoint * msg = (cybergear_interfaces__msg__SetPoint *)allocator.allocate(sizeof(cybergear_interfaces__msg__SetPoint), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cybergear_interfaces__msg__SetPoint));
  bool success = cybergear_interfaces__msg__SetPoint__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cybergear_interfaces__msg__SetPoint__destroy(cybergear_interfaces__msg__SetPoint * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cybergear_interfaces__msg__SetPoint__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cybergear_interfaces__msg__SetPoint__Sequence__init(cybergear_interfaces__msg__SetPoint__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cybergear_interfaces__msg__SetPoint * data = NULL;

  if (size) {
    data = (cybergear_interfaces__msg__SetPoint *)allocator.zero_allocate(size, sizeof(cybergear_interfaces__msg__SetPoint), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cybergear_interfaces__msg__SetPoint__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cybergear_interfaces__msg__SetPoint__fini(&data[i - 1]);
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
cybergear_interfaces__msg__SetPoint__Sequence__fini(cybergear_interfaces__msg__SetPoint__Sequence * array)
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
      cybergear_interfaces__msg__SetPoint__fini(&array->data[i]);
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

cybergear_interfaces__msg__SetPoint__Sequence *
cybergear_interfaces__msg__SetPoint__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cybergear_interfaces__msg__SetPoint__Sequence * array = (cybergear_interfaces__msg__SetPoint__Sequence *)allocator.allocate(sizeof(cybergear_interfaces__msg__SetPoint__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cybergear_interfaces__msg__SetPoint__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cybergear_interfaces__msg__SetPoint__Sequence__destroy(cybergear_interfaces__msg__SetPoint__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cybergear_interfaces__msg__SetPoint__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cybergear_interfaces__msg__SetPoint__Sequence__are_equal(const cybergear_interfaces__msg__SetPoint__Sequence * lhs, const cybergear_interfaces__msg__SetPoint__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cybergear_interfaces__msg__SetPoint__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cybergear_interfaces__msg__SetPoint__Sequence__copy(
  const cybergear_interfaces__msg__SetPoint__Sequence * input,
  cybergear_interfaces__msg__SetPoint__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cybergear_interfaces__msg__SetPoint);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cybergear_interfaces__msg__SetPoint * data =
      (cybergear_interfaces__msg__SetPoint *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cybergear_interfaces__msg__SetPoint__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cybergear_interfaces__msg__SetPoint__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cybergear_interfaces__msg__SetPoint__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
