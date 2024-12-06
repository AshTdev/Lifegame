#ifndef CELL
#define CELL
#include <vector>

class Cell{
    protected:
    int x;
    int y;
    bool Change;
    public:
    Cell(int x, int y);
    bool PrepareChange();
    void ChangeStatement();
    virtual bool CheckNeighbours(std::vector<std::vector<Cell*>> &Cells, int longueur, int largeur)=0;

};

#endif
