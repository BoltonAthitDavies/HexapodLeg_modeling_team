// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from cybergear_interfaces:msg/MotorControlGroup.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "cybergear_interfaces/msg/detail/motor_control_group__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace cybergear_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void MotorControlGroup_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) cybergear_interfaces::msg::MotorControlGroup(_init);
}

void MotorControlGroup_fini_function(void * message_memory)
{
  auto typed_message = static_cast<cybergear_interfaces::msg::MotorControlGroup *>(message_memory);
  typed_message->~MotorControlGroup();
}

size_t size_function__MotorControlGroup__motor_controls(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<cybergear_interfaces::msg::MotorControl> *>(untyped_member);
  return member->size();
}

const void * get_const_function__MotorControlGroup__motor_controls(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<cybergear_interfaces::msg::MotorControl> *>(untyped_member);
  return &member[index];
}

void * get_function__MotorControlGroup__motor_controls(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<cybergear_interfaces::msg::MotorControl> *>(untyped_member);
  return &member[index];
}

void fetch_function__MotorControlGroup__motor_controls(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const cybergear_interfaces::msg::MotorControl *>(
    get_const_function__MotorControlGroup__motor_controls(untyped_member, index));
  auto & value = *reinterpret_cast<cybergear_interfaces::msg::MotorControl *>(untyped_value);
  value = item;
}

void assign_function__MotorControlGroup__motor_controls(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<cybergear_interfaces::msg::MotorControl *>(
    get_function__MotorControlGroup__motor_controls(untyped_member, index));
  const auto & value = *reinterpret_cast<const cybergear_interfaces::msg::MotorControl *>(untyped_value);
  item = value;
}

void resize_function__MotorControlGroup__motor_controls(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<cybergear_interfaces::msg::MotorControl> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MotorControlGroup_message_member_array[2] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cybergear_interfaces::msg::MotorControlGroup, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "motor_controls",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<cybergear_interfaces::msg::MotorControl>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cybergear_interfaces::msg::MotorControlGroup, motor_controls),  // bytes offset in struct
    nullptr,  // default value
    size_function__MotorControlGroup__motor_controls,  // size() function pointer
    get_const_function__MotorControlGroup__motor_controls,  // get_const(index) function pointer
    get_function__MotorControlGroup__motor_controls,  // get(index) function pointer
    fetch_function__MotorControlGroup__motor_controls,  // fetch(index, &value) function pointer
    assign_function__MotorControlGroup__motor_controls,  // assign(index, value) function pointer
    resize_function__MotorControlGroup__motor_controls  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MotorControlGroup_message_members = {
  "cybergear_interfaces::msg",  // message namespace
  "MotorControlGroup",  // message name
  2,  // number of fields
  sizeof(cybergear_interfaces::msg::MotorControlGroup),
  MotorControlGroup_message_member_array,  // message members
  MotorControlGroup_init_function,  // function to initialize message memory (memory has to be allocated)
  MotorControlGroup_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MotorControlGroup_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MotorControlGroup_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace cybergear_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<cybergear_interfaces::msg::MotorControlGroup>()
{
  return &::cybergear_interfaces::msg::rosidl_typesupport_introspection_cpp::MotorControlGroup_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, cybergear_interfaces, msg, MotorControlGroup)() {
  return &::cybergear_interfaces::msg::rosidl_typesupport_introspection_cpp::MotorControlGroup_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
