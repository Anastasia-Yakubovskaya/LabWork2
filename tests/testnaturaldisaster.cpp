#include <gtest/gtest.h>
#include "naturaldisaster.h"
#include "board.h"
#include "characteristic.h"

/**
 * @brief Тест для проверки срабатывания стихийного бедствия.
 *
 * Этот тест проверяет, что стихийное бедствие корректно наносит урон объекту на игровом поле.
 * В данном случае проверяется, что здоровье объекта уменьшается на указанное значение урона.
 */
TEST(NaturalDisasterTest, TriggerDisaster)
{

    NaturalDisaster disaster("Flood", 10);

    Board board;

    int playerScore = 100;

    Characteristic playerCharacteristic("None");

    board.placeObject(0, 0, "House1", 30);

    disaster.trigger(board, playerScore, playerCharacteristic, "1");

    EXPECT_EQ(board.grid[0][0].health, 20);
}
