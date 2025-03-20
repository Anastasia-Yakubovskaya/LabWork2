#include <gtest/gtest.h>
#include "graphics.h"
#include "board.h"

TEST(UITest, DisplayBoard) {
    Board board;
    Graphics::displayBoard(board.grid);

    // Manually verify the output (UI testing is often manual)
    // This test is more about ensuring no crashes occur
    SUCCEED();
}
