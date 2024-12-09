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
// Fonction permettant de colorier les cases sur la grille en fonction de l'état d'une cellule.

    int x, y;
    auto& cells = grille.getCells();
    window.clear();
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));
    for (y = 0; y < grille.getHeight(); ++y) {
// Parcours de ligne en ligne.
        for (x = 0; x < grille.getWidth(); ++x) {
// Parcours de case en case dans la ligne actuelle.    
            if (dynamic_cast<AliveCell*>(cells[y][x])) {
                cell.setPosition(x * cellSize, y * cellSize); // Position de la cellule.
                if ((cells[y][x]->getObstacle())){
                    cell.setFillColor(sf::Color::Green); // Obstacle Vivant
                }
                else{
                    cell.setFillColor(sf::Color::White); // Cellule Vivante
                }
                window.draw(cell); // Affichage de la cellule.
            }
            else{

                cell.setPosition(x * cellSize, y * cellSize); // Position de la cellule.
                if ((cells[y][x]->getObstacle())){
                    cell.setFillColor(sf::Color::Red); // Obstacle Mort
                }
                else{
                    cell.setFillColor(sf::Color::Black); // Cellule Morte
                }
                window.draw(cell); // Affichage de la cellule.
            }
        }
    }window.display();
}

string createfolder(){
// Fonction permettant de créer un dossier.
    string foldername;
    cout << "Entrez le nom du dossier que vous voulez créer" << endl;
    cin >> foldername;
    string command = "mkdir " + foldername; // Commande pour créer un dossier.
    system(command.c_str()); // Création du dossier.
    return foldername;
}
void createandwritefile(string folder, Grid &grille, int etape){
// Fonction permettant de créer un fichier et d'y écrire la grille.

    filesystem::create_directory(folder); // Création du répertoire
    string filename=to_string(etape);
    ofstream file(folder + "/" + filename + "_out.txt");
    if (file.is_open()) { 
    auto& cells = grille.getCells(); // Récupération des cellules.
    for (int y = 0; y < grille.getHeight(); ++y) {
// Parcours de ligne en ligne.
        for (int x = 0; x < grille.getWidth(); ++x) {
// Parcours de case en case dans la ligne actuelle.
            if (dynamic_cast<AliveCell*>(cells[y][x])) { 
                if ((cells[y][x]->getObstacle())){
                    file << "3 "; // Obstacle Vivant.
                }
                else{
                    file << "1 "; // Cellule Vivante.
                }
            } else {
                if ((cells[y][x]->getObstacle())){
                    file << "2 "; // Obstacle Mort.
                }
                else{
                    file << "0 "; // Cellule Morte.
                }
            }
        }
        file << endl; // Passage à la ligne suivante.
    }
        file.close();
    } else {
        cerr << "Failed to create file." << endl; // Erreur si le fichier n'a pas pu être créé.
    }
}


int main() {
    string nom_fichier;
    cout << "Entrez le nom de votre fichier .txt (sans l'extension)" << endl;
    cin >> nom_fichier;
    nom_fichier += ".txt"; // Ajout de l'extension .txt.
    ifstream fichier(nom_fichier);
    if (!fichier.is_open()) { // Vérification si le fichier existe.
        cerr << "Erreur : Impossible d'ouvrir le fichier." << endl;
        return 1;
    }

    int choix;
    cout << "Mode console (0) ou graphique (1) ?" << endl;
    cin >> choix;
    if (choix != 0 && choix != 1) { 
        cerr << "Erreur : Choix invalide." << endl; // Erreur si le choix n'est pas 0 ou 1.
        return 1;
    }
    int NbIterations;

    cout << "Nombre d'itérations (minimum 1) : " << endl;
    cin >> NbIterations;
    if (NbIterations < 1){
        cerr << "Erreur : Le nombre d'itération doit être plus élevé que 0." << endl; // Erreur si le nombre d'itérations est inférieur à 1.
        return 1;
    }


    Grid Grille(nom_fichier);

    if (choix == 1) {
// Mode graphique.
        int temps;
        cout << "Temps (en ms) entre les itérations : " << endl;
        cin >> temps;
        if (temps < 0){
            cerr << "Erreur : Le temps doit être positif." << endl; // Erreur si le temps est négatif.
            return 1;
        }
        int cellSize;
        cout << "Taille d'une cellule (minimum 2) : " << endl; // Une taille de 1 marche en théorie, mais est trop petite pour être visible.
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
                if (event.type == sf::Event::Closed) // Fermeture de la fenêtre si l'utilisateur clique sur la croix.
                    window.close();
            }

            if (NbIterations > 0) {


                    if (!Grille.Iteration()){
                        NbIterations = 1; // Arrêt si aucune cellule n'a changé.
                    }
                    renderGrid(window, Grille, cellSize); // Actualisation de l'affichage.

                    NbIterations--;
                    if (NbIterations == 0){
                        cout << "End" << endl; // Fin de la simulation.
                    }
                    sf::sleep(sf::milliseconds(temps)); // Attente entre chaque itération pour laisser le temps de voir.
                
            }
            
        }
    } else {
// Mode console.
        string folder = createfolder(); 
        int etape=0;
        while (etape < NbIterations) {
            etape++;
            bool change = Grille.Iteration(); 
            createandwritefile(folder, Grille, etape); // Création du fichier et écriture de la grille.
            if (!change){
                        etape = NbIterations; // Arrêt si aucune cellule n'a changé.
                    }
            if (etape == NbIterations){
                        cout << "End" << endl; // Fin de la simulation.
            }
        }
    }
}
