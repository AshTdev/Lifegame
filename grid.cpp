#include "grid.h"
#include "AliveCell.h"
#include "DeadCell.h"
#include <typeinfo>
#include <fstream>
#include <sstream>
#include <iostream>

int Grid::getWidth(){
    return Width; 
}
int Grid::getHeight(){
    return Height; 
}
vector<vector<Cell*>>& Grid::getCells(){
    return Cells;
}

Grid::Grid(string nom_fichier){
    ifstream fichier(nom_fichier);
    string line;
    int i=0, j;
    string word;
    int number;
    bool allocation=false;
    while (getline(fichier, line)){ // On lit le fichier ligne par ligne.
        j=0;
        istringstream linestream(line); // On crée un flux à partir de la ligne.
        while (linestream >> word){ // On lit chaque mot de la ligne.
                number=stoi(word); // On convertit le mot en entier.
                if (i==0){ // On lit la première ligne pour obtenir la largeur et la hauteur de la grille.
                    if (j==0){ 
                    Width=number;}
                    else{
                    Height=number;
                    allocation=true; // On peut maintenant allouer la mémoire pour la grille.
                    }
                }
                else{
                if (allocation){
                    Cells.resize(Height, vector<Cell*>(Width, nullptr)); // Allocation de la mémoire pour la grille.
                    allocation=false; // Inutile de le refaire. Cela générerait une erreur.
                }   // Le i-1 permet de prendre en compte le fait que la première ligne contient les dimensions de la grille.
                    if(number==1){
                        Cells[i-1][j] = new AliveCell(j,i-1, false); // On crée une cellule vivante.
                    }
                    else if(number==0){
                        Cells[i-1][j] = new DeadCell(j,i-1, false); // On crée une cellule morte.
                    }
                    else if(number==2){
                        Cells[i-1][j] = new DeadCell(j,i-1, true); // On crée un obstacle mort.
                    }
                    else if(number==3){
                        Cells[i-1][j] = new AliveCell(j,i-1, true); // On crée un obstacle vivant.
                    }
                }
            j++; 

        }i++;
    }
}
bool Grid::Iteration(){
    bool change=false;
    for(int i=0;i<Height;i++){
// On parcourt ligne par ligne.
        for (int j=0;j<Width;j++){
// On parcourt case par case dans la ligne actuelle.
            if (!Cells[i][j]->getObstacle()){ // Si on le faisait pour une cellule obstacle, cela retirerait l'intérêt de l'obstacle.
                Cells[i][j]->CheckNeighbours(Cells, Width, Height); // On vérifie les voisins de la cellule.
        }}}

    for(int i=0;i<Height;i++){ 
// On parcourt ligne par ligne.
        for (int j=0;j<Width;j++){
// On parcourt case par case dans la ligne actuelle.
                if (Cells[i][j]->getChange()==true){ 
                    if(dynamic_cast<AliveCell*>(Cells[i][j])){ 
                    delete Cells[i][j]; // On libère la case actuelle.
                    Cells[i][j]=new DeadCell(j,i,false); // On la remplace par une cellule morte.
                    if (!change){
                        change=true; // On confirme que la grille a changé si une cellule a changé.
                    }

                }else{
                    // Même déroulement pour une cellule morte.
                    delete Cells[i][j]; 
                    Cells[i][j]=new AliveCell(j,i,false);
                    if (!change){
                        change=true; 
                    }
                }
            }
        }    
    }
    return change; // On retourne si la grille a changé ou non.
} 
