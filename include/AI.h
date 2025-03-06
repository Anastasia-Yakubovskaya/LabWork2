#ifndef AI_H
#define AI_H

#include "Characteristic.h"
#include "Board.h"
#include <string>

class AI {
public:
    std::string name; // Имя AI
    Characteristic characteristic; // Характеристика AI
    int score; // Счет AI

    AI(const std::string& name, const Characteristic& characteristic);
    void chooseCell(Board& board);
};

#endif
