/**
 * Network class definition.
 *
 * Represents a Network of modules.
 *
 * Lautaro Mazzitelli <lmazzitelli@gmail.com>
**/
#include <iostream>
#include <exception>
#include <utility>
#include <map>
#include <string>

#include "./network.h"
#include "./module.h"

#define MODULE "module"
#define CONNECT "connect"
#define PROCESS "process"

#define __DEBUG__ false

Network::~Network() {
    std::map<const std::string, Module*>::const_iterator it;
    for ( it = network.begin(); it != network.end(); ++it ) {
        if (it->second != NULL)
            delete (it->second);
    }
}

bool Network::isModuleNameInNetwork(const std::string aName) {
    return ( !(network.find( aName ) == network.end() ) );
}

void Network::insert(const Module *aModule) {
    if ( !isModuleNameInNetwork(aModule->getName())) {
        network.insert(std::pair<std::string, Module*>((std::string)aModule->getName(), const_cast<Module *>(aModule)));
    } else {
        throw std::string("Module repeated : ") + aModule->getName();
    }
}

void Network::connect(const std::string aModule, const std::string anotherModule) {
    if ( !isModuleNameInNetwork(aModule) ) {
        throw std::string("Module doesn't exists : ") + aModule;
    }
    if ( !isModuleNameInNetwork(anotherModule) ) {
        throw std::string("Module doesn't exists : ") + anotherModule;
    }

    (network[aModule])->setNextModule(network[anotherModule]);

    if ( start.size() == 0 ) {
        start = aModule;
    }
}

std::string Network::process() {
    std::string processed;

    if ( !network.empty() && theInput.size() ) {

        std::list<std::string> toProcess;
        while ( theInput.size() ) {
            toProcess = theInput.front();
            theInput.pop_front();

            std::string sample;
            while ( toProcess.size() || dirty ) {
                sample = "";
                if ( toProcess.size() ) {
                    sample = toProcess.front();
                    toProcess.pop_front();
                }

                network[start]->setInput(sample);
                current = start;
                network[current]->execute();
                dirty = network[current]->isDirty();

                while ( network[current]->getNextModule() != NULL ) {
                    Module *nextMod = network[current]->getNextModule();
                    nextMod->setInput(network[current]->getOutput());
                    current = nextMod->getName();
                    network[current]->execute();

                    dirty = network[current]->isDirty();

                    sample = "";
                    if ( toProcess.size() ) {
                        sample = toProcess.front();
                    }
                }
                processed += network[current]->getOutput() + " ";
            }

            processed += "\n";
            
            std::map<const std::string, Module*>::const_iterator it;
            for ( it = network.begin(); it != network.end(); ++it ) {
                 it->second->reset();
            }
        }
    }

    return processed;
}

void Network::populate(std::list<std::vector<std::string>> *commands) {
    std::list<std::vector<std::string>>::iterator itc;
    for (itc = commands->begin(); itc != commands->end(); ++itc) {
        if ( MODULE  == (*itc)[0] ) {
            if (__DEBUG__)
                std::cout << "Module created. " << (*itc)[1] << std::endl;

            Module *aModule;
            try {
                aModule = new Module( (*itc)[1], (*itc)[2], NULL);
                insert(aModule);
            } catch ( std::string error ) {
                if (__DEBUG__)
                    std::cout << error << std::endl;
                delete aModule;
            }
        }
        if ( CONNECT == (*itc)[0] ) {
            if (__DEBUG__) {
                std::cout << "Conection created. " << (*itc)[1]
                     << " " << (*itc)[2] << std::endl;
            }
            try {
                connect( (*itc)[1], (*itc)[2] );
            } catch ( std::string error ) {
                if (__DEBUG__)
                    std::cout << error << std::endl;
            }
        }
        if ( PROCESS == (*itc)[0] ) {
            if (__DEBUG__)
                std::cout << "Processing command." << std::endl;

            std::list<std::string> command;
            for (unsigned int cnt = 1 ; cnt < (*itc).size() ; cnt++) {
                command.push_back((*itc)[cnt]);
            }
            addInput(command);
        }
    }
}