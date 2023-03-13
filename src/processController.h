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
#include "dataLoader.h"

#define FILEPATH "SOMEFILEPATH"

class processController {
public:
    explicit processController(std::string port, std::string address,std::vector<std::string> nodes);
    ~processController() =default;
    void loadFromFile();
    void saveToFile(const std::string &value);
    bool process();
    bool sendData(const std::string &value);
private:
    udpSender mSender;
    dataLoader mLoader;
    bool checkAddress(canString value);
    std::vector<std::string> mNodeId;
};


#endif //CANTRANSLATOR_PROCESSCONTROLLER_H
