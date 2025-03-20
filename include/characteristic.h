#ifndef CHARACTERISTIC_H
#define CHARACTERISTIC_H

#include <string>

/**
 * @class Characteristic
 * @brief Класс, представляющий характеристику.
 *
 * Этот класс представляет характеристику, которая может
 * применяться к игроку или объекту, изменяя их состояние.
 */
class Characteristic {
public:
    /// Тип характеристики (например, "сила", "ловкость" и т.д.).
    std::string type;

    /**
     * @brief Конструктор класса Characteristic.
     * 
     * Создает объект Characteristic с заданным типом.
     * 
     * @param type Тип характеристики.
     */
    Characteristic(const std::string& type);

    /**
     * @brief Применяет эффект характеристики.
     * 
     * Этот метод изменяет текущий счет, добавляя или вычитая
     * указанное значение.
     * 
     * @param score Ссылка на текущий счет, который будет изменен.
     * @param change Изменение, которое будет применено к счету.
     */
    void applyEffect(int& score, int change) const;
};

#endif // CHARACTERISTIC_H
