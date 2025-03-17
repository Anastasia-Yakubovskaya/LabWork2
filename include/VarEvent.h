#ifndef VAREVENT_H
#define VAREVENT_H

#include "BonusCard.h"
#include "playerbase.h"

class VarEvent : public BonusCard {
public:
    PlayerBase* target;
    int damage;

    VarEvent(const std::string& name, const std::string& description, PlayerBase* target, int damage);
    void trigger();
};

#endif // VAREVENT_H
