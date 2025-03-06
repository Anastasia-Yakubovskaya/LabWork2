#include "AI.h"
#include "Board.h"
#include <cstdlib>
#include <iostream>

AI::AI(const std::string& name, const Characteristic& characteristic)
    : name(name), characteristic(characteristic), score(0) {}

void AI::chooseCell(Board& board) {
    int x, y;
    do {
        x = rand() % Board::size;
        y = rand() % Board::size;
    } while (!board.isCellEmpty(x, y));
    board.placeObject(x, y, "2");
    score += 10;
    std::cout << name << " разместил дом на (" << x << ", " << y << ").\n";
}

