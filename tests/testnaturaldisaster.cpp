#include <gtest/gtest.h>
#include "naturaldisaster.h"
#include "board.h"
#include "characteristic.h"

TEST(NaturalDisasterTest, TriggerDisaster) { // Уникальное имя теста
    NaturalDisaster disaster("Flood", 10);
    Board board;
    int playerScore = 100;
    Characteristic playerCharacteristic("None");

    board.placeObject(0, 0, "House1", 30);
    disaster.trigger(board, playerScore, playerCharacteristic, "1");

    EXPECT_EQ(board.grid[0][0].health, 20);
}
