//
// Created by gyxma on 10.03.2023.
//

#ifndef CANTRANSLATOR_CANSTRING_H
#define CANTRANSLATOR_CANSTRING_H


#include "string"
#include "vector"
class canString {
public:
    explicit canString(std::string data);
    ~canString()=default;
    std::string getString()     {   return mBaseline;   }
    std::string getAddress()    {   return mNodeId;     } //возвращает значение  адреса в формате строки без проверок.
    bool isCorrect()            {   return mCorrect;    }
protected:
    bool parse();
    bool checkAddress(std::vector<std::string> address);

private:
    std::string mBaseline;
    std::string mDate,mCan,mNodeId;
    bool mCorrect;
};

#endif //CANTRANSLATOR_CANSTRING_H
