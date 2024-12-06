#include "cell.h"

Cell::Cell(int x, int y){
    this->x=x;
    this->y=y;
    Change=false;
}

bool Cell::PrepareChange(){
    Change = !Change;
    return true;
}

