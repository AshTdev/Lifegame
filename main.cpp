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
    if (choix != 0 && choix != 1) {
        cerr << "Erreur : Choix invalide." << endl;
        return 1;
    }
    int NbIterations;

    cout << "Nombre d'itérations (minimum 1) : " << endl;
    cin >> NbIterations;
    if (NbIterations < 1){
        cerr << "Erreur : Le nombre d'itération doit être plus élevé que 0." << endl;
        return 1;
    }


    Grid Grille(nom_fichier);

    if (choix == 1) {
        int temps;
        cout << "Temps (en ms) entre les itérations : " << endl;
        cin >> temps;
        if (temps < 0){
            cerr << "Erreur : Le temps doit être positif." << endl;
            return 1;
        }
        int cellSize;
        cout << "Taille d'une cellule (minimum 2) : " << endl;
        cin >> cellSize;
        if (cellSize < 2){
            cerr << "Erreur : La taille d'une cellule doit être plus élevé que 1." << endl;
            return 1;
        }
        sf::RenderWindow window(sf::VideoMode(Grille.getWidth() * cellSize, Grille.getHeight() * cellSize), "Game of Life");
        renderGrid(window, Grille, cellSize);


        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            if (NbIterations > 0) {


                    if (!Grille.Iteration()){
                        NbIterations = 1;
                    }
                    renderGrid(window, Grille, cellSize);

                    NbIterations--;
                    if (NbIterations == 0){
                        cout << "End" << endl;
                    }
                    sf::sleep(sf::milliseconds(temps));
                
            }
            
        }
    } else {
        string folder = createfolder();
        int etape=0;
        while (etape < NbIterations) {
            etape++;
            bool change = Grille.Iteration();
            createandwritefile(folder, Grille, etape);
            if (!change){
                        etape = NbIterations;
                    }
            if (etape == NbIterations){
                        cout << "End" << endl;
            }
        }
    }
}
