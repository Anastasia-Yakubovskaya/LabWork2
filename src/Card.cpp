#include "card.h"
#include <iostream>

// Реализация конструктора Card
Card::Card(const std::string& name, const std::string& description)
    : name(name), description(description) {}

// Реализация метода play (если нужно)
void Card::play(int& score, const Characteristic& characteristic) {
    std::cout << "Playing card: " << name << " (" << description << ")\n";
}
