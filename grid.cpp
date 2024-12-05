#include "grid.h"
#include "AliveCell.h"
#include "DeadCell.h"
#include <iostream>

Grid::Grid(int width, int height) : width(width), height(height) {
    cells.resize(height, std::vector<Cell*>(width, nullptr)); // Corrected the dimensions
}

Grid::~Grid() {
    for (auto& row : cells) {
        for (auto& cell : row) {
            delete cell;
        }
    }
}

void Grid::initialize(const std::vector<std::vector<bool>>& initialState) {
    for (int i = 0; i < height; ++i) { // Corrected the loop bounds
        for (int j = 0; j < width; ++j) {
            if (initialState[i][j]) {
                cells[i][j] = new AliveCell(i, j);
            } else {
                cells[i][j] = new DeadCell(i, j);
            }
        }
    }
}

void Grid::update() {
    for (auto& row : cells) {
        for (auto& cell : row) {
            cell->checkNeighbours(cells);
        }
    }
    for (auto& row : cells) {
        for (auto& cell : row) {
            cell->changeState();
        }
    }
}

void Grid::draw(sf::RenderWindow& window, float cellSize) const {
    for (const auto& row : cells) {
        for (const auto& cell : row) {
            cell->draw(window, cellSize);
        }
    }
}