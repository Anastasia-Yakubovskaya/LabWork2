/* Yakubovskaya Anastasya st130155@student.spbu.ru LabWork2 */
#include "dice.h"
#include <cstdlib>
#include <ctime>

/**
 * @brief Бросает кубик.
 * 
 * Этот метод генерирует случайное число от 1 до 6, имитируя бросок стандартного шестигранного кубика.
 * 
 * @return Случайное число от 1 до 6, представляющее результат броска кубика.
 */
int Dice::roll()
{
    return rand() % 6 + 1;
}
