#include "PoliticalEvent.h"
#include <iostream>

PoliticalEvent::PoliticalEvent(const std::string& type, const std::string& impact)
    : EventCard("Political Event", "Affects all buildings and the score.", impact), type(type), impact(impact) {}

void PoliticalEvent::trigger(Board& board, int& score, const Characteristic& characteristic, const std::string& playerPrefix) {
    std::cout << "Triggering political event: " << type << " (" << impact << ")\n";
    for (int i = 0; i < Board::size; ++i) {
        for (int j = 0; j < Board::size; ++j) {
            if (board.grid[i][j].content.find(playerPrefix) != std::string::npos) {
                board.grid[i][j].takeDamage(10);
                std::cout << "Building at cell (" << i << ", " << j << ") has been affected.\n";
            }
        }
    }
    characteristic.applyEffect(score, 25);
}
