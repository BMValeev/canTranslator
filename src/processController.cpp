//
// Created by gyxma on 10.03.2023.
//

#include "processController.h"
// конструктор класса, принимает адрес, порт и адреса которые надо проспускать.
// кроме этого создает класс для записи на диск. Но я не стал заморачиваться и опредлил путь файла через define
processController::processController(std::string port, std::string address,std::vector<std::string> nodes)
    : mNodeId(nodes)
    , mSender(address, port)
    , mLoader(FILEPATH)
    {

}
// Основной метод в котором происходит прием данных. Сделал через cin построчный ввод данных,
// то есть обработка происходит в момент когда приходит конец строки, на EOF не тестировал
bool processController::process(){
    char input;
    std::string dataToParse;
    while(true){
        std::cin >>std::noskipws >>input;
        if(input=='\n'){
            //std::cout<<"value"<<std::endl;
            sendData(dataToParse);
            dataToParse.clear();
        }
        else if(input==EOF)
            return false;
        else
            dataToParse.push_back(input);
    }
}
//В случае если данные не отправлены, сделал отладочное сообщение что сохранено сообщенеи на диск.

bool processController::sendData(const std::string &value){
    canString dataToSend(value);
    if(!dataToSend.isCorrect())
        return false;
    if(!checkAddress(dataToSend))
        return false;
    if(!mSender.sendData(value)){
        std::cout<<"not send, write to disk"<<std::endl;
        saveToFile(value);
        return false;
    }
    return true;
}
// Метод для  считывания сохраненных строк из файла
//Очиащет файл после считывания
// Есди файл не существует то не пытаться считывать его
void processController::loadFromFile(){
    if (!mLoader.isCorrect())
        return;
    std::vector<std::string> loadedData= mLoader.readFromFile();
    mLoader.clearFile();
    for (auto i :loadedData){
        std::cout<<i<<std::endl;
        sendData(i);
    }
    return;
}

void processController::saveToFile(const std::string &value){
    mLoader.writeToFile(value);
}
//Процедура проверки адреса на совпадение.

bool processController::checkAddress(canString value){
    if (!value.isCorrect())
        return false;
    for(auto i: mNodeId){
        if (value.getAddress()==i)
            return true;
    }
    return false;
}