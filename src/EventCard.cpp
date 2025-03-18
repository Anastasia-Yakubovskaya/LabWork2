/*Yakubovskaya Anastasya st130155@student.spbu.ru LabWork2*/
#include "eventcard.h"
#include <iostream>
EventCard::EventCard(const std::string& name, const std::string& description, const std::string& effect)
    : Card(name, description), effect(effect) {}

void EventCard::play(int& score, const Characteristic& characteristic)
{
    (void)score;
    (void)characteristic;
    std::cout << "Playing event card: " << name << " (" << description << ")\n";
}
