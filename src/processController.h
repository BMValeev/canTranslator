//
// Created by gyxma on 10.03.2023.
//

#ifndef CANTRANSLATOR_PROCESSCONTROLLER_H
#define CANTRANSLATOR_PROCESSCONTROLLER_H
#include "string"
#include "vector"
#include "iostream"
#include "canString.h"
#include "udpSender.h"

class processController {
public:
    explicit processController(std::string port, std::string address,std::vector<std::string> nodes);
    ~processController() =default;
    void parseSaved();
    void saveToFile();
    bool process();
    bool sendData(const std::string &value);
private:
    udpSender sender;
    bool checkAddress(canString value);
    std::vector<std::string> mNodeId;
};


#endif //CANTRANSLATOR_PROCESSCONTROLLER_H
