// WIP
./ma#include <SFML/Graphics.hpp>
#include "grid.h"
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;


vector<vector<int>> grid(gridWidth, vector<int>(gridHeight));

void initializeGrid() {
    srand(time(0));
    for (int x = 0; x < gridWidth; ++x) {
        for (int y = 0; y < gridHeight; ++y) {
            grid[x][y] = rand() % 2;  // Randomly initialize cells as alive or dead
        }
    }
}

void renderGrid(sf::RenderWindow &window) {
    int x, y;
    
    window.clear();
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));
    for (x = 0; x < gridWidth; ++x) {
        for (y = 0; y < gridHeight; ++y) {
            if (grid[x][y] == 1) {
                cell.setPosition(x * cellSize, y * cellSize);
                window.draw(cell);
            }
        }
    }
    window.display();
}

int main() {
    string nom_fichier;
    cout <<"Entrez le nom de votre fichier .txt (sans l'extension)"<<endl;
    cin >> nom_fichier;
    nom_fichier+=".txt";
    ifstream fichier(nom_fichier);
    if (!fichier.is_open()) {
        cerr << "Erreur : Impossible d'ouvrir le fichier." << endl;
        return 1;
    }
    // A complèter ?

    int choix;
    cout <<"Mode console (par défaut) ou graphique (1) ?"<<endl;
    cin >> choix; 
    int gridHeight;
    int gridWidth;
    int NbIterations;
    int temps;
    cout <<"Nombre d'itérations : "<< endl;
    cin >> NbIterations;
    cout <<"Temps (en ms) entre les itérations : "<<endl;
    cin >> temps;
    Grid Grille(gridWidth, gridHeight);
    if (choix==1){
    int cellSize;
    cout << "Taille d'une cellule : "<<endl;
    cin << cellSize;
    sf::RenderWindow window(sf::VideoMode(gridWidth * cellSize, gridHeight * cellSize), "Game of Life");
    }
    else{

    }

    initializeGrid();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        renderGrid(window);

        sf::sleep(sf::milliseconds(100));
    }

    return 0;
}
