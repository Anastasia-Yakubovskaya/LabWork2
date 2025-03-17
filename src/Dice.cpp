#include "dice.h"
#include <cstdlib>
#include <ctime>

int Dice::roll() {
    return rand() % 6 + 1;
}
