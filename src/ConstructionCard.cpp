/* Yakubovskaya Anastasya st130155@student.spbu.ru LabWork2 */
#include "constructioncard.h"
#include <iostream>

/**
 * @brief Конструктор строительной карты.
 * 
 * Этот конструктор инициализирует объект строительной карты с заданным типом
 * и изменением счета. Строительная карта позволяет строить объекты на игровом поле.
 * 
 * @param type Тип строительной карты, представляющий строящийся объект.
 * @param scoreChange Изменение счета, связанное с использованием этой карты.
 */
ConstructionCard::ConstructionCard(const std::string& type, int scoreChange)
    : Card("Construction Card", "Allows you to build an object on the board."), type(type), scoreChange(scoreChange) {}

/**
 * @brief Играет строительную карту.
 * 
 * Этот метод применяет эффект строительной карты, изменяя счет игрока
 * в зависимости от типа карты и характеристик, связанных с ней.
 * 
 * @param score Ссылка на текущий счет игрока, который будет изменен.
 * @param characteristic Характеристика, которая будет применена к счету.
 */
void ConstructionCard::play(int& score, const Characteristic& characteristic)
{
    std::cout << "Built object: " << type << " (Score change: " << scoreChange << ")\n";
    characteristic.applyEffect(score, scoreChange);
}
