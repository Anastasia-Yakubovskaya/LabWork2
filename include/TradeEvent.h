#ifndef TRADEEVENT_H
#define TRADEEVENT_H

#include "BonusCard.h"
#include "playerbase.h"
#include "board.h"

class TradeEvent : public BonusCard {
public:
    PlayerBase* target;
    std::string resource;

    TradeEvent(const std::string& name, const std::string& description, PlayerBase* target, const std::string& resource);
    void trigger(Board& board);
};

#endif // TRADEEVENT_H
