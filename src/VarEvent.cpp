/*Yakubovskaya Anastasya st130155@student.spbu.ru LabWork2*/
#include "varevent.h"
#include <iostream>

VarEvent::VarEvent(const std::string& name, const std::string& description, PlayerBase* target, int damage)
    : BonusCard(name, description, "VarEvent"), target(target), damage(damage) {}

void VarEvent::trigger()
{
    std::cout << "Triggering VarEvent: " << name << " (Damage: " << damage << ")\n";
    if (target)
    {
        target->score -= damage;
        std::cout << "Player " << target->name << "'s score decreased by " << damage << ".\n";
    }
    else
    {
        std::cout << "Target not set.\n";
    }
}
