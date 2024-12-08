#include "cell.h"

Cell::Cell(int x, int y, bool Obstacle){
    this->x=x;
    this->y=y;
    Change=false;
    this->Obstacle=Obstacle;
    
}

bool Cell::PrepareChange(){
    Change = true;
    return true;
}

bool Cell::getObstacle(){
    return Obstacle;
}

bool Cell::getChange(){
    return Change;
}
