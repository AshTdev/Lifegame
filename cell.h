#include <vector>
#ifndef CELL
#define CELL


class Cell{
    protected:
    int x;
    int y;
    bool Change;
    public:
    Cell(int x, int y);
    bool getChange();
    bool PrepareChange();
    void ChangeStatement();
    virtual bool CheckNeighbours(std::vector<std::vector<Cell*>> &Cells, int longueur, int largeur)=0;

};

#endif
