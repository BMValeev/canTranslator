//
// Created by gyxma on 10.03.2023.
//

#ifndef CANTRANSLATOR_DATALOADER_H
#define CANTRANSLATOR_DATALOADER_H

//#include <mutex>
#include "string"
#include "vector"
#include <fstream>

// класс для записи и чтения из файла, достаточно простой. много проверок не делал.
class dataLoader {
public:
    explicit dataLoader(const std::string &filepath);
    ~dataLoader()=default;
    std::vector<std::string> readFromFile();
    bool writeToFile(const std::string &value);
    bool clearFile();
    bool isCorrect() {  return mFileExists;  }
private:
    //std::mutex mtx;
    bool mFileExists;
    std::string mFilepath;
};


#endif //CANTRANSLATOR_DATALOADER_H
