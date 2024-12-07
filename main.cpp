#include <SFML/Graphics.hpp>
#include "grid.h"
#include "AliveCell.h"
#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>
#include <filesystem>

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
                if ((cells[y][x]->getObstacle())){
                    cell.setFillColor(sf::Color::Green);
                }
                else{
                    cell.setFillColor(sf::Color::White);
                }
                window.draw(cell);
            }
            else{

                cell.setPosition(x * cellSize, y * cellSize);
                if ((cells[y][x]->getObstacle())){
                    cell.setFillColor(sf::Color::Red);
                }
                else{
                    cell.setFillColor(sf::Color::Black);
                }
                window.draw(cell);
            }
        }
    }window.display();
}

string createfolder(){
    string foldername;
    cout << "Entrez le nom du dossier que vous voulez créer" << endl;
    cin >> foldername;
    string command = "mkdir " + foldername;
    system(command.c_str());
    return foldername;
}
void createandwritefile(string folder, Grid &grille, int etape){
    filesystem::create_directory(folder);
    string filename=to_string(etape);
    ofstream file(folder + "/" + filename + "_out.txt");
    if (file.is_open()) {
    auto& cells = grille.getCells();
    for (int y = 0; y < grille.getHeight(); ++y) {
        for (int x = 0; x < grille.getWidth(); ++x) {
            if (dynamic_cast<AliveCell*>(cells[y][x])) {
                if ((cells[y][x]->getObstacle())){
                    file << "3 ";
                }
                else{
                    file << "1 ";
                }
            } else {
                if ((cells[y][x]->getObstacle())){
                    file << "2 ";
                }
                else{
                    file << "0 ";
                }
            }
        }
        file << endl;
    }
        file.close();
    } else {
        cerr << "Failed to create file." << endl;
    }
}

void printGrid(Grid &grille) {
    auto& cells = grille.getCells();
    for (int y = 0; y < grille.getHeight(); ++y) {
        for (int x = 0; x < grille.getWidth(); ++x) {
            if (dynamic_cast<AliveCell*>(cells[y][x])) {
                if ((cells[y][x]->getObstacle())){
                    cout << "3 ";
                }
                else{
                    cout << "1 ";
                }
            } else {
                if ((cells[y][x]->getObstacle())){
                    cout << "2 ";
                }
                else{
                    cout << "0 ";
                }
            }
        }
        cout << endl;
    }
}

int main() {
    string nom_fichier;
    cout << "Entrez le nom de votre fichier .txt (sans l'extension)" << endl;
    cin >> nom_fichier;
    nom_fichier += ".txt";
    ifstream fichier(nom_fichier);
    if (!fichier.is_open()) {
        cerr << "Erreur : Impossible d'ouvrir le fichier." << endl;
        return 1;
    }

    int choix;
    cout << "Mode console (0) ou graphique (1) ?" << endl;
    cin >> choix;
    int NbIterations;
    int temps;
    cout << "Nombre d'itérations : " << endl;
    cin >> NbIterations;
    cout << "Temps (en ms) entre les itérations : " << endl;
    cin >> temps;

    Grid Grille(nom_fichier);

    if (choix == 1) {
        int cellSize;
        cout << "Taille d'une cellule : " << endl;
        cin >> cellSize;
        sf::RenderWindow window(sf::VideoMode(Grille.getWidth() * cellSize, Grille.getHeight() * cellSize), "Game of Life");

        sf::Clock clock;
        sf::Time timePerFrame = sf::milliseconds(temps);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            if (NbIterations > 0) {
                sf::Time elapsed = clock.getElapsedTime();
                if (elapsed >= timePerFrame) {
                    Grille.Iteration();
                    renderGrid(window, Grille, cellSize);
                    clock.restart();
                    NbIterations--;
                }
            }
        }
    } else (choix == 0); {
        string folder = createfolder();
        int etape=0;
        for (int i = 0; i < NbIterations; ++i) {
            etape++;
            Grille.Iteration();
            createandwritefile(folder, Grille, etape);
        }
    }

    return 0;
}
