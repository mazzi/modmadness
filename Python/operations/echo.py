# -*- coding: utf-8 -*-

import abc
from operation import Operation

class EchoOperation(Operation):
    """ Echo Operation definition """

    def __init__(self):
        super(EchoOperation, self).__init__()

    def execute(self):
    	if self.input != None:
        	self.output = self.input + self.input
        else:
            self.output = None
