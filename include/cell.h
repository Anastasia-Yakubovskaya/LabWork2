#ifndef CELL_H
#define CELL_H

#include <string>

class Cell {
public:
    std::string content;
    bool isOccupied;
    int health;

    Cell();
    void place(const std::string& object, int health);
    void takeDamage(int damage);
};

#endif // CELL_H
