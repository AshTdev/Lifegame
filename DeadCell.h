#include "cell.h"

class DeadCell : Cell{
    DeadCell(int x, int y);
    bool CheckNeighbours(std::vector<std::vector<Cell*>> &Cells, int longueur, int largeur);
}
