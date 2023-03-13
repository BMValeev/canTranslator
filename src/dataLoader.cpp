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
    //std::lock_guard<std::mutex> guard(mtx);
    std::ofstream mFile;
    mFile.open("test.txt", std::ofstream::out | std::ofstream::trunc);
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
    mFile.open(mFilepath,std::fstream::out);
    mFile << value;
    mFile.close();
    return true;
}

/*
 *     return {
        " (1970-01-01 05:36:04.885558)  can0  1E0007F6   [8]  15 FF FF FF FF FF FF FF   '........'"
        ," (1970-01-01 05:36:04.206865)  can0  704   [1]  7F                        '.'"
        ," (1970-01-01 05:36:04.215653)  can0  701   [1]  7F                        '.'"
        ," (1970-01-01 05:36:04.216128)  can0  707   [1]  7F                        '.'"
    };
 */