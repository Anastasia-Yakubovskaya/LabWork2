/* Yakubovskaya Anastasya st130155@student.spbu.ru LabWork2 */
#include "player.h"
#include <iostream>

/**
 * @brief Конструктор класса Player.
 * 
 * Инициализирует игрока с указанным именем и характеристикой.
 * 
 * @param name Имя игрока.
 * @param characteristic Характеристика игрока, влияющая на игровой процесс.
 */
Player::Player(const std::string& name, const Characteristic& characteristic)
    : PlayerBase(name, characteristic) {}

/**
 * @brief Метод для взятия карты из колоды.
 * 
 * Игрок берет карту из колоды. В зависимости от параметра isConstruction
 * берется либо карта строительства, либо карта события.
 * 
 * @param deck Колода, из которой берется карта.
 * @param isConstruction Флаг, указывающий, какую карту взять: строительства (true) или события (false).
 */
void Player::drawCard(Deck& deck, bool isConstruction)
{
    Card* card = isConstruction ? deck.drawConstructionCard() : deck.drawEventCard();
    if (card)
    {
        hand.push_back(card);
        std::cout << name << " drew a card: " << card->name << "\n";
    }
}

/**
 * @brief Метод для взятия бонусной карты из колоды.
 * 
 * Игрок берет бонусную карту из колоды и добавляет ее в свою руку.
 * 
 * @param deck Колода, из которой берется бонусная карта.
 */
void Player::drawBonusCard(Deck& deck)
{
    Card* card = deck.drawBonusCard();
    if (card)
    {
        hand.push_back(card);
        std::cout << name << " drew a bonus card: " << card->name << "\n";
    }
}

/**
 * @brief Метод для отображения карт в руке игрока.
 * 
 * Выводит в консоль список всех карт, находящихся в руке игрока,
 * с их названиями и описаниями.
 */
void Player::showHand() const
{
    std::cout << "Cards in hand of " << name << ":\n";
    for (const Card* card : hand)
    {
        std::cout << "- " << card->name << " (" << card->description << ")\n";
    }
}

/**
 * @brief Деструктор класса Player.
 * 
 * Освобождает память, выделенную для карт в руке игрока.
 */
Player::~Player()
{
    for (Card* card : hand)
    {
        delete card;
    }
}
