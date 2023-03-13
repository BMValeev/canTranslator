//
// Created by gyxma on 10.03.2023.
//
//" (1970-01-01 05:36:04.335344)  can0  604   [8]  40 18 10 03 00 00 00 00   '@.......'"
#include "canString.h"
#include "iostream"
// Конструктор класса, парсит данные и переводит адрес в читаемый формат.
// В случае если данные не удалось обработать отмечает данные как некорректные
canString::canString(const std::string &data)
    :mBaseline(data) {
    mCorrect=parse();
    if(isCorrect())
        mCorrect=parseNodeId(parameters["node"]);
}

// Парсит по списку параметров  зная их очередность
// Не стал корректно парсить дату, как как в этом нет необходимости и это бы усложнило процедуру
//Так как тут не требуется потом использовать эти данные то пока оставлю в такой форме.
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
//Здесь проверяется если ищется не пробел, то ищет до этого символа, если ищется пробел, то ищет до первого не пробела
// Последняя строка парсится отдельно,  она просто берется до самого конца.
bool canString::findParameter(std::string* value,const std::string & name,const std::string &startSymbol,const std::string &endSymbol){
    std::size_t foundParStart,foundParEnd;
    std::string temp;
    foundParStart = value->find_first_of(startSymbol);
    // если первый символ пробел, то ищет до первого не пробела
    if (startSymbol==" ")
        foundParStart = value->find_first_not_of(startSymbol);
    if (printOut(name,foundParStart==std::string::npos))
        return false;
    foundParEnd = value->substr(foundParStart).find_first_of(endSymbol);
    if (printOut(name,foundParEnd==std::string::npos))
        return false;
    //В случае если последний символ это \' то читает данные до конца строки
    if (startSymbol=="'"){
        parameters[name]=value->substr(foundParStart);
        temp=value->substr(foundParStart);
    }
    else{
        parameters[name]=value->substr(foundParStart,foundParEnd);
        temp=value->substr(foundParEnd+foundParStart);
    }
    //В случае если строка оказалась пустой то это тоже считается ошибкой
    if (printOut(name,temp.empty()))
        return false;
    value->swap(temp);
    return true;
}
// Отладочный вывод информации для понимания была ли ошибка
bool canString::printOut(const std::string &node, bool result){
    if(result)
        std::cout<<"Par is incorrect, incorrect parameter is: "<<node <<std::endl;
    return result;
}


// Проверяет на корректность строку, парсит оба случая адресации. Сохраняет их в отдельной переменной
bool canString::parseNodeId(const std::string &value ){
    // случай с расширенной адресацией
    if(value.size()==8){
        if((value.substr(0,3)!="1E0")
           ||(value.substr(3,1).find_first_not_of("01") != std::string::npos)
           ||(value.substr(4).find_first_not_of("0123456789abcdefABCDEF") != std::string::npos)
                )
            return printOut("node",false);
        mNodeId="0x";
        mNodeId+=value[4];
        mNodeId+=value[5];
    }
    // случай с базовой адресацией
    else if(value.size()==3){
        if(value.find_first_not_of("0123456789abcdefABCDEF", 1) != std::string::npos)
            return printOut("node",false);
        mNodeId="0x";
        mNodeId+=value.substr(1,2);
    }
    // Если пришло непонятно что
    else
        return printOut("node",false);

    return true;
}