#include <gtest/gtest.h>
#include "player.h"
#include "board.h"
#include "deck.h"
#include "constructioncard.h"

TEST(PlayerBoardIntegrationTest, PlayerPlaceObjectOnBoard) { // Уникальное имя теста
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
