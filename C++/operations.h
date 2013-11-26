/**
 * Operatioms class header.
 *
 * Includes all the possible operations. 
 *
 * Represents a Module.
 *
 * Lautaro Mazzitelli <lmazzitelli@gmail.com>
**/
#ifndef _OPERATIONS_H_
#define _OPERATIONS_H_

#include <string>
#include <algorithm>
#include <queue>

class Operation {
    public:
        // Input for the operation
        std::string input;
        // Output for the operation
        std::string output;
        // Dirty flag (stuff to process)
        bool dirty;

        /** Default constructor **/
        Operation() { dirty = false; }

        /** Default destructor **/
        virtual ~Operation() {}

        /**
         * execute
         *
         * Executes the operation.
         * Pure virtual method to be implemented by child classes.
         */
        virtual void execute() = 0;

        /**
         * setInput
         *
         * Setter for the input
         *
         * @param   const std::string   aInput      A input to set up.
         */
        virtual void setInput(const std::string aInput) { input = aInput;}

        /**
         * getOutput
         *
         * Getter for the output
         *
         * @return   const std::string
         */
        virtual std::string  getOutput() { return output; }

        /**
         * setOutput
         *
         * Setter for the imput
         * 
         * @param   const std::string   aOutput      A input to set up.
         */
        virtual void setOutput(const std::string aOutput) { output = aOutput;}

        /*
         * reset
         *
         * Resets the operation to its initial state.
         *
         */
        virtual void reset() { };
};

class DelayOperation : public Operation {
    private:
        class std::queue<std::string> buffer;
    public:
        /** Default constructor **/
        DelayOperation();

        /**
         * execute
         *
         * Executes the operation.
         */
        void execute();

        /**
         * setInput
         *
         * Setter for the input
         *
         * @param   const std::string   aInput      A input to set up.
         */
        void setInput(const std::string aInput);

        /*
         * reset
         *
         * Resets the module to its initial state.
         *
         */
        void reset();
};

class EchoOperation : public Operation {
    public:
        /**
         * execute
         *
         * Executes the operation.
         */
        void execute();
};


class NoopOperation : public Operation {
    public:
        /**
         * execute
         *
         * Executes the operation.
         */
        void execute();
};

class ReverseOperation : public Operation {
    public:
        /**
         * execute
         *
         * Executes the operation.
         */
        void execute();
};

#endif  // _OPERATIONS_H_
