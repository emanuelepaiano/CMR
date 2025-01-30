#ifndef INTERACTION_TYPE_HPP
#define INTERACTION_TYPE_HPP

#include <bits/stdc++.h>

namespace insura {

    enum InteractionType {
        CONTRACT,
        MEETING,
        OTHER
    };

    /**
     * convert InteractionType value to string
     * @param type the type
     * @return string format of InteractionType
     */
    std::string to_string(InteractionType type);

    /**
     * parse InteractionType string
     * @param value the string type
     * @return InteractionType
     */
    InteractionType to_interaction_type(std::string value);

}


#endif