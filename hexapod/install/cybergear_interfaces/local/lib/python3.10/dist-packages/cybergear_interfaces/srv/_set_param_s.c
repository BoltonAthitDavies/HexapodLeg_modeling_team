// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from cybergear_interfaces:srv/SetParam.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "cybergear_interfaces/srv/detail/set_param__struct.h"
#include "cybergear_interfaces/srv/detail/set_param__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool cybergear_interfaces__srv__set_param__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[53];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("cybergear_interfaces.srv._set_param.SetParam_Request", full_classname_dest, 52) == 0);
  }
  cybergear_interfaces__srv__SetParam_Request * ros_message = _ros_message;
  {  // motor_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "motor_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->motor_id = (int8_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // control_mode
    PyObject * field = PyObject_GetAttrString(_pymsg, "control_mode");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->control_mode = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // param_name
    PyObject * field = PyObject_GetAttrString(_pymsg, "param_name");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->param_name, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // communication_type
    PyObject * field = PyObject_GetAttrString(_pymsg, "communication_type");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->communication_type = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // param_value
    PyObject * field = PyObject_GetAttrString(_pymsg, "param_value");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->param_value = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // cur_kp
    PyObject * field = PyObject_GetAttrString(_pymsg, "cur_kp");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->cur_kp = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // cur_ki
    PyObject * field = PyObject_GetAttrString(_pymsg, "cur_ki");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->cur_ki = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // spd_kp
    PyObject * field = PyObject_GetAttrString(_pymsg, "spd_kp");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->spd_kp = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // spd_ki
    PyObject * field = PyObject_GetAttrString(_pymsg, "spd_ki");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->spd_ki = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // loc_kp
    PyObject * field = PyObject_GetAttrString(_pymsg, "loc_kp");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->loc_kp = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // spd_filt_gain
    PyObject * field = PyObject_GetAttrString(_pymsg, "spd_filt_gain");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->spd_filt_gain = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // limit_spd
    PyObject * field = PyObject_GetAttrString(_pymsg, "limit_spd");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->limit_spd = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // limit_cur
    PyObject * field = PyObject_GetAttrString(_pymsg, "limit_cur");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->limit_cur = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * cybergear_interfaces__srv__set_param__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of SetParam_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("cybergear_interfaces.srv._set_param");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "SetParam_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  cybergear_interfaces__srv__SetParam_Request * ros_message = (cybergear_interfaces__srv__SetParam_Request *)raw_ros_message;
  {  // motor_id
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->motor_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "motor_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // control_mode
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->control_mode);
    {
      int rc = PyObject_SetAttrString(_pymessage, "control_mode", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // param_name
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->param_name.data,
      strlen(ros_message->param_name.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "param_name", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // communication_type
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->communication_type);
    {
      int rc = PyObject_SetAttrString(_pymessage, "communication_type", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // param_value
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->param_value);
    {
      int rc = PyObject_SetAttrString(_pymessage, "param_value", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // cur_kp
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->cur_kp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "cur_kp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // cur_ki
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->cur_ki);
    {
      int rc = PyObject_SetAttrString(_pymessage, "cur_ki", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // spd_kp
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->spd_kp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "spd_kp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // spd_ki
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->spd_ki);
    {
      int rc = PyObject_SetAttrString(_pymessage, "spd_ki", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // loc_kp
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->loc_kp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "loc_kp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // spd_filt_gain
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->spd_filt_gain);
    {
      int rc = PyObject_SetAttrString(_pymessage, "spd_filt_gain", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // limit_spd
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->limit_spd);
    {
      int rc = PyObject_SetAttrString(_pymessage, "limit_spd", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // limit_cur
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->limit_cur);
    {
      int rc = PyObject_SetAttrString(_pymessage, "limit_cur", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "cybergear_interfaces/srv/detail/set_param__struct.h"
// already included above
// #include "cybergear_interfaces/srv/detail/set_param__functions.h"

// already included above
// #include "rosidl_runtime_c/string.h"
// already included above
// #include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool cybergear_interfaces__srv__set_param__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[54];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("cybergear_interfaces.srv._set_param.SetParam_Response", full_classname_dest, 53) == 0);
  }
  cybergear_interfaces__srv__SetParam_Response * ros_message = _ros_message;
  {  // success
    PyObject * field = PyObject_GetAttrString(_pymsg, "success");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->success = (Py_True == field);
    Py_DECREF(field);
  }
  {  // message
    PyObject * field = PyObject_GetAttrString(_pymsg, "message");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->message, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * cybergear_interfaces__srv__set_param__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of SetParam_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("cybergear_interfaces.srv._set_param");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "SetParam_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  cybergear_interfaces__srv__SetParam_Response * ros_message = (cybergear_interfaces__srv__SetParam_Response *)raw_ros_message;
  {  // success
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->success ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "success", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // message
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->message.data,
      strlen(ros_message->message.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "message", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
