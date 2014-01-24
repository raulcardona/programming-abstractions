
/*
 * File: 5_09.cpp
 * -------------
 * Contains a function to check the validity of a Sudoku puzzle.
 * It would be more useful if it could read the values from a file.
 * Maybe in a future exercise.
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
bool checkSudokuSolution(Grid<int> &puzzle);
bool checkRulesOnString(std::string str);
void fillGrid(Grid<int> &grid, Vector<int> &values);
std::string organizeString(std::string str);

/* main */
int main() {
    
    Grid<int> matrix(9, 9);
    Vector<int> values;
    values += 3, 9, 2, 4, 6, 5, 8, 1, 7;
    values += 7, 4, 1, 8, 9, 3, 6, 2, 5;
    values += 6, 8, 5, 2, 7, 1, 4, 3, 9;
    values += 2, 5, 4, 1, 3, 8, 7, 9, 6;
    values += 8, 3, 9, 6, 2, 7, 1, 5, 4;
    values += 1, 7, 6, 9, 5, 4, 2, 8, 3;
    values += 9, 6, 7, 5, 8, 2, 3, 4, 1;
    values += 4, 2, 3, 7, 1, 9, 5, 6, 8;
    values += 5, 1, 8, 3, 4, 6, 9, 7, 2;

    
    fillGrid(matrix, values);
    
    
    if (checkSudokuSolution(matrix)) {
        std::cout << "True";
    } else {
        std::cout << "False";
    }
    
    return 0;
}

/* functions */

bool checkSudokuSolution(Grid<int> &puzzle) {
    if (puzzle.numCols() != 9 || puzzle.numRows() != 9) {
        return false;
    }
    
    Vector<string> theRows(9);
    Vector<string> theColumns(9);
    Vector<string> theBlocks(9);

    // fill all the string vectors
    for (int i = 0; i < puzzle.numRows(); i++) {
        for (int j = 0; j < puzzle.numCols(); j++) {
            
            //verify the integer is smaller than 10 and bigger than 0
            if (puzzle[i][j] <= 0 || puzzle[i][j] > 9) {
                return false; //stops filling right away if it finds a bad value
            }
            
            //fill the row and column vectors
            theRows[i] += integerToString(puzzle[i][j]);
            theColumns[j] += integerToString(puzzle[i][j]);
            
            //fill the block vector
            //for the first 3 blocks left to right
            if (i < 3) {
                if (j < 3) {
                    theBlocks[0] += integerToString(puzzle[i][j]);
                } else if (j >= 3 && j < 6) {
                    theBlocks[1] += integerToString(puzzle[i][j]);
                } else if (j >= 6) {
                    theBlocks[2] += integerToString(puzzle[i][j]);
                }
            //for the second 3 blocks left to right
            } else if (i >= 3 && i < 6) {
                if (j < 3) {
                    theBlocks[3] += integerToString(puzzle[i][j]);
                } else if (j >= 3 && j < 6) {
                    theBlocks[4] += integerToString(puzzle[i][j]);
                } else if (j >= 6) {
                    theBlocks[5] += integerToString(puzzle[i][j]);
                }
            //for the last 3 blocks left to right
            } else if (i >= 6) {
                if (j < 3) {
                    theBlocks[6] += integerToString(puzzle[i][j]);
                } else if (j >= 3 && j < 6) {
                    theBlocks[7] += integerToString(puzzle[i][j]);
                } else if (j >= 6) {
                    theBlocks[8] += integerToString(puzzle[i][j]);
                }
            }
        }
    }
    
    /*print the sudoku sections for testing
     
    std::cout << "Rows:" << std::endl;
    for (int i = 0; i < 9; i++) {
        std::cout << theRows[i] << std::endl;
    }
    std::cout << "Columns:" << std::endl;
    for (int i = 0; i < 9; i++) {
        std::cout << theColumns[i] << std::endl;
    }
    std::cout << "Blocks:" << std::endl;
    for (int i = 0; i < 9; i++) {
        std::cout << theBlocks[i] << std::endl;
    }
    
    */
    
    
    // verify each string vector using "checkRulesOnString"
    for (int i = 0; i < 9; i++) {
        if (!checkRulesOnString(theBlocks.get(i))) {
            return false;
        } else if (!checkRulesOnString(theRows.get(i))) {
            return false;
        } else if (!checkRulesOnString(theColumns.get(i))) {
            return false;
        }
    }
    return true;
}

// verifies the string has 1-9 and no repeats
bool checkRulesOnString(std::string str) {
    if (organizeString(str) == "123456789") {
        return true;
    }
    return false;
}

void fillGrid(Grid<int> &grid, Vector<int> &values) {
    int count = 0;
    for (int i = 0; i < grid.numRows(); i++) {
        for (int j = 0; j < grid.numCols(); j++) {
            grid.set(i, j, values.get(count));
            count++;
        }
    }
}

std::string organizeString(std::string str) {
    int numberToCheck = 1;
    std::string newStr;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (str.substr(j, 1) == integerToString(numberToCheck)) {
                newStr += str.substr(j, 1);
                numberToCheck++;
            }
        }
        }
    
    
    return newStr;
}



