#ifndef VALIDATOR_HPP
#define VALIDATOR_HPP

#include <bits/stdc++.h>

/**
 * Class used to instantiate an input validator
 */
class Validator {

    public:
        /**
         * default constructor
         */
        Validator();

        /**
         * return true if input contain a value in validInputs, false otherwise
         * @param input value to validate
         * @param validInputs an array containing a possible values
         */
        bool isValidInput(std::string input, std::vector<std::string> validInputs);

        /**
         * return true if input contain a value in validInputs, false otherwise
         * @param str value to validate
         * @param pattern a regex string for validation (check CustomerRegex.hpp and InteractionRegex.hpp)
         */
        bool validateValue(const std::string &str, const std::string &pattern);
};

#endif