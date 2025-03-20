/* Yakubovskaya Anastasya st130155@student.spbu.ru LabWork2 */
#include "economicevent.h"
#include <iostream>

/**
 * @brief Конструктор экономического события.
 * 
 * Этот конструктор инициализирует объект экономического события с заданным типом и воздействием.
 * 
 * @param type Тип экономического события.
 * @param impact Воздействие события на характеристики игрока.
 */
EconomicEvent::EconomicEvent(const std::string& type, const std::string& impact)
    : EventCard("Economic Event", "Affects the player's score.", impact), type(type), impact(impact) {}

/**
 * @brief Активирует экономическое событие.
 * 
 * Этот метод применяет эффект экономического события к счету игрока в зависимости от его воздействия.
 * 
 * @param score Ссылка на счет игрока, который будет изменен в результате события.
 * @param characteristic Объект, представляющий характеристики игрока, на которые будет оказано влияние.
 */
void EconomicEvent::trigger(int& score, const Characteristic& characteristic)
{
    std::cout << "Triggering economic event: " << type << " (" << impact << ")\n";
    if (impact == "Default")
    {
        characteristic.applyEffect(score, -25);
    }
    else if (impact == "Crisis")
    {
        characteristic.applyEffect(score, -50);
    }
}
