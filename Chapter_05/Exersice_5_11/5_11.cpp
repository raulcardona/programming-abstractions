
/*
 * File: 5_11.cpp
 * -------------
 * This program saves the values in a grid when resized
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
void reshape(Grid<int> &grid, int nRows, int nCols);
void printGrid(Grid<int> counts);
void fillGrid(Grid<int> &grid, Vector<int> &values);


/* main */
int main() {
    Vector<int> values;
    Grid<int> grid(2, 5);
    
    values += 1, 2, 3, 4, 5;
    values += 6, 7, 8, 9, 1;
    
    fillGrid(grid, values);
    printGrid(grid);
    std::cout << std::endl;
    reshape(grid, 2, 12);
    printGrid(grid);
    
    return 0;
}

/* functions */

void reshape(Grid<int> &grid, int nRows, int nCols) {
	Vector<int> values;
	for (int i = 0; i < grid.numRows(); i++)
	{
		for (int j = 0; j < grid.numCols(); ++j)
		{
			values.add(grid.get(i, j));
		}
	}
	grid.resize(nRows, nCols);
	int numleft = values.size();
	int count = 0;
	for (int i = 0; i < grid.numRows(); ++i)
	{
		for (int j = 0; j < grid.numCols(); ++j)
		{
			if (numleft > 0)
			{
				grid.set(i, j, values[count]);
                count++;
			} else {
                grid.set(i, j, 0);
			}
            numleft--;
		}
	}
    
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

void printGrid(Grid<int> counts) {
    for (int i = 0; i < counts.numRows(); i++) {
        for (int j = 0; j < counts.numCols(); j++) {
            std::cout << counts.get(i, j) << " ";
        }
        std::cout << std::endl;
        
    }
    
}