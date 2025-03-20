/* Yakubovskaya Anastasya st130155@student.spbu.ru LabWork2 */
#include "graphics.h"
#include <iostream>

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define PURPLE  "\033[35m"

/**
 * @brief Отображает заголовок игры.
 * 
 * Этот метод выводит стилизованный заголовок игры в консоль с использованием 
 * цветного текста. Заголовок оформлен в виде ASCII-арт.
 */
void Graphics::displayTitle()
{
    std::cout << PURPLE << R"(
  ____        _ _     _       __      ___   _     _                  __       _____ 
 |  _ \      (_) |   | |     /  \    |   \ | |   | | __        __   /  \     |  __ \
 | |_) |_   _ _| | __| |    / /\ \   | |\ \| | __| | \ \      / /  / /\ \    | |__) |
 |  _ <| | | | | |/ _` |   / /__\ \  | | \ | |/ _` |  \ \ /\ / /  / /__\ \   |  _  /
 | |_) | |_| | | | (_| |  / _____  \ | |  \  | (_| |   \ V  V /  / _____  \  | | \ \
 |____/ \__,_|_|_|\__,_| /_/      \_\|_|   \_|\__,_|    \_/\_/  /_/      \_\ |_|  \_\
)" << RESET << std::endl;
}

/**
 * @brief Отображает игровое поле.
 * 
 * Этот метод выводит текущее состояние игрового поля в консоль. Каждая ячейка 
 * поля отображается в зависимости от того, занята ли она и какой контент в ней находится.
 * 
 * @param grid Двумерный вектор, представляющий игровое поле, где каждая ячейка 
 * содержит информацию о занятости, контенте и здоровье.
 */
void Graphics::displayBoard(const std::vector<std::vector<Cell>>& grid) {
    for (size_t i = 0; i < grid.size(); ++i) {
        for (size_t j = 0; j < grid[i].size(); ++j) {
            if (grid[i][j].isOccupied) {
                if (grid[i][j].content.back() == '1') {
                    std::cout << GREEN << grid[i][j].content << "(" << grid[i][j].health << ") " << RESET;
                } else if (grid[i][j].content.back() == '2') {
                    std::cout << RED << grid[i][j].content << "(" << grid[i][j].health << ") " << RESET;
                } else {
                    std::cout << grid[i][j].content << "(" << grid[i][j].health << ") ";
                }
            } else {
                std::cout << "* (  ) ";
            }
        }
        std::cout << std::endl;
    }
}
