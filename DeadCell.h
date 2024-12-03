#include "cell.h"

class DeadCell : Cell{
    DeadCell(int x, int y);
    void CheckNeighbours();
}