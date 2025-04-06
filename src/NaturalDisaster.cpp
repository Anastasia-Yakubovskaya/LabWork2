/* Yakubovskaya Anastasya st130155@student.spbu.ru LabWork2 */
#include "naturaldisaster.h"
#include <iostream>

/**
 * @brief Конструктор класса NaturalDisaster.
 * 
 * Инициализирует карту природного бедствия с указанным типом и уроном.
 * 
 * @param type Тип природного бедствия (например, "Earthquake", "Flood").
 * @param damage Урон, который наносит бедствие зданиям.
 */
NaturalDisaster::NaturalDisaster(const std::string& type, int damage)
    : EventCard("Natural Disaster", "Deals damage to buildings.", "Damage"), type(type), damage(damage) {}

/**
 * @brief Активирует эффект природного бедствия.
 * 
 * Этот метод наносит урон всем зданиям на игровом поле, принадлежащим указанному игроку.
 * Урон применяется только к тем ячейкам, которые содержат префикс игрока.
 * 
 * @param board Игровое поле, на котором находятся здания.
 * @param score Счет игрока (не используется в данном методе).
 * @param characteristic Характеристика игрока (не используется в данном методе).
 * @param playerPrefix Префикс игрока, определяющий принадлежность зданий (например, "1" для игрока, "2" для ИИ).
 */
void NaturalDisaster::trigger(Board& board, [[maybe_unused]] int& score, [[maybe_unused]] const Characteristic& characteristic, const std::string& playerPrefix)
{
    std::cout << "Triggering natural disaster: " << type << " (Damage: " << damage << ")\n";
    for (int i = 0; i < Board::size; ++i)
    {
        for (int j = 0; j < Board::size; ++j)
        {
            if (board.grid[i][j].content.find(playerPrefix) != std::string::npos)
            {
                board.grid[i][j].takeDamage(damage);
                std::cout << "Building at cell (" << i << ", " << j << ") has taken damage.\n";
            }
        }
    }
}
