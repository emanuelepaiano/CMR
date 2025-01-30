#ifndef INTERACTION_REGEX_HPP
#define INTERACTION_REGEX_HPP

#include <bits/stdc++.h>

/**
 * Interaction regex for input valitation
 */
struct InteractionRegex
{
    public:

        const std::string ID = "^[0-9]+$";

        const std::string DESCRIPTION = "^[a-zA-Z0-9\\s]+$";

        const std::string DATE = "^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/([0-9]{4})$";
};

#endif