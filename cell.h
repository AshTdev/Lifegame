
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
    void CheckNeighbours()=0;

}

#endif