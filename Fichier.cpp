#include "Fichier.h"
#include "AliveCell.h"
#include "DeadCell.h"



#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;


GameOfLife::GameOfLife(const string& nom_fichier) {
    readFile(nom_fichier);
}

void GameOfLife::readFile(const string& nom_fichier) {
    ifstream file(nom_fichier);
    if (!file.is_open()) {
        throw runtime_error("Could not open file");
    }

    string line;
    getline(file, line);
    istringstream iss(line);
    iss >> height >> width;

    matrix.resize(height, vector<Cell*>(width));

    for (int i = 0; i < height; ++i) {
        getline(file, line);
        istringstream iss(line);
        for (int j = 0; j < width; ++j) {
            int cellValue;
            iss >> cellValue;
            if (cellValue == 1) {
                matrix[i][j] = new AliveCell(i, j);
            } else {
                matrix[i][j] = new DeadCell(i, j);
            }
        }
    }

    file.close();
}

void GameOfLife::printMatrix() const {
    for (const auto& row : matrix) {
        for (const auto& cell : row) {
            if (dynamic_cast<AliveCell*>(cell)) {
                cout << "1 ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}
