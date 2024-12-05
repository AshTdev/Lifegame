#include "cell.h"

class DeadCell : Cell{
    DeadCell(int x, int y);
    void CheckNeighbours(std::vector<std::vector<Cell*>> &Cells, int longueur, int largeur);
}
