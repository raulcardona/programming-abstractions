/*
 * File: 5_07.cpp
 * -------------
 * Checks a integer grid to see if it is a "magic square"
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
bool ismagicSquare(Grid<int> &square);

/* main */
int main() {
    
    Grid<int> matrix(3, 3);
    Vector<int> values;
    values += 8, 1, 6;
    values += 3, 5, 7;
    values += 4, 9, 2;
    fillGrid(matrix, values);
    
    
    // print matrix filled using "fillGrid"
    for (int i = 0; i < matrix.numRows(); i++) {
        for (int j = 0; j < matrix.numCols(); j++) {
            std::cout << matrix.get(i, j) << " ";
        }
        std::cout << std::endl;
    }
    
    std::cout << std::endl;
    std::cout << std::endl;
    
    if (ismagicSquare(matrix)) {
        std::cout << "This is a magic square.";
    } else std::cout << "This is NOT a magic square";
    
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


bool ismagicSquare(Grid<int> &square) {
    Vector<int> magicNumber(square.numCols() + square.numRows() + 2); // magic number keeps the sums of the lines we are testing
    int horzCount = 0;
    int vertCount = square.numRows();  // starts keeping sums at the posision of number of rows
    int diagCountA = square.numRows() * 2;  // starts keeping sums of "\" diagonal after the horizontal and vertical.
    int diagCountB = diagCountA + 1;  // starts keeping sums of "/" diagonal after first set of diagonals.

    if (square.numCols() != square.numRows()) {
        return false;
    }
    
    //this nested for loop fills the magicNumber vector with line totals for horizontal, vertical and left-to-right diagonal "\"
    for (int i = 0; i < square.numRows(); i++) {
        int diagBPos = square.numCols() - 1; // counter that subtracts the column pos for each new row helping to total the "/" diagonal
        for (int j = 0; j < square.numCols(); j++) {
            magicNumber[horzCount] += square.get(i, j);
            magicNumber[vertCount] += square.get(j, i);
            if (i == j) {
                magicNumber[diagCountA] += square.get(i, j);
            }
        }
        magicNumber[diagCountB] += square.get(i, diagBPos);
        horzCount++;
        vertCount++;
        diagBPos--;
    }
   
    
    int previousValue = magicNumber[0];
    for (int i = 0; i < magicNumber.size(); i++) {
        std::cout << magicNumber[i] << std::endl;
        if (magicNumber[i] != 0 && magicNumber[i] != previousValue) {
            return false;
        }
    }
    return true;
}
