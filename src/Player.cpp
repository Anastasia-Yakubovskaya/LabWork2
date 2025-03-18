/*Yakubovskaya Anastasya st130155@student.spbu.ru LabWork2*/
#include "player.h"
#include <iostream>

Player::Player(const std::string& name, const Characteristic& characteristic)
    : PlayerBase(name, characteristic) {}

void Player::drawCard(Deck& deck, bool isConstruction)
{
    Card* card = isConstruction ? deck.drawConstructionCard() : deck.drawEventCard();
    if (card)
    {
        hand.push_back(card);
        std::cout << name << " drew a card: " << card->name << "\n";
    }
}

void Player::drawBonusCard(Deck& deck)
{
    Card* card = deck.drawBonusCard();
    if (card)
    {
        hand.push_back(card);
        std::cout << name << " drew a bonus card: " << card->name << "\n";
    }
}

void Player::showHand() const
{
    std::cout << "Cards in hand of " << name << ":\n";
    for (const Card* card : hand)
    {
        std::cout << "- " << card->name << " (" << card->description << ")\n";
    }
}

Player::~Player()
{
    for (Card* card : hand)
    {
        delete card;
    }
}
