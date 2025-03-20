#include <gtest/gtest.h>
#include "board.h"

TEST(ScoringSystemTest, CalculateFinalScore) {
    Board board;
    board.placeObject(0, 0, "House1", 30);
    board.placeObject(1, 1, "Tree1", 40);

    int playerScore = board.calculateFinalScore("1");
    EXPECT_EQ(playerScore, 15 + 25); // House (15) + Tree (25)
}
