//
// Created by gyxma on 10.03.2023.
//

#include "canString.h"
canString::canString(std::string data) {
    mBaseline=data;
    mCorrect=parse();
}

bool canString::parse() {
    std::size_t found;
}
bool canString::checkAddress(std::vector<std::string> address){
    if (!isCorrect())
        return false;
    for(auto i: address){
        if (getAddress()==i)
            return true;
    }
    return false;
}