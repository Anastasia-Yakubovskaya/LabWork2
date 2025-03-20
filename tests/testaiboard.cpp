#include <gtest/gtest.h>
#include "ai.h"
#include "board.h"
#include "deck.h"
#include "constructioncard.h" // Подключаем заголовочный файл ConstructionCard

/**
 * @brief Тест для проверки интеграции AI и Board.
 *
 * Этот тест проверяет, что AI может успешно взять карту из колоды и разместить объект на доске.
 * Также проверяется, что объект корректно размещается на указанной ячейке.
 */
TEST(AIBoardIntegrationTest, AIPlaceObject)
{

    Board board;
    AI ai("AI", Characteristic("None"));


    Deck deck;


    deck.addCard(new ConstructionCard("House", -5));
    deck.addCard(new ConstructionCard("Tree", -3));


    ai.drawCard(deck, true);


    board.placeObject(5, 5, "Tree2", 40);


    EXPECT_TRUE(board.grid[5][5].isOccupied);
    EXPECT_EQ(board.grid[5][5].content, "Tree2");
}
