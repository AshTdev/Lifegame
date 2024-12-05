#include "cell.h"

Cell::Cell(int x, int y, bool alive) : x(x), y(y), alive(alive) {}

bool Cell::isAlive() const {
    return alive;
}