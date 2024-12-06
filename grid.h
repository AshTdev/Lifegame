#include "cell.h"
#include <vector>
#include <fstream>
#ifndef GRID
#define GRID

class Grid{
    private:
    int Width;
    int Height;
    std::vector<std::vector<Cell*>> Cells;
    public:
    Grid(string nom_fichier);
}

#endif
