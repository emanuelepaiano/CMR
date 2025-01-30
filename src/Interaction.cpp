#ifndef INTERACTION_CPP
#define INTERACTION_CPP

#include "Interaction.hpp"

Interaction::Interaction() {}

Interaction::Interaction(size_t id, std::string description, std::string type, std::string date, size_t customerId) {
    _id = id;
    _description = description;
    setInteractionType(type);
    _date = date;
    _customerId = customerId;
}

Interaction::Interaction(std::string description, std::string type, std::string date, size_t customerId) {
    _description = description;
    setInteractionType(type);
    _date = date;
    _customerId = customerId;
}
    
// setters
void Interaction::setId(size_t value) {
    this->_id = value;
}

void Interaction::setDescription(std::string value) {
    this->_description = value;
}

void Interaction::setInteractionType(InteractionType value) {
    this->_type = value;
}

void Interaction::setInteractionType(std::string value) {
    InteractionType parsed_value = to_interaction_type(value);
    this->_type = parsed_value;
}

void Interaction::setDate(std::string value) {
    this->_date = value;
}

void Interaction::setCustomerId(size_t value) {
    this->_customerId = value;
}

// getters
size_t Interaction::getId() {
    return this->_id;
}

std::string Interaction::getDescription() {
    return this->_description;
}

InteractionType Interaction::getType() {
    return this->_type;
}

std::string Interaction::getTypeString() {
    return to_string(this->_type);
}

std::string Interaction::getDate() {
    return this->_date;
}

size_t Interaction::getCustomerId() {
    return this->_customerId;
}


// java-like tostd::string() replacement
Interaction::operator std::string() {
    std::string str;
    return str.append("Interaction[ id: ")
    .append(std::to_string(this->_id))
    .append(", description: ")
    .append(this->_description)
    .append(", type: ")
    .append(to_string(this->_type))
    .append(", date: ")
    .append(this->_date)
    .append(" ]");   
}

#endif