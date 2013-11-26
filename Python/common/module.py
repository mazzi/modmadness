# -*- coding: utf-8 -*-

import operations
from operationFactory import OperationFactory

class Module(object):
	"""Module class that represents a node in the network"""

	def __init__(self, aName=None, aOperation=None, next=None):
		self.operation = OperationFactory.newOperation(aOperation)
		self.name = aName
		self.next_module = next

		"""The module itself has to have an input and output
			because they can be extended with several operations
			in the future."""
		self.input = None
		self.output = None
		self.dirty = False

	def execute(self):
		self.operation.input = self.input
		self.operation.execute()
		self.output = self.operation.output
		self.dirty = self.operation.dirty
		return True