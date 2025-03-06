#include "Game.h"
#include <iostream>
#include <cstdlib>

void Game::chooseCharacteristics(Player& player, AI& ai) {
    std::vector<std::string> characteristics = {
        "Natural disasters deal 20% less damage",
        "Building structures costs 10% less",
        "The player earns 5% more points"
    };

    std::cout << "Выберите характеристику для игрока:\n";
    for (size_t i = 0; i < characteristics.size(); ++i) {
        std::cout << i + 1 << ". " << characteristics[i] << "\n";
    }
    int choice;
    std::cin >> choice;

    if (choice >= 1 && choice <= characteristics.size()) {
        player.characteristic = Characteristic(characteristics[choice - 1]);
    } else {
        std::cout << "Неверный выбор. Характеристика не выбрана.\n";
    }

    int aiChoice = rand() % characteristics.size();
    ai.characteristic = Characteristic(characteristics[aiChoice]);
    std::cout << ai.name << " выбрал характеристику: " << characteristics[aiChoice] << "\n";
}

void Game::startGame() {
    std::cout << "Игра началась!" << std::endl;
}
