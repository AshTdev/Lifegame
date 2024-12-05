#ifndef CELL
#define CELL

class Cell{
    protected:
    int x;
    int y;
    bool Change;
    public:
    Cell(int x, int y);
    bool PrepareChange();
    void ChangeStatement();
    bool CheckNeighbours(std::vector<std::vector<Cell*>> &Cells, int longueur, int largeur)=0;

}

#endif
