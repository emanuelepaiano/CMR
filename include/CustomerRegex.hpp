#ifndef CUSTOMER_REGEX_HPP
#define CUSTOMER_REGEX_HPP

#include <bits/stdc++.h>

/**
 * Regex for Customer input validation
 */
struct CustomerRegex
{
    public:
        const std::string ID = "^[0-9]+$";

        const std::string TYPE = "^[a-zA-Z]+$";

        const std::string LASTNAME = "^[a-zA-Z]+$";

        const std::string ADDRESS = "^[a-zA-Z0-9\\s.,'-]+$";

        const std::string CITY = "^[a-zA-Z]+$";

        const std::string POSTAL_CODE = "^[A-Za-z0-9\\s\\-]{3,10}$";

        const std::string PROVINCE = "^[a-zA-Z]+$";

        const std::string STATE = "^[a-zA-Z]+$";

        const std::string FISCAL_CODE = "^[A-Z]{6}\\d{2}[A-Z]\\d{2}[A-Z]\\d{3}[A-Z]$";

        const std::string PHONE_NUMBER = "^[0-9]+$";
};

#endif