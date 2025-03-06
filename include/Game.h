#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "AI.h"
#include "Board.h"
#include "ScoringSystem.h"
#include <vector>

class Game {
public:
    std::vector<Player> players; // Список игроков
    Board board; // Игровое поле
    ScoringSystem scoringSystem; // Система подсчета очков

    void chooseCharacteristics(Player& player, AI& ai);
    void startGame();
};

#endif
