#include "cell.h"

class AliveCell : public Cell{
    public:AliveCell(int x, int y);
    bool CheckNeighbours(std::vector<std::vector<Cell*>> &Cells, int longueur, int largeur);
};
