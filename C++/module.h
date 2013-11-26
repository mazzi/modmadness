/**
 * Module class header.
 *
 * Represents a Module.
 *
 * Lautaro Mazzitelli <lmazzitelli@gmail.com>
**/
#ifndef _MODULE_H_
#define _MODULE_H_

#include <string>
#include <cstdbool>

#include "./operations.h"

class Module {
    public:
        /**
         * Default constructor.
         */
        Module() { operation = NULL; nextModule = NULL; }

        /**
         * Constructor with parameters.
         *
         * @param   const std::string   aName               A name for the module.
         * @param   std::string         aOperationName      An operation name.
         * @param   const Module*       aNextModule         Next module in the network.
         */
        Module(const std::string aName, const std::string aOperationName, const Module *aNextModule);

        /**
         * execute
         *
         * Executes a module.
         *
         * @param   void
         *
         * @return  void
         */
        void execute();

        /**
         * Default destructor (virtual)
         */
        virtual ~Module();

        /*
         * isDirty
         *
         * @return  bool    true if the module is dirty. false otherwise.
         */
        bool isDirty();

        /*
         * getName
         *
         * Gets the name of the module
         *
         * @return  std::string     the name of the Moudule.
         */
        std::string getName() const;


        /*
         * getNextModule
         *
         * Gets the next module in the linked list.
         *
         *
         * @return  Module*     a reference to the next Module.
         */
        Module* getNextModule() const;

        /*
         * setNextModule
         *
         * Setter for nextmodule.
         *
         * @param 
         */ 
        void setNextModule(const Module *aNextModule);

        /*
         * getInput
         *
         * Getter for modules input
         *
         * @return std::string      modules input.
         */
        std::string getInput() const;

        /*
         * setInput
         *
         * Setter for Input.
         *
         * @param   std::string   aInput    A input for the module.
         */ 
        void setInput(const std::string aInput);

        /*
         * getOutput
         *
         * Getter for modules output
         *
         * @return std::string      modules output.
         */
        std::string getOutput() const;

        /*
         * setOutput
         *
         * Setter for Output.
         *
         * @param   std::string   aInput    A input for the module.
         */ 
        void setOutput(const std::string aOutput);

        /*
         * reset
         *
         * Resets the module to its initial state.
         *
         */
        void reset();

    private:
        // Indicates if the module is dirty (strings to process)
        bool dirty;

        // Name of the module
        std::string name;

        // An operation
        Operation *operation;

        // Ponter to the next module.
        Module *nextModule;

        // Input for the module.
        std::string input;

        // Output for the module.
        std::string output;

};

#endif  // _MODULE_H_
