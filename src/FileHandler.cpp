#ifndef FILEHANDLER_CPP
#define FILEHANDLER_CPP

#include "FileHandler.hpp"
#include <fstream>

FileHandler::FileHandler(std::string file) {
    this->_filePath = file;
}

FileHandler::FileHandler() {
    this->_filePath = "test.csv";
}

bool FileHandler::writeRows(std::vector<std::string> rows)
{
    std::ofstream outFile(_filePath);
    for (std::string &row : rows)
    {
        outFile << row << std::endl;
    }
    outFile.close();
    return true;
}

std::vector<std::string> FileHandler::readRows()
{
    std::vector<std::string> rows;
    std::string row;
    std::ifstream inFile(_filePath);
    if (inFile.is_open())
    {
        while (getline(inFile, row))
        {
            rows.push_back(row);
        }
        inFile.close();
    }
    return rows;
}

#endif