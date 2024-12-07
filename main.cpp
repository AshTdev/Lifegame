
#include <SFML/Graphics.hpp>
#include "grid.h"
#include "AliveCell.h"
#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>

 


using namespace std;

void renderGrid(sf::RenderWindow &window, Grid &grille, int cellSize) {

    int x, y;
    auto& cells = grille.getCells();
    window.clear();
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));
    for (y = 0; y < grille.getHeight(); ++y) {

        for (x = 0; x < grille.getWidth(); ++x) {
            
            if (dynamic_cast<AliveCell*>(cells[y][x])) {

                cell.setPosition(x * cellSize, y * cellSize);
                cell.setFillColor(sf::Color::White);
                window.draw(cell);
            }
            else{

                cell.setPosition(x * cellSize, y * cellSize);
                cell.setFillColor(sf::Color::Black);
                window.draw(cell);
            }
        }
    }window.display();
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
    cout << "Théo-1" << endl;
    cin >> temps;
    cout << "Théo0" << endl;
    Grid Grille(nom_fichier);
    cout << "Théo1" << endl;
    if (choix==1){
    int cellSize;
    cout << "Taille d'une cellule : "<<endl;
    cin >> cellSize;
    sf::RenderWindow window(sf::VideoMode(Grille.getWidth() * cellSize, Grille.getHeight() * cellSize), "Game of Life");

    
    renderGrid(window, Grille, cellSize);
    
    sf::sleep(sf::milliseconds(temps));
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (NbIterations!=0){
                Grille.Iteration();
                renderGrid(window, Grille, cellSize);
                NbIterations--;
                sf::sleep(sf::milliseconds(temps));
            }
            else{
                window.close();
            }
            if (event.type == sf::Event::Closed)
                window.close();

                
                //renderGrid(window, cellSize);// 
                }

    
    }
    
    
}
}
