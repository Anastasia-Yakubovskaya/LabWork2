#ifndef CONSTRUCTIONCARD_H
#define CONSTRUCTIONCARD_H

#include "card.h"

/**
 * @class ConstructionCard
 * @brief Класс, представляющий строительную карту.
 *
 * Этот класс наследует от класса Card и представляет
 * строительную карту, которая может изменять счет игрока
 * в зависимости от типа карты и связанных характеристик.
 */
class ConstructionCard : public Card {
public:
    /// Тип строительной карты (например, "здание", "дерево").
    std::string type;
    
    /// Изменение счета, связанное с использованием этой карты.
    int scoreChange;

    /**
     * @brief Конструктор класса ConstructionCard.
     * 
     * Создает объект ConstructionCard с заданным типом и изменением счета.
     * 
     * @param type Тип строительной карты.
     * @param scoreChange Изменение счета, которое будет применено при использовании карты.
     */
    ConstructionCard(const std::string& type, int scoreChange);

    /**
     * @brief Играет строительную карту.
     * 
     * Этот метод применяет эффект карты, изменяя текущий счет
     * в зависимости от типа карты и характеристик.
     * 
     * @param score Ссылка на текущий счет, который будет изменен.
     * @param characteristic Характеристика, которая может повлиять на эффект карты.
     */
    void play(int& score, const Characteristic& characteristic) override;
};

#endif // CONSTRUCTIONCARD_H
