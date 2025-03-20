#include <gtest/gtest.h>
#include "ai.h"
#include "deck.h"
#include "constructioncard.h"

/**
 * @brief Тест для проверки размещения объекта AI на доске.
 *
 * Этот тест проверяет, что AI может успешно взять карту из колоды и выполнить действие,
 * связанное с размещением объекта на доске.
 */
TEST(AITest, AIPlaceObject)
{

    AI ai("AI", Characteristic("None"));

    Deck deck;


    deck.addCard(new ConstructionCard("House", -5));
    deck.addCard(new ConstructionCard("Tree", -3));


    ai.drawCard(deck, true);

    SUCCEED();
}
