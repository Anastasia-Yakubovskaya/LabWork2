/*Yakubovskaya Anastasya st130155@student.spbu.ru LabWork2*/
#include "tradeevent.h"
#include <iostream>

/**
 * @brief Конструктор класса TradeEvent.
 * 
 * Инициализирует карту события обмена с указанным названием, описанием, целью и ресурсом.
 * 
 * @param name Название карты (например, "Trade Event").
 * @param description Описание карты (например, "Exchanges buildings between players").
 * @param target Указатель на игрока, с которым происходит обмен.
 * @param resource Ресурс, участвующий в обмене (например, "Wood", "Stone").
 */

TradeEvent::TradeEvent(const std::string& name, const std::string& description, PlayerBase* target, const std::string& resource)
    : BonusCard(name, description, "TradeEvent"), target(target), resource(resource) {}

void TradeEvent::trigger( [[maybe_unused]] Board& board)
{
    std::cout << "Triggering TradeEvent: " << name << " (Resource: " << resource << ")\n";
    std::cout << "Players have exchanged buildings.\n";
}
