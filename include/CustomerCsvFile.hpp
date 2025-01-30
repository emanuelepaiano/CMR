#ifndef CUSTOMER_CSV_FILE_HPP
#define CUSTOMER_CSV_FILE_HPP

#include <bits/stdc++.h>
#include <stdio.h>
#include "CsvFile.hpp"
#include "Customer.hpp"
#include "FileHandler.hpp"

/**
 * Customer class CsvFile used to convert / Parsing CSV
 */
class CustomerCsvFile: public CsvFile<Customer>
{
    private:
        FileHandler _csvFile;

        /**
         * return CSV Customer header
         */
        std::string getCsvHeader();

        /**
         * return customer data in csv row format
         */
        std::string toCsvRow(Customer &element);

        /**
         * parsing element from a single CSV ROW
         * @param parsed row from file
         */
        Customer fromCsvRow(std::string row);

    public:
        /**
         * Create CsvFormatter with custom separator
         * @param csvFilePath csv file path
         */
        CustomerCsvFile(std::string csvFilePath);

        /**
         * Default constructor
         */
        CustomerCsvFile();

};

#endif