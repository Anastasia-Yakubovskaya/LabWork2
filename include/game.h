#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "deck.h"
#include "dice.h"

class Game {
public:
    Board board;
    Deck deck;
    Dice dice;

    Game();  // Объявление конструктора
    void startGame();  // Объявление метода startGame
};

#endif // GAME_H
