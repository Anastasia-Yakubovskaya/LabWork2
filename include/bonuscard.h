#ifndef BONUSCARD_H
#define BONUSCARD_H

#include "card.h"

/**
 * @class BonusCard
 * @brief Класс, представляющий бонусную карту.
 *
 * Этот класс наследует от Card и представляет бонусные карты,
 * которые могут быть использованы игроками для получения различных
 * преимуществ в игре.
 */
class BonusCard : public Card {
public:
    /// Тип бонуса, связанный с этой картой.
    std::string bonusType;

    /**
     * @brief Конструктор класса BonusCard.
     * 
     * Создает объект BonusCard с заданным именем, описанием и типом бонуса.
     * 
     * @param name Имя бонусной карты.
     * @param description Описание бонусной карты.
     * @param bonusType Тип бонуса, который предоставляет карта.
     */
    BonusCard(const std::string& name, const std::string& description, const std::string& bonusType);

    /**
     * @brief Применяет бонусную карту.
     * 
     * Этот метод применяет эффект бонусной карты к текущему счету
     * игрока, основываясь на характеристиках.
     * 
     * @param score Ссылка на текущий счет игрока, который будет изменен.
     * @param characteristic Характеристики игрока, которые могут влиять на эффект карты.
     */
    void play(int& score, const Characteristic& characteristic) override; // Переопределение метода play
};

#endif // BONUSCARD_H
