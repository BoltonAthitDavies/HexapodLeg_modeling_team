# generated from rosidl_generator_py/resource/_idl.py.em
# with input from cybergear_interfaces:srv/SetParam.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SetParam_Request(type):
    """Metaclass of message 'SetParam_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('cybergear_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'cybergear_interfaces.srv.SetParam_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__set_param__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__set_param__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__set_param__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__set_param__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__set_param__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SetParam_Request(metaclass=Metaclass_SetParam_Request):
    """Message class 'SetParam_Request'."""

    __slots__ = [
        '_motor_id',
        '_control_mode',
        '_param_name',
        '_communication_type',
        '_param_value',
        '_cur_kp',
        '_cur_ki',
        '_spd_kp',
        '_spd_ki',
        '_loc_kp',
        '_spd_filt_gain',
        '_limit_spd',
        '_limit_cur',
    ]

    _fields_and_field_types = {
        'motor_id': 'int8',
        'control_mode': 'uint8',
        'param_name': 'string',
        'communication_type': 'uint8',
        'param_value': 'float',
        'cur_kp': 'float',
        'cur_ki': 'float',
        'spd_kp': 'float',
        'spd_ki': 'float',
        'loc_kp': 'float',
        'spd_filt_gain': 'float',
        'limit_spd': 'float',
        'limit_cur': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.motor_id = kwargs.get('motor_id', int())
        self.control_mode = kwargs.get('control_mode', int())
        self.param_name = kwargs.get('param_name', str())
        self.communication_type = kwargs.get('communication_type', int())
        self.param_value = kwargs.get('param_value', float())
        self.cur_kp = kwargs.get('cur_kp', float())
        self.cur_ki = kwargs.get('cur_ki', float())
        self.spd_kp = kwargs.get('spd_kp', float())
        self.spd_ki = kwargs.get('spd_ki', float())
        self.loc_kp = kwargs.get('loc_kp', float())
        self.spd_filt_gain = kwargs.get('spd_filt_gain', float())
        self.limit_spd = kwargs.get('limit_spd', float())
        self.limit_cur = kwargs.get('limit_cur', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.motor_id != other.motor_id:
            return False
        if self.control_mode != other.control_mode:
            return False
        if self.param_name != other.param_name:
            return False
        if self.communication_type != other.communication_type:
            return False
        if self.param_value != other.param_value:
            return False
        if self.cur_kp != other.cur_kp:
            return False
        if self.cur_ki != other.cur_ki:
            return False
        if self.spd_kp != other.spd_kp:
            return False
        if self.spd_ki != other.spd_ki:
            return False
        if self.loc_kp != other.loc_kp:
            return False
        if self.spd_filt_gain != other.spd_filt_gain:
            return False
        if self.limit_spd != other.limit_spd:
            return False
        if self.limit_cur != other.limit_cur:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def motor_id(self):
        """Message field 'motor_id'."""
        return self._motor_id

    @motor_id.setter
    def motor_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'motor_id' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'motor_id' field must be an integer in [-128, 127]"
        self._motor_id = value

    @builtins.property
    def control_mode(self):
        """Message field 'control_mode'."""
        return self._control_mode

    @control_mode.setter
    def control_mode(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'control_mode' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'control_mode' field must be an unsigned integer in [0, 255]"
        self._control_mode = value

    @builtins.property
    def param_name(self):
        """Message field 'param_name'."""
        return self._param_name

    @param_name.setter
    def param_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'param_name' field must be of type 'str'"
        self._param_name = value

    @builtins.property
    def communication_type(self):
        """Message field 'communication_type'."""
        return self._communication_type

    @communication_type.setter
    def communication_type(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'communication_type' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'communication_type' field must be an unsigned integer in [0, 255]"
        self._communication_type = value

    @builtins.property
    def param_value(self):
        """Message field 'param_value'."""
        return self._param_value

    @param_value.setter
    def param_value(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'param_value' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'param_value' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._param_value = value

    @builtins.property
    def cur_kp(self):
        """Message field 'cur_kp'."""
        return self._cur_kp

    @cur_kp.setter
    def cur_kp(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'cur_kp' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'cur_kp' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._cur_kp = value

    @builtins.property
    def cur_ki(self):
        """Message field 'cur_ki'."""
        return self._cur_ki

    @cur_ki.setter
    def cur_ki(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'cur_ki' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'cur_ki' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._cur_ki = value

    @builtins.property
    def spd_kp(self):
        """Message field 'spd_kp'."""
        return self._spd_kp

    @spd_kp.setter
    def spd_kp(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'spd_kp' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'spd_kp' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._spd_kp = value

    @builtins.property
    def spd_ki(self):
        """Message field 'spd_ki'."""
        return self._spd_ki

    @spd_ki.setter
    def spd_ki(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'spd_ki' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'spd_ki' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._spd_ki = value

    @builtins.property
    def loc_kp(self):
        """Message field 'loc_kp'."""
        return self._loc_kp

    @loc_kp.setter
    def loc_kp(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'loc_kp' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'loc_kp' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._loc_kp = value

    @builtins.property
    def spd_filt_gain(self):
        """Message field 'spd_filt_gain'."""
        return self._spd_filt_gain

    @spd_filt_gain.setter
    def spd_filt_gain(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'spd_filt_gain' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'spd_filt_gain' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._spd_filt_gain = value

    @builtins.property
    def limit_spd(self):
        """Message field 'limit_spd'."""
        return self._limit_spd

    @limit_spd.setter
    def limit_spd(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'limit_spd' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'limit_spd' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._limit_spd = value

    @builtins.property
    def limit_cur(self):
        """Message field 'limit_cur'."""
        return self._limit_cur

    @limit_cur.setter
    def limit_cur(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'limit_cur' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'limit_cur' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._limit_cur = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_SetParam_Response(type):
    """Metaclass of message 'SetParam_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('cybergear_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'cybergear_interfaces.srv.SetParam_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__set_param__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__set_param__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__set_param__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__set_param__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__set_param__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SetParam_Response(metaclass=Metaclass_SetParam_Response):
    """Message class 'SetParam_Response'."""

    __slots__ = [
        '_success',
        '_message',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'message': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())
        self.message = kwargs.get('message', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.success != other.success:
            return False
        if self.message != other.message:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value

    @builtins.property
    def message(self):
        """Message field 'message'."""
        return self._message

    @message.setter
    def message(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'message' field must be of type 'str'"
        self._message = value


class Metaclass_SetParam(type):
    """Metaclass of service 'SetParam'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('cybergear_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'cybergear_interfaces.srv.SetParam')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__set_param

            from cybergear_interfaces.srv import _set_param
            if _set_param.Metaclass_SetParam_Request._TYPE_SUPPORT is None:
                _set_param.Metaclass_SetParam_Request.__import_type_support__()
            if _set_param.Metaclass_SetParam_Response._TYPE_SUPPORT is None:
                _set_param.Metaclass_SetParam_Response.__import_type_support__()


class SetParam(metaclass=Metaclass_SetParam):
    from cybergear_interfaces.srv._set_param import SetParam_Request as Request
    from cybergear_interfaces.srv._set_param import SetParam_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
