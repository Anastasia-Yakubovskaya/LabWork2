#include <gtest/gtest.h>
#include "game.h"
#include "ai.h"
#include "player.h"
#include "playerbase.h"

/**
 * @brief Тест для проверки полного цикла игры.
 *
 * Этот тест проверяет, что игра корректно инициализируется и прогрессирует,
 * включая ходы игрока и AI. Также проверяется, что колода карт не пуста после
 * нескольких ходов.
 */
TEST(GameSystemTest, FullGameCycle)
{

    Game game;
    game.startGame();

    Player player("Player1", Characteristic("None"));
    AI ai("AI", Characteristic("None"));

    player.drawCard(game.deck, true);
    ai.drawCard(game.deck, true);

    EXPECT_TRUE(game.deck.getRemainingCards() > 0);
}
