//
// Created by gyxma on 10.03.2023.
//
//" (1970-01-01 05:36:04.335344)  can0  604   [8]  40 18 10 03 00 00 00 00   '@.......'"
#include "canString.h"
#include "iostream"
canString::canString(const std::string &data)
    :mBaseline(data) {
    mCorrect=parse();
}
// Парсит по списку параметров  зная их очередность
bool canString::parse() {
    std::string processedLine=mBaseline;
    if(!findParameter(&processedLine,"date1"," "," "))
        return false;
    if(!findParameter(&processedLine,"date2"," "," "))
        return false;
    if(!findParameter(&processedLine,"can"))
        return false;
    if(!findParameter(&processedLine,"node"))
        return false;
    if(!findParameter(&processedLine,"type"))
        return false;
    if(!findParameter(&processedLine,"hex"," ","'"))
        return false;
    if(!findParameter(&processedLine,"string","'","'"))
        return false;
    return true;
}


//Тут как будто перемудрил с проверками и сложностью кода, но не стал править на более корректную форму.
//Так как тут не требуется потом использовать эти данные то пока оставлю в такой форме.
// по хорошему надо переписать чуть лучше и убрать отладочный вывод printOut
//Здесь проверяется если ищется не пробел, то ищет до этого символа, если ищется пробел, то ищет до первого не пробела
// Последняя строка парсится отдельно, то она просто берется до самого конца.
bool canString::findParameter(std::string* value,const std::string & name,const std::string &startSymbol,const std::string &endSymbol){
    std::size_t foundParStart,foundParEnd;
    std::string temp;
    foundParStart = value->find_first_of(startSymbol);
    if (startSymbol==" ")
        foundParStart = value->find_first_not_of(startSymbol);
    if (printOut(name,foundParStart==std::string::npos))
        return false;
    foundParEnd = value->substr(foundParStart).find_first_of(endSymbol);
    if (printOut(name,foundParEnd==std::string::npos))
        return false;
    if (startSymbol=="'"){
        parameters[name]=value->substr(foundParStart);
        temp=value->substr(foundParStart);
    }
    else{
        parameters[name]=value->substr(foundParStart,foundParEnd);
        temp=value->substr(foundParEnd+foundParStart);
    }
    if (printOut(name,temp.empty()))
        return false;
    value->swap(temp);
    return true;
}
bool canString::printOut(const std::string &node, bool result){
    if(result)
        std::cout<<"Par is incorrect, incorrect parameter is: "<<node <<std::endl;
 //  else
//      std::cout<<"Par is correct, correct parameter is: "<<node <<std::endl;
    return result;
}
// Проверяет на корректность строку, парсит оба случая адресации. Сохраняет их в отдельной переменной
bool canString::parseNodeId(const std::string &value ){
    if(value.size()==8){
        if((value.substr(0,3)!="1E0")
           ||(value.substr(3,1).find_first_not_of("01") != std::string::npos)
           ||(value.substr(4).find_first_not_of("0123456789abcdefABCDEF") != std::string::npos)
                ){
            printOut("node",false);
            return false;
        }
        mNodeId="0x00";
        mNodeId[2]=value[4];
        mNodeId[3]=value[5];
    }
    if(value.size()==3){
        if(value.find_first_not_of("0123456789abcdefABCDEF", 3) != std::string::npos){
            printOut("node",false);
            return false;
        }
        mNodeId="0x00";
        mNodeId=value.substr(1,2);
    }
    printOut("node",true);
    return true;
}