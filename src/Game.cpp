/*Yakubovskaya Anastasya st130155@student.spbu.ru LabWork2*/
#include "game.h"
#include "constructioncard.h"
#include "naturaldisaster.h"
#include "economicevent.h"
#include "politicalevent.h"
#include "varevent.h"
#include "tradeevent.h"
#include "stealcardevent.h"

Game::Game()
{
    // Добавление карт в колоду
    for (int i = 0; i < 5; ++i)
    {
        deck.addCard(new ConstructionCard("House", -5));
        deck.addCard(new ConstructionCard("Tree", -3));
        deck.addCard(new ConstructionCard("Water", -10));
        deck.addCard(new NaturalDisaster("Flood", 10));
        deck.addCard(new NaturalDisaster("Earthquake", 15));
        deck.addCard(new NaturalDisaster("Drought", 20));
        deck.addCard(new EconomicEvent("Default", "Decreases score by 25"));
        deck.addCard(new EconomicEvent("Crisis", "Decreases score by 50"));
        deck.addCard(new PoliticalEvent("Revolution", "Affects all buildings and score"));
        deck.addCard(new VarEvent("Score Reduction", "Reduces opponent's score", nullptr, 10));
        deck.addCard(new TradeEvent("Building Exchange", "Exchanges buildings with opponent", nullptr, "Resource"));
        deck.addCard(new StealCardEvent("Card Steal", "Steals a card from opponent", nullptr));
    }
    deck.shuffle();
}

void Game::startGame()
{
    std::cout << "The game has started!" << std::endl;
}
