#ifndef PLAYERBASE_H
#define PLAYERBASE_H

#include <string>
#include <vector>
#include "characteristic.h"
#include "card.h"

/**
 * @class PlayerBase
 * @brief Базовый класс для игроков.
 *
 * Этот класс представляет базовую функциональность для игроков,
 * включая имя, счет, характеристики и карты на руке.
 */
class PlayerBase {
public:
    /// Имя игрока.
    std::string name;

    /// Счет игрока.
    int score;

    /// Характеристика игрока.
    Characteristic characteristic;

    /// Вектор карт на руке игрока.
    std::vector<Card*> hand;

    /**
     * @brief Конструктор класса PlayerBase.
     * 
     * Этот конструктор инициализирует игрока с заданным именем
     * и характеристиками.
     * 
     * @param name Имя игрока.
     * @param characteristic Характеристика игрока.
     */
    PlayerBase(const std::string& name, const Characteristic& characteristic);

    /**
     * @brief Деструктор класса PlayerBase.
     * 
     * Этот деструктор освобождает ресурсы, связанные с игроком.
     * Он является виртуальным, чтобы обеспечить корректное
     * освобождение ресурсов в производных классах.
     */
    virtual ~PlayerBase() = default;
};

#endif // PLAYERBASE_H
