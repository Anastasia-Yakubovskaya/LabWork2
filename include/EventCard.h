#ifndef EVENTCARD_H
#define EVENTCARD_H

#include "card.h"

class EventCard : public Card {
public:
    std::string effect; // Эффект карты

    EventCard(const std::string& name, const std::string& description, const std::string& effect); // Конструктор
    void play(int& score, const Characteristic& characteristic) override; // Переопределение метода play
};

#endif
