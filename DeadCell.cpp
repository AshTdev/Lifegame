#include "DeadCell.h"
#include "AliveCell.h"
#include <iostream>
using namespace std;

// Constructeur DeadCell
DeadCell::DeadCell(int x, int y, bool Obstacle) : Cell(x, y, Obstacle) {
    // Appelle le constructeur "Cell"
}

// Méthode pour vérifier les voisins de la cellule
bool DeadCell::CheckNeighbours(std::vector<std::vector<Cell*>> &Cells, int longueur, int largeur) {
    int aliveNeighbours = 0;

    // On parcout les voisins de la cellule
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if ((i != 0 || j != 0)) { // Ignore sa propre position
                int nx = (x + j + longueur) % longueur; // Coordonnée x du voisin
                int ny = (y + i + largeur) % largeur;  // Coordonnée y du voisin

                // Vérifie si le voisin est une cellule vivant
                if (dynamic_cast<AliveCell*>(Cells[ny][nx])) {
                    aliveNeighbours++;
                }
            }
        }
    }

    // Si la cellule morte a exactement 3 voisins vivants --> cellule vivante
    if (aliveNeighbours == 3) {
        return PrepareChange();
    } else {
        return false;
    }
}
