#ifndef ECONOMICEVENT_H
#define ECONOMICEVENT_H

#include "eventcard.h"

/**
 * @class EconomicEvent
 * @brief Класс, представляющий экономическое событие.
 *
 * Этот класс наследует от класса EventCard и представляет
 * экономическое событие с определенным типом и воздействием.
 */
class EconomicEvent : public EventCard {
public:
    /// Тип экономического события.
    std::string type;
    
    /// Воздействие экономического события.
    std::string impact;

    /**
     * @brief Конструктор класса EconomicEvent.
     * 
     * Этот конструктор инициализирует тип и воздействие
     * экономического события.
     * 
     * @param type Тип экономического события.
     * @param impact Воздействие экономического события.
     */
    EconomicEvent(const std::string& type, const std::string& impact);

    /**
     * @brief Активирует экономическое событие.
     * 
     * Этот метод применяет воздействие экономического события
     * к указанному счету и характеристике.
     * 
     * @param score Ссылка на счет, который будет изменен.
     * @param characteristic Характеристика, к которой будет применено воздействие.
     */
    void trigger(int& score, const Characteristic& characteristic);
};

#endif // ECONOMICEVENT_H
