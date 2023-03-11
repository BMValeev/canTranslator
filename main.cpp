#include <iostream>
#include "argParser.h"
int main(int argc, char *argv[]) {
    /*std::cout << "Have " << argc << " arguments:" << std::endl;
    for (int i = 0; i < argc; ++i) {
        std::cout << argv[i] << std::endl;
    }
    std::cout << "Hello, World!" << std::endl;*/
    argParser arguments=argParser( argc, argv);
    if(arguments.isHelp())
        return 0;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
