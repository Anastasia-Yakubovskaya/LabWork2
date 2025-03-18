#ifndef CONSTRUCTIONCARD_H
#define CONSTRUCTIONCARD_H

#include "card.h"

class ConstructionCard : public Card {
public:
    std::string type;
    int scoreChange;

    ConstructionCard(const std::string& type, int scoreChange);
    void play(int& score, const Characteristic& characteristic) override;
};

#endif // CONSTRUCTIONCARD_H
