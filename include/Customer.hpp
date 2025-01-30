#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <bits/stdc++.h>

using namespace std;

/**
 * Class for client entity
 */
class Customer
{
private:
    size_t _id;
    string _firstName;
    string _lastName;
    string _address;
    string _city;
    string _postalCode;
    string _province;
    string _state;
    string _fiscalCode;
    string _phoneNumber;

public:
    Customer();

    Customer(string firstName, string lastName, string address, string city,
             string postalCode, string province, string state, string fiscalCode, string phoneNumber);

    // setters
    void setId(size_t value);
    void setFirstName(string value);
    void setLastName(string value);
    void setAddress(string value);
    void setCity(string value);
    void setPostalCode(string value);
    void setProvince(string value);
    void setFiscalCode(string value);
    void setPhoneNumber(string value);
    void setState(string value);

    // getters
    size_t getId();
    string getFirstName();
    string getLastName();
    string getAddress();
    string getCity();
    string getPostalCode();
    string getProvince();
    string getFiscalCode();
    string getPhoneNumber();
    string getState();

    // java-like toString() replacement
    operator std::string();
};

#endif