#ifndef INTERACTION_MANAGER_HPP
#define INTERACTION_MANAGER_HPP

#include <bits/stdc++.h>
#include "Interaction.hpp"
#include "InteractionCsvFile.hpp"

/**
 * Class for interaction entity
 */
class InteractionManager
{
private:
    std::vector<Interaction> _interactions;
    InteractionCsvFile _interactionFile;

public:
    /**
     * default constructor
     */
    InteractionManager();

    /**
     * load interactions from csv file
     */
    void loadInteractions();

    /**
     * save interactions to csv file
     */
    void saveInteractions();

    /**
     * Create a new interaction 
     * @param interaction new interaction to create
     * @return created Interaction pointer if success, nullptr otherwise
     */
    Interaction *addInteraction(Interaction &interaction);
    
    /**
     * retrieve all Interactions by Customer 's ID
     * @param customerId customer ID
     * @return customer 's interactions if success, empty vector otherwise
     */
    std::vector<Interaction*> getInteractionsByCustomer(const size_t &customerId);

    bool removeInteraction(const size_t &id);

    /**
     * display all Interactions for a given customer ID
     * @param customerId customer's ID
     */
    Interaction *getInteraction(const size_t interactionId);

    /**
     * retrieve all interactions
     */
    std::vector<Interaction> getAllInteractions();

    /**
     * update a given interaction
     * @param updatedInteraction updated interaction
     */
    Interaction *updateInteraction(Interaction &updatedInteraction);

};

#endif