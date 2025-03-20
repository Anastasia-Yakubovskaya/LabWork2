#include <gtest/gtest.h>
#include "characteristic.h"

/**
 * @brief Тест для проверки применения эффекта характеристики.
 *
 * Этот тест проверяет, что метод `applyEffect` корректно применяет эффект характеристики
 * к значению счета. В данном случае проверяется, что стоимость строительства уменьшается на 10%.
 */
TEST(CharacteristicTest, ApplyEffect)
{

    Characteristic characteristic("Building structures costs 10% less");


    int score = 100;

    characteristic.applyEffect(score, -10);

    EXPECT_EQ(score, 91);
}
