#include "game.h"
#include "player.h"
#include "ai.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "graphics.h"  // Добавлено для использования макросов YELLOW и RESET
#include "utils.h"  
#include "ConstructionCard.h"  // Для ConstructionCard
#include "NaturalDisaster.h"   // Для NaturalDisaster
#include "EconomicEvent.h"     // Для EconomicEvent
#include "PoliticalEvent.h"    // Для PoliticalEvent
#include "VarEvent.h"          // Для VarEvent
#include "TradeEvent.h"        // Для TradeEvent
#include "StealCardEvent.h" 

int main() {
    srand(static_cast<unsigned int>(time(0)));

    Game game;
    std::string playerName;

    std::cout << "Enter player name: ";
    std::cin >> playerName;

    std::vector<std::string> characteristics = {
        "Natural disasters deal 20% less damage",
        "Building structures costs 10% less",
        "The player earns 5% more points"
    };

    std::cout << "Choose a characteristic for the player:\n";
    for (size_t i = 0; i < characteristics.size(); ++i) {
        std::cout << i + 1 << ". " << characteristics[i] << "\n";
    }
    int choice;
    std::cin >> choice;

    Characteristic playerCharacteristic("");
    if (choice >= 1 && static_cast<size_t>(choice) <= characteristics.size()) {
        playerCharacteristic = Characteristic(characteristics[choice - 1]);
    } else {
        std::cout << "Invalid choice. No characteristic selected.\n";
    }

    int aiChoice = rand() % characteristics.size();
    Characteristic aiCharacteristic(characteristics[aiChoice]);
    std::cout << "AI has chosen the characteristic: " << characteristics[aiChoice] << "\n";

    Player player(playerName, playerCharacteristic);
    AI ai("AI", aiCharacteristic);

    game.startGame();

    clearConsole();

    while (true) {
        if (game.deck.isAnyDeckEmpty()) {
            std::cout << "One of the decks is empty. The game is over.\n";
            break;
        }

        Graphics::displayTitle();
        std::cout << "\nCurrent board state:\n";
        game.board.display();

        std::cout << YELLOW << "\n--- Player's Turn ---\n" << RESET;

        player.drawCard(game.deck, true);
        player.showHand();

        if (!player.hand.empty()) {
            Card* card = player.hand.back();
            player.hand.pop_back();

            if (auto* constructionCard = dynamic_cast<ConstructionCard*>(card)) {
                std::cout << "Drew a construction card: " << constructionCard->type << "\n";
                std::cout << "Do you want to build an object? (1 - Yes, 0 - No): ";
                int buildChoice;
                std::cin >> buildChoice;

                if (buildChoice == 1) {
                    constructionCard->play(player.score, player.characteristic);

                    int x, y;
                    std::cout << "Enter coordinates (x y) to place the object (or 0 to exit): ";
                    std::cin >> x;

                    if (x == 0) {
                        std::cout << "Game over.\n";
                        delete card;
                        break;
                    }

                    std::cin >> y;

                    if (x >= 0 && x < Board::size && y >= 0 && y < Board::size) {
                        if (game.board.isCellEmpty(x, y)) {
                            int health = 0;
                            if (constructionCard->type == "House") {
                                health = 30;
                            } else if (constructionCard->type == "Tree") {
                                health = 40;
                            } else if (constructionCard->type == "Water") {
                                health = 50;
                            }
                            std::string object = constructionCard->type.substr(0, 1) + "1";
                            game.board.placeObject(x, y, object, health);
                        } else {
                            std::cout << "Cell is occupied! Try another one.\n";
                        }
                    } else {
                        std::cout << "Invalid coordinates. Object not placed.\n";
                    }
                } else {
                    std::cout << "Player chose not to build an object.\n";
                }
            }
            delete card;
        }

        player.drawCard(game.deck, false);
        player.showHand();

        if (!player.hand.empty()) {
            Card* card = player.hand.back();
            player.hand.pop_back();

            if (auto* eventCard = dynamic_cast<EventCard*>(card)) {
                eventCard->play(player.score, player.characteristic);

                int diceResult1 = game.dice.roll();
                std::cout << "First dice roll result: " << diceResult1 << "\n";

                int diceResult2 = game.dice.roll();
                std::cout << "Second dice roll result: " << diceResult2 << "\n";

                if (diceResult1 >= 5) {
                    std::cout << "Lucky! Player gets a bonus.\n";
                } else {
                    std::cout << "Unlucky! Player loses points or buildings take damage.\n";
                }

                if (diceResult2 >= 5) {
                    std::cout << "Player gets a bonus card.\n";
                    player.drawBonusCard(game.deck);

                    if (!player.hand.empty()) {
                        Card* bonusCard = player.hand.back();
                        player.hand.pop_back();

                        std::cout << "Do you want to use the bonus card? (1 - Yes, 0 - No): ";
                        int useBonusChoice;
                        std::cin >> useBonusChoice;

                        if (useBonusChoice == 1) {
                            if (auto* varEvent = dynamic_cast<VarEvent*>(bonusCard)) {
                                varEvent->target = &ai;
                                varEvent->trigger();
                            } else if (auto* stealCardEvent = dynamic_cast<StealCardEvent*>(bonusCard)) {
                                stealCardEvent->target = &ai;
                                stealCardEvent->trigger(game.board, &player);
                            } else if (auto* tradeEvent = dynamic_cast<TradeEvent*>(bonusCard)) {
                                tradeEvent->target = &ai;
                                tradeEvent->trigger(game.board);
                            }
                        } else {
                            std::cout << "Player chose not to use the bonus card.\n";
                        }

                        delete bonusCard;
                    } else {
                        std::cout << "Player has no bonus cards to use.\n";
                    }
                } else {
                    std::cout << "Unlucky! Player does not get a bonus card.\n";
                }
            }
            delete card;
        }

        std::cout << YELLOW << "\n--- AI's Turn ---\n" << RESET;

        ai.drawCard(game.deck, true);
        ai.showHand();

        if (!ai.hand.empty()) {
            Card* card = ai.hand.back();
            ai.hand.pop_back();

            if (auto* constructionCard = dynamic_cast<ConstructionCard*>(card)) {
                std::cout << "AI drew a construction card: " << constructionCard->type << "\n";
                int x, y;
                do {
                    x = rand() % Board::size;
                    y = rand() % Board::size;
                } while (!game.board.isCellEmpty(x, y));

                int health = 0;
                if (constructionCard->type == "House") {
                    health = 30;
                } else if (constructionCard->type == "Tree") {
                    health = 40;
                } else if (constructionCard->type == "Water") {
                    health = 50;
                }
                std::string object = constructionCard->type.substr(0, 1) + "2";
                game.board.placeObject(x, y, object, health);
            }
            delete card;
        }

        ai.drawCard(game.deck, false);
        ai.showHand();

        if (!ai.hand.empty()) {
            Card* card = ai.hand.back();
            ai.hand.pop_back();

            if (auto* eventCard = dynamic_cast<EventCard*>(card)) {
                eventCard->play(ai.score, ai.characteristic);

                int diceResult1 = game.dice.roll();
                std::cout << "AI's first dice roll result: " << diceResult1 << "\n";

                int diceResult2 = game.dice.roll();
                std::cout << "AI's second dice roll result: " << diceResult2 << "\n";

                if (diceResult1 >= 5) {
                    std::cout << "Lucky! AI gets a bonus.\n";
                } else {
                    std::cout << "Unlucky! AI loses points or buildings take damage.\n";
                }

                if (diceResult2 >= 5) {
                    std::cout << "AI gets a bonus card.\n";
                    ai.drawBonusCard(game.deck);

                    if (!ai.hand.empty()) {
                        Card* bonusCard = ai.hand.back();
                        ai.hand.pop_back();

                        if (auto* stealCardEvent = dynamic_cast<StealCardEvent*>(bonusCard)) {
                            stealCardEvent->target = &player;
                            stealCardEvent->trigger(game.board, &ai);
                        } else {
                            std::cout << "AI uses the bonus card: " << bonusCard->name << "\n";
                            if (auto* varEvent = dynamic_cast<VarEvent*>(bonusCard)) {
                                varEvent->target = &player;
                                varEvent->trigger();
                            } else if (auto* tradeEvent = dynamic_cast<TradeEvent*>(bonusCard)) {
                                tradeEvent->target = &player;
                                tradeEvent->trigger(game.board);
                            }
                        }

                        delete bonusCard;
                    } else {
                        std::cout << "AI has no bonus cards to use.\n";
                    }
                } else {
                    std::cout << "Unlucky! AI does not get a bonus card.\n";
                }
            }
            delete card;
        }

        std::cout << "\nPress Enter to continue...";
        std::cin.ignore();
        std::cin.get();

        clearConsole();
    }

    int playerFinalScore = game.board.calculateFinalScore("1");
    int aiFinalScore = game.board.calculateFinalScore("2");

    std::cout << "\n--- Final Scores ---\n";
    std::cout << player.name << ": " << playerFinalScore << " points\n";
    std::cout << ai.name << ": " << aiFinalScore << " points\n";

    if (playerFinalScore > aiFinalScore) {
        std::cout << "Congratulations, " << player.name << " wins!\n";
    } else if (playerFinalScore < aiFinalScore) {
        std::cout << ai.name << " wins. Try again!\n";
    } else {
        std::cout << "It's a tie! Both players have the same score.\n";
    }

    return 0;
}
