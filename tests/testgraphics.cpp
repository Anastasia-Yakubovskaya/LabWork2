#include <gtest/gtest.h>
#include "graphics.h"
#include "board.h"

/**
 * @brief Тест для проверки отображения игрового поля.
 *
 * Этот тест проверяет, что метод `displayBoard` класса `Graphics` корректно
 * отображает игровое поле без возникновения ошибок. Поскольку тестирование
 * пользовательского интерфейса (UI) часто требует визуальной проверки,
 * данный тест в основном проверяет, что код выполняется без сбоев.
 */
TEST(UITest, DisplayBoard)
{
    Board board;


    Graphics::displayBoard(board.grid);


    SUCCEED();
}
