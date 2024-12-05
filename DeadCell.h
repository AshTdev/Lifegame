#include "cell.h"

class DeadCell : public Cell {
public:
    DeadCell(int x, int y);
    void prepareChange(int aliveNeighbours) override;
    void changeState() override;
    void checkNeighbours(const std::vector<std::vector<Cell*>>& cells) override;
    void draw(sf::RenderWindow& window, float cellSize) const override;
};