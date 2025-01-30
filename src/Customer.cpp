#ifndef CUSTOMER_CPP
#define CUSTOMER_CPP

#include "Customer.hpp"

// constructors
Customer::Customer() {}

Customer::Customer(std::string first_name, std::string last_name, std::string address, std::string city, 
std::string postal_code, std::string province, std::string state, std::string fiscal_code, std::string phone_number) {
    setFirstName(first_name);
    setLastName(last_name);
    setAddress(address);
    setCity(city);
    setPostalCode(postal_code);
    setProvince(province);
    setState(state);
    setFiscalCode(fiscal_code);
    setPhoneNumber(phone_number);    
}


// setters

void Customer::setId(size_t value) {
    this->_id = value;
}

void Customer::setFirstName(std::string value) {
    this->_firstName = value;
}

void Customer::setLastName(std::string value) {
    this->_lastName = value;
}

void Customer::setAddress(std::string value) {
    this->_address = value;
}

void Customer::setCity(std::string value) {
    this->_city = value;
}

void Customer::setPostalCode(std::string value) {
    this->_postalCode = value;
}

void Customer::setProvince(std::string value) {
    this->_province = value;
}

void Customer::setState(std::string value) {
    this->_state = value;
}

void Customer::setFiscalCode(std::string value) {
    this->_fiscalCode = value;
}

void Customer::setPhoneNumber(std::string value) {
    this->_phoneNumber = value;
}

// getters

size_t Customer::getId() {
    return this->_id;
}

std::string Customer::getFirstName() {
    return this->_firstName;
}

std::string Customer::getLastName() {
    return this->_lastName;
}

std::string Customer::getAddress() {
    return this->_address;
}

std::string Customer::getCity() {
    return this->_city;
}

std::string Customer::getPostalCode() {
    return this->_postalCode;
}

std::string Customer::getProvince() {
    return this->_province;
}

std::string Customer::getState() {
    return this->_state;
}

std::string Customer::getFiscalCode() {
    return this->_fiscalCode;
}

std::string Customer::getPhoneNumber() {
    return this->_phoneNumber;
}


// java-like toString() replacement
Customer::operator std::string() {
    string str;
    return str.append("Client[ id: ")
    .append(to_string(this->_id))
    .append(", first_name: ")
    .append(this->_firstName)
    .append(", last_name: ")
    .append(this->_lastName)
    .append(", address: ")
    .append(this->_address)
    .append(", city: ")
    .append(this->_city)
    .append(", postal_code: ")
    .append(this->_postalCode)
    .append(", province: ")
    .append(this->_province)
    .append(", state: ")
    .append(this->_state)
    .append(", fiscal_code: ")
    .append(this->_fiscalCode)
    .append(", phone_number: ")
    .append(this->_phoneNumber)
    .append(" ]");   
}

#endif