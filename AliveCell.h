#include "cell.h"

// Classe qui représente la cellule vivante | Héritage de la classe "Cell"
class AliveCell : public Cell {
public:
    // Constructeur 
    AliveCell(int x, int y, bool Obstacle);

    // Méthode pour vérifier les voisins de la cellule 
    bool CheckNeighbours(std::vector<std::vector<Cell*>> &Cells, int longueur, int largeur);
};
