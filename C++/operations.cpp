/**
 *
 * Lautaro Mazzitelli <lmazzitelli@gmail.com>
**/
#include <string>

#include "./operations.h"

#define INITDELAY "hello"

/* --------- DelayOperation --------- */

DelayOperation::DelayOperation() {
    buffer.push(INITDELAY);
}

void DelayOperation::execute() {
    if (!buffer.empty()) {
        output = buffer.front();
        buffer.pop();
        dirty = !buffer.empty();
    }
}

void DelayOperation::reset() {
    buffer.push(INITDELAY);   
}

void DelayOperation::setInput(std::string aInput) {
    if (!aInput.empty()) {
        buffer.push(aInput);
    }
}

/* --------- EchoOperation --------- */

void EchoOperation::execute() {
    setOutput(input + input);
}

/* --------- NoopOperation --------- */

void NoopOperation::execute() {
    setOutput(input);
}

/* --------- ReverseOperation --------- */

void ReverseOperation::execute() {
    std::string aOutput = input;
    reverse(aOutput.begin(), aOutput.end());
    setOutput(aOutput);
}
