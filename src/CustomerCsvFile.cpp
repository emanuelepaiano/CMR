#ifndef CUSTOMER_CSV_FILE_CPP
#define CUSTOMER_CSV_FILE_CPP

#include "CustomerCsvFile.hpp"
#include <sstream>
#include <string>
#include "Settings.hpp"

CustomerCsvFile::CustomerCsvFile(): CsvFile(CSV_CUSTOMERS_FILE) {
}

CustomerCsvFile::CustomerCsvFile(std::string csvFilePath): CsvFile(csvFilePath) {
}

/**
 * return CSV Customer header
 */
std::string CustomerCsvFile::getCsvHeader()
{
    return "id,firstName,lastName,address,city,postalCode,province,state,fiscalCode,phoneNumber";
}

/**
 * return customer data in csv row format
 */
std::string CustomerCsvFile::toCsvRow(Customer &element)
{
    std::string result;
    return result.append(to_string(element.getId()))
        .append(",")
        .append(element.getFirstName())
        .append(",")
        .append(element.getLastName())
        .append(",")
        .append(element.getCity())
        .append(",")
        .append(element.getPostalCode())
        .append(",")
        .append(element.getProvince())
        .append(",")
        .append(element.getState())
        .append(",")
        .append(element.getFiscalCode())
        .append(",")
        .append(element.getPhoneNumber());
}

/**
 * parsing element from a single CSV ROW
 * @param parsed row from file
 */
Customer CustomerCsvFile::fromCsvRow(std::string row)
{
    Customer element;
    stringstream ss(row);
    string token;

    // Estraiamo e assegnamo i valori alle variabili
    getline(ss, token, ',');
    element.setId(stoi(token));

    string _firstName;
    string _lastName;
    string _address;
    string _city;
    string _postalCode;
    string _province;
    string _state;
    string _fiscalCode;
    string _phoneNumber;

    getline(ss, _firstName, ',');
    getline(ss, _lastName, ',');
    getline(ss, _address, ',');
    getline(ss, _city, ',');
    getline(ss, _postalCode, ',');
    getline(ss, _province, ',');
    getline(ss, _state, ',');
    getline(ss, _fiscalCode, ',');
    getline(ss, _phoneNumber, ',');

    element.setFirstName(_firstName);
    element.setLastName(_lastName);
    element.setAddress(_address);
    element.setCity(_city);
    element.setPostalCode(_postalCode);
    element.setProvince(_province);
    element.setState(_state);
    element.setFiscalCode(_fiscalCode);
    element.setPhoneNumber(_phoneNumber);

    return element;
}

#endif