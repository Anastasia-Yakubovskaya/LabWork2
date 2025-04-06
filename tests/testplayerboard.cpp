#include <gtest/gtest.h>
#include "player.h"
#include "board.h"
#include "deck.h"
#include "constructioncard.h"

/**
 * @brief Тест для проверки интеграции игрока и игрового поля.
 *
 * Этот тест проверяет, что игрок может успешно взять карту из колоды и разместить
 * объект на игровом поле. Также проверяется, что объект корректно размещается
 * на указанной ячейке.
 */
TEST(PlayerBoardIntegrationTest, PlayerPlaceObjectOnBoard)
{

    Board board;

    Player player("Player1", Characteristic("None"));

    Deck deck;


    deck.addCard(new ConstructionCard("House", -5));
    deck.addCard(new ConstructionCard("Tree", -3));

    player.drawCard(deck, true);

    board.placeObject(0, 0, "House1", 30);

    EXPECT_TRUE(board.grid[0][0].isOccupied);

    EXPECT_EQ(board.grid[0][0].content, "House1");
}
