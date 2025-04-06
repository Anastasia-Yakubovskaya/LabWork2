#include <gtest/gtest.h>
#include "cell.h"

/**
 * @brief Тест для проверки размещения объекта в ячейке.
 *
 * Этот тест проверяет, что объект успешно размещается в ячейке, и проверяет,
 * что состояние ячейки (занятость, содержимое и здоровье) обновляется корректно.
 */
TEST(CellTest, PlaceObject)
{

    Cell cell;

    cell.place("House1", 30);


    EXPECT_TRUE(cell.isOccupied);

    EXPECT_EQ(cell.content, "House1");


    EXPECT_EQ(cell.health, 30);
}

/**
 * @brief Тест для проверки получения урона объектом в ячейке.
 *
 * Этот тест проверяет, что объект в ячейке корректно получает урон,
 * и что ячейка освобождается, если здоровье объекта падает до нуля или ниже.
 */
TEST(CellTest, TakeDamage)
{

    Cell cell;

    cell.place("House1", 30);

    cell.takeDamage(10);


    EXPECT_EQ(cell.health, 20);

    cell.takeDamage(20);

    EXPECT_FALSE(cell.isOccupied);

    EXPECT_EQ(cell.content, "*");
}
