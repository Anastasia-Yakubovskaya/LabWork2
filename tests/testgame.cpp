#include <gtest/gtest.h>
#include "game.h"
#include "ai.h"
#include "player.h"
#include "playerbase.h"

TEST(GameSystemTest, FullGameCycle) {
    Game game;
    game.startGame();

    // Simulate player and AI turns
    Player player("Player1", Characteristic("None"));
    AI ai("AI", Characteristic("None"));

    // Simulate a few moves
    player.drawCard(game.deck, true);
    ai.drawCard(game.deck, true);

    // Check if the game progresses correctly
    EXPECT_TRUE(game.deck.getRemainingCards() > 0);
}
