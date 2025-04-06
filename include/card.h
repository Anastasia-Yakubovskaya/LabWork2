#ifndef CARD_H
#define CARD_H

#include <string>
#include "characteristic.h"

/**
 * @class Card
 * @brief Базовый класс для карт.
 *
 * Этот класс представляет базовую карту, которая содержит
 * имя и описание. Он служит основой для других типов карт,
 * таких как бонусные карты.
 */
class Card {
public:
    /// Имя карты.
    std::string name;
    
    /// Описание карты.
    std::string description;

    /**
     * @brief Конструктор класса Card.
     * 
     * Создает объект Card с заданным именем и описанием.
     * 
     * @param name Имя карты.
     * @param description Описание карты.
     */
    Card(const std::string& name, const std::string& description);

    /**
     * @brief Применяет эффект карты.
     * 
     * Этот метод применяет эффект карты к текущему счету
     * игрока, основываясь на характеристиках.
     * 
     * @param score Ссылка на текущий счет игрока, который будет изменен.
     * @param characteristic Характеристики игрока, которые могут влиять на эффект карты.
     */
    virtual void play(int& score, const Characteristic& characteristic);

    /// Виртуальный деструктор для корректного удаления производных классов.
    virtual ~Card() = default;
};

#endif // CARD_H
