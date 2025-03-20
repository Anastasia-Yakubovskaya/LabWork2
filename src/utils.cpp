/* Yakubovskaya Anastasya st130155@student.spbu.ru LabWork2 */
#include "utils.h"
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

/**
 * @brief Очищает консоль.
 * 
 * Этот метод очищает содержимое консоли в зависимости от операционной системы.
 * На Windows используется команда `cls`, на Unix-подобных системах — `clear`.
 */
void clearConsole()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
