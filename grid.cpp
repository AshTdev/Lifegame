#include "grid.h"
#include "AliveCell.h"
#include "DeadCell.h"
#include <fstream>
#include <sstream>


Grid::Grid(string nom_fichier){

    ifstream fichier(nom_fichier);
    string line;
    int i=0, j;
    string word;
    int number;
    while (getline(fichier, line)){
        j=0;
        istringstream linestream(line); // Voir comment ça marche
        while (linestream >> word){
                 
                number=stoi(word);
                if (j==0){
                    if (i==0){
                    Width=number;}
                    else{
                    Height=number;}
                }
                else{
                    if(number==1){
                        Cells[i-1].push_back(new AliveCell(i-1,j));
                    }
                    else{
                        Cells[i-1].push_back(new DeadCell(i-1,j));
                    }
                }
            j++;

        }i++;
    }
}
bool Grid::Iteration(){
    for(int i=0;i<Height;i++){
        for (int j=0;j<Width;j++){
                Cells[i][j]->CheckNeighbours(Cells, Width, Height);
        }}
    for(int i=0;i<Height;i++){
        for (int j=0;j<Width;j++){
                if (Cells[i][j]->getChange()==true){
                if(dynamic_cast<AliveCell*>(Cells[i][j])){ 
                    delete Cells[i][j];
                    Cells[i][j]=new DeadCell(i,j);
                }else{
                    delete Cells[i][j];
                    Cells[i][j]=new AliveCell(i,j);
                }}
        }    
    }
}
