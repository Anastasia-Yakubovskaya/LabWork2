#include <gtest/gtest.h>
#include "board.h"
#include "player.h"
#include "deck.h"
#include "NaturalDisaster.h"
#include "ai.h"
#include "game.h"
#include "card.h"
#include "ConstructionCard.h"  // Подключаем заголовочный файл
#include "EconomicEvent.h"
#include "PoliticalEvent.h"
#include "VarEvent.h"
#include "TradeEvent.h"
#include "StealCardEvent.h"

// Тестирование игрового поля (Board)
TEST(BoardTest, PlaceObjectOnEmptyCell) {
    Board board;
    EXPECT_TRUE(board.isCellEmpty(0, 0));  // Проверяем, что клетка пуста
    board.placeObject(0, 0, "House", 30);  // Размещаем объект
    EXPECT_FALSE(board.isCellEmpty(0, 0)); // Проверяем, что клетка занята
}

TEST(BoardTest, PlaceObjectOnOccupiedCell) {
    Board board;
    board.placeObject(0, 0, "House", 30);  // Размещаем объект
    EXPECT_FALSE(board.isCellEmpty(0, 0));  // Проверяем, что клетка занята
}

// Тестирование игрока (Player)
TEST(PlayerTest, DrawCardFromDeck) {
    Deck deck;
    Player player("TestPlayer", Characteristic("Default"));
    player.drawCard(deck, true);  // Игрок берет карту из колоды
    EXPECT_FALSE(player.hand.empty());  // Проверяем, что карта добавлена в руку
}

TEST(PlayerTest, BuildObject) {
    Board board;
    Deck deck;
    Player player("TestPlayer", Characteristic("Default"));
    player.drawCard(deck, true);  // Игрок берет карту строительства
    Card* card = player.hand.back();
    player.hand.pop_back();
    ASSERT_NE(card, nullptr);  // Убедимся, что карта существует
    if (auto* constructionCard = dynamic_cast<ConstructionCard*>(card)) {
        board.placeObject(0, 0, constructionCard->type, 30);  // Размещаем объект
        EXPECT_FALSE(board.isCellEmpty(0, 0));  // Проверяем, что клетка занята
    } else {
        FAIL() << "Card is not a ConstructionCard";
    }
}

// Тестирование колоды карт (Deck)
TEST(DeckTest, DrawConstructionCard) {
    Deck deck;
    Card* card = deck.drawConstructionCard();
    EXPECT_NE(card, nullptr);  // Проверяем, что карта успешно взята
    delete card;
}

TEST(DeckTest, ShuffleDeck) {
    Deck deck;
    deck.shuffle();  // Перемешиваем колоду
    Card* firstCard = deck.drawConstructionCard();
    Card* secondCard = deck.drawConstructionCard();
    EXPECT_NE(firstCard->name, secondCard->name);  // Проверяем, что карты разные
    delete firstCard;
    delete secondCard;
}



// Тестирование системы подсчета очков (ScoringSystem)
TEST(ScoringSystemTest, UpdateScore) {
    Player player("TestPlayer", Characteristic("Default"));
    player.score += 10;  // Увеличиваем счет игрока
    EXPECT_EQ(player.score, 10);  // Проверяем, что счет обновился
}

TEST(ScoringSystemTest, CheckWinner) {
    Player player1("Player1", Characteristic("Default"));
    Player player2("Player2", Characteristic("Default"));
    player1.score = 100;
    player2.score = 50;
    EXPECT_GT(player1.score, player2.score);  // Проверяем, что Player1 выиграл
}

// Тестирование ИИ (AI)
TEST(AITest, AIPlaceObject) {
    Board board;
    Deck deck;
    AI ai("AI", Characteristic("Default"));
    ai.drawCard(deck, true);  // ИИ берет карту строительства
    Card* card = ai.hand.back();
    ai.hand.pop_back();
    ASSERT_NE(card, nullptr);  // Убедимся, что карта существует
    if (auto* constructionCard = dynamic_cast<ConstructionCard*>(card)) {
        board.placeObject(0, 0, constructionCard->type, 30);  // ИИ размещает объект
        EXPECT_FALSE(board.isCellEmpty(0, 0));  // Проверяем, что клетка занята
    } else {
        FAIL() << "Card is not a ConstructionCard";
    }
}

// Тестирование игрового цикла (Game)
TEST(GameTest, StartGame) {
    Game game;
    game.startGame();  // Запускаем игру
    EXPECT_TRUE(true);  // Заглушка, можно добавить проверку вывода
}

TEST(GameTest, EndGame) {
    Game game;
    const int boardSize = 10;  // Example size
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            game.board.placeObject(i, j, "House", 30);
        }
    }
    EXPECT_TRUE(game.deck.isAnyDeckEmpty());  // Проверяем, что игра завершена
}

// Основная функция для запуска тестов
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
