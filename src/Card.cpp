/* Yakubovskaya Anastasya st130155@student.spbu.ru LabWork2 */
#include "card.h"
#include <iostream>

/**
 * @brief Конструктор карты.
 * 
 * Этот конструктор инициализирует объект карты с заданным именем
 * и описанием.
 * 
 * @param name Имя карты.
 * @param description Описание карты.
 */
Card::Card(const std::string& name, const std::string& description)
    : name(name), description(description) {}

/**
 * @brief Играет карту.
 * 
 * Этот метод выполняет действие, связанное с игрой карты,
 * и выводит информацию о ней на экран.
 * 
 * @param score Ссылка на текущий счет игрока. В данном методе не используется.
 * @param characteristic Ссылка на характеристики, связанные с картой. В данном методе не используется.
 */
void Card::play([[maybe_unused]] int& score, [[maybe_unused]] const Characteristic& characteristic)
{
    std::cout << "Playing card: " << name << " (" << description << ")\n";
}
