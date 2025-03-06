#include <iostream> // Добавьте этот заголовочный файл
#include <ctime>
#include "Game.h"

int main() {
    srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел

    Game game;
    std::string playerName;

    std::cout << "Введите имя игрока: ";
    std::cin >> playerName;

    Player player(playerName, Characteristic("")); // Создаем игрока
    AI ai("ИИ", Characteristic("")); // Создаем ИИ

    game.chooseCharacteristics(player, ai); // Выбор характеристик

    game.startGame(); // Начинаем игру
    game.board.display(); // Отображаем игровое поле

    // Игровой цикл
    while (true) {
        // Ход игрока
        int x, y;
        std::cout << "Введите координаты (x y) для размещения дома (или 0 для выхода): ";
        std::cin >> x;

        if (x == 0) {
            std::cout << "Игра завершена." << std::endl;
            break; // Выход из игры
        }

        std::cin >> y; // Ввод y после проверки x

        player.chooseCell(x, y, game.board); // Игрок размещает дом
        game.board.display(); // Отображаем игровое поле

        // Выводим текущие очки
        game.scoringSystem.updateScore(player, 10); // Обновляем очки игрока
        game.scoringSystem.updateScore(ai, 10); // Обновляем очки ИИ
        game.scoringSystem.displayScores(player, ai); // Отображаем очки

        // Ход ИИ
        ai.chooseCell(game.board); // ИИ размещает дом
        game.board.display(); // Отображаем игровое поле

        // Выводим текущие очки
        game.scoringSystem.displayScores(player, ai); // Отображаем очки
    }

    return 0; // Завершение программы
}
