#include "BonusCard.h"
#include <iostream>



BonusCard::BonusCard(const std::string& name, const std::string& description, const std::string& bonusType)
    : Card(name, description), bonusType(bonusType) {}

void BonusCard::play(int& score, const Characteristic& characteristic) {
    (void)score;          // Подавляем предупреждение
    (void)characteristic; // Подавляем предупреждение
    std::cout << "Playing bonus card: " << name << " (" << description << ")\n";
}
