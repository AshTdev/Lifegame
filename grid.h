#include "cell.h"
#include <vector>
#include <fstream>
#include <string>

using namespace std;


#ifndef GRID
#define GRID

class Grid{
    private:
    int Width;
    int Height;
    std::vector<std::vector<Cell*>> Cells;
    public:
    int getWidth();
    int getHeight();
    vector<vector<Cell*>>& getCells();
    Grid(string nom_fichier);
    bool Iteration();
};

#endif
