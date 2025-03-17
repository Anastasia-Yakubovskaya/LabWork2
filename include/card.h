#ifndef CARD_H
#define CARD_H

#include <string>
#include "characteristic.h"

class Card {
public:
    std::string name;
    std::string description;

    Card(const std::string& name, const std::string& description);
    virtual void play(int& score, const Characteristic& characteristic);
    virtual ~Card() = default;
};

#endif // CARD_H
