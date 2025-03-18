#ifndef ECONOMICEVENT_H
#define ECONOMICEVENT_H

#include "eventcard.h"

class EconomicEvent : public EventCard {
public:
    std::string type;
    std::string impact;

    EconomicEvent(const std::string& type, const std::string& impact);
    void trigger(int& score, const Characteristic& characteristic);
};

#endif // ECONOMICEVENT_H
