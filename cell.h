#ifndef CELL
#define CELL

#include <SFML/Graphics.hpp>

class Cell {
protected:
    int x;
    int y;
    bool alive;

public:
    Cell(int x, int y, bool alive);
    virtual ~Cell() = default;
    virtual bool isAlive() const;
    virtual void prepareChange(int aliveNeighbours) = 0;
    virtual void changeState() = 0;
    virtual void checkNeighbours(const std::vector<std::vector<Cell*>>& cells) = 0;
    virtual void draw(sf::RenderWindow& window, float cellSize) const = 0;
};

#endif