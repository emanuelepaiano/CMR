#ifndef CUSTOMER_MANAGER_HPP
#define CUSTOMER_MANAGER_HPP

#include <bits/stdc++.h>
#include "Customer.hpp"
#include "CustomerCsvFile.hpp"
#include "Settings.hpp"

/**
 * Class for Customer managing
 */
class CustomerManager
{
private:
    std::vector<Customer> _customers;
    bool equalsIgnoreCase(std::string value, std::string match_value);
    CustomerCsvFile _customerFile;

public:
    CustomerManager();

    /**
     * load customers
     * */    
    void loadCustomers();
    
    /**
     * save customers
     */
    void saveCustomers();
    
    /**
     * get all customers ID
     */
    vector<size_t> getAllCustomersIds();
    
    /**
     * Add new customer
     * @param customer the new customer
     * @return added customer's ptr
     */
    Customer *addCustomer(Customer &customer);

    /**
     * remove customer by id
     * @param id customer id
     * @return true if customer will be removed successfully, false otherwise
     *
     */
    bool removeCustomer(const size_t &id);

    

    /**
     * search Customer by Name and Surname using AND operator if name and surname are not nulls
     * @param name the first_name
     * @param surname the last name
     * @return Customer pointer if user is present, false otherwise
     *
     */
    vector<size_t> searchCustomersByNameAndSurname(const std::string &name, const std::string &surname);

    /**
     * get customer object pointer by id
     * @param id customer id
     * @return Customer object pointer if present, nullptr otherwise
     */
    Customer *getCustomerById(const size_t &id);

    /**
     * update customer
     * @param customer updated customer to replace
     * @return updated customer ptr if success, nullptr otherwise
     */
    Customer *updateCustomer(Customer &updatedCustomer);

    /**
     * get all customers List
     */
    std::vector<Customer> getAllCustomers();

};

#endif