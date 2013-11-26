# -*- coding: utf-8 -*-

import abc
from operation import Operation

class NoopOperation(Operation):
    """ Noop Operation definition """

    def __init__(self):
        super(NoopOperation, self).__init__()

    def execute(self):
    	if self.input != None:
        	self.output = self.input
        else:
            self.output = None