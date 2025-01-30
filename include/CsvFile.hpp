#ifndef CSV_FILE_HPP
#define CSV_FILE_HPP
#include <bits/stdc++.h>
#include <stdio.h>
#include "FileHandler.hpp"

/**
 * Abstract class CsvFormatter used to convert / Parsing CSV
 */
template <class T>
class CsvFile
{
    private:
        FileHandler _csvFile;

        /**
         * return CSV Customer header
         */
        virtual std::string getCsvHeader() = 0;

        /**
         * return customer data in csv row format
         */
        virtual std::string toCsvRow(T &element) = 0;

        /**
         * parsing element from a single CSV ROW
         * @param parsed row from file
         */
        virtual T fromCsvRow(std::string row) = 0;

    public:
        /**
         * Create CsvFormatter with custom separator
         * @param csvFilePath csv file path
         */
        CsvFile(std::string csvFilePath)
        {   
            FileHandler f(csvFilePath);
            _csvFile = f;
        }

        /**
         * save elements into csv file
         */
        bool save(std::vector<T> elements)
        {
            std::vector<std::string> rows;
            rows.push_back(getCsvHeader());
            for (T &element : elements)
            {
                rows.push_back(toCsvRow(element));
            }
            _csvFile.writeRows(rows);
            return true;
        }

        /**
         * load elements from csv file
         */
        std::vector<T> load()
        {
            std::vector<std::string> rows = _csvFile.readRows();
            std::vector<T> parsedElements;
            for (size_t rowIndex=1; rowIndex < rows.size(); rowIndex++)
            {
                parsedElements.push_back(fromCsvRow(rows[rowIndex]));
            }
            return parsedElements;
        }
};

#endif