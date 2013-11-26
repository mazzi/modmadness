/**
 * Operation Factory class header.
 *
 * Lautaro Mazzitelli <lmazzitelli@gmail.com>
**/
#ifndef _OPERATIONFACTORY_H_
#define _OPERATIONFACTORY_H_

#include <string>

#include "./operations.h"

class OperationFactory {
    public:
        /**
         * CreateOperation
         *
         * Static method to create operations (Factory pattern)
         *
         * @param   std::string     aOperationName      A name of the operation to create.
         *
         * @return  Operation pointer.
         */
        static Operation *CreateOperation(const std::string aOperationName);
};

#endif  // _OPERATIONFACTORY_H_
