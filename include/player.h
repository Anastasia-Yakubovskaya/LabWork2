#ifndef PLAYER_H
#define PLAYER_H

#include "playerbase.h"
#include "deck.h"

class Player : public PlayerBase {
public:
    Player(const std::string& name, const Characteristic& characteristic);
    void drawCard(Deck& deck, bool isConstruction);
    void drawBonusCard(Deck& deck);
    void showHand() const;
    ~Player();
};

#endif // PLAYER_H
