# -*- coding: utf-8 -*-

import sys
import re

from common import network, module

MODULE = 'module'
CONNECT = 'connect'
PROCESS = 'process'
COMMANDS = [MODULE,CONNECT,PROCESS]

def parse(file):
    commands = []
    f = open(file)
    for line in f:
        command = re.findall(r'(\bconnect\b|\bmodule\b) ([a-z0-9]*) ([a-z0-9]*)', line)
        if not len(command):
            command = re.findall(r'(\bprocess\b) ([a-z ]*)', line)
        commands.append(command)
    f.close()
    return commands

def create(commands):
    netwrk = network.Network()
    for command in commands:
        if command:
            command = command[0]    
            if command[0] not in COMMANDS:
                raise Exception("Invalid command {0}".format(command[0]))
            if MODULE == command[0]:
                netwrk.insert(module.Module(command[1], command[2]))
            if CONNECT == command[0]:
                netwrk.connect(command[1], command[2])
            if PROCESS == command[0]:
                for word in command[1].split():
                    netwrk.addInput(word)

    return netwrk

def main(argv):
    commands = parse(argv[0])
    netwrk = create(commands)
    for word in netwrk.process():
        print word,
    #print netwrk.dirty
    
if __name__ == '__main__':
    main(sys.argv[1:])