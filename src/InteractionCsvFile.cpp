#ifndef CUSTOMER_CSV_FILE_CPP
#define CUSTOMER_CSV_FILE_CPP

#include "InteractionCsvFile.hpp"
#include <sstream>
#include <string>
#include "Settings.hpp"

/**
 * return CSV Interaction header
 */
std::string InteractionCsvFile::getCsvHeader()
{
    return "id,description,type,date,customerId";
}

/**
 * return Interaction data in csv row format
 */
std::string InteractionCsvFile::toCsvRow(Interaction &element)
{
    std::string result;
    return result.append(std::to_string(element.getId()))
        .append(",")
        .append(element.getDescription())
        .append(",")
        .append(insura::to_string(element.getType()))
        .append(",")
        .append(element.getDate())
        .append(",")
        .append(std::to_string(element.getCustomerId()));
}

/**
 * parsing element from a single CSV ROW
 * @param parsed row from file
 */
Interaction InteractionCsvFile::fromCsvRow(std::string row)
{
    Interaction element;
    std::stringstream ss(row);
    std::string token;

    getline(ss, token, ',');
    element.setId(std::stoi(token));

    std::string _description;
    std::string _type;
    std::string _date;
    std::string _customerId;

    getline(ss, _description, ',');
    getline(ss, _type, ',');
    getline(ss, _date, ',');
    getline(ss, _customerId, ',');

    element.setDescription(_description);
    element.setInteractionType(_type);
    element.setDate(_date);
    element.setCustomerId(stoi(_customerId));

    return element;
}

#endif