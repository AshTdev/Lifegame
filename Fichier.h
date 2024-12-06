#ifndef FICHIER_H
#define FICHIER_H

#include <vector>
#include <string>
#include "cell.h"

using namespace std;

class GameOfLife {
public:
    GameOfLife(const string& nom_fichier);
    void printMatrix() const;

private:
    int height;
    int width;
    vector<vector<Cell*>> matrix;
    void readFile(const string& nom_fichier);
};

#endif 
