//
// Created by gyxma on 10.03.2023.
//

#ifndef CANTRANSLATOR_UDPSENDER_H
#define CANTRANSLATOR_UDPSENDER_H
#include "string"
//Этот класс осуществляет отправку данных через udp строк.
// Класс принимает на вход порт и адрес, не проверяет их на корректность
// никаких действий со строкой не производит.
// По хорошему нужно дублировать проверки для переиспользования кода в случае если он будет использован в дальнейшем.
//Но на текущий момент я разместил проверяющую логику в обработку входных параметров и контролирующий класс
class udpSender {

public:
    explicit udpSender(std::string address,std::string port);
    ~udpSender()=default;
    //устанавливает значение порта. принимает строку. не проверяет на корректность.
    void setPort(std::string port) { mPort=port; }
    //устанавливает значение IP адреса. принимает строку. не проверяет на корректность
    void setAddress(std::string address) { mAddress=address;}
    //отправить данные. В случае ошибки выдает false
    bool sendData(std::string data);
    //возвращает значение IP адреса в формате строки без проверок.
    std::string getAddress()    { return mAddress; }
    //возвращает значение порта в формате строки без проверок.
    std::string getPort()   { return mPort; }

private:
    std::string mAddress,mPort;

};


#endif //CANTRANSLATOR_UDPSENDER_H
