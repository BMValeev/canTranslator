//
// Created by gyxma on 10.03.2023.
//

#include "argParser.h"
#include "map"
#include "iostream"
argParser::argParser(int argc, char *argv[])
    :mIsHelp(false)
    ,mAddress("")
    ,mPort(""){
    parse( argc, argv);
    if (isHelp())
        std::cout<<mHelp<<std::endl;
}
//проходит по всем аргументам и в случае если совпадает с опциями все следующие аргументы
// до совпадения со следующей опцией будут считаться параметрами. Проверки упростил. Если порт будет указан
// несколько раз или будет -p 11 12 13, учтется только последнее значение. Решил не усложнять процедуры.
void argParser::parse(int argc, char *argv[]) {
    std::vector<std::string> parameters;
    std::map<int,std::string> options;
    int currentState(0);
    bool checkOption;
    options={{3,"-port"},{1,"-a"},{2,"-ip"}};
    for (int i = 1; i < argc; ++i) {
        parameters.push_back( argv[i]);
    }
    if (parameters.empty())
        mIsHelp=true;
    for (auto i: parameters){
        if (i=="-h") {
            mIsHelp=true;
            break;
        }
        for(auto opt:options){
            if (i==opt.second){
                currentState=opt.first;
                checkOption=true;
                break;
            }
        }
        if(checkOption){
            checkOption=false;
            continue;
        }
        parseParameter(currentState,i);
    }
}


void argParser::parseParameter(int state,std::string value){
    switch (state){
        case 1: if(isCorrectNodeId(value)){
                mNodeId.push_back(value);
                std::cout<<"added nodeID: " <<value<<std::endl;
            }
            break;
        case 2: {
            mAddress=value;
            std::cout<<"added address: " <<value<<std::endl;
            break;
        }
        case 3: if(checkPort(value)){
                mPort=value;
                std::cout<<"added port: " <<value<<std::endl;
                break;
        }
        default: {
            std::cout<<"unparsed parameter: " <<value<<std::endl;
        }
    }
}


bool argParser::isCorrectNodeId(std::string const& value){ //пока не сделано
    return value.compare(0, 2, "0x") == 0
           && value.size() == 4
           && value.find_first_not_of("0123456789abcdefABCDEF", 2) == std::string::npos;
}

bool argParser::checkPort(std::string port){
    int val=std::stoi(port);
    return ((val>10000) && (val <100000));
}

bool argParser::checkAddress(std::string address){
#ifndef WIN32
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, address.c_str(), &(sa.sin_addr));
    return result != 0;
#endif
    return true;
}