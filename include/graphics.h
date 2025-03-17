#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <vector>
#include "cell.h"


#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define PURPLE  "\033[35m"


class Graphics {
public:
    static void displayTitle();
    static void displayBoard(const std::vector<std::vector<Cell>>& grid);
};

#endif // GRAPHICS_H
