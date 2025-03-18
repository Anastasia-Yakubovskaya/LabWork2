#ifndef NATURALDISASTER_H
#define NATURALDISASTER_H

#include "eventcard.h"
#include "board.h"

class NaturalDisaster : public EventCard {
public:
    std::string type;
    int damage;

    NaturalDisaster(const std::string& type, int damage);
    void trigger(Board& board, int& score, const Characteristic& characteristic, const std::string& playerPrefix);
};

#endif // NATURALDISASTER_H
