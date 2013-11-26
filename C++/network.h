/**
 * Network class header.
 *
 * Represents a Network of modules.
 *
 * Lautaro Mazzitelli <lmazzitelli@gmail.com>
**/
#ifndef _NETWORK_H_
#define _NETWORK_H_

#include <map>
#include <list>
#include <string>

#include "./module.h"

class Network {
    public:
        /**
         * Netowrk
         *
         * Default constructor.
         */
        Network() { dirty = false; }

        /**
         * populate
         *
         * Populates the network with the commands to be executed.
         *
         * @param   std::list<std::vector<std::string>> *commands
                    List of vectors with the commands to introduce in
                    the network.
         *
         * @return  void
         *
         */
        void populate(std::list<std::vector<std::string>> *commands);

        /**
         * isEmpty
         *
         * Checks if the network is empty (without modules)
         *
         * @param   void
         *
         * @return  bool    true if the network is empty. false otherwise.
         */
        bool isEmpty() { return !network.size(); }

        /**
         * addInput
         *
         * Adds a string to be processed into the network.
         *
         * @param   const std::string   aInput      A string to be processed.
         *
         * @return  void
         */
        void addInput(const std::list<std::string> aInput) { theInput.push_back(aInput); }

        /**
         * insert
         *
         * Inserts a Module into the Network.
         * 
         * @param   const Module*   aModule     A module to insert in the network.
         *
         * @return  void
         */
        void insert(const Module *aModule);

        /**
         * connect
         *
         * Connects two modules between them.
         *
         * @param   const std::string   aModuleName         Name of a module to connect from.
         * @param   const std::string   anotherModuleName   Name of a module to connect to.
         *
         * @return  void
         */
        void connect(const std::string aModuleName, const std::string anotherModuleName);

        /**
         * process
         *
         * Process the input and returns the result.
         *
         * @param   void
         *
         * @return  std::string     the result of processing the input strings.
         */
        std::string process();

        /**
         * ~Netowrk
         *
         * Default destructor (virtual).
         */
        virtual ~Network();

    private:
        // A map to store name of the module (key) and module (value)
        std::map<const std::string, Module*> network;

        // Start of the linked map
        std::string start;

        // Current element in the map
        std::string current;

        // List with the input of process words to process
        class std::list<std::list<std::string>> theInput;

        // Stores if the network is dirty (delays have some thing to process)
        bool dirty;

        /**
         * isModuleNameInNetwork
         *
         * Checks if name aName is already used in the network.
         *
         * @param   const std::string   aName       Name to check.
         *
         * @return  bool    true if aName is the network. false if not.
        */
        bool isModuleNameInNetwork(const std::string aName);
};

#endif  // _NETWORK_H_
