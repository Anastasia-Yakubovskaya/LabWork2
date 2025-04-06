#include <gtest/gtest.h>
#include "board.h"

/**
 * @brief Тест для проверки системы подсчета очков.
 *
 * Этот тест проверяет, что метод `calculateFinalScore` корректно вычисляет
 * итоговый счет игрока на основе объектов, размещенных на игровом поле.
 * В данном случае проверяется, что счет игрока равен сумме очков за дом и дерево.
 */
TEST(ScoringSystemTest, CalculateFinalScore)
{

    Board board;

    board.placeObject(0, 0, "House1", 30);
    board.placeObject(1, 1, "Tree1", 40);


    int playerScore = board.calculateFinalScore("1");

    EXPECT_EQ(playerScore, 15 + 25);
}
