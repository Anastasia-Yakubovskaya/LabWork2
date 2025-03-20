#ifndef VAREVENT_H
#define VAREVENT_H

#include "bonuscard.h"
#include "playerbase.h"

/**
 * @class VarEvent
 * @brief Класс, представляющий событие с переменной величиной.
 *
 * Этот класс наследует от класса BonusCard и представляет
 * событие, которое может нанести урон целевому игроку.
 */
class VarEvent : public BonusCard {
public:
    /// Указатель на игрока, который является целью события.
    PlayerBase* target;

    /// Урон, который будет нанесен целевому игроку.
    int damage;

    /**
     * @brief Конструктор класса VarEvent.
     * 
     * Этот конструктор инициализирует событие с заданным
     * именем, описанием, целью и величиной урона.
     * 
     * @param name Имя события.
     * @param description Описание события.
     * @param target Указатель на игрока, который является целью события.
     * @param damage Величина урона, который будет нанесен.
     */
    VarEvent(const std::string& name, const std::string& description, PlayerBase* target, int damage);

    /**
     * @brief Активирует событие.
     * 
     * Этот метод выполняет логику события, нанося урон
     * целевому игроку.
     */
    void trigger();
};

#endif // VAREVENT_H
