#include "Cell.h"

Cell::Cell() : content("*"), isOccupied(false) {}

void Cell::place(const std::string& object) {
    content = object;
    isOccupied = true;
}
