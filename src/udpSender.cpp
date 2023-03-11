//
// Created by gyxma on 10.03.2023.
//

#include "udpSender.h"
#include <sys/types.h>
#include <iostream>
#include <vector>
//#include <arpa/inet.h>
//#include <netinet/in.h>
//#include <sys/socket.h>


bool udpSender::sendData(std::string data)
{
#ifndef WIN32
    int sock;
    struct sockaddr_in addr;

    addr.sin_family = AF_INET;
    addr.sin_port = htons(getPort().c_str());
    addr.sin_addr.s_addr = inet_addr(getAddress().c_str());

    sock = socket(AF_INET, SOCK_STREAM, IPPROTO_UDP);
    if ((sock < 0)
        || (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
                )
            return false;
    send(sock, data.c_str(), data.length(), 0);
    close(sock);
#endif
    return true;
}
udpSender::udpSender(std::string address,std::string port){
    setAddress(checkAddress(address)?address:ADDRESS);
    setPort(checkPort(port)?port:PORT);
}


void udpSender::setPort(std::string port){
    mPort=port;
    return;
}

void udpSender::setAddress(std::string address){
    mAddress=address;
    return;
}

