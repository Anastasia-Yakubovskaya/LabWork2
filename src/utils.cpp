#include "utils.h"
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
