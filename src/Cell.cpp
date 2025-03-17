#include "cell.h"

Cell::Cell() : content("*(  )"), isOccupied(false), health(0) {}

void Cell::place(const std::string& object, int health) {
    content = object;
    isOccupied = true;
    this->health = health;
}

void Cell::takeDamage(int damage) {
    health -= damage;
    if (health <= 0) {
        content = "*";
        isOccupied = false;
        health = 0;
    }
}
