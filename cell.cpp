#include "cell.h"

Cell::Cell(int x, int y){
    this->x=x;
    this->y=y;
    Change=false;
}
bool Cell::isAlive(){
    return Alive;
}
void Cell::PrepareChange(){
    Alive = !Alive;
}

