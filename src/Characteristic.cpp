/* Yakubovskaya Anastasya st130155@student.spbu.ru LabWork2 */
#include "characteristic.h"
#include <iostream>

/**
 * @brief Конструктор характеристики.
 * 
 * Этот конструктор инициализирует объект характеристики с заданным типом.
 * 
 * @param type Тип характеристики, определяющий ее эффект.
 */
Characteristic::Characteristic(const std::string& type) : type(type) {}

/**
 * @brief Применяет эффект характеристики к счету.
 * 
 * Этот метод изменяет счет в зависимости от типа характеристики.
 * В зависимости от типа, эффект может уменьшать урон от стихийных бедствий,
 * снижать стоимость строительства или увеличивать количество получаемых очков.
 * 
 * @param score Ссылка на текущий счет игрока, который будет изменен.
 * @param change Изменение, которое будет применено к счету.
 */
void Characteristic::applyEffect(int& score, int change) const
{
    if (type == "Natural disasters deal 20% less damage")
    {
        std::cout << "Effect: Natural disasters deal 20% less damage.\n";
    }
    else if (type == "Building structures costs 10% less")
    {
        score += static_cast<int>(change * 0.9);
        std::cout << "Effect: Building structures costs 10% less. Score changed by: " << static_cast<int>(change * 0.9) << "\n";
    }
    else if (type == "The player earns 5% more points")
    {
        score += static_cast<int>(change * 1.05);
        std::cout << "Effect: The player earns 5% more points. Score changed by: " << static_cast<int>(change * 1.05) << "\n";
    }
    else
    {
        score += change; // Применяем стандартное изменение
    }
}
