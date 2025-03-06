#ifndef BOARD_H
#define BOARD_H

#include "Cell.h"
#include <vector>

class Board {
public:
    static const int size = 20; // Размер поля
    std::vector<std::vector<Cell>> grid; // Поле 20x20

    Board();
    void placeObject(int x, int y, const std::string& object);
    bool isCellEmpty(int x, int y);
    void display();
};

#endif
