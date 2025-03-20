/* Yakubovskaya Anastasya st130155@student.spbu.ru LabWork2 */
#include "eventcard.h"
#include <iostream>

/**
 * @brief Конструктор карты события.
 * 
 * Этот конструктор инициализирует объект карты события с заданным именем, описанием и эффектом.
 * 
 * @param name Имя карты события.
 * @param description Описание карты события.
 * @param effect Эффект, который будет применен при использовании карты.
 */
EventCard::EventCard(const std::string& name, const std::string& description, const std::string& effect)
    : Card(name, description), effect(effect) {}

/**
 * @brief Играет карту события.
 * 
 * Этот метод выполняет действие карты события, выводя информацию о ней.
 * 
 * @param score Ссылка на счет игрока, который может быть изменен в результате действия карты.
 * @param characteristic Объект, представляющий характеристики игрока, которые могут быть затронуты.
 */
void EventCard::play(int& score, const Characteristic& characteristic)
{
    (void)score;          // Убираем предупреждение о неиспользуемой переменной
    (void)characteristic; // Убираем предупреждение о неиспользуемой переменной
    std::cout << "Playing event card: " << name << " (" << description << ")\n";
}
