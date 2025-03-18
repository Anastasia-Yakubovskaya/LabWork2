/*Yakubovskaya Anastasya st130155@student.spbu.ru LabWork2*/
#include "characteristic.h"
#include <iostream>

Characteristic::Characteristic(const std::string& type) : type(type) {}

void Characteristic::applyEffect(int& score, int change) const
{
    if (type == "Natural disasters deal 20% less damage")
    {
        std::cout << "Effect: Natural disasters deal 20% less damage.\n";
    }
    else if (type == "Building structures costs 10% less")
    {
        score += static_cast<int>(change * 0.9);
        std::cout << "Effect: Building structures costs 10% less. Score changed by: " << static_cast<int>(change * 0.9) << "\n";
    }
    else if (type == "The player earns 5% more points")
    {
        score += static_cast<int>(change * 1.05);
        std::cout << "Effect: The player earns 5% more points. Score changed by: " << static_cast<int>(change * 1.05) << "\n";
    }
    else
    {
        score += change;
    }
}
