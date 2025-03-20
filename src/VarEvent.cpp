/* Yakubovskaya Anastasya st130155@student.spbu.ru LabWork2 */
#include "varevent.h"
#include <iostream>

/**
 * @brief Конструктор класса VarEvent.
 * 
 * Инициализирует карту события с переменным эффектом (VarEvent) с указанным названием,
 * описанием, целью и уроном.
 * 
 * @param name Название карты (например, "Var Event").
 * @param description Описание карты (например, "Decreases target player's score").
 * @param target Указатель на игрока, который является целью события.
 * @param damage Урон, который наносится счету целевого игрока.
 */
VarEvent::VarEvent(const std::string& name, const std::string& description, PlayerBase* target, int damage)
    : BonusCard(name, description, "VarEvent"), target(target), damage(damage) {}

/**
 * @brief Активирует эффект карты VarEvent.
 * 
 * Этот метод уменьшает счет целевого игрока на указанное значение урона.
 * Если цель не установлена, выводится сообщение об ошибке.
 */
void VarEvent::trigger()
{
    std::cout << "Triggering VarEvent: " << name << " (Damage: " << damage << ")\n";
    if (target)
    {
        target->score -= damage;
        std::cout << "Player " << target->name << "'s score decreased by " << damage << ".\n";
    }
    else
    {
        std::cout << "Target not set.\n";
    }
}
