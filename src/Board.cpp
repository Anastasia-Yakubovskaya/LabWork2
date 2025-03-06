#include "Board.h"
#include <iostream>
Board::Board() {
    grid.resize(size, std::vector<Cell>(size));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            grid[i][j] = Cell();
        }
    }
}

void Board::placeObject(int x, int y, const std::string& object) {
    if (isCellEmpty(x, y)) {
        grid[x][y].place(object);
    } else {
        std::cout << "Клетка занята! Попробуйте другую.\n";
    }
}

bool Board::isCellEmpty(int x, int y) {
    return !grid[x][y].isOccupied;
}

void Board::display() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << grid[i][j].content << " ";
        }
        std::cout << std::endl;
    }
}
