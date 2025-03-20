/* Yakubovskaya Anastasya st130155@student.spbu.ru LabWork2 */
#include "deck.h"
#include <random>
#include <algorithm>
#include <iostream>
#include "constructioncard.h"
#include "naturaldisaster.h"
#include "economicevent.h"
#include "politicalevent.h"
#include "varevent.h"
#include "tradeevent.h"
#include "stealcardevent.h"

/**
 * @brief Добавляет карту в колоду.
 * 
 * Этот метод добавляет карту в соответствующий вектор в зависимости от типа карты.
 * 
 * @param card Указатель на карту, которую нужно добавить в колоду.
 */
void Deck::addCard(Card* card)
{
    if (dynamic_cast<ConstructionCard*>(card))
    {
        constructionCards.push_back(card);
    }
    else if (dynamic_cast<EventCard*>(card))
    {
        eventCards.push_back(card);
    }
    else if (dynamic_cast<BonusCard*>(card))
    {
        bonusCards.push_back(card);
    }
}

/**
 * @brief Перемешивает колоду карт.
 * 
 * Этот метод перемешивает все карты в колоде, включая строительные карты,
 * карты событий и бонусные карты.
 */
void Deck::shuffle()
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(constructionCards.begin(), constructionCards.end(), g);
    std::shuffle(eventCards.begin(), eventCards.end(), g);
    std::shuffle(bonusCards.begin(), bonusCards.end(), g);
    std::cout << "Deck shuffled!\n";
}

/**
 * @brief Берет строительную карту из колоды.
 * 
 * Этот метод извлекает последнюю строительную карту из колоды.
 * Если строительные карты закончились, возвращает nullptr.
 * 
 * @return Указатель на извлеченную строительную карту или nullptr, если карты закончились.
 */
Card* Deck::drawConstructionCard()
{
    if (constructionCards.empty())
    {
        std::cout << "No more construction cards left!\n";
        return nullptr;
    }
    Card* card = constructionCards.back();
    constructionCards.pop_back();
    return card;
}

/**
 * @brief Берет карту события из колоды.
 * 
 * Этот метод извлекает последнюю карту события из колоды.
 * Если карты событий закончились, возвращает nullptr.
 * 
 * @return Указатель на извлеченную карту события или nullptr, если карты закончились.
 */
Card* Deck::drawEventCard()
{
    if (eventCards.empty())
    {
        std::cout << "No more event cards left!\n";
        return nullptr;
    }
    Card* card = eventCards.back();
    eventCards.pop_back();
    return card;
}

/**
 * @brief Берет бонусную карту из колоды.
 * 
 * Этот метод извлекает последнюю бонусную карту из колоды.
 * Если бонусные карты закончились, возвращает nullptr.
 * 
 * @return Указатель на извлеченную бонусную карту или nullptr, если карты закончились.
 */
Card* Deck::drawBonusCard()
{
    if (bonusCards.empty())
    {
        std::cout << "No more bonus cards left!\n";
        return nullptr;
    }
    Card* card = bonusCards.back();
    bonusCards.pop_back();
    return card;
}

/**
 * @brief Получает количество оставшихся карт в колоде.
 * 
 * Этот метод возвращает общее количество оставшихся карт во всех типах колод.
 * 
 * @return Общее количество оставшихся карт.
 */
size_t Deck::getRemainingCards() const
{
    return constructionCards.size() + eventCards.size() + bonusCards.size();
}

/**
 * @brief Проверяет, есть ли пустая колода.
 * 
 * Этот метод проверяет, есть ли хотя бы одна пустая колода (строительные карты,
 * карты событий или бонусные карты).
 * 
 * @return true, если хотя бы одна колода пуста; false в противном случае.
 */
bool Deck::isAnyDeckEmpty() const
{
    return constructionCards.empty() || eventCards.empty() || bonusCards.empty();
}

/**
 * @brief Деструктор колоды.
 * 
 * Этот метод освобождает память, выделенную для карт в колоде.
 */
Deck::~Deck()
{
    for (Card* card : constructionCards)
    {
        delete card;
    }
    for (Card* card : eventCards)
    {
        delete card;
    }
    for (Card* card : bonusCards)
    {
        delete card;
    }
}
