#include <iostream>
#include <fstream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "DeadCell.h"
#include "AliveCell.h"
#include "grid.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    ifstream inputFile(argv[1]);
    if (!inputFile) {
        cerr << "Error opening file: " << argv[1] << endl;
        return 1;
    }

    int rows, cols;
    inputFile >> rows >> cols;
    cout << "Grid dimensions: " << rows << "x" << cols << endl;

    vector<vector<bool>> initialState(rows, vector<bool>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int state;
            inputFile >> state;
            initialState[i][j] = (state == 1);
        }
    }

    Grid grid(rows, cols);
    grid.initialize(initialState);

    sf::RenderWindow window(sf::VideoMode(800, 800), "Game of Life");
    float cellSize = 800.0f / max(rows, cols); // Adjust cell size based on the larger dimension

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        grid.draw(window, cellSize);
        window.display();

        grid.update();
        sf::sleep(sf::milliseconds(100)); // Control the speed of the simulation
    }

    return 0;
}