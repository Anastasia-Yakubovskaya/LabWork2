/* Yakubovskaya Anastasya st130155@student.spbu.ru LabWork2 */
#include "ai.h"
#include <iostream>

AI::AI(const std::string& name, const Characteristic& characteristic)
    : PlayerBase(name, characteristic) {}

/**
 * @brief Тянет карту из колоды.
 * 
 * Этот метод позволяет ИИ тянуть карту из колоды. 
 * В зависимости от параметра isConstruction, 
 * он может тянуть либо строительную карту, либо карту события.
 * 
 * @param deck Ссылка на колоду, из которой будет тянута карта.
 * @param isConstruction Флаг, указывающий, тянуть ли строительную карту (true) 
 *                      или карту события (false).
 */
void AI::drawCard(Deck& deck, bool isConstruction)
{
    Card* card = isConstruction ? deck.drawConstructionCard() : deck.drawEventCard();
    if (card)
    {
        hand.push_back(card);
        std::cout << name << " drew a card: " << card->name << "\n";
    }
}

/**
 * @brief Тянет бонусную карту из колоды.
 * 
 * Этот метод позволяет ИИ тянуть бонусную карту из колоды.
 * 
 * @param deck Ссылка на колоду, из которой будет тянута бонусная карта.
 */
void AI::drawBonusCard(Deck& deck)
{
    Card* card = deck.drawBonusCard();
    if (card)
    {
        hand.push_back(card);
        std::cout << name << " drew a bonus card: " << card->name << "\n";
    }
}

/**
 * @brief Показывает карты в руке.
 * 
 * Этот метод выводит на экран все карты, которые находятся в руке ИИ.
 */
void AI::showHand() const
{
    std::cout << "Cards in hand of " << name << ":\n";
    for (const Card* card : hand)
    {
        std::cout << "- " << card->name << " (" << card->description << ")\n";
    }
}

/**
 * @brief Деструктор класса AI.
 * 
 * Этот деструктор освобождает память, занятую картами в руке ИИ.
 */
AI::~AI()
{
    for (Card* card : hand)
    {
        delete card;
    }
}
