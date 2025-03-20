#ifndef EVENTCARD_H
#define EVENTCARD_H

#include "card.h"

/**
 * @class EventCard
 * @brief Класс, представляющий карту события.
 *
 * Этот класс наследует от класса Card и представляет
 * карту события с определенным эффектом, который может
 * быть применен в игре.
 */
class EventCard : public Card {
public:
    /// Эффект карты события.
    std::string effect; 

    /**
     * @brief Конструктор класса EventCard.
     * 
     * Этот конструктор инициализирует имя, описание и эффект
     * карты события.
     * 
     * @param name Имя карты.
     * @param description Описание карты.
     * @param effect Эффект карты события.
     */
    EventCard(const std::string& name, const std::string& description, const std::string& effect);

    /**
     * @brief Применяет эффект карты события.
     * 
     * Этот метод переопределяет метод play из базового класса Card
     * и применяет эффект карты события к указанному счету и характеристике.
     * 
     * @param score Ссылка на счет, который будет изменен.
     * @param characteristic Характеристика, к которой будет применен эффект.
     */
    void play(int& score, const Characteristic& characteristic) override; // Переопределение метода play
};

#endif // EVENTCARD_H
