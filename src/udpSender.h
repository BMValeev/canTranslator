//
// Created by gyxma on 10.03.2023.
//

#ifndef CANTRANSLATOR_UDPSENDER_H
#define CANTRANSLATOR_UDPSENDER_H
#include "string"
//Этот класс осуществляет отправку данных через udp строк.
// Класс принимает на вход порт и адрес, проверяет их на корректность
// никаких действий со строкой не производит.
#define ADDRESS "127.0.0.1"
#define PORT "5555"
class udpSender {

public:
    explicit udpSender(std::string address=ADDRESS,std::string port=PORT);
    ~udpSender()=default;
    void setPort(std::string address);  //устанавливает значение порта. принимает строку. не проверяет на корректность.
    void setAddress(std::string port);  //устанавливает значение IP адреса. принимает строку. не проверяет на корректность
    bool sendData(std::string data); //отправить данные. В случае ошибки выдает false

protected:
    std::string getAddress()    { return mAddress; } //возвращает значение IP адреса в формате строки без проверок.
    std::string getPort()   { return mPort; }       //возвращает значение порта в формате строки без проверок.

private:
    std::string mAddress,mPort;

};


#endif //CANTRANSLATOR_UDPSENDER_H
