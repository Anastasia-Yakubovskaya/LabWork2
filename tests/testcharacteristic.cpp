#include <gtest/gtest.h>
#include "characteristic.h"

TEST(CharacteristicTest, ApplyEffect) {
    Characteristic characteristic("Building structures costs 10% less");
    int score = 100;
    characteristic.applyEffect(score, -10);
    EXPECT_EQ(score, 91); // 10% less
}
