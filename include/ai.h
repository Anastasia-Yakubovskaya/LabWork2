#ifndef AI_H
#define AI_H

#include "playerbase.h"
#include "deck.h"

class AI : public PlayerBase {
public:
    AI(const std::string& name, const Characteristic& characteristic);
    void drawCard(Deck& deck, bool isConstruction);
    void drawBonusCard(Deck& deck);
    void showHand() const;
    ~AI();
};

#endif // AI_H
