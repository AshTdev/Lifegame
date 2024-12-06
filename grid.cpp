#include "grid.h"
#include <SFML/Graphics.hpp>

Grid::Grid(int Width, int Height){
    this->Width=Width;
    this->Height=Height;
    Cells.resize(Width, std::vector<Cell*>(Height));

}
void Grid::Initialization(){

}
