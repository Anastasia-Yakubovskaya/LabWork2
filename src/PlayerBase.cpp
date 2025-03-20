/* Yakubovskaya Anastasya st130155@student.spbu.ru LabWork2 */
#include "playerbase.h"

/**
 * @brief Конструктор класса PlayerBase.
 * 
 * Инициализирует базовый класс игрока с указанным именем и характеристикой.
 * 
 * @param name Имя игрока.
 * @param characteristic Характеристика игрока, которая влияет на игровой процесс.
 */
PlayerBase::PlayerBase(const std::string& name, const Characteristic& characteristic)
    : name(name), score(0), characteristic(characteristic) {}
