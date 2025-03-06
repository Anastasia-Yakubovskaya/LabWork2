#include "ScoringSystem.h"
#include <iostream>

void ScoringSystem::updateScore(Player& player, int points) {
    scores[player.name] += points;
}

void ScoringSystem::updateScore(AI& ai, int points) {
    scores[ai.name] += points;
}

void ScoringSystem::displayScores(Player& player, AI& ai) {
    std::cout << "Текущие очки:\n";
    std::cout << player.name << ": " << player.score << " очков\n";
    std::cout << ai.name << ": " << ai.score << " очков\n";
}
