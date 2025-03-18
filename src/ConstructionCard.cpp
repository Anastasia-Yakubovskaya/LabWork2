/*Yakubovskaya Anastasya st130155@student.spbu.ru LabWork2*/
#include "constructioncard.h"
#include <iostream>

ConstructionCard::ConstructionCard(const std::string& type, int scoreChange)
    : Card("Construction Card", "Allows you to build an object on the board."), type(type), scoreChange(scoreChange) {}

void ConstructionCard::play(int& score, const Characteristic& characteristic)
{
    std::cout << "Built object: " << type << " (Score change: " << scoreChange << ")\n";
    characteristic.applyEffect(score, scoreChange);
}
