#include "cell.h"
#include <vector>

// Classe représentant une cellule morte, héritage de la classe Cell
class DeadCell : public Cell {
public:
    // Constructeur 
    DeadCell(int x, int y, bool Obstacle);

    // Méthode pour vérifier les voisins de la cellule
    bool CheckNeighbours(std::vector<std::vector<Cell*>> &Cells, int longueur, int largeur);
};
