#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include "cell.h"
#include "graphics.h" 
#include <iostream>

class Board {
public:
    static const int size = 10;
    std::vector<std::vector<Cell>> grid;

    Board();
    void placeObject(int x, int y, const std::string& object, int health);
    bool isCellEmpty(int x, int y);
    void display();
    int calculateFinalScore(const std::string& playerPrefix);
    void stealBuilding(const std::string& fromPrefix, const std::string& toPrefix);
    void exchangeAllBuildings(const std::string& player1Prefix, const std::string& player2Prefix);
};

#endif // BOARD_H
