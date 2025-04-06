#ifndef NATURALDISASTER_H
#define NATURALDISASTER_H

#include "eventcard.h"
#include "board.h"

/**
 * @class NaturalDisaster
 * @brief Класс, представляющий природное бедствие.
 *
 * Этот класс наследует от класса EventCard и представляет
 * карту события, связанного с природным бедствием, которое
 * может нанести урон игрокам или игровому полю.
 */
class NaturalDisaster : public EventCard {
public:
    /// Тип природного бедствия.
    std::string type;

    /// Урон, наносимый природным бедствием.
    int damage;

    /**
     * @brief Конструктор класса NaturalDisaster.
     * 
     * Этот конструктор инициализирует тип природного бедствия
     * и его урон.
     * 
     * @param type Тип природного бедствия.
     * @param damage Урон, наносимый природным бедствием.
     */
    NaturalDisaster(const std::string& type, int damage);

    /**
     * @brief Активирует природное бедствие.
     * 
     * Этот метод применяет эффект природного бедствия к игровому
     * полю и обновляет счет игрока.
     * 
     * @param board Ссылка на игровую доску, к которой будет применено бедствие.
     * @param score Ссылка на счет игрока, который может быть изменен.
     * @param characteristic Характеристика, к которой будет применен эффект.
     * @param playerPrefix Префикс игрока, для отображения информации.
     */
    void trigger(Board& board, int& score, const Characteristic& characteristic, const std::string& playerPrefix);
};

#endif // NATURALDISASTER_H
