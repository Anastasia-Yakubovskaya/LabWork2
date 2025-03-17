#include "EventCard.h"
#include <iostream>
EventCard::EventCard(const std::string& name, const std::string& description, const std::string& effect)
    : Card(name, description), effect(effect) {}

void EventCard::play(int& score, const Characteristic& characteristic) {
    (void)score;          // Подавляем предупреждение
    (void)characteristic; // Подавляем предупреждение
    std::cout << "Playing event card: " << name << " (" << description << ")\n";
}
