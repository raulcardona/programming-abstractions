//
//  File: 9_05.cpp
//  Programming Abstractions C++
//
//  Exercise Description:
//
//  Created by Ben Mills on 10/4/14.
//
//  Go row by row and try to place a queen if queen can be placed.
//  Blue squares indicate squares that were changed at some point.
//  The two commented out lines can be uncommented to see a print of the grid and/or slow down the process.

#include <stdio.h>
#include "grid.h"
#include "gwindow.h"
#include "gobjects.h"

const int SQUARE_SIZE = 100;
const int NQEEENS = 8;
const int SCREEN_WIDTH_AND_HEIGHT = SQUARE_SIZE * NQEEENS;

bool nQueensPossible(GWindow &gw, Grid<bool> &board, int column);
void drawBoard(GWindow &gw, Grid<bool> board);
bool queenIsSafe(Grid<bool> board, int row, int column);
void placeQueen(GWindow &gw, Grid<bool> &board, int row, int column);
void removeQueen(GWindow &gw, Grid<bool> &board, int row, int column);
bool diagonalIsSafe(Grid<bool> board, int row, int column);
bool horizontalIsSafe(Grid<bool> board, int row, int column);

int main() {
    GWindow gw(SCREEN_WIDTH_AND_HEIGHT, SCREEN_WIDTH_AND_HEIGHT);
    Grid<bool> board(NQEEENS, NQEEENS);
    drawBoard(gw, board);
    if (!nQueensPossible(gw, board, 0)) {
        cout << "Not Possible" << endl;
    } else {
        cout << "Possble" << endl;
        //cout << board << endl;
    }
    
    return 0;
}

void drawBoard(GWindow &gw, Grid<bool> board) {
    for (int i = 0; i < board.numRows(); i++) {
        for (int j = 0; j < board.numCols(); j++) {
            if ((i + j) % 2 != 0) {
                gw.setColor("Black");
            } else {
                gw.setColor("White");
            }
            pause(5);
            gw.fillRect(SQUARE_SIZE * j, SQUARE_SIZE * i, SQUARE_SIZE, SQUARE_SIZE);
        }
    }
}

bool nQueensPossible(GWindow &gw, Grid<bool> &board, int column) {
    if (column >= board.numCols()) {
        return true;
    }
    for (int i = 0; i < board.numRows(); i++) {
        //pause(300);
        if (queenIsSafe(board, i, column)) {
            placeQueen(gw, board, i, column);
            if (nQueensPossible(gw, board, column + 1)) {
                return true;
            }
            removeQueen(gw, board, i, column);
        }
    }
    return false;
}

bool queenIsSafe(Grid<bool> board, int row, int column) {
    if (diagonalIsSafe(board, row, column) && horizontalIsSafe(board, row, column)) {
        return true;
    } else {
        return false;
    }
}

bool diagonalIsSafe(Grid<bool> board, int row, int column) {
    int d1 = row;
    int d2 = row;
    for (int i = column - 1; i >= 0; i--) {
        d1++;
        d2--;
        if ((d1 < board.numRows() && board[d1][i]) || (d2 >= 0 && board[d2][i])) {
            return false;
        }
    }
    return true;
}

bool horizontalIsSafe(Grid<bool> board, int row, int column) {
    for (int i = 0; i < board.numRows(); i++) {
        if (board[row][i]) {
            return false;
        }
    }
    return true;
}

void placeQueen(GWindow &gw, Grid<bool> &board, int row, int column) {
    gw.setColor("Red");
    gw.fillOval(SQUARE_SIZE * row, SQUARE_SIZE * column, SQUARE_SIZE, SQUARE_SIZE);
    board.set(row, column, true);

}

void removeQueen(GWindow &gw, Grid<bool> &board, int row, int column) {
    gw.setColor("Blue");
    gw.fillRect(SQUARE_SIZE * row, SQUARE_SIZE * column, SQUARE_SIZE, SQUARE_SIZE);
    board.set(row, column, false);
}