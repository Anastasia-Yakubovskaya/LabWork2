#include "Characteristic.h"
#include <iostream>

Characteristic::Characteristic(const std::string& type) : type(type) {}

void Characteristic::applyEffect() {
    if (type == "Natural disasters deal 20% less damage") {
        std::cout << "Эффект: Природные катастрофы наносят на 20% меньше урона.\n";
    } else if (type == "Building structures costs 10% less") {
        std::cout << "Эффект: Строительство стоит на 10% меньше.\n";
    } else if (type == "The player earns 5% more points") {
        std::cout << "Эффект: Игрок зарабатывает на 5% больше очков.\n";
    }
}
