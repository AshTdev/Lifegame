#include "cell.h"

// Constructeur 
Cell::Cell(int x, int y, bool Obstacle) {
    this->x = x; // On initialise la coordonnée X
    this->y = y; // On iniitialise la coordonnée Y
    Change = false; // On initialise l'état de change à false
    this->Obstacle = Obstacle; // On initialise l'état "Obstacle"
}

// Prépare la cellule pour un changement d'état
bool Cell::PrepareChange() {
    Change = true; // Marque la cellule pour changement
    return true;
}

// Return si la cellule est un obstacle
bool Cell::getObstacle() {
    return Obstacle;
}

// Return si la cellule est marquée pour changement
bool Cell::getChange() {
    return Change;
}
