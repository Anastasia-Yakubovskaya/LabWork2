#include <gtest/gtest.h>
#include "dice.h"

/**
 * @brief Тест для проверки работы кубика (Dice).
 *
 * Этот тест проверяет, что метод `roll` возвращает значение в диапазоне от 1 до 6,
 * что соответствует стандартному шестигранному кубику.
 */
TEST(DiceTest, RollDice)
{

    Dice dice;

    int result = dice.roll();

    EXPECT_GE(result, 1);
    EXPECT_LE(result, 6);
}
