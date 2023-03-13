#include <iostream>
#include "argParser.h"
#include "canString.h"
#include "processController.h"
int main(int argc, char *argv[]) {
    argParser arguments=argParser( argc, argv);
    if(arguments.isHelp() || !arguments.isFull())
        return 0;
    //canString test=canString(" (1970-01-01 05:36:04.885558)  can0  1E0007F6   [8]  15 FF FF FF FF FF FF FF   '........'");
    //test.printAll();
    processController controller =processController(arguments.getPort(),arguments.getAddress(),arguments.getNodes());
    controller.loadFromFile();
    controller.process();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}



/*std::cout << "Have " << argc << " arguments:" << std::endl;
for (int i = 0; i < argc; ++i) {
    std::cout << argv[i] << std::endl;
}
std::cout << "Hello, World!" << std::endl;*/