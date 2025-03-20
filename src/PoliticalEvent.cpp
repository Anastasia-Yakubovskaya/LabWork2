/* Yakubovskaya Anastasya st130155@student.spbu.ru LabWork2 */
#include "politicalevent.h"
#include <iostream>

/**
 * @brief Конструктор класса PoliticalEvent.
 * 
 * Инициализирует карту политического события с указанным типом и эффектом.
 * 
 * @param type Тип политического события (например, "Election", "Policy Change").
 * @param impact Описание эффекта события (например, "Reduces score by 25 points").
 */
PoliticalEvent::PoliticalEvent(const std::string& type, const std::string& impact)
    : EventCard("Political Event", "Affects all buildings and the score.", impact), type(type), impact(impact) {}

/**
 * @brief Активирует эффект политического события.
 * 
 * Этот метод применяет эффект политического события ко всем зданиям на игровом поле,
 * принадлежащим указанному игроку, и изменяет счет игрока в зависимости от его характеристики.
 * 
 * @param board Игровое поле, на котором находятся здания.
 * @param score Счет игрока, который будет изменен в зависимости от эффекта события.
 * @param characteristic Характеристика игрока, которая влияет на применение эффекта.
 * @param playerPrefix Префикс игрока, определяющий принадлежность зданий (например, "1" для игрока, "2" для ИИ).
 */
void PoliticalEvent::trigger(Board& board, int& score, const Characteristic& characteristic, const std::string& playerPrefix)
{
    std::cout << "Triggering political event: " << type << " (" << impact << ")\n";
    for (int i = 0; i < Board::size; ++i)
    {
        for (int j = 0; j < Board::size; ++j)
        {
            if (board.grid[i][j].content.find(playerPrefix) != std::string::npos)
            {
                board.grid[i][j].takeDamage(10);
                std::cout << "Building at cell (" << i << ", " << j << ") has been affected.\n";
            }
        }
    }
    characteristic.applyEffect(score, 25);
}
