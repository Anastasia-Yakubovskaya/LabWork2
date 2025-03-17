#ifndef STEALCARDEVENT_H
#define STEALCARDEVENT_H

#include "BonusCard.h"
#include "playerbase.h"
#include "board.h"

class StealCardEvent : public BonusCard {
public:
    PlayerBase* target;
    Card* stolenCard;

    StealCardEvent(const std::string& name, const std::string& description, PlayerBase* target);
    void trigger(Board& board, PlayerBase* currentPlayer);
};

#endif // STEALCARDEVENT_H
