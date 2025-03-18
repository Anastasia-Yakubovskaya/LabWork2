/*Yakubovskaya Anastasya st130155@student.spbu.ru LabWork2*/
#include "economicevent.h"
#include <iostream>

EconomicEvent::EconomicEvent(const std::string& type, const std::string& impact)
    : EventCard("Economic Event", "Affects the player's score.", impact), type(type), impact(impact) {}

void EconomicEvent::trigger(int& score, const Characteristic& characteristic)
{
    std::cout << "Triggering economic event: " << type << " (" << impact << ")\n";
    if (impact == "Default")
    {
        characteristic.applyEffect(score, -25);
    }
    else if (impact == "Crisis")
    {
        characteristic.applyEffect(score, -50);
    }
}
