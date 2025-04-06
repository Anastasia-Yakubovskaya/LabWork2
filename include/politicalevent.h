#ifndef POLITICALEVENT_H
#define POLITICALEVENT_H

#include "eventcard.h"
#include "board.h"

/**
 * @class PoliticalEvent
 * @brief Класс, представляющий политическое событие.
 *
 * Этот класс наследует от класса EventCard и представляет
 * карту события, связанного с политическими изменениями,
 * которые могут оказать влияние на игру.
 */
class PoliticalEvent : public EventCard {
public:
    /// Тип политического события.
    std::string type;

    /// Влияние политического события.
    std::string impact;

    /**
     * @brief Конструктор класса PoliticalEvent.
     * 
     * Этот конструктор инициализирует тип политического события
     * и его влияние.
     * 
     * @param type Тип политического события.
     * @param impact Влияние, оказываемое политическим событием.
     */
    PoliticalEvent(const std::string& type, const std::string& impact);

    /**
     * @brief Активирует политическое событие.
     * 
     * Этот метод применяет эффект политического события к игровому
     * полю и обновляет счет игрока.
     * 
     * @param board Ссылка на игровую доску, к которой будет применено событие.
     * @param score Ссылка на счет игрока, который может быть изменен.
     * @param characteristic Характеристика, к которой будет применен эффект.
     * @param playerPrefix Префикс игрока, для отображения информации.
     */
    void trigger(Board& board, int& score, const Characteristic& characteristic, const std::string& playerPrefix);
};

#endif // POLITICALEVENT_H
