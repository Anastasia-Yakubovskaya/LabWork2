#ifndef PLAYER_H
#define PLAYER_H

#include "playerbase.h"
#include "deck.h"

/**
 * @class Player
 * @brief Класс, представляющий игрока в игре.
 *
 * Этот класс наследует от класса PlayerBase и предоставляет
 * функциональность для управления картами игрока, включая
 * возможность тянуть карты из колоды и отображать свою руку.
 */
class Player : public PlayerBase {
public:
    /**
     * @brief Конструктор класса Player.
     * 
     * Этот конструктор инициализирует игрока с заданным именем
     * и характеристиками.
     * 
     * @param name Имя игрока.
     * @param characteristic Характеристика игрока.
     */
    Player(const std::string& name, const Characteristic& characteristic);

    /**
     * @brief Тянет карту из колоды.
     * 
     * Этот метод позволяет игроку тянуть карту из колоды.
     * 
     * @param deck Ссылка на колоду, из которой будет тянута карта.
     * @param isConstruction Флаг, указывающий, является ли карта
     *                      строительной (true) или нет (false).
     */
    void drawCard(Deck& deck, bool isConstruction);

    /**
     * @brief Тянет бонусную карту из колоды.
     * 
     * Этот метод позволяет игроку тянуть бонусную карту из колоды.
     * 
     * @param deck Ссылка на колоду, из которой будет тянута бонусная карта.
     */
    void drawBonusCard(Deck& deck);

    /**
     * @brief Отображает карты на руке игрока.
     * 
     * Этот метод выводит в консоль карты, которые находятся на руке
     * у игрока.
     */
    void showHand() const;

    /**
     * @brief Деструктор класса Player.
     * 
     * Этот деструктор освобождает ресурсы, связанные с игроком.
     */
    ~Player();
};

#endif // PLAYER_H
