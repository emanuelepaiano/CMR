#ifndef INTERACTION_HPP
#define INTERACTION_HPP

#include <bits/stdc++.h>
#include "InteractionType.hpp"

using namespace insura;

/**
 * Class for interaction entity
 */
class Interaction {
    private:
        size_t _id;
        std::string _description;
        InteractionType _type;
        std::string _date;
        size_t _customerId;
    
    public:
        Interaction();
        Interaction(size_t id, std::string description, std::string value, std::string date, size_t customerId);

        Interaction(std::string description, std::string type, std::string date, size_t customerId);

        // setters
        void setId(size_t value);
        void setDescription(std::string value);
        void setInteractionType(InteractionType value);
        void setInteractionType(std::string value);
        void setDate(std::string value);
        void setCustomerId(size_t value);

        // getters
        size_t getId();
        std::string getDescription();
        InteractionType getType();
        std::string getTypeString();
        std::string getDate();
        size_t getCustomerId();


        // java-like toString() replacement
        operator std::string();   

};

#endif