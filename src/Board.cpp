#include "board.h"
#include "graphics.h"
#include <iostream>  // Добавлено для использования класса Graphics

Board::Board() {
    grid.resize(size, std::vector<Cell>(size));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            grid[i][j] = Cell();
        }
    }
}

void Board::placeObject(int x, int y, const std::string& object, int health) {
    if (isCellEmpty(x, y)) {
        grid[x][y].place(object, health);
        std::cout << "Object " << object << " placed on the board at cell (" << x << ", " << y << ").\n";
    } else {
        std::cout << "Cell is occupied! Try another one.\n";
    }
}

bool Board::isCellEmpty(int x, int y) {
    return !grid[x][y].isOccupied;
}

void Board::display() {
    Graphics::displayBoard(grid);  // Теперь компилятор знает о Graphics
}

int Board::calculateFinalScore(const std::string& playerPrefix) {
    int score = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (grid[i][j].content.find(playerPrefix) != std::string::npos) {
                char objectType = grid[i][j].content[0];
                switch (objectType) {
                    case 'H': score += 15; break;
                    case 'T': score += 25; break;
                    case 'W': score += 30; break;
                    default: break;
                }
            }
        }
    }
    return score;
}

void Board::stealBuilding(const std::string& fromPrefix, const std::string& toPrefix) {
    std::vector<std::pair<int, int>> buildings;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (grid[i][j].content.find(fromPrefix) != std::string::npos) {
                buildings.push_back({i, j});
            }
        }
    }

    if (!buildings.empty()) {
        int index = rand() % buildings.size();
        int x = buildings[index].first;
        int y = buildings[index].second;
        std::string object = grid[x][y].content;
        object[object.size() - 1] = toPrefix[0];
        grid[x][y].content = object;
        std::cout << "Building at cell (" << x << ", " << y << ") has been transferred to player " << toPrefix << ".\n";
    } else {
        std::cout << "The opponent has no buildings to steal.\n";
    }
}

void Board::exchangeAllBuildings(const std::string& player1Prefix, const std::string& player2Prefix) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (grid[i][j].content.find(player1Prefix) != std::string::npos) {
                grid[i][j].content[grid[i][j].content.size() - 1] = player2Prefix[0];
            } else if (grid[i][j].content.find(player2Prefix) != std::string::npos) {
                grid[i][j].content[grid[i][j].content.size() - 1] = player1Prefix[0];
            }
        }
    }
    std::cout << "All buildings between players " << player1Prefix << " and " << player2Prefix << " have been exchanged.\n";
}
