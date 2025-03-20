#include <gtest/gtest.h>
#include "ai.h"
#include "board.h"
#include "deck.h"
#include "constructioncard.h" // Подключаем заголовочный файл ConstructionCard

TEST(AIBoardIntegrationTest, AIPlaceObject) {
    // Создаем объекты Board и AI
    Board board;
    AI ai("AI", Characteristic("None"));

    // Создаем объект Deck
    Deck deck;

    // Инициализируем колоду (если нужно)
    // Например, добавляем несколько карт
    deck.addCard(new ConstructionCard("House", -5)); // Создаем карту строительства "House"
    deck.addCard(new ConstructionCard("Tree", -3));  // Создаем карту строительства "Tree"

    // AI берет карту из колоды
    ai.drawCard(deck, true); // Рисуем карту строительства

    // Симулируем размещение объекта AI на доске
    board.placeObject(5, 5, "Tree2", 40);

    // Проверяем, что объект размещен корректно
    EXPECT_TRUE(board.grid[5][5].isOccupied);
    EXPECT_EQ(board.grid[5][5].content, "Tree2");
}
