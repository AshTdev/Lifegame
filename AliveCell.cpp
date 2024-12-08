#include "AliveCell.h"
#include <iostream>
using namespace std;

AliveCell::AliveCell(int x, int y, bool Obstacle) : Cell(x, y, Obstacle) {
}

bool AliveCell::CheckNeighbours(std::vector<std::vector<Cell*>> &Cells, int longueur, int largeur) {
    int aliveNeighbours = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if ((i != 0 || j != 0)) {
                int nx = (x + j + longueur) % longueur;
                int ny = (y + i + largeur) % largeur;
                if (dynamic_cast<AliveCell*>(Cells[ny][nx])) {
                    aliveNeighbours++;
                }
            else {
            }
            }
        }
    }

    if (!(aliveNeighbours == 2 || aliveNeighbours == 3)){
        return PrepareChange();
    } else {
        return false;
    }
}
