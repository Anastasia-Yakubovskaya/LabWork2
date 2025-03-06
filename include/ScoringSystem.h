#ifndef SCORINGSYSTEM_H
#define SCORINGSYSTEM_H

#include "Player.h"
#include "AI.h"
#include <map>

class ScoringSystem {
public:
    std::map<std::string, int> scores; // Счет для каждого игрока

    void updateScore(Player& player, int points);
    void updateScore(AI& ai, int points);
    void displayScores(Player& player, AI& ai);
};

#endif
