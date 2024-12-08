#include <vector>
#ifndef CELL
#define CELL


class Cell{
    protected:
    int x;
    int y;
    bool Change;
    bool Obstacle;
    
    public:
    Cell(int x, int y, bool Obstacle);
    bool getObstacle();
    bool getChange();
    bool PrepareChange();
    void ChangeStatement();
    virtual bool CheckNeighbours(std::vector<std::vector<Cell*>> &Cells, int longueur, int largeur)=0;

};

#endif
