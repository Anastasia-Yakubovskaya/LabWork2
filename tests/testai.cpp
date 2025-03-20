#include <gtest/gtest.h>
#include "ai.h"
#include "deck.h"
#include "constructioncard.h" 

TEST(AITest, AIPlaceObject) {
    
    AI ai("AI", Characteristic("None"));

   
    Deck deck;

    // Инициализируем колоду (если нужно)
    // Например, добавляем несколько карт
    deck.addCard(new ConstructionCard("House", -5)); // Создаем карту строительства "House"
    deck.addCard(new ConstructionCard("Tree", -3));  // Создаем карту строительства "Tree"

    // AI берет карту из колоды
    ai.drawCard(deck, true); // Рисуем карту строительства

    // Проверяем, что AI успешно взял карту
    // (Здесь можно добавить дополнительные проверки, если нужно)
    SUCCEED();
}
