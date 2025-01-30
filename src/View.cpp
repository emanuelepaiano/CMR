#ifndef VIEW_CPP
#define VIEW_CPP

#include "Validator.hpp"
#include "View.hpp"
#include "Settings.hpp"
#include <string> 
#include <iostream> 

using namespace std;

View::View()
{
    this->_bannerFileHandler = FileHandler(BANNER_FILE);
}

View::~View()
{
    this->save();
}

void View::addCustomer()
{
    string firstName = inputValue("First name: ", _customerRegex.TYPE); 
    string lastName = inputValue("Last name: ", _customerRegex.LASTNAME); 
    string address = inputValue("Address: ", _customerRegex.ADDRESS); 
    string city = inputValue("City: ", _customerRegex.CITY); 
    string postalCode = inputValue("Postalcode: ", _customerRegex.POSTAL_CODE); 
    string province = inputValue("Province: ", _customerRegex.PROVINCE); 
    string state = inputValue("State: ", _customerRegex.STATE); 
    string fiscalCode = inputValue("Fiscal code: ", _customerRegex.FISCAL_CODE); 
    string phoneNumber = inputValue("Phone number: ", _customerRegex.PHONE_NUMBER); 
    
    Customer customer = Customer(firstName, lastName, address, city, postalCode, province, state, fiscalCode, phoneNumber);
    Customer* newUser = _customerManager.addCustomer(customer);
    
    cout << "Successfully insert: " << (string) *newUser << endl << endl;
}   

void View::editCustomer()
{
    string customerId = inputValue("Customer ID: ", _customerRegex.ID);
    size_t id = atoi(customerId.data());
    Customer* updatingCustomer = _customerManager.getCustomerById(id);
    if (updatingCustomer!=nullptr) {
        
    } else {
        cout << "ERR: Customer with ID " << id << " not found!" <<endl;
    }
    this->_doUpdateCustomer(*updatingCustomer);
}

void View::deleteCustomer()
{
    string customerId = inputValue("Customer ID: ", _customerRegex.ID);
    size_t id = atoi(customerId.data());
    Customer* deletingCustomer = _customerManager.getCustomerById(id);
    if (deletingCustomer!=nullptr) {
        _doDeleteCustomer(id);
    } else {
        cout << "ERR: Customer with ID " << id << " not found!" <<endl;
    }
}

void View::_doDeleteCustomer(size_t id) {
    if (_customerManager.removeCustomer(id)) {
        cout << "SUCCESS: Removed customer with ID " << id <<endl;
    } else {
        cout << "ERR: Error while deleting customer with ID " << id <<endl;
    }
}

void View::_doUpdateCustomer(Customer & customer) {
    string firstName = updateValue("First name", customer.getFirstName(), _customerRegex.TYPE); 
    string lastName = updateValue("Last name", customer.getLastName(),  _customerRegex.LASTNAME); 
    string address = updateValue("Address", customer.getAddress(),  _customerRegex.ADDRESS); 
    string city = updateValue("City", customer.getCity(),  _customerRegex.CITY); 
    string postalCode = updateValue("Postal code", customer.getPostalCode(), _customerRegex.POSTAL_CODE); 
    string province = updateValue("Province", customer.getProvince(),  _customerRegex.PROVINCE); 
    string state = updateValue("State", customer.getState(),  _customerRegex.STATE); 
    string fiscalCode = updateValue("Fiscal code", customer.getFiscalCode(),  _customerRegex.FISCAL_CODE); 
    string phoneNumber = updateValue("Phone number", customer.getPhoneNumber(),  _customerRegex.PHONE_NUMBER); 
    customer.setFirstName(firstName);
    customer.setLastName(lastName);
    customer.setAddress(address);
    customer.setCity(city);
    customer.setPostalCode(postalCode);
    customer.setProvince(province);
    customer.setState(state);
    customer.setFiscalCode(fiscalCode);
    customer.setPhoneNumber(phoneNumber);
    _customerManager.updateCustomer(customer);
    cout << "Updated " << (std::string) customer << endl;
}

void View::searchCustomers() {
    string firstName = inputValue("First name: ", _customerRegex.TYPE); 
    string lastName = inputValue("Last name: ", _customerRegex.LASTNAME); 
    vector<size_t> customersFound = _customerManager.searchCustomersByNameAndSurname(firstName, lastName);
    if (customersFound.size() > 0) {
        cout << "*******************************" << endl;
    } else {
        cout << "Empty Customers list!" << endl;
    }
    
    for (size_t id: customersFound) {
        Customer *customer = _customerManager.getCustomerById(id);
        cout << endl;
        cout << "ID: " << customer->getId() << endl;
        cout << "First name: " << customer->getFirstName() << endl;
        cout << "Last name: " << customer->getLastName() << endl;
        cout << "Phone number: " << customer->getPhoneNumber() << endl;
        cout << "Fiscal code : " << customer->getFiscalCode() << endl;
        cout << "Address: " << customer->getAddress() << endl;
        cout << "City: " << customer->getCity() << endl;
        cout << "Postal code: " << customer->getPostalCode() << endl;
        cout << "Province: " << customer->getProvince() << endl;
        cout << "State: " << customer->getState() << endl << endl;
        cout << "*******************************" << endl;
    }
}

string View::updateValue(string fieldName, string value, string valueRegex) {
    string promptText = "Insert new value for " + fieldName + " or press ENTER to skip: [" + value + "]";
    string newInput = inputValue(promptText, valueRegex, true);
    if (!newInput.empty()) {
        return newInput;
    } else {
        return value;
    }
}

string View::updateValue(string fieldName, string value, vector<string> inputValues) {
    string promptText = "Insert new value for " + fieldName + " or press ENTER to skip: [" + value + "]";
    string newInput = inputValue(promptText, inputValues, true);
    if (!newInput.empty()) {
        return newInput;
    } else {
        return value;
    }
}

void View::displayAllCustomers()
{
    if (_customerManager.getAllCustomers().size() > 0) {
        cout << "*******************************" << endl;
    } else {
        cout << "Empty Customers list!" << endl;
    }
    
    for (Customer& customer: _customerManager.getAllCustomers()) {
        cout << endl;
        cout << "ID: " << customer.getId() << endl;
        cout << "First name: " << customer.getFirstName() << endl;
        cout << "Last name: " << customer.getLastName() << endl;
        cout << "Phone number: " << customer.getPhoneNumber() << endl;
        cout << "Fiscal code : " << customer.getFiscalCode() << endl;
        cout << "Address: " << customer.getAddress() << endl;
        cout << "City: " << customer.getCity() << endl;
        cout << "Postal code: " << customer.getPostalCode() << endl;
        cout << "Province: " << customer.getProvince() << endl;
        cout << "State: " << customer.getState() << endl << endl;
        cout << "*******************************" << endl;
    }
}

void View::addInteraction()
{
    vector<size_t> customerIds = _customerManager.getAllCustomersIds();
    if (!customerIds.empty()) {
        string type = inputValueSet("Type (contract, meeting, other): ", {"contract", "meeting", "other"}); 
        string description = inputValue("Description: ", _interactionRegex.DESCRIPTION); 
        string date = inputValue("Data (gg/mm/aaaa): ", _interactionRegex.DATE); 
        string customerId = inputValueSet("Customer ID: ", toIntVect(customerIds)); 
        
        Interaction interaction = Interaction(0, description, type, date, atoi(customerId.data()));
        Interaction* newInteraction = _interactionManager.addInteraction(interaction);
        
        cout << "Successfully insert: " << (string) *newInteraction << endl << endl;
    } else {
        cout << "No customers found." << endl;
    }
}

vector<string> View::toIntVect(vector<size_t>& ids) {
    vector<string> result;
    for (size_t& id: ids) {
        stringstream ss;
        ss << id;
        result.push_back(ss.str());
    }
    return result;
}

void View::editInteraction()
{
    string interactionId = inputValue("Interaction ID: ", _interactionRegex.ID); 
    Interaction *interaction = _interactionManager.getInteraction(atoi(interactionId.data()));
 
    if (interaction!=nullptr) {
        string type = updateValue("Interaction type", interaction->getTypeString(), {"contract", "meeting", "other"});
        string description = updateValue("Description", interaction->getDescription(), _interactionRegex.DESCRIPTION); 
        string date = updateValue("Data", interaction->getDate(), _interactionRegex.DATE); 
        size_t customerId = interaction->getCustomerId();
        Interaction updatedInteraction = Interaction(interaction->getId(), description, type, date, customerId);
        updatedInteraction = *(_interactionManager.updateInteraction(updatedInteraction));
        
        cout << "Successfully updated: " << (string) updatedInteraction << endl << endl;
    } else {
        cout << "No Interaction found." << endl;
    }
}

void View::deleteInteraction()
{
    string interactionId = inputValue("Interaction ID: ", _interactionRegex.ID);
    size_t id = atoi(interactionId.data());
    Interaction* deletingInteraction = _interactionManager.getInteraction(id);
    if (deletingInteraction!=nullptr) {
        _doDeleteInteraction(id);
    } else {
        cout << "ERR: Interaction with ID " << id << " not found!" <<endl;
    }
}

void View::_doDeleteInteraction(size_t id) {
    if (_interactionManager.removeInteraction(id)) {
        cout << "SUCCESS: Removed interaction with ID " << id <<endl;
    } else {
        cout << "ERR: Error while deleting interaction with ID " << id <<endl;
    }
}


void View::displayCustomerInteractions()
{
    string customerId = inputValue("Customer ID: ", _customerRegex.ID);
    size_t id = atoi(customerId.data());
    Customer* currentCustomerPtr = _customerManager.getCustomerById(id);
    if (currentCustomerPtr!=nullptr) {
        vector<Interaction*> usersInteractions = _interactionManager.getInteractionsByCustomer(id);
        doDisplayCustomerInteractions(usersInteractions, currentCustomerPtr);
    } else {
        cout << "ERR: Customer with ID " << id << " not found!" <<endl;
    }
}

void View::doDisplayCustomerInteractions(vector<Interaction*> customerInteractions, Customer* currentCustomerPtr) {
    
    cout << "Interactions for customer ID " << currentCustomerPtr->getId() << " (" << currentCustomerPtr->getFirstName();
    cout << " " << currentCustomerPtr->getLastName() << ")" << endl <<endl; 

    if (customerInteractions.size() > 0) {
        cout << "*******************************" << endl;
    } else {
        cout << "No interaction found." << endl;
    }
    
    for (Interaction *interaction: customerInteractions) {
        cout << "ID: " << interaction->getId() << endl;
        cout << "Date: " << interaction->getDate() << endl;
        cout << "Type: " << interaction-> getTypeString() << endl;
        cout << "Description: " << interaction->getDescription() << endl;
        cout << "*******************************" << endl;
    }
}

void View::save()
{
    cout << "[SAVE] Saving customers..";
    this->_customerManager.saveCustomers();
    cout << " DONE" << endl;

    cout << "[SAVE] Saving interactions..";
    this->_interactionManager.saveInteractions();
    cout << " DONE" << endl;
}

void View::load()
{
    cout << "[LOAD] Loading customers..";
    this->_customerManager.loadCustomers();
    cout << "DONE" << endl;
    
    cout << "[LOAD] Loading interactions..";
    this->_interactionManager.loadInteractions();
    cout << "DONE" << endl;
}

void View::showCustomerMenu()
{
    cout << endl;
    cout << "Manage Customer " << endl;
    cout << "1) Add a new customer " << endl;
    cout << "2) Edit existing customer " << endl;
    cout << "3) Delete existing customer " << endl;
    cout << "4) Search customers " << endl;
    cout << "5) Show all customers " << endl;
    cout << "6) Back previous menu " << endl;
    cout << endl;
}

void View::showInteractionMenu()
{
    cout << endl;
    cout << "Manage Interaction " << endl;
    cout << "1) Add a new interaction " << endl;
    cout << "2) Edit existing interaction " << endl;
    cout << "3) Delete existing interaction " << endl;
    cout << "4) Show all interactions " << endl;
    cout << "5) Back previous menu " << endl;
    cout << endl;
}

void View::showMainMenu()
{
    cout << endl;
    cout << "Main Menu" << endl;
    cout << "1) Manage customers " << endl;
    cout << "2) Manage interactions " << endl;
    cout << "3) Show customer's interactions " << endl;
    cout << "4) Show all interactions " << endl;
    cout << "5) Exit (and save data)" << endl;
    cout << endl;
}

void View::showBanner()
{
    vector<string> bannerRows = _bannerFileHandler.readRows();
    for (string &bannerRow : bannerRows)
    {
        cout << bannerRow << endl;
    }
}

string View::inputChoice(vector<string> validInputs) {
    return inputValueSet("> ", validInputs);
}

string View::inputValueSet(string prompt, vector<string> validInputs)
{
    bool isValidInput;
    string input;
    do
    {
        cout << prompt;
        cin >> input;
        isValidInput = _validator.isValidInput(input, validInputs);
        if (!isValidInput)
        {
            cout << "Error: " << input << " is not a valid value!" << endl;
        }
    } while (!isValidInput);
    return input;
}

string View::inputValue(string promptText, string validRegex) {
    return inputValue(promptText, validRegex, false);
}

string View::inputValue(string promptText, string validRegex, bool isUpdate)
{
    bool isValidValue;
    string value;
    do
    {
        cout << promptText;
        getline(cin >> ws, value);
        
        if (value.empty()) {
            isValidValue = isUpdate;
        } else {
            isValidValue = _validator.validateValue(value, validRegex);
        }

        if (!isValidValue)
        {
            cout << "Error: " << value << " is not a valid value!" << endl;
        }
    } while (!isValidValue);
    return value;
}

string View::inputValue(string promptText, vector<string> inputValidValues, bool isUpdate)
{
    bool isValidValue;
    string value;
    do
    {
        cout << promptText;
        getline(cin >> ws, value);
        
        cout << "DEBUG: value='" << value << "'" << endl;

        if (value.empty()) {
            isValidValue = isUpdate;
        } else {
            isValidValue = _validator.isValidInput(value, inputValidValues);
        }

        if (!isValidValue)
        {
            cout << "Error: " << value << " is not a valid value!" << endl;
        }
    } while (!isValidValue);
    return value;
}

void View::run()
{
    showBanner();
    this->load();
    while (true) {
        runMainMenu();
    }    
}

void View::runMainMenu()
{
    showMainMenu();
    string userChoice = inputChoice({"1", "2", "3", "4", "5"});
    if (userChoice == "1") {
        runCustomerMenu();
    } else if (userChoice == "2"){
       runInteractionMenu();
    } else if (userChoice == "3"){
       displayCustomerInteractions();
    } else if (userChoice == "4"){
       displayAllInteractions(); 
    } else if (userChoice == "5") {
        this->save();
        exit(EXIT_SUCCESS);
    }
}

void View::runCustomerMenu()
{
    showCustomerMenu();
    string userChoice = inputChoice({"1", "2", "3", "4", "5", "6"});
    if (userChoice == "1") {
        addCustomer();
    } else if (userChoice == "2"){
        editCustomer();
    } else if (userChoice == "3"){
        deleteCustomer();
    } else if (userChoice == "4"){
        searchCustomers();
    } else if (userChoice == "5"){
        displayAllCustomers();
    } 
}

void View::runInteractionMenu()
{
    showInteractionMenu();
    string userChoice = inputChoice({"1", "2", "3", "4"});
    if (userChoice == "1") {
       addInteraction();
    } else if (userChoice == "2"){
      editInteraction();
    } else if (userChoice == "3"){
       deleteInteraction();
    } 
}

void View::displayAllInteractions() {
    vector<Interaction> interactions = _interactionManager.getAllInteractions();
    if (interactions.size() > 0) {
        cout << "*******************************" << endl;
    } else {
        cout << "No interaction found." << endl;
    }
    for (Interaction& interaction: interactions) {
        Customer* customerPtr = _customerManager.getCustomerById(interaction.getId());
        cout << "ID: " << interaction.getId() << endl;
        cout << "Date: " << interaction.getDate() << endl;
        cout << "Type: " << interaction.getTypeString() << endl;
        cout << "Description: " << interaction.getDescription() << endl;
        cout << "Customer: " << customerPtr->getFirstName() << "  " << customerPtr->getLastName();
        cout << " (Customer ID: " << customerPtr->getId() << ")" << endl;
        cout << "*******************************" << endl;
    }
}

#endif
