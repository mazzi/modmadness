# -*- coding: utf-8 -*-

import abc

class Operation(object):
    """Abstract class for defining operations."""
    __metaclass__ = abc.ABCMeta

    def __init__(self):
        self.input  = None
        self.output = None
        self.dirty = False

    @abc.abstractmethod
    def execute(self):
        """Executes the operation using input and output properties."""
        raise NotImplementedError

