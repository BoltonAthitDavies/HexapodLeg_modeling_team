# generated from rosidl_generator_py/resource/_idl.py.em
# with input from cybergear_interfaces:srv/VoltaOperationCommand.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_VoltaOperationCommand_Request(type):
    """Metaclass of message 'VoltaOperationCommand_Request'."""

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
                'cybergear_interfaces.srv.VoltaOperationCommand_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__volta_operation_command__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__volta_operation_command__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__volta_operation_command__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__volta_operation_command__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__volta_operation_command__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class VoltaOperationCommand_Request(metaclass=Metaclass_VoltaOperationCommand_Request):
    """Message class 'VoltaOperationCommand_Request'."""

    __slots__ = [
        '_operation_command',
    ]

    _fields_and_field_types = {
        'operation_command': 'int16',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.operation_command = kwargs.get('operation_command', int())

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
        if self.operation_command != other.operation_command:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def operation_command(self):
        """Message field 'operation_command'."""
        return self._operation_command

    @operation_command.setter
    def operation_command(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'operation_command' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'operation_command' field must be an integer in [-32768, 32767]"
        self._operation_command = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_VoltaOperationCommand_Response(type):
    """Metaclass of message 'VoltaOperationCommand_Response'."""

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
                'cybergear_interfaces.srv.VoltaOperationCommand_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__volta_operation_command__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__volta_operation_command__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__volta_operation_command__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__volta_operation_command__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__volta_operation_command__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class VoltaOperationCommand_Response(metaclass=Metaclass_VoltaOperationCommand_Response):
    """Message class 'VoltaOperationCommand_Response'."""

    __slots__ = [
        '_response',
    ]

    _fields_and_field_types = {
        'response': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.response = kwargs.get('response', str())

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
        if self.response != other.response:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def response(self):
        """Message field 'response'."""
        return self._response

    @response.setter
    def response(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'response' field must be of type 'str'"
        self._response = value


class Metaclass_VoltaOperationCommand(type):
    """Metaclass of service 'VoltaOperationCommand'."""

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
                'cybergear_interfaces.srv.VoltaOperationCommand')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__volta_operation_command

            from cybergear_interfaces.srv import _volta_operation_command
            if _volta_operation_command.Metaclass_VoltaOperationCommand_Request._TYPE_SUPPORT is None:
                _volta_operation_command.Metaclass_VoltaOperationCommand_Request.__import_type_support__()
            if _volta_operation_command.Metaclass_VoltaOperationCommand_Response._TYPE_SUPPORT is None:
                _volta_operation_command.Metaclass_VoltaOperationCommand_Response.__import_type_support__()


class VoltaOperationCommand(metaclass=Metaclass_VoltaOperationCommand):
    from cybergear_interfaces.srv._volta_operation_command import VoltaOperationCommand_Request as Request
    from cybergear_interfaces.srv._volta_operation_command import VoltaOperationCommand_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
