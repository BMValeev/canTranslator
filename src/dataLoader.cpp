//
// Created by gyxma on 10.03.2023.
//

#include "dataLoader.h"

dataLoader::dataLoader(const std::string &filepath)
    :mFilepath(filepath)
    ,mFileExists(false){
    std::ifstream mFile;
    mFile.open(mFilepath);
    if (mFile.is_open()) {
        mFileExists=true;
        mFile.close();
    };
}

bool dataLoader::clearFile(){
   // std::lock_guard<std::mutex> guard(mtx);
    std::ofstream mFile;
    mFile.open(mFilepath, std::ofstream::out | std::ofstream::trunc);
    mFile.close();
    return true;
}

std::vector<std::string> dataLoader::readFromFile(){
    //std::lock_guard<std::mutex> guard(mtx);
    std::ifstream mFile;
    std::string line;
    std::vector<std::string> dataToSend;
    if (mFileExists)
        mFile.open(mFilepath);
    while(getline(mFile, line))
        dataToSend.push_back(line);
    return dataToSend;

}
bool dataLoader::writeToFile(const std::string &value){
    //std::lock_guard<std::mutex> guard(mtx);
    std::fstream mFile;
    mFile.open(mFilepath,std::fstream::out| std::ios_base::app);
    mFile <<std::endl << value;
    mFile.close();
    return true;
}
