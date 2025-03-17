#include "TradeEvent.h"
#include <iostream>

TradeEvent::TradeEvent(const std::string& name, const std::string& description, PlayerBase* target, const std::string& resource)
    : BonusCard(name, description, "TradeEvent"), target(target), resource(resource) {}

void TradeEvent::trigger(Board& board) {
    std::cout << "Triggering TradeEvent: " << name << " (Resource: " << resource << ")\n";
    std::cout << "Players have exchanged buildings.\n";
}
