#ifndef TRADEEVENT_H
#define TRADEEVENT_H

#include "bonuscard.h"
#include "playerbase.h"
#include "board.h"

/**
 * @class TradeEvent
 * @brief Класс, представляющий событие торговли.
 *
 * Этот класс наследует от класса BonusCard и представляет
 * событие, при котором игрок может обмениваться ресурсами
 * с другим игроком.
 */
class TradeEvent : public BonusCard {
public:
    /// Указатель на игрока, с которым будет осуществлена торговля.
    PlayerBase* target;

    /// Ресурс, который будет обменен.
    std::string resource;

    /**
     * @brief Конструктор класса TradeEvent.
     * 
     * Этот конструктор инициализирует событие торговли с заданным
     * именем, описанием, целью торговли и ресурсом.
     * 
     * @param name Имя события торговли.
     * @param description Описание события торговли.
     * @param target Указатель на игрока, с которым будет осуществлена торговля.
     * @param resource Ресурс, который будет обменен.
     */
    TradeEvent(const std::string& name, const std::string& description, PlayerBase* target, const std::string& resource);

    /**
     * @brief Активирует событие торговли.
     * 
     * Этот метод выполняет логику торговли между текущим игроком
     * и целевым игроком, обновляя состояние игры на доске.
     * 
     * @param board Ссылка на игровую доску, на которой происходит событие.
     */
    void trigger(Board& board);
};

#endif // TRADEEVENT_H
