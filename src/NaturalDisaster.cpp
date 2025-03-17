#include "NaturalDisaster.h"
#include <iostream>

NaturalDisaster::NaturalDisaster(const std::string& type, int damage)
    : EventCard("Natural Disaster", "Deals damage to buildings.", "Damage"), type(type), damage(damage) {}

void NaturalDisaster::trigger(Board& board, int& score, const Characteristic& characteristic, const std::string& playerPrefix) {
    std::cout << "Triggering natural disaster: " << type << " (Damage: " << damage << ")\n";
    for (int i = 0; i < Board::size; ++i) {
        for (int j = 0; j < Board::size; ++j) {
            if (board.grid[i][j].content.find(playerPrefix) != std::string::npos) {
                board.grid[i][j].takeDamage(damage);
                std::cout << "Building at cell (" << i << ", " << j << ") has taken damage.\n";
            }
        }
    }
}
