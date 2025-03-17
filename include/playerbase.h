#ifndef PLAYERBASE_H
#define PLAYERBASE_H

#include <string>
#include <vector>
#include "characteristic.h"
#include "card.h"

class PlayerBase {
public:
    std::string name;
    int score;
    Characteristic characteristic;
    std::vector<Card*> hand;

    PlayerBase(const std::string& name, const Characteristic& characteristic);
    virtual ~PlayerBase() = default;
};

#endif // PLAYERBASE_H
