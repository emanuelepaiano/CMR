#ifndef VIEW_HPP
#define VIEW_HPP

#include "Customer.hpp"
#include "Interaction.hpp"
#include "CustomerCsvFile.hpp"
#include "InteractionCsvFile.hpp"
#include "Settings.hpp"
#include "CustomerRegex.hpp"
#include "InteractionRegex.hpp"
#include "Validator.hpp"
#include "CustomerManager.hpp"
#include "InteractionManager.hpp"

class View {
    private:
        FileHandler _bannerFileHandler; // Handles the banner file
        CustomerRegex _customerRegex; // Regex for validating customer data
        InteractionRegex _interactionRegex; // Regex for validating interactions
        Validator _validator; // Class for validating user input
        CustomerManager _customerManager; // Manages customers
        InteractionManager _interactionManager; // Manages interactions
        
        /**
         * Adds a new customer
         */
        void addCustomer();
        
        /**
         * Edits an existing customer
         */
        void editCustomer();
        
        /**
         * Deletes an existing customer
         */
        void deleteCustomer();

        /**
         * Internal method to delete a customer by ID
         */
        void _doDeleteCustomer(size_t id);

        /**
         * Internal method to update a customer
         */
        void _doUpdateCustomer(Customer &customer);

        /**
         * Searches for customers based on defined criteria
         */
        void searchCustomers();

        /**
         * Displays all existing customers
         */
        void displayAllCustomers();

        /**
         * Adds a new interaction
         */
        void addInteraction();

        /**
         * Converts a vector of size_t to a vector of strings
         */
        vector<string> toIntVect(vector<size_t> &ids);

        /**
         * Edits an existing interaction
         */
        void editInteraction();

        /**
         * Deletes an existing interaction
         */
        void deleteInteraction();

        /**
         * Internal method to delete an interaction by ID
         */
        void _doDeleteInteraction(size_t id);
        
        /**
         * Displays interactions for a specific customer
         */
        void displayCustomerInteractions();

        /**
         * Internal method to display interactions of a customer
         * @param usersInteractions customer's interactions
         * @param currentCustomerPtr Customer's object pointer
         */
        void doDisplayCustomerInteractions(vector<Interaction *> usersInteractions, Customer *currentCustomerPtr);

        /**
         * Displays all existing interactions
         */
        void displayAllInteractions();

        /**
         * Saves data to the filesystem
         */
        void save();

        /**
         * Loads data from the filesystem
         */
        void load();

        /**
         * Displays the startup banner
         */
        void showBanner();

        /**
         * Checks if input is contained in a set of valid inputs
         * @param input input string
         * @param validInputs admitted input values
         * @return true if input is valid, false otherwise
         */
        bool isValidInput(string input, vector<string> validInputs);
        
        /**
         * Prompts the user for input from a set of valid values
         * @param validInputs admitted input values
         */
        string inputChoice(vector<string> validInputs);

        /**
         * Prompts the user for a value with a specific prompt and valid value set, if fails, it try to ask new input
         * @param prompt prompt to display
         * @param validInputs admitted input values
         * @return read value from keyboard
         */
        string inputValueSet(string prompt, vector<string> validInputs);

        /**
         * Prompts the user for a value validated by a regular expression, if fails, it try to ask new input
         * @param promptText prompt to display
         * @param validRegex regex for input validation
         * @return read value from keyboard
         */
        string inputValue(string promptText, string validRegex);

        /**
         * Prompts the user for a value with regex validation and update option, if fails, it try to ask new input
         * @param promptText prompt to display
         * @param validRegex regex for input validation
         * @param isUpdate set true if it is used into update operation (accept empty input), false otherwise
         * @return read value from keyboard
         */
        string inputValue(string promptText, string validRegex, bool isUpdate);

        /**
         * Prompts the user for a value with a set of valid values and update option
         * @param promptText prompt to display
         * @param inputValidValues input valid values set
         * @param isUpdate set true if it is used into update operation (accept empty input), false otherwise
         * @return read value from keyboard
         */
        string inputValue(string promptText, vector<string> inputValidValues, bool isUpdate);

        /**
         * Updates a value if it matches a regex
         * @param fieldName field name (i.e. Name)
         * @param value input previous value (i.e. customer.getName())
         * @param valueRegex validation regex
         * @return read value from keyboard
         */
        string updateValue(string fieldName, string value, string valueRegex);

        /**
         * Updates a value if it matches a set of valid values
         * @param fieldName field name (i.e. Name)
         * @param value input previous value (i.e. customer.getName())
         * @param inputValues input valid values set
         * @return read value from keyboard
         */
        string updateValue(string fieldName, string value, vector<string> inputValues);

        /**
         * Displays the customer menu
         */
        void showCustomerMenu();

        /**
         * Displays the interaction menu
         */
        void showInteractionMenu();

        /**
         * Displays the main menu
         */
        void showMainMenu();

        /**
         * Runs the main menu
         */
        void runMainMenu();

        /**
         * Runs the customer menu
         */
        void runCustomerMenu();

        /**
         * Runs the interaction menu
         */
        void runInteractionMenu();

    public:
        /**
         * Constructor
         */
        View();
        
        /**
         * Destructor
         */
        ~View();
        
        /**
         * Starts the interface
         */
        void run();
};

#endif
