// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from cybergear_interfaces:msg/MotorControlGroup.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "cybergear_interfaces/msg/detail/motor_control_group__rosidl_typesupport_introspection_c.h"
#include "cybergear_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "cybergear_interfaces/msg/detail/motor_control_group__functions.h"
#include "cybergear_interfaces/msg/detail/motor_control_group__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `motor_controls`
#include "cybergear_interfaces/msg/motor_control.h"
// Member `motor_controls`
#include "cybergear_interfaces/msg/detail/motor_control__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void cybergear_interfaces__msg__MotorControlGroup__rosidl_typesupport_introspection_c__MotorControlGroup_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  cybergear_interfaces__msg__MotorControlGroup__init(message_memory);
}

void cybergear_interfaces__msg__MotorControlGroup__rosidl_typesupport_introspection_c__MotorControlGroup_fini_function(void * message_memory)
{
  cybergear_interfaces__msg__MotorControlGroup__fini(message_memory);
}

size_t cybergear_interfaces__msg__MotorControlGroup__rosidl_typesupport_introspection_c__size_function__MotorControlGroup__motor_controls(
  const void * untyped_member)
{
  const cybergear_interfaces__msg__MotorControl__Sequence * member =
    (const cybergear_interfaces__msg__MotorControl__Sequence *)(untyped_member);
  return member->size;
}

const void * cybergear_interfaces__msg__MotorControlGroup__rosidl_typesupport_introspection_c__get_const_function__MotorControlGroup__motor_controls(
  const void * untyped_member, size_t index)
{
  const cybergear_interfaces__msg__MotorControl__Sequence * member =
    (const cybergear_interfaces__msg__MotorControl__Sequence *)(untyped_member);
  return &member->data[index];
}

void * cybergear_interfaces__msg__MotorControlGroup__rosidl_typesupport_introspection_c__get_function__MotorControlGroup__motor_controls(
  void * untyped_member, size_t index)
{
  cybergear_interfaces__msg__MotorControl__Sequence * member =
    (cybergear_interfaces__msg__MotorControl__Sequence *)(untyped_member);
  return &member->data[index];
}

void cybergear_interfaces__msg__MotorControlGroup__rosidl_typesupport_introspection_c__fetch_function__MotorControlGroup__motor_controls(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const cybergear_interfaces__msg__MotorControl * item =
    ((const cybergear_interfaces__msg__MotorControl *)
    cybergear_interfaces__msg__MotorControlGroup__rosidl_typesupport_introspection_c__get_const_function__MotorControlGroup__motor_controls(untyped_member, index));
  cybergear_interfaces__msg__MotorControl * value =
    (cybergear_interfaces__msg__MotorControl *)(untyped_value);
  *value = *item;
}

void cybergear_interfaces__msg__MotorControlGroup__rosidl_typesupport_introspection_c__assign_function__MotorControlGroup__motor_controls(
  void * untyped_member, size_t index, const void * untyped_value)
{
  cybergear_interfaces__msg__MotorControl * item =
    ((cybergear_interfaces__msg__MotorControl *)
    cybergear_interfaces__msg__MotorControlGroup__rosidl_typesupport_introspection_c__get_function__MotorControlGroup__motor_controls(untyped_member, index));
  const cybergear_interfaces__msg__MotorControl * value =
    (const cybergear_interfaces__msg__MotorControl *)(untyped_value);
  *item = *value;
}

bool cybergear_interfaces__msg__MotorControlGroup__rosidl_typesupport_introspection_c__resize_function__MotorControlGroup__motor_controls(
  void * untyped_member, size_t size)
{
  cybergear_interfaces__msg__MotorControl__Sequence * member =
    (cybergear_interfaces__msg__MotorControl__Sequence *)(untyped_member);
  cybergear_interfaces__msg__MotorControl__Sequence__fini(member);
  return cybergear_interfaces__msg__MotorControl__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember cybergear_interfaces__msg__MotorControlGroup__rosidl_typesupport_introspection_c__MotorControlGroup_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cybergear_interfaces__msg__MotorControlGroup, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "motor_controls",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cybergear_interfaces__msg__MotorControlGroup, motor_controls),  // bytes offset in struct
    NULL,  // default value
    cybergear_interfaces__msg__MotorControlGroup__rosidl_typesupport_introspection_c__size_function__MotorControlGroup__motor_controls,  // size() function pointer
    cybergear_interfaces__msg__MotorControlGroup__rosidl_typesupport_introspection_c__get_const_function__MotorControlGroup__motor_controls,  // get_const(index) function pointer
    cybergear_interfaces__msg__MotorControlGroup__rosidl_typesupport_introspection_c__get_function__MotorControlGroup__motor_controls,  // get(index) function pointer
    cybergear_interfaces__msg__MotorControlGroup__rosidl_typesupport_introspection_c__fetch_function__MotorControlGroup__motor_controls,  // fetch(index, &value) function pointer
    cybergear_interfaces__msg__MotorControlGroup__rosidl_typesupport_introspection_c__assign_function__MotorControlGroup__motor_controls,  // assign(index, value) function pointer
    cybergear_interfaces__msg__MotorControlGroup__rosidl_typesupport_introspection_c__resize_function__MotorControlGroup__motor_controls  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers cybergear_interfaces__msg__MotorControlGroup__rosidl_typesupport_introspection_c__MotorControlGroup_message_members = {
  "cybergear_interfaces__msg",  // message namespace
  "MotorControlGroup",  // message name
  2,  // number of fields
  sizeof(cybergear_interfaces__msg__MotorControlGroup),
  cybergear_interfaces__msg__MotorControlGroup__rosidl_typesupport_introspection_c__MotorControlGroup_message_member_array,  // message members
  cybergear_interfaces__msg__MotorControlGroup__rosidl_typesupport_introspection_c__MotorControlGroup_init_function,  // function to initialize message memory (memory has to be allocated)
  cybergear_interfaces__msg__MotorControlGroup__rosidl_typesupport_introspection_c__MotorControlGroup_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t cybergear_interfaces__msg__MotorControlGroup__rosidl_typesupport_introspection_c__MotorControlGroup_message_type_support_handle = {
  0,
  &cybergear_interfaces__msg__MotorControlGroup__rosidl_typesupport_introspection_c__MotorControlGroup_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_cybergear_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cybergear_interfaces, msg, MotorControlGroup)() {
  cybergear_interfaces__msg__MotorControlGroup__rosidl_typesupport_introspection_c__MotorControlGroup_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  cybergear_interfaces__msg__MotorControlGroup__rosidl_typesupport_introspection_c__MotorControlGroup_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cybergear_interfaces, msg, MotorControl)();
  if (!cybergear_interfaces__msg__MotorControlGroup__rosidl_typesupport_introspection_c__MotorControlGroup_message_type_support_handle.typesupport_identifier) {
    cybergear_interfaces__msg__MotorControlGroup__rosidl_typesupport_introspection_c__MotorControlGroup_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &cybergear_interfaces__msg__MotorControlGroup__rosidl_typesupport_introspection_c__MotorControlGroup_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
