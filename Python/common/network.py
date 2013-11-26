# -*- coding: utf-8 -*-

import module

class Network(object):

    def __init__(self):
        self.network = {}
        self.start = None
        self.current = None
        
        self.input = []
        self.dirty = False

    def isEmpty(self):
        return len(self.network) == 0

    def insert(self, aModule):
        if aModule != None:
            if aModule.name in self.network.keys():
                raise ValueError("Module name duplicated ({0})".format(aModule.name))
            self.network[aModule.name] = aModule

    def connect(self, aModuleName, anotherModuleName):
        if aModuleName not in self.network.keys():
            raise ValueError("Module name {0} doesn't exists.".format(aModuleName.name))
        if anotherModuleName not in self.network.keys():
            raise ValueError("Module name {0} doesn't exists.".format(anotherModuleName.name))

        self.network[aModuleName].next_module = self.network[anotherModuleName]

        if self.start == None:
            self.start = self.network[aModuleName]

    def addInput(self,aString):
        self.input.append(aString)

    def process(self):
        self.input.reverse()
        if len(self.network) and len(self.input): 
            sample = self.input.pop()
            while sample or self.dirty:
                self.start.input = sample
                self.current = self.start
                self.current.execute()
                self.dirty = self.current.dirty

                while self.current.next_module != None:
                    self.current.next_module.input = self.current.output
                    self.current = self.current.next_module
                    self.current.execute()
                    if self.current.dirty:
                        self.dirty = True 
                if len(self.input):
                    sample = self.input.pop()
                else:
                    sample = None
                yield self.current.output