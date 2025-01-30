
#ifndef INTERACTION_MANAGER_CPP
#define INTERACTION_MANAGER_CPP

#include "InteractionManager.hpp"
#include "InteractionCsvFile.hpp"
#include "Settings.hpp"

InteractionManager::InteractionManager() {
     _interactionFile = InteractionCsvFile(CSV_INTERACTIONS_FILE);
}

void InteractionManager::loadInteractions()
{
    _interactions = _interactionFile.load();
}

void InteractionManager::saveInteractions()
{
   _interactionFile.save(_interactions);
}

Interaction *InteractionManager::addInteraction(Interaction &interaction)
{
    interaction.setId(_interactions.size() + 1);
    _interactions.push_back(interaction);
    return &_interactions.back();
}

Interaction *InteractionManager::getInteraction(const size_t interactionId) {
    Interaction *interactionPtr;
    for (Interaction &interaction : _interactions)
    {
        if (interaction.getCustomerId() == interactionId)
        {
            return &interaction;
        }
    }
    return nullptr;
}

std::vector<Interaction> InteractionManager::getAllInteractions() {
    return _interactions;
}

Interaction *InteractionManager::updateInteraction(Interaction &updatedInteraction)
{
    for (size_t i = 0; i < _interactions.size(); i++)
    {
        if (_interactions[i].getId() == updatedInteraction.getId())
        {
            _interactions[i] = updatedInteraction;
            return &_interactions[i];
        }
    }
    return nullptr;
}

std::vector<Interaction *> InteractionManager::getInteractionsByCustomer(const size_t &customerId)
{
    std::vector<Interaction *> foundInteractions;
    for (Interaction &interaction : _interactions)
    {
        if (interaction.getCustomerId() == customerId)
        {
            foundInteractions.push_back(&interaction);
        }
    }
    return foundInteractions;
}

bool InteractionManager::removeInteraction(const size_t &id)
{
    for (auto it = _interactions.begin(); it != _interactions.end(); ++it)
    {
        if (it->getId() == id)
        {
            this->_interactions.erase(it);
            return true;
        }
    }
    return false;
}


#endif