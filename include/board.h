#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include "cell.h"
#include "graphics.h" 
#include <iostream>

/**
 * @class Board
 * @brief Класс, представляющий игровое поле.
 *
 * Этот класс управляет игровым полем, состоящим из сетки ячеек,
 * и предоставляет методы для размещения объектов, проверки состояния ячеек
 * и отображения поля.
 */
class Board {
public:
    /// Размер игрового поля (10x10).
    static const int size = 10;

    /// Двумерный вектор, представляющий сетку ячеек.
    std::vector<std::vector<Cell>> grid;

    /**
     * @brief Конструктор класса Board.
     * 
     * Инициализирует игровое поле, создавая сетку ячеек.
     */
    Board();

    /**
     * @brief Размещает объект на игровом поле.
     * 
     * Этот метод позволяет разместить объект в указанной ячейке
     * с заданным уровнем здоровья.
     * 
     * @param x Координата по оси X для размещения объекта.
     * @param y Координата по оси Y для размещения объекта.
     * @param object Имя объекта, который будет размещен.
     * @param health Здоровье объекта.
     */
    void placeObject(int x, int y, const std::string& object, int health);

    /**
     * @brief Проверяет, пуста ли ячейка.
     * 
     * Этот метод проверяет, есть ли объект в указанной ячейке.
     * 
     * @param x Координата по оси X ячейки.
     * @param y Координата по оси Y ячейки.
     * @return true Если ячейка пуста.
     * @return false Если ячейка занята.
     */
    bool isCellEmpty(int x, int y);

    /**
     * @brief Отображает игровое поле.
     * 
     * Этот метод выводит текущее состояние игрового поля на экран.
     */
    void display();

    /**
     * @brief Вычисляет финальный счет игрока.
     * 
     * Этот метод рассчитывает финальный счет для игрока
     * на основе его зданий.
     * 
     * @param playerPrefix Префикс имени игрока для идентификации.
     * @return Итоговый счет игрока.
     */
    int calculateFinalScore(const std::string& playerPrefix);

    /**
     * @brief Украсть здание у другого игрока.
     * 
     * Этот метод позволяет одному игроку украсть здание у другого.
     * 
     * @param fromPrefix Префикс имени игрока, у которого будет украдено здание.
     * @param toPrefix Префикс имени игрока, который украдет здание.
     */
    void stealBuilding(const std::string& fromPrefix, const std::string& toPrefix);

    /**
     * @brief Обменять все здания между двумя игроками.
     * 
     * Этот метод позволяет двум игрокам обменяться всеми своими зданиями.
     * 
     * @param player1Prefix Префикс имени первого игрока.
     * @param player2Prefix Префикс имени второго игрока.
     */
    void exchangeAllBuildings(const std::string& player1Prefix, const std::string& player2Prefix);
};

#endif // BOARD_H
