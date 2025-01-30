#ifndef VALIDATOR_CPP
#define VALIDATOR_CPP

#include "Validator.hpp"

Validator::Validator() {

}

bool Validator::isValidInput(std::string input, std::vector<std::string> validInputs)
{
    for (std::string &validInput : validInputs){
        if (input == validInput){
            return true;
        }
    }
    return false;
}

bool Validator::validateValue(const std::string& str, const std::string& regex) {
    std::regex pattern(regex);
    return std::regex_match(str, pattern);
}

#endif

