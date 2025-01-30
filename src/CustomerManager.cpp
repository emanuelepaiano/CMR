
#ifndef CUSTOMER_MANAGER_CPP
#define CUSTOMER_MANAGER_CPP

#include "CustomerManager.hpp"

CustomerManager::CustomerManager()
{
    _customerFile = CustomerCsvFile();
}


void CustomerManager::loadCustomers()
{
    _customers = _customerFile.load();
}

void CustomerManager::saveCustomers()
{
   _customerFile.save(_customers);
}

vector<size_t> CustomerManager::getAllCustomersIds() {
    vector<size_t> customerIds;
    for(Customer &customer: _customers) {
        customerIds.push_back(customer.getId());
    }
    return customerIds;
}


Customer *CustomerManager::addCustomer(Customer &customer)
{
    customer.setId(_customers.size()+1);
    this->_customers.push_back(customer);
    return &_customers.back();
}

bool CustomerManager::removeCustomer(const size_t &id)
{
    for (auto it = _customers.begin(); it != _customers.end(); ++it)
    {
        if (it->getId() == id)
        {
            this->_customers.erase(it);
            return true;
        }
    }
    return false;
}

vector<size_t> CustomerManager::searchCustomersByNameAndSurname(const std::string &name, const std::string &surname)
{
    vector<size_t> foundCustomers;
    for (Customer &customer : this->_customers)
    {
        bool isNameMatching = name.empty() || equalsIgnoreCase(customer.getFirstName(), name);
        bool isSurnameMatching = surname.empty() || equalsIgnoreCase(customer.getLastName(), surname);
        if (isNameMatching && isSurnameMatching)
        {
            foundCustomers.push_back(customer.getId());
        }
    }
    return foundCustomers;
}

Customer *CustomerManager::getCustomerById(const size_t &id)
{
    for (Customer &customer : _customers)
    {
        if (customer.getId() == id)
        {
            return &customer;
        }
    }
    return nullptr;
}

Customer *CustomerManager::updateCustomer(Customer &updatedCustomer)
{
    for (size_t i = 0; i < _customers.size(); i++)
    {
        if (_customers[i].getId() == updatedCustomer.getId())
        {
            _customers[i] = updatedCustomer;
            return &_customers[i];
        }
    }
    return nullptr;
}

std::vector<Customer> CustomerManager::getAllCustomers()
{
    return _customers;
}

bool CustomerManager::equalsIgnoreCase(std::string value, std::string match_value)
{
    std::transform(value.begin(), value.end(), value.begin(), ::tolower);
    std::transform(match_value.begin(), match_value.end(), match_value.begin(), ::tolower);
    return value.find(match_value) != std::string::npos;
}

#endif