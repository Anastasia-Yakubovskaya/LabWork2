#ifndef STEALCARDEVENT_H
#define STEALCARDEVENT_H

#include "bonuscard.h"
#include "playerbase.h"
#include "board.h"

/**
 * @class StealCardEvent
 * @brief Класс, представляющий событие кражи карты.
 *
 * Этот класс наследует от класса BonusCard и представляет
 * событие, при котором игрок может украсть карту у другого игрока.
 */
class StealCardEvent : public BonusCard {
public:
    /// Указатель на игрока, у которого будет украдена карта.
    PlayerBase* target;

    /// Указатель на украденную карту.
    Card* stolenCard;

    /**
     * @brief Конструктор класса StealCardEvent.
     * 
     * Этот конструктор инициализирует событие кражи карты с заданным
     * именем, описанием и целью кражи.
     * 
     * @param name Имя события кражи карты.
     * @param description Описание события кражи карты.
     * @param target Указатель на игрока, у которого будет украдена карта.
     */
    StealCardEvent(const std::string& name, const std::string& description, PlayerBase* target);

    /**
     * @brief Активирует событие кражи карты.
     * 
     * Этот метод выполняет логику кражи карты у целевого игрока
     * и обновляет состояние игры на доске.
     * 
     * @param board Ссылка на игровую доску, на которой происходит событие.
     * @param currentPlayer Указатель на текущего игрока, который инициирует событие.
     */
    void trigger(Board& board, PlayerBase* currentPlayer);
};

#endif // STEALCARDEVENT_H
