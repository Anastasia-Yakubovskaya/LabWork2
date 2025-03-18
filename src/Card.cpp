/*Yakubovskaya Anastasya st130155@student.spbu.ru LabWork2*/
#include "card.h"
#include <iostream>


Card::Card(const std::string& name, const std::string& description)
    : name(name), description(description) {}


void Card::play([[maybe_unused]] int& score, [[maybe_unused]] const Characteristic& characteristic)
{
    std::cout << "Playing card: " << name << " (" << description << ")\n";
}
