# -*- coding: utf-8 -*-

import abc
import Queue
from operation import Operation

class DelayOperation(Operation):
    """ Delay Operation definition """

    def __init__(self):
        self.q = Queue.Queue()
        self.q.put("hello")
        super(DelayOperation, self).__init__()

    @property
    def input(self):
        pass

    @input.setter
    def input(self, value):
        if value != None:
            self.q.put(value)

    def execute(self):
        if self.q.qsize():
            self.output = self.q.get()
            self.dirty = (self.q.qsize() > 0)

            