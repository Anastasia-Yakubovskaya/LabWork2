#ifndef CELL_H
#define CELL_H

#include <string>

class Cell {
public:
    std::string content; // Содержимое клетки
    bool isOccupied; // Занята ли клетка

    Cell();
    void place(const std::string& object);
};

#endif
