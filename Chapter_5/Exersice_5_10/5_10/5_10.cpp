
/*
 * File: 5_10.cpp
 * -------------
 * This program initializes a grid of mine counts given a grid of mines.
 *
 */

/* Imports */
#include <iostream>
#include <string>
#include "simpio.h"
#include "vector.h"
#include "strlib.h"
#include "grid.h"


/* Function Prototypes */
void fixCounts(Grid<bool> &mines, Grid<int> &counts);
int countBools(Grid<bool> bools, int row, int col);
void fillGrid(Grid<bool> &grid, Vector<bool> &values);
void printGrid(Grid<int> counts);

/* main */
int main() {

    Grid<int> counts(6, 6);
    Grid<bool> mines(6, 6);
    Vector<bool> values;
    values += true, false, false, false, false, true;
    values += false, false, false, false, false, true;
    values += true, true, false, true, false, true;
    values += true, false, false, false, false, false;
    values += false, false, true, false, false, false;
    values += false, false, false, false, false, false;
    fillGrid(mines, values);
    fixCounts(mines, counts);
    printGrid(counts);
    
    
    return 0;
}

/* functions */

void fixCounts(Grid<bool> &mines, Grid<int> &counts) {
    for (int i = 0; i < mines.numRows(); i++) {
        for (int j = 0; j < mines.numCols(); j++) {
            counts.set(i, j, countBools(mines, i, j));
        }
    }
}

int countBools(Grid<bool> bools, int row, int col) {
    int mineCount = 0;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (bools.inBounds(i + row, j + col)) {
                if (bools.get(i + row, j + col)) {
                    mineCount++;
                }
            }
        }
    }
    return mineCount;
}

void fillGrid(Grid<bool> &grid, Vector<bool> &values) {
    int count = 0;
    for (int i = 0; i < grid.numRows(); i++) {
        for (int j = 0; j < grid.numCols(); j++) {
            grid.set(i, j, values.get(count));
            count++;
        }
    }
}

void printGrid(Grid<int> counts) {
    for (int i = 0; i < counts.numRows(); i++) {
        for (int j = 0; j < counts.numCols(); j++) {
            std::cout << counts.get(i, j) << " ";
        }
        std::cout << std::endl;
        
    }
    
}




