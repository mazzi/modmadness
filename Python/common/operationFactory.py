# -*- coding: utf-8 -*-

import operations
from types import *

DELAY = 'delay'
ECHO = 'echo'
NOOP = 'noop'
REVERSE = 'reverse'

OPERATIONS = [DELAY,ECHO,NOOP,REVERSE]

class OperationFactory(object):
	"""Factory for Operations"""

	@staticmethod
	def newOperation(operation):
		if type(operation) is not StringType:
			raise TypeError("Operation must be a String.")
		if operation not in OPERATIONS:
			raise TypeError("Operation not supported.")

		if operation == DELAY:
			return operations.DelayOperation()
		elif operation == ECHO:
			return operations.EchoOperation()
		elif operation == NOOP:
			return operations.NoopOperation()
		elif operation == REVERSE:
			return operations.ReverseOperation()
		else:
			return None