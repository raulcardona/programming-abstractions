//
//  pegBoard.cpp
//  Programming Abstractions C++
//
//  Created by Ben Mills on 10/21/14.
//
//

#include "pegBoard.h"
using namespace std;

const char EMPTY_SPACE = '.';
const char PEG = 'x';
const char HOLE = 'O';
const int START_HOLE_POINT = 3;
const char MARK = '^';

PegBoard::PegBoard(int cRows, int cColumns, int cCornerSize) {
    numRows = cRows;
    numColumns = cColumns;
    cornerSize = cCornerSize;
    board.resize(numRows, numColumns);
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++) {
            if ((i < cornerSize && j < cornerSize) || (i < cornerSize && j >= (numColumns - cornerSize)) || (i >= (numRows - cornerSize) && j < cornerSize) || (i >= (numRows - cornerSize) && j >= (numRows - cornerSize))) {
                board.set(i, j, EMPTY_SPACE);
            } else if (i == START_HOLE_POINT && j == START_HOLE_POINT) {
                board.set(i, j, HOLE);
            } else {
                board.set(i, j, PEG);
            }
        }
    }
}

Vector<Point> PegBoard::getListOfHoles() {
    Vector<Point> list;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++) {
            if (isOnBoard(Point(i, j)) && board.get(i, j) == HOLE) {
                list.add(Point(i, j));
            }
        }
    }
    return list;
}

Vector<Point> PegBoard::getListOfPegs() {
    Vector<Point> list;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++) {
            if (isOnBoard(Point(i, j)) && board.get(i, j) == PEG) {
                list.add(Point(i, j));
            }
        }
    }
    return list;
}

bool PegBoard::canJump(Point hole, Direction dir) {
    Point jumpingPeg;
    Point pegToRemove;
    switch (dir) {
        case NORTH:
            jumpingPeg = Point(hole.getX() + 2, hole.getY());
            pegToRemove = Point(hole.getX() + 1, hole.getY());
            break;
        case EAST:
            jumpingPeg = Point(hole.getX(), hole.getY() - 2);
            pegToRemove = Point(hole.getX(), hole.getY() - 1);
            break;
        case SOUTH:
            jumpingPeg = Point(hole.getX() - 2, hole.getY());
            pegToRemove = Point(hole.getX() - 1, hole.getY());
            break;
        case WEST:
            jumpingPeg = Point(hole.getX(), hole.getY() - 2);
            pegToRemove = Point(hole.getX(), hole.getY() - 1);
            break;
        default:
            break;
    }
    if (isVacant(hole) && isOnBoard(jumpingPeg) && !isVacant(jumpingPeg) && !isVacant(pegToRemove)) {
        return true;
    } else {
        return false;
    }
    
}

void PegBoard::jump(Point hole, Direction dir) {
    switch (dir) {
        case NORTH:
            if (isOnBoard(Point(hole.getX() + 2, hole.getY()))) {
                board.set(hole.getX(), hole.getY(), PEG);
                board.set(hole.getX() + 1, hole.getY(), HOLE);
                board.set(hole.getX() + 2, hole.getY(), HOLE);
            }
            break;
        case EAST:
            if (isOnBoard(Point(hole.getX(), hole.getY() - 2))) {
                board.set(hole.getX(), hole.getY(), PEG);
                board.set(hole.getX(), hole.getY() - 1, HOLE);
                board.set(hole.getX(), hole.getY() - 2, HOLE);
            }
            break;
        case SOUTH:
            if (isOnBoard(Point(hole.getX() - 2, hole.getY()))) {
                board.set(hole.getX(), hole.getY(), PEG);
                board.set(hole.getX() - 1, hole.getY(), HOLE);
                board.set(hole.getX() - 2, hole.getY(), HOLE);
            }
            break;
        case WEST:
            if (isOnBoard(Point(hole.getX(), hole.getY() + 2))) {
                board.set(hole.getX(), hole.getY(), PEG);
                board.set(hole.getX(), hole.getY() + 1, HOLE);
                board.set(hole.getX(), hole.getY() + 2, HOLE);
            }
            break;
            
        default:
            break;
    }
}

void PegBoard::unJump(Point hole, Direction dir) {
    switch (dir) {
        case NORTH:
                board.set(hole.getX(), hole.getY(), HOLE);
                board.set(hole.getX() + 1, hole.getY(), PEG);
                board.set(hole.getX() + 2, hole.getY(), PEG);
            break;
        case EAST:
                board.set(hole.getX(), hole.getY(), HOLE);
                board.set(hole.getX(), hole.getY() - 1, PEG);
                board.set(hole.getX(), hole.getY() - 2, PEG);
            break;
        case SOUTH:
                board.set(hole.getX(), hole.getY(), HOLE);
                board.set(hole.getX() - 1, hole.getY(), PEG);
                board.set(hole.getX() - 2, hole.getY(), PEG);
            break;
        case WEST:
                board.set(hole.getX(), hole.getY(), HOLE);
                board.set(hole.getX(), hole.getY() + 1, PEG);
                board.set(hole.getX(), hole.getY() + 2, PEG);
            break;
            
        default:
            break;
    }
}

void PegBoard::mark(Point hole) {
    board.set(hole.getX(), hole.getY(), MARK);
}

int PegBoard::numPegsLeft() {
    int count = 0;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++) {
            Point check(i, j);
            if (isOnBoard(check) && board.get(i, j) == PEG) {
                count++;
            }
        }
    }
    return count;
}

bool PegBoard::isVacant(Point p) {
    if (board.get(p.getX(), p.getY()) == HOLE) {
        return true;
    } else {
        return false;
    }
}

bool PegBoard::isOnBoard(Point p) {
    if (board.inBounds(p.getX(), p.getY()) && board.get(p.getX(), p.getY()) != EMPTY_SPACE) {
        return true;
    } else {
        return false;
    }
}

std::string PegBoard::toString() {
    string str;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++) {
            str += board.get(i, j);
        }
        str += '\n';
    }
    return str;
}