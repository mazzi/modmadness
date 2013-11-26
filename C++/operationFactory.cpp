/**
 * Operation Factory class definition.
 *
 * Lautaro Mazzitelli <lmazzitelli@gmail.com>
**/
#include <string>

#include "./operationFactory.h"

#define  DELAY      "delay"
#define  ECHO       "echo"
#define  NOOP       "noop"
#define  REVERSE    "reverse"

Operation *OperationFactory::CreateOperation(const std::string aOperationName) {
    Operation *op = NULL;

    if ( DELAY == aOperationName ) {
        op = new DelayOperation();
    }
    if ( ECHO == aOperationName ) {
        op = new EchoOperation();
    }
    if ( NOOP == aOperationName ) {
        op = new NoopOperation();
    }
    if ( REVERSE == aOperationName ) {
        op = new ReverseOperation();
    }

    return op;
}
