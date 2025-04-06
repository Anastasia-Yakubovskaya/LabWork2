/* Yakubovskaya Anastasya st130155@student.spbu.ru LabWork2 */
#include "board.h"
#include "graphics.h"
#include <iostream> 

Board::Board()
{
    grid.resize(size, std::vector<Cell>(size));
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            grid[i][j] = Cell();
        }
    }
}

/**
 * @brief Размещает объект на доске.
 * 
 * Этот метод размещает указанный объект на заданной ячейке доски,
 * если ячейка пуста.
 * 
 * @param x Координата по оси X (строка).
 * @param y Координата по оси Y (столбец).
 * @param object Имя объекта, который нужно разместить.
 * @param health Здоровье объекта.
 */
void Board::placeObject(int x, int y, const std::string& object, int health)
{
    if (isCellEmpty(x, y))
    {
        grid[x][y].place(object, health);
        std::cout << "Object " << object << " placed on the board at cell (" << x << ", " << y << ").\n";
    }
    else
    {
        std::cout << "Cell is occupied! Try another one.\n";
    }
}

/**
 * @brief Проверяет, пуста ли ячейка.
 * 
 * Этот метод проверяет, занята ли указанная ячейка на доске.
 * 
 * @param x Координата по оси X (строка).
 * @param y Координата по оси Y (столбец).
 * @return true Если ячейка пуста.
 * @return false Если ячейка занята.
 */
bool Board::isCellEmpty(int x, int y)
{
    return !grid[x][y].isOccupied;
}

/**
 * @brief Отображает доску.
 * 
 * Этот метод вызывает функцию отображения графики для
 * визуализации текущего состояния доски.
 */
void Board::display()
{
    Graphics::displayBoard(grid);  
}

/**
 * @brief Вычисляет финальный счет игрока.
 * 
 * Этот метод подсчитывает финальный счет игрока на основе
 * объектов, размещенных на доске, с учетом префикса игрока.
 * 
 * @param playerPrefix Префикс игрока, для которого нужно подсчитать счет.
 * @return int Финальный счет игрока.
 */
int Board::calculateFinalScore(const std::string& playerPrefix)
{
    int score = 0;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (grid[i][j].content.find(playerPrefix) != std::string::npos)
            {
                char objectType = grid[i][j].content[0];
                switch (objectType)
                {
                case 'H':
                    score += 15;
                    break;
                case 'T':
                    score += 25;
                    break;
                case 'W':
                    score += 30;
                    break;
                default:
                    break;
                }
            }
        }
    }
    return score;
}

/**
 * @brief Украсть здание у противника.
 * 
 * Этот метод случайным образом выбирает здание у противника
 * и передает его текущему игроку.
 * 
 * @param fromPrefix Префикс игрока, у которого будет украдено здание.
 * @param toPrefix Префикс игрока, которому будет передано здание.
 */
void Board::stealBuilding(const std::string& fromPrefix, const std::string& toPrefix)
{
    std::vector<std::pair<int, int>> buildings;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (grid[i][j].content.find(fromPrefix) != std::string::npos)
            {
                buildings.push_back({i, j});
            }
        }
    }

    if (!buildings.empty())
    {
        int index = rand() % buildings.size();
        int x = buildings[index].first;
        int y = buildings[index].second;
        std::string object = grid[x][y].content;
        object[object.size() - 1] = toPrefix[0];
        grid[x][y].content = object;
        std::cout << "Building at cell (" << x << ", " << y << ") has been transferred to player " << toPrefix << ".\n";
    }
    else
    {
        std::cout << "The opponent has no buildings to steal.\n";
    }
}

/**
 * @brief Обменять все здания между двумя игроками.
 * 
 * Этот метод меняет здания между двумя игроками, 
 * заменяя префиксы их зданий.
 * 
 * @param player1Prefix Префикс первого игрока.
 * @param player2Prefix Префикс второго игрока.
 */
void Board::exchangeAllBuildings(const std::string& player1Prefix, const std::string& player2Prefix)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (grid[i][j].content.find(player1Prefix) != std::string::npos)
            {
                grid[i][j].content[grid[i][j].content.size() - 1] = player2Prefix[0];
            }
            else if (grid[i][j].content.find(player2Prefix) != std::string::npos)
            {
                grid[i][j].content[grid[i][j].content.size() - 1] = player1Prefix[0];
            }
        }
    }
    std::cout << "All buildings between players " << player1Prefix << " and " << player2Prefix << " have been exchanged.\n";
}
