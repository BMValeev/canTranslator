//
// Created by gyxma on 10.03.2023.
//

#ifndef CANTRANSLATOR_PROCESSCONTROLLER_H
#define CANTRANSLATOR_PROCESSCONTROLLER_H
#include "string"
#include "vector"

class processController {
public:
    explicit processController(std::string port, std::string address,std::vector<std::string> nodes);
    ~processController() =default;
    bool process();
private:
    std::string mAddress, mPort;
    std::vector<std::string> mNodeId;
};


#endif //CANTRANSLATOR_PROCESSCONTROLLER_H
