//
//  File: 9_06.cpp
//  Programming Abstractions C++
//
//	Exercise Description:
//
//  Created by Ben Mills on 10/5/14.
//

#include <stdio.h>
#include "grid.h"
#include "gwindow.h"
#include "gobjects.h"

const int SQUARE_SIZE = 100;
const int BOARD_SIZE = 8;
const int MAX_MOVES = 8;


bool canHazKnightsTour(Grid<int> &board, GPoint start, int count);
void placeKnight(Grid<int> &board, GPoint point, int count);
void removeKnight(Grid<int> &board, GPoint point);
GPoint getNextPoint(int num, GPoint point);
bool isNewSpace(Grid<int> board, GPoint point);

int main() {
    Grid<int> board(BOARD_SIZE, BOARD_SIZE);
    GPoint start(0, 0);
    int count = 1;
    if (canHazKnightsTour(board, start, count)) {
        cout << "Yes" << endl;
        cout << board << endl;
    } else {
        cout << "Nope" << endl;
        cout << board << endl;
    }
    return 0;
}

bool canHazKnightsTour(Grid<int> &board, GPoint start, int count) {
    if (count == BOARD_SIZE * BOARD_SIZE + 1) {
        return true;
    }
    for (int i = 0; i < MAX_MOVES; i++) {
        if (board.inBounds(start.getX(), start.getY())) {
            if (isNewSpace(board, start)) {
                placeKnight(board, start, count);
                if (canHazKnightsTour(board, getNextPoint(i, start), count + 1)) {
                    return true;
                }
                removeKnight(board, start);
            }
        }
    }
    return false;
}

GPoint getNextPoint(int num, GPoint point) {
    switch (num) {
        case 0: {
            GPoint nextPoint(point.getX() + 1, point.getY() + 2);
            return nextPoint;
        }
        case 1: {
            GPoint nextPoint(point.getX() + 2, point.getY() + 1);
            return nextPoint;
        }
        case 2: {
            GPoint nextPoint(point.getX() + 2, point.getY() - 1);
            return nextPoint;
        }
        case 3: {
            GPoint nextPoint(point.getX() + 1, point.getY() - 2);
            return nextPoint;
        }
        case 4: {
            GPoint nextPoint(point.getX() - 1, point.getY() - 2);
            return nextPoint;
        }
        case 5: {
            GPoint nextPoint(point.getX() - 2, point.getY() - 1);
            return nextPoint;
        }
        case 6: {
            GPoint nextPoint(point.getX() - 2, point.getY() + 1);
            return nextPoint;
        }
        case 7: {
            GPoint nextPoint(point.getX() - 1, point.getY() + 2);
            return nextPoint;
        }
    }
}

void placeKnight(Grid<int> &board, GPoint point, int count) {
    board.set(point.getX(), point.getY(), count);
}

void removeKnight(Grid<int> &board, GPoint point) {
    board.set(point.getX(), point.getY(), 0);
}

bool isNewSpace(Grid<int> board, GPoint point) {
    if (board.get(point.getX(), point.getY()) == 0) {
        return true;
    } else {
        return false;
    }
}

