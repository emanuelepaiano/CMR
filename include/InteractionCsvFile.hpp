#ifndef INTERACTION_CSV_FILE_HPP
#define INTERACTION_CSV_FILE_HPP

#include <bits/stdc++.h>
#include <stdio.h>
#include "CsvFile.hpp"
#include "Interaction.hpp"
#include "Settings.hpp"

/**
 * Customer class CsvFile used to convert / Parsing CSV
 */
class InteractionCsvFile: public CsvFile<Interaction>
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
        std::string toCsvRow(Interaction &element);

        /**
         * parsing element from a single CSV ROW
         * @param parsed row from file
         */
        Interaction fromCsvRow(std::string row);

    public:
        /**
         * Create CsvHandler 
         * @param csvFilePath csv file path
         */
        InteractionCsvFile(): CsvFile(CSV_INTERACTIONS_FILE) {}

        /**
         * Create csv interaction file handler to another location
         */
        InteractionCsvFile(std::string csvFilePath): CsvFile(csvFilePath) {}

};

#endif