#ifndef FILE_HANDLER_HPP
#define FILE_HANDLER_HPP

#include "bits/stdc++.h"
#include <stdio.h>

class FileHandler
{
    private:
        std::string _filePath;
    public:
        /**
         * FileHandler
         */
        FileHandler(std::string file);

        /**
         * Default constructor
         */
        FileHandler();
        
        
        /**
         * save rows into file
         * @param rows rows to save
         * @param file file to save
         * @return true if success, false otherwise
         */
        bool writeRows(std::vector<std::string> rows);

        /**
         * save rows into file
         * @param file file to save
         * @return loaded lines false otherwise
         */
        std::vector<std::string> readRows();
};

#endif