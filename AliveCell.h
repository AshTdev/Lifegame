#include "cell.h"

class AliveCell : Cell{
    AliveCell(int x, int y);
    void CheckNeighbours();
}