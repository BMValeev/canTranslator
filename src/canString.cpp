//
// Created by gyxma on 10.03.2023.
//
//" (1970-01-01 05:36:04.335344)  can0  604   [8]  40 18 10 03 00 00 00 00   '@.......'"
#include "canString.h"
canString::canString(const std::string &data)
    :mBaseline(data) {
    mCorrect=parse();
}

bool canString::parse() {
    std::string processedLine=mBaseline;
    if(findParameter(&processedLine,"date","(",")"))
        return false;
    if(!findParameter(&processedLine,"can"))
        return false;
    if(!findParameter(&processedLine,"node"))
        return false;
    if(!findParameter(&processedLine,"type"))
        return false;
    if(!findParameter(&processedLine,"hex"," ","\'"))
        return false;
    if(!findParameter(&processedLine,"string","\'","\'"))
        return false;
    return true;
}
/*bool canString::checkAddress(std::vector<std::string> address){
    if (!isCorrect())
        return false;
    for(auto i: address){
        if (getAddress()==i)
            return true;
    }
    return false;
}*/
bool canString::parseNodeId(const std::string &value ){
    if(value.size()==8){
        if((value.substr(0,3)!="1E0")
            ||(value.substr(3,1).find_first_not_of("01") != std::string::npos)
            ||(value.substr(4).find_first_not_of("0123456789abcdefABCDEF") != std::string::npos)
            )
            return false;
        mNodeId="0x00";
        mNodeId[2]=value[4];
        mNodeId[3]=value[5];
    }
    if(value.size()==3){
         if(value.find_first_not_of("0123456789abcdefABCDEF", 3) != std::string::npos)
             return false;
        mNodeId="0x00";
        mNodeId=value.substr(1,2);
    }
    return true;
}

bool canString::findParameter(std::string* value,const std::string & name,const std::string &startSymbol,const std::string &endSymbol){
    std::size_t foundParStart,foundParEnd;
    if (startSymbol==" ")
        foundParStart = value->find_first_not_of(startSymbol);
    else
        foundParStart = value->find_first_of(startSymbol);
    if (foundParStart==std::string::npos)
        return false;
    foundParEnd = value->substr(foundParStart).find_first_of(endSymbol);
    if (foundParEnd==std::string::npos)
        return false;
    if (foundParStart==foundParEnd)
        return false;
    parameters[name]=value->substr(foundParStart,foundParEnd-foundParStart);
    std::string temp=value->substr(foundParEnd);
    if (!temp.size())
        return false;
    value->swap(temp);
    return true;
}