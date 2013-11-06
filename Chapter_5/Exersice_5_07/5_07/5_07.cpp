/*
 * File: 5_07.cpp
 * -------------
 * Contains a function to streamline initializing a grid
 *
 */

/* Imports */
#include <iostream>
#include <string>
#include "simpio.h"
#include "vector.h"
#include "strlib.h"
#include "benfile.h"
#include "grid.h"


/* Function Prototypes */
void fillGrid(Grid<int> &grid, Vector<int> &values);


/* main */
int main() {
    
    Grid<int> matrix(3, 3);
    Vector<int> values;
    values += 1, 2, 3;
    values += 4, 5, 6;
    values += 7, 8, 9;
    fillGrid(matrix, values);
    
    // matrix filled using "fillGrid"
    for (int i = 0; i < matrix.numRows(); i++) {
        for (int j = 0; j < matrix.numCols(); j++) {
            std::cout << matrix.get(i, j) << " ";
        }
        std::cout << std::endl;
    }
    
    std::cout << std::endl;
    
    // values printed to look like matrix
    for (int i = 0; i < values.size(); i++) {
        std::cout << values.get(i) << " ";
        if (values.get(i) % 3 == 0) {
            std::cout << std::endl;
        }
    }
    
    
    return 0;
}

/* functions */

void fillGrid(Grid<int> &grid, Vector<int> &values) {
    int count = 0;
    for (int i = 0; i < grid.numRows(); i++) {
        for (int j = 0; j < grid.numCols(); j++) {
            grid.set(i, j, values.get(count));
            count++;
        }
    }
}



