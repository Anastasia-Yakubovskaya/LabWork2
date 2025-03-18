/*Yakubovskaya Anastasya st130155@student.spbu.ru LabWork2*/
#include "tradeevent.h"
#include <iostream>

TradeEvent::TradeEvent(const std::string& name, const std::string& description, PlayerBase* target, const std::string& resource)
    : BonusCard(name, description, "TradeEvent"), target(target), resource(resource) {}

void TradeEvent::trigger( [[maybe_unused]] Board& board)
{
    std::cout << "Triggering TradeEvent: " << name << " (Resource: " << resource << ")\n";
    std::cout << "Players have exchanged buildings.\n";
}
