#include "cell.h"
#include <vector>
#include <fstream>
#include <string>

using namespace std;

#ifndef GRID
#define GRID

// Classe qui représente les cellules de la grille
class Grid {
private:
    int Width; // Largeur de la grille
    int Height; // Hauteur de la grille
    std::vector<std::vector<Cell*>> Cells; // Matrice de pointeurs vers les cellules

public:
    int getWidth();     // Retourne la largeur de la grille
    int getHeight();    // Retourne la hauteur de la grille
    vector<vector<Cell*>>& getCells();  // Retourne une référence à la matrice de cellules
    Grid(string nom_fichier); // Constructeur Grid, permet d'initialiser la grille à partir du fichier fourni par l'utilisateur


    bool Iteration(); // Correspond à une itération sur la grille (tout en appliquant les règles du jeu)
};

#endif
