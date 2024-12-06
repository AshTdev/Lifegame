#include "DeadCell.h"
#include "AliveCell.h"

DeadCell::DeadCell(int x, int y) : Cell(x, y) {

}

bool DeadCell::CheckNeighbours(std::vector<std::vector<Cell*>> &Cells, int longueur, int largeur) {
    int aliveNeighbours = 0;
    for (int i = -1; i <= 1; i++) {
        int nx = x + i;

        for (int j = -1; j <= 1; j++) {
            int ny = y + j;

            if ((i != 0 || j != 0) && (nx >= 0 && nx < longueur) && (ny >= 0 && ny < largeur)) {
                if (dynamic_cast<AliveCell*>(Cells[nx][ny])) {
                    aliveNeighbours++;
                }
            }
        }
    }
    return aliveNeighbours == 3;
}
