#include "ai.h"
#include <iostream>

AI::AI(const std::string& name, const Characteristic& characteristic)
    : PlayerBase(name, characteristic) {}

void AI::drawCard(Deck& deck, bool isConstruction) {
    Card* card = isConstruction ? deck.drawConstructionCard() : deck.drawEventCard();
    if (card) {
        hand.push_back(card);
        std::cout << name << " drew a card: " << card->name << "\n";
    }
}

void AI::drawBonusCard(Deck& deck) {
    Card* card = deck.drawBonusCard();
    if (card) {
        hand.push_back(card);
        std::cout << name << " drew a bonus card: " << card->name << "\n";
    }
}

void AI::showHand() const {
    std::cout << "Cards in hand of " << name << ":\n";
    for (const Card* card : hand) {
        std::cout << "- " << card->name << " (" << card->description << ")\n";
    }
}

AI::~AI() {
    for (Card* card : hand) {
        delete card;
    }
}
