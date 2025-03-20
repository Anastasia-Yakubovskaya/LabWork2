#include <gtest/gtest.h>
#include "dice.h"

TEST(DiceTest, RollDice) {
    Dice dice;
    int result = dice.roll();
    EXPECT_GE(result, 1);
    EXPECT_LE(result, 6);
}
