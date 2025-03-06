#ifndef PLAYER_H
#define PLAYER_H

#include "Characteristic.h"
#include "Board.h"
#include <string>

class Player {
public:
    std::string name; // Имя игрока
    int score; // Счет игрока
    Characteristic characteristic; // Характеристика игрока

    Player(const std::string& name, const Characteristic& characteristic);
    void chooseCell(int x, int y, Board& board);
    int rollDice();
};

#endif
