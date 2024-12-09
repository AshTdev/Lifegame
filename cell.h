#include <vector>
#ifndef CELL
#define CELL

// Classe abstraite représentant une cellule dans la grille
class Cell {
protected:
    int x; // Coordonnée x de la cellule
    int y; // Coordonnée y de la cellule
    bool Change; // Indique un  changement d'état
    bool Obstacle; // Indique si la cellule est un obstacle

public:

    Cell(int x, int y, bool Obstacle);   // Constructeur 
    bool getObstacle();  // Return si la cellule est un obstacle
    bool getChange(); // Return si la cellule est marquée pour changement
    bool PrepareChange(); 
    void ChangeStatement(); // Change l'état de la cellule

    // Méthode virtuelle pure qui check les voisins.
    virtual bool CheckNeighbours(std::vector<std::vector<Cell*>> &Cells, int longueur, int largeur) = 0;
};

#endif
