// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from cybergear_interfaces:srv/SetMotionGain.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "cybergear_interfaces/srv/detail/set_motion_gain__rosidl_typesupport_introspection_c.h"
#include "cybergear_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "cybergear_interfaces/srv/detail/set_motion_gain__functions.h"
#include "cybergear_interfaces/srv/detail/set_motion_gain__struct.h"


// Include directives for member types
// Member `param_name`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void cybergear_interfaces__srv__SetMotionGain_Request__rosidl_typesupport_introspection_c__SetMotionGain_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  cybergear_interfaces__srv__SetMotionGain_Request__init(message_memory);
}

void cybergear_interfaces__srv__SetMotionGain_Request__rosidl_typesupport_introspection_c__SetMotionGain_Request_fini_function(void * message_memory)
{
  cybergear_interfaces__srv__SetMotionGain_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember cybergear_interfaces__srv__SetMotionGain_Request__rosidl_typesupport_introspection_c__SetMotionGain_Request_message_member_array[7] = {
  {
    "motor_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cybergear_interfaces__srv__SetMotionGain_Request, motor_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "param_name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cybergear_interfaces__srv__SetMotionGain_Request, param_name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cybergear_interfaces__srv__SetMotionGain_Request, position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "velocity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cybergear_interfaces__srv__SetMotionGain_Request, velocity),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "effort",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cybergear_interfaces__srv__SetMotionGain_Request, effort),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "kp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cybergear_interfaces__srv__SetMotionGain_Request, kp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "kd",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cybergear_interfaces__srv__SetMotionGain_Request, kd),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers cybergear_interfaces__srv__SetMotionGain_Request__rosidl_typesupport_introspection_c__SetMotionGain_Request_message_members = {
  "cybergear_interfaces__srv",  // message namespace
  "SetMotionGain_Request",  // message name
  7,  // number of fields
  sizeof(cybergear_interfaces__srv__SetMotionGain_Request),
  cybergear_interfaces__srv__SetMotionGain_Request__rosidl_typesupport_introspection_c__SetMotionGain_Request_message_member_array,  // message members
  cybergear_interfaces__srv__SetMotionGain_Request__rosidl_typesupport_introspection_c__SetMotionGain_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  cybergear_interfaces__srv__SetMotionGain_Request__rosidl_typesupport_introspection_c__SetMotionGain_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t cybergear_interfaces__srv__SetMotionGain_Request__rosidl_typesupport_introspection_c__SetMotionGain_Request_message_type_support_handle = {
  0,
  &cybergear_interfaces__srv__SetMotionGain_Request__rosidl_typesupport_introspection_c__SetMotionGain_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_cybergear_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cybergear_interfaces, srv, SetMotionGain_Request)() {
  if (!cybergear_interfaces__srv__SetMotionGain_Request__rosidl_typesupport_introspection_c__SetMotionGain_Request_message_type_support_handle.typesupport_identifier) {
    cybergear_interfaces__srv__SetMotionGain_Request__rosidl_typesupport_introspection_c__SetMotionGain_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &cybergear_interfaces__srv__SetMotionGain_Request__rosidl_typesupport_introspection_c__SetMotionGain_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "cybergear_interfaces/srv/detail/set_motion_gain__rosidl_typesupport_introspection_c.h"
// already included above
// #include "cybergear_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "cybergear_interfaces/srv/detail/set_motion_gain__functions.h"
// already included above
// #include "cybergear_interfaces/srv/detail/set_motion_gain__struct.h"


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void cybergear_interfaces__srv__SetMotionGain_Response__rosidl_typesupport_introspection_c__SetMotionGain_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  cybergear_interfaces__srv__SetMotionGain_Response__init(message_memory);
}

void cybergear_interfaces__srv__SetMotionGain_Response__rosidl_typesupport_introspection_c__SetMotionGain_Response_fini_function(void * message_memory)
{
  cybergear_interfaces__srv__SetMotionGain_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember cybergear_interfaces__srv__SetMotionGain_Response__rosidl_typesupport_introspection_c__SetMotionGain_Response_message_member_array[2] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cybergear_interfaces__srv__SetMotionGain_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cybergear_interfaces__srv__SetMotionGain_Response, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers cybergear_interfaces__srv__SetMotionGain_Response__rosidl_typesupport_introspection_c__SetMotionGain_Response_message_members = {
  "cybergear_interfaces__srv",  // message namespace
  "SetMotionGain_Response",  // message name
  2,  // number of fields
  sizeof(cybergear_interfaces__srv__SetMotionGain_Response),
  cybergear_interfaces__srv__SetMotionGain_Response__rosidl_typesupport_introspection_c__SetMotionGain_Response_message_member_array,  // message members
  cybergear_interfaces__srv__SetMotionGain_Response__rosidl_typesupport_introspection_c__SetMotionGain_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  cybergear_interfaces__srv__SetMotionGain_Response__rosidl_typesupport_introspection_c__SetMotionGain_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t cybergear_interfaces__srv__SetMotionGain_Response__rosidl_typesupport_introspection_c__SetMotionGain_Response_message_type_support_handle = {
  0,
  &cybergear_interfaces__srv__SetMotionGain_Response__rosidl_typesupport_introspection_c__SetMotionGain_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_cybergear_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cybergear_interfaces, srv, SetMotionGain_Response)() {
  if (!cybergear_interfaces__srv__SetMotionGain_Response__rosidl_typesupport_introspection_c__SetMotionGain_Response_message_type_support_handle.typesupport_identifier) {
    cybergear_interfaces__srv__SetMotionGain_Response__rosidl_typesupport_introspection_c__SetMotionGain_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &cybergear_interfaces__srv__SetMotionGain_Response__rosidl_typesupport_introspection_c__SetMotionGain_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "cybergear_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "cybergear_interfaces/srv/detail/set_motion_gain__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers cybergear_interfaces__srv__detail__set_motion_gain__rosidl_typesupport_introspection_c__SetMotionGain_service_members = {
  "cybergear_interfaces__srv",  // service namespace
  "SetMotionGain",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // cybergear_interfaces__srv__detail__set_motion_gain__rosidl_typesupport_introspection_c__SetMotionGain_Request_message_type_support_handle,
  NULL  // response message
  // cybergear_interfaces__srv__detail__set_motion_gain__rosidl_typesupport_introspection_c__SetMotionGain_Response_message_type_support_handle
};

static rosidl_service_type_support_t cybergear_interfaces__srv__detail__set_motion_gain__rosidl_typesupport_introspection_c__SetMotionGain_service_type_support_handle = {
  0,
  &cybergear_interfaces__srv__detail__set_motion_gain__rosidl_typesupport_introspection_c__SetMotionGain_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cybergear_interfaces, srv, SetMotionGain_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cybergear_interfaces, srv, SetMotionGain_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_cybergear_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cybergear_interfaces, srv, SetMotionGain)() {
  if (!cybergear_interfaces__srv__detail__set_motion_gain__rosidl_typesupport_introspection_c__SetMotionGain_service_type_support_handle.typesupport_identifier) {
    cybergear_interfaces__srv__detail__set_motion_gain__rosidl_typesupport_introspection_c__SetMotionGain_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)cybergear_interfaces__srv__detail__set_motion_gain__rosidl_typesupport_introspection_c__SetMotionGain_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cybergear_interfaces, srv, SetMotionGain_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cybergear_interfaces, srv, SetMotionGain_Response)()->data;
  }

  return &cybergear_interfaces__srv__detail__set_motion_gain__rosidl_typesupport_introspection_c__SetMotionGain_service_type_support_handle;
}
