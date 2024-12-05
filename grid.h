#include "cell.h"
#include <vector>
#include <SFML/Graphics.hpp>

#ifndef GRID
#define GRID

class Grid {
private:
    int width;
    int height;
    std::vector<std::vector<Cell*>> cells;

public:
    Grid(int width, int height);
    ~Grid();
    void initialize(const std::vector<std::vector<bool>>& initialState);
    void update();
    void draw(sf::RenderWindow& window, float cellSize) const;
};

#endif