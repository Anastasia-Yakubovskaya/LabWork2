#ifndef BONUSCARD_H
#define BONUSCARD_H

#include "card.h"

class BonusCard : public Card {
public:
    std::string bonusType; // Тип бонуса

    BonusCard(const std::string& name, const std::string& description, const std::string& bonusType); // Конструктор
    void play(int& score, const Characteristic& characteristic) override; // Переопределение метода play
};

#endif
