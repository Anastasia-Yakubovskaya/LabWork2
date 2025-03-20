#ifndef AI_H
#define AI_H

#include "playerbase.h"
#include "deck.h"

/**
 * @class AI
 * @brief Класс, представляющий искусственный интеллект игрока.
 *
 * Этот класс наследует от PlayerBase и реализует логику
 * для действий, которые может выполнять искусственный интеллект
 * в игре, такие как взятие карт и отображение своей руки.
 */
class AI : public PlayerBase {
public:
    /**
     * @brief Конструктор класса AI.
     * 
     * Создает объект AI с заданным именем и характеристиками.
     * 
     * @param name Имя игрока.
     * @param characteristic Характеристики игрока.
     */
    AI(const std::string& name, const Characteristic& characteristic);

    /**
     * @brief Берет карту из колоды.
     * 
     * Этот метод позволяет AI взять карту из колоды.
     * 
     * @param deck Ссылка на колоду, из которой будет взята карта.
     * @param isConstruction Флаг, указывающий, находится ли игра в стадии строительства.
     */
    void drawCard(Deck& deck, bool isConstruction);

    /**
     * @brief Берет бонусную карту из колоды.
     * 
     * Этот метод позволяет AI взять бонусную карту из колоды.
     * 
     * @param deck Ссылка на колоду, из которой будет взята бонусная карта.
     */
    void drawBonusCard(Deck& deck);

    /**
     * @brief Отображает карты на руке AI.
     * 
     * Этот метод выводит на экран карты, которые находятся на руке AI.
     */
    void showHand() const;

    /**
     * @brief Деструктор класса AI.
     * 
     * Освобождает ресурсы, используемые объектом AI.
     */
    ~AI();
};

#endif // AI_H
