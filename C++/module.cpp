/**
 *
 * Lautaro Mazzitelli <lmazzitelli@gmail.com>
**/
#include <string>

#include "./module.h"
#include "./operationFactory.h"

Module::Module(const std::string aName, const std::string aOperationName, const Module *aNextModule) {
    name = aName;
    operation = OperationFactory::CreateOperation(aOperationName);
    nextModule = const_cast<Module *>(aNextModule);
    dirty = false;
}

Module::~Module() {
    if (operation) {
        delete operation;
    }
}

void Module::execute() {
    operation->setInput(input);
    operation->execute();
    output = operation->getOutput();
    dirty  = operation->dirty;
}

bool Module::isDirty() {
    return dirty;
}

std::string Module::getName() const {
    return name;
}

Module* Module::getNextModule() const {
    return nextModule;
}

void Module::setNextModule(const Module *aNextModule) {
    nextModule = const_cast<Module *>(aNextModule);
}

std::string Module::getOutput() const {
    return output;
}

std::string Module::getInput() const {
    return input;
}

void Module::setInput(const std::string aInput) {
    input = aInput;
}

void Module::setOutput(const std::string aOutput) {
    output = aOutput;
}

void Module::reset() {
    operation->reset();
}