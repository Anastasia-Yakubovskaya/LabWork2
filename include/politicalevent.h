#ifndef POLITICALEVENT_H
#define POLITICALEVENT_H

#include "eventcard.h"
#include "board.h"

class PoliticalEvent : public EventCard {
public:
    std::string type;
    std::string impact;

    PoliticalEvent(const std::string& type, const std::string& impact);
    void trigger(Board& board, int& score, const Characteristic& characteristic, const std::string& playerPrefix);
};

#endif // POLITICALEVENT_H
