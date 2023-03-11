//
// Created by gyxma on 10.03.2023.
//

#ifndef CANTRANSLATOR_ARGPARSER_H
#define CANTRANSLATOR_ARGPARSER_H
#include "string"
#include "vector"
// Класс осуществляет обработку входящих параметров для приложения. Проверяет на разрешенность значений и их корректность
// В случае если нет аргументов или есть запрос справки, предоставляет ее
// имеет методы получения обработанных параметров.
// Если получены некорректные данные будет использовать значения по умолчанию
//Проверка на полноценность данных проходит nodeID.
// Если получен хотя бы 1 nodeID то считается что данные полностью сформированы
#define MINPORT "1000"
#define MAXPORT "100000"
#define ADDRESS "127.0.0.1"
#define PORT "5555"
class argParser {
public:

    explicit argParser(int argc, char *argv[]);
    ~argParser()=default;

    std::string getPort() { return mPort;}
    std::string getAddress() { return mAddress;}
    std::vector<std::string> getNodes() { return mNodeId;}
    bool isHelp() { return  mIsHelp; }
    bool isFull() { return  mIsFull; }
private:
    bool isCorrectNodeId(std::string const& value);
    bool checkPort(std::string port);
    bool checkAddress(std::string address);
    void parse(int argc, char *argv[]);
    void parseOption(int state, std::string value);
    const std::string mHelp="__________________________________________________________________\n"
                      "Usage og the script: ./script -a 0xaa 0xbb -p xxxx -ip yyy.yyy.yyy.yyy\n"
                      "-a is the option for the address. Can must be in 0xFF format\n"
                      "-port is the option for the port. Valid is from " MINPORT " to " MAXPORT ". Default  value is "  PORT " \n"
                      "-ip is option for ip address. Valid format is yyy.yyy.yyy.yyy .Default  value is "  ADDRESS " \n"
                      "-h is option for help. Usage without options will also show help\n"
                      "________________________________________________________________\n";
    std::string mAddress, mPort;
    bool mIsHelp,mIsFull;
    std::vector<std::string> mNodeId;
};


#endif //CANTRANSLATOR_ARGPARSER_H
