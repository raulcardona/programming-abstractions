//
//  9_08.cpp
//  Programming Abstractions C++
//
//  Created by Ben Mills on 10/11/14.
//
//
//  Currently gets stuck in infinite loop when run.  Using some "cout"s to print the gameboard
//  Shows it working but alas it gets stuck.
//  The logic of the algorythm seems good but something gets stuck at 8 pegs left.
//  Logged and will address later - spent too much time on it so far.


#include <stdio.h>
#include "pegBoard.h"
#include "console.h"
#include "random.h"

bool solvePegBoard(PegBoard &gameBoard, Vector<Point> holes);

int main() {
    PegBoard gameBoard(7, 7, 2);
    Vector<Point> holes;
    holes += Point(3, 3);
    cout << gameBoard.toString() << endl;
    solvePegBoard(gameBoard, holes);

    
    return 0;
}

bool solvePegBoard(PegBoard &gameBoard, Vector<Point> holes) {
    if (gameBoard.numPegsLeft() <= 1 && !gameBoard.isVacant(Point(3, 3))) {
        cout << "WINNER" << endl;
        cout << endl;
        cout << gameBoard.toString() << endl;
        return true;
    }

    for (int i = 0; i < holes.size(); i++) {
        for (Direction dir = NORTH; dir <= WEST; dir++) {
            if (gameBoard.canJump(holes[i], dir)) {
                gameBoard.jump(holes[i], dir);
                if (solvePegBoard(gameBoard, gameBoard.getListOfHoles())) {
                    return true;
                }
                gameBoard.unJump(holes[i], dir);
            }
        }
    }
    return false;
}
