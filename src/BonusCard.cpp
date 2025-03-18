/*Yakubovskaya Anastasya st130155@student.spbu.ru LabWork2*/
#include "bonuscard.h"
#include <iostream>



BonusCard::BonusCard(const std::string& name, const std::string& description, const std::string& bonusType)
    : Card(name, description), bonusType(bonusType) {}

void BonusCard::play(int& score, const Characteristic& characteristic)
{
    (void)score;          
    (void)characteristic; 
    std::cout << "Playing bonus card: " << name << " (" << description << ")\n";
}
