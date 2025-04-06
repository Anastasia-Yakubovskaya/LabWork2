/* Yakubovskaya Anastasya st130155@student.spbu.ru LabWork2 */
#include "bonuscard.h"
#include <iostream>

/**
 * @brief Конструктор карты бонусов.
 * 
 * Этот конструктор инициализирует объект карты бонусов с заданным именем,
 * описанием и типом бонуса.
 * 
 * @param name Имя карты бонусов.
 * @param description Описание карты бонусов.
 * @param bonusType Тип бонуса, связанного с картой.
 */
BonusCard::BonusCard(const std::string& name, const std::string& description, const std::string& bonusType)
    : Card(name, description), bonusType(bonusType) {}

/**
 * @brief Играет бонусную карту.
 * 
 * Этот метод выполняет действие, связанное с игрой бонусной карты.
 * В данном случае он просто выводит информацию о карте на экран.
 * 
 * @param score Ссылка на текущий счет игрока. В данном методе не используется.
 * @param characteristic Ссылка на характеристики, связанные с картой. В данном методе не используется.
 */
void BonusCard::play(int& score, const Characteristic& characteristic)
{
    (void)score;          // Игнорируем параметр score
    (void)characteristic; // Игнорируем параметр characteristic
    std::cout << "Playing bonus card: " << name << " (" << description << ")\n";
}
