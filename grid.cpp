#include "grid.h"
#include "AliveCell.h"
#include "DeadCell.h"
#include <fstream>
#include <sstream>
#include <iostream>

int Grid::getWidth(){
    return Width;
}
int Grid::getHeight(){
    return Height;
}
vector<vector<Cell*>> Grid::getCells(){
    return Cells;
}

Grid::Grid(string nom_fichier){
    cout << "Théo41" << endl;
    ifstream fichier(nom_fichier);
    cout << "Théo41.5" << endl;
    string line;
    int i=0, j;
    string word;
    int number;
    cout << "Théo42" << endl;
    while (getline(fichier, line)){
        j=0;
        cout << "Théo43" << endl;
        istringstream linestream(line);
        while (linestream >> word){
                cout << "Théo44" << endl; 
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
                }                 cout << "Théo45" << endl;
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
                }
            }
        }    
    }
    return true;
} 
