#ifndef DECK_H
#define DECK_H

#include <vector>
#include "card.h"

class Deck {
private:
    std::vector<Card*> constructionCards;
    std::vector<Card*> eventCards;
    std::vector<Card*> bonusCards;

public:
    void addCard(Card* card);
    void shuffle();
    Card* drawConstructionCard();
    Card* drawEventCard();
    Card* drawBonusCard();
    size_t getRemainingCards() const;
    bool isAnyDeckEmpty() const;
    ~Deck();
};

#endif // DECK_H
