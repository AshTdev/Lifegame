#include "cell.h"
#include <vector>

class DeadCell : public Cell{
    public:DeadCell(int x, int y, bool Obstacle);
    bool CheckNeighbours(std::vector<std::vector<Cell*>> &Cells, int longueur, int largeur);
};
