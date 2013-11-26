# -*- coding: utf-8 -*-

import abc
from operation import Operation

class ReverseOperation(Operation):
    """ Reverse Operation definition """

    def __init__(self):
        super(ReverseOperation, self).__init__()

    def execute(self):
    	if self.input != None:
        	self.output = self.input[::-1]
        else:
        	self.output = None
