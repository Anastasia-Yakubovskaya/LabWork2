#include "Player.h"
#include "Board.h"
#include <cstdlib>

Player::Player(const std::string& name, const Characteristic& characteristic)
    : name(name), score(0), characteristic(characteristic) {}

void Player::chooseCell(int x, int y, Board& board) {
    board.placeObject(x, y, "1");
    score += 10;
}

int Player::rollDice() {
    return rand() % 6 + 1;
}
