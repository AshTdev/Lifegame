#include "AliveCell.h"
#include <iostream>
using namespace std;

// Constructeur AliveCell
AliveCell::AliveCell(int x, int y, bool Obstacle) : Cell(x, y, Obstacle) {
    // Appelle le constructeur "Cell"
}

// Méthode pour vérifier les voisins de la cellule
bool AliveCell::CheckNeighbours(std::vector<std::vector<Cell*>> &Cells, int longueur, int largeur) {
    int aliveNeighbours = 0;

    // On parcout les voisins de la cellule
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if ((i != 0 || j != 0)) { // Ignore sa propre position
                int nx = (x + j + longueur) % longueur; // Coordonnée x du voisin
                int ny = (y + i + largeur) % largeur;   // Coordonnée y du voisin

                // Vérifie si le voisin est une cellule vivante
                if (dynamic_cast<AliveCell*>(Cells[ny][nx])) {
                    aliveNeighbours++;
                }
            else {
            }
            }
        }
    }

    // Si la cellule vivante a moins de 2 voisins vivants ou plus de 3 voisins vivants --> cellule morte
    if (!(aliveNeighbours == 2 || aliveNeighbours == 3)){
        return PrepareChange();
    } else {
        return false;
    }
}
