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
    while (getline(fichier, line)){
        j=0;
        istringstream linestream(line);
        while (linestream >> word){
                number=stoi(word);
                if (i==0){
                    if (j==0){
                    Width=number;}
                    else{
                    Height=number;
                    allocation=true;
                    }
                }
                else{
                if (allocation){
                    Cells.resize(Height, vector<Cell*>(Width, nullptr));
                    allocation=false;
                }   
                    if(number==1){
                        Cells[i-1][j] = new AliveCell(i-1,j, false);
                    }
                    else if(number==0){
                        Cells[i-1][j] = new DeadCell(i-1,j, false);
                    }
                    else if(number==2){
                        Cells[i-1][j] = new DeadCell(i-1,j, true);
                    }
                    else if(number==3){
                        Cells[i-1][j] = new AliveCell(i-1,j, true);
                    }
                }
            j++;

        }i++;
    }
}
bool Grid::Iteration(){
    for(int i=0;i<Height;i++){
        for (int j=0;j<Width;j++){
            if (!(Cells[i][j]->getObstacle())){
                Cells[i][j]->CheckNeighbours(Cells, Width, Height);
        }}}
    for(int i=0;i<Height;i++){
        for (int j=0;j<Width;j++){
                if (Cells[i][j]->getChange()==true){
                    if(dynamic_cast<AliveCell*>(Cells[i][j])){ 
                    delete Cells[i][j];
                    Cells[i][j]=new DeadCell(i,j,false);
                }else{
                    delete Cells[i][j];
                    Cells[i][j]=new AliveCell(i,j,false);
                }
            }
        }    
    }
    return true;
} 
