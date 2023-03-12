//
// Created by gyxma on 10.03.2023.
//

#include "processController.h"
processController::processController(std::string port, std::string address,std::vector<std::string> nodes)
    :mNodeId(nodes)
    ,sender(address,port)
    {

}
bool processController::process(){
    char input;
    std::string dataToParse;
    while(true){
        std::cin>>input;
        if(input=='\n'){
            sendData(dataToParse);
            dataToParse.clear();
        }
        else if(input==EOF)
            return false;
        else
            dataToParse.push_back(input);
    }
}
bool processController::sendData(const std::string &value){
    canString dataToSend(value);
    if(!dataToSend.isCorrect())
        return false;
    if(!checkAddress(dataToSend))
        return false;
    if(!sender.sendData(value)){
        saveToFile();
        return false;
    }
}
void processController::saveToFile(){

}
bool processController::checkAddress(canString value){
    if (!value.isCorrect())
        return false;
    for(auto i: mNodeId){
        if (value.getAddress()==i)
            return true;
    }
    return false;
}