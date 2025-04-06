/* Yakubovskaya Anastasya st130155@student.spbu.ru LabWork2 */
#include "stealcardevent.h"
#include <iostream>

/**
 * @brief Конструктор класса StealCardEvent.
 * 
 * Инициализирует карту события кражи с указанным названием, описанием и целью.
 * 
 * @param name Название карты (например, "Steal Card").
 * @param description Описание карты (например, "Steals an object from the opponent").
 * @param target Указатель на игрока, у которого будет украден объект.
 */
StealCardEvent::StealCardEvent(const std::string& name, const std::string& description, PlayerBase* target)
    : BonusCard(name, description, "StealCardEvent"), target(target), stolenCard(nullptr) {}

/**
 * @brief Активирует эффект карты кражи.
 * 
 * Этот метод позволяет текущему игроку украсть объект у целевого игрока.
 * Объект выбирается случайным образом из всех объектов целевого игрока на игровом поле.
 * 
 * @param board Игровое поле, на котором находятся объекты.
 * @param currentPlayer Указатель на текущего игрока, который активирует карту.
 */
void StealCardEvent::trigger(Board& board, PlayerBase* currentPlayer)
{
    std::cout << "Triggering StealCardEvent: " << name << "\n";
    if (target)
    {
        std::vector<std::pair<int, int>> buildings;
        for (int i = 0; i < Board::size; ++i)
        {
            for (int j = 0; j < Board::size; ++j)
            {
                if (board.grid[i][j].content.find(target->name) != std::string::npos)
                {
                    buildings.push_back({i, j});
                }
            }
        }

        if (!buildings.empty())
        {
            int index = rand() % buildings.size();
            int x = buildings[index].first;
            int y = buildings[index].second;
            std::string object = board.grid[x][y].content;
            object[object.size() - 1] = (target == currentPlayer) ? '2' : '1';
            board.grid[x][y].content = object;
            std::cout << "Object at cell (" << x << ", " << y << ") has been transferred to " << name << ".\n";
        }
        else
        {
            std::cout << "The opponent has no objects to steal.\n";
        }
    }
    else
    {
        std::cout << "Target not set.\n";
    }
}
