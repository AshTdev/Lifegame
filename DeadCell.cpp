#include "DeadCell.h"

DeadCell::DeadCell(int x, int y) : Cell(x, y, false) {}

void DeadCell::prepareChange(int aliveNeighbours) {
    if (aliveNeighbours == 3) {
        alive = true;
    }
}

void DeadCell::changeState() {
    // No change needed, state is already updated in prepareChange
}

void DeadCell::checkNeighbours(const std::vector<std::vector<Cell*>>& cells) {
    int aliveNeighbours = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;
            int nx = x + i;
            int ny = y + j;
            if (nx >= 0 && nx < cells.size() && ny >= 0 && ny < cells[0].size() && cells[nx][ny]->isAlive()) {
                ++aliveNeighbours;
            }
        }
    }
    prepareChange(aliveNeighbours);
}

void DeadCell::draw(sf::RenderWindow& window, float cellSize) const {
    sf::RectangleShape cellShape(sf::Vector2f(cellSize, cellSize));
    cellShape.setPosition(x * cellSize, y * cellSize);
    cellShape.setFillColor(sf::Color::Black);
    window.draw(cellShape);
}