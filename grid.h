#include "cell.h"
#include <vector>
#include <string>
using namespace std;
#ifndef GRID
#define GRID

class Grid{
    private:
    int Width;
    int Height;
    vector<vector<Cell*>> Cells;
    public:
    Grid(string nom_fichier);
    bool Iteration();
};

#endif
