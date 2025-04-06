#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <vector>
#include "cell.h"

// Определения цветовых кодов для консольного вывода
#define RESET   "\033[0m"    ///< Сброс цвета
#define GREEN   "\033[32m"   ///< Зеленый цвет
#define RED     "\033[31m"   ///< Красный цвет
#define YELLOW  "\033[33m"   ///< Желтый цвет
#define PURPLE  "\033[35m"   ///< Пурпурный цвет

/**
 * @class Graphics
 * @brief Класс для отображения графики в консоли.
 *
 * Этот класс предоставляет статические методы для отображения
 * заголовка игры и игрового поля в консольном интерфейсе.
 */
class Graphics {
public:
    /**
     * @brief Отображает заголовок игры.
     * 
     * Этот метод выводит заголовок игры в консоль с использованием
     * цветового оформления.
     */
    static void displayTitle();

    /**
     * @brief Отображает игровое поле.
     * 
     * Этот метод выводит текущее состояние игрового поля в консоль.
     * 
     * @param grid Двумерный вектор, представляющий игровое поле,
     *             состоящее из объектов Cell.
     */
    static void displayBoard(const std::vector<std::vector<Cell>>& grid);
};

#endif // GRAPHICS_H
