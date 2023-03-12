//
// Created by gyxma on 10.03.2023.
//

#ifndef CANTRANSLATOR_CANSTRING_H
#define CANTRANSLATOR_CANSTRING_H

//" (1970-01-01 05:36:04.335344)  can0  604   [8]  40 18 10 03 00 00 00 00   '@.......'"
#include "string"
#include "map"
#include "vector"
#include "iostream"
class canString {
public:
    explicit canString(const std::string &data);
    ~canString()=default;
    std::string getString()     {   return mBaseline;   }
    std::string getAddress()    {   return mNodeId;     } //возвращает значение  адреса в формате строки без проверок.
    bool isCorrect()            {   return mCorrect;    }
    void printAll()   { for(auto i: parameters) std::cout <<i.first <<"____" << i.second <<std::endl; };
protected:
    //Распарсить параметры в строке по типу данных и провести базовую проверку
    bool parse();


private:
    //сохранить адрес получателя в формате в котором будет происходить проверка
    bool parseNodeId(const std::string &value );
    //Парсинг строки по конкретному параметру и фильтрация по символам, для упрощения чтения кода
    bool findParameter(std::string* value,const std::string & name,const std::string &startSymbol=" ",const std::string &endSymbol=" ");
    // вывод распарсен ли параметр или нет
    bool printOut(const std::string &node, const bool result);
    std::string mBaseline;
    std::string mNodeId;
    bool mCorrect;
    std::map<std::string,std::string> parameters;
};

#endif //CANTRANSLATOR_CANSTRING_H
