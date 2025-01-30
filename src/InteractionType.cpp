#ifndef INTERATION_TYPE_CPP
#define INTERATION_TYPE_CPP

#include "InteractionType.hpp"

namespace insura {

    /**
     * convert InteractionType value to string
     * @param type the type
     * @return string format of InteractionType
     */
    std::string to_string(InteractionType type) {
        switch(type) {
            case CONTRACT:
                return "contract";
            case MEETING:
                return "meeting";
            case OTHER:
            default:
                return "other";
        }
    }

    /**
     * parse InteractionType string
     * @param value the string type
     * @return InteractionType
     */
    InteractionType to_interaction_type(std::string value) {
        if (value == "contract") {
            return CONTRACT;
        } else if (value == "meeting") {
            return MEETING;
        } else {
            return OTHER;
        }
    }

}

#endif