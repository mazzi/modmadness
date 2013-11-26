/**
 *
 * Lautaro Mazzitelli <lmazzitelli@gmail.com>
**/
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <regex>
#include <string>
#include <algorithm>

#include "./network.h"

/**
 * Parse
 *
 * Given an input argv with argc elements, parses the input to process
 * the specified filename to be stored in commands list of vectors.
 * 
 * @param   int                                     argc        Amount of command line
 *                                                              parameters.
 * @param   const char*                             argv        Command line parameteres.
 * @param   std::list<std::vector<std::string>>*    commands    Pointer to a list to 
 *                                                              be filled with vectors
 *                                                              with the strings found.
 * @return  int     0 if succees, 1 if it fails.
**/
int parse(int argc, const char* argv[], std::list<std::vector<std::string>> *commands);

/**
 * Main
*/
int main(int argc, const char* argv[]) {
    Network *netwrk = new Network();
    std::list<std::vector<std::string>> commands;

    int rtn = parse(argc, argv, &commands);

    if (!rtn) {
        netwrk->populate(&commands);
        std::cout << netwrk->process() << std::endl;
    }

    delete netwrk;

    return rtn;
}

int parse(int argc, const char* argv[], std::list<std::vector<std::string>> *commands) {
    if ( argc != 2 ) {
        std::cout << "1st argument missing (a filename to parse)." << std::endl;
        return 1;
    }

    std::string input_file(argv[1]);

    std::ifstream infile(input_file);

    std::string line;
    while (getline(infile, line)) {
        std::istringstream iss(line);

        std::vector<std::string> tokens;
        copy(std::istream_iterator<std::string>(iss),
            std::istream_iterator<std::string>(),
            std::back_inserter<std::vector<std::string> >(tokens));

        commands->push_back(tokens);
    }
    return 0;
}

