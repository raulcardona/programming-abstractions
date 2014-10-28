//
//  pegBoard.h
//  Programming Abstractions C++
//
//  Created by Ben Mills on 10/21/14.
//
//

#ifndef __Programming_Abstractions_C____pegBoard__
#define __Programming_Abstractions_C____pegBoard__

#include <stdio.h>
#include <string>
#include "point.h"
#include "direction.h"
#include "grid.h"

class PegBoard {
public:
   
    PegBoard(int cRows, int cColumns, int cCornerSize);
    
    Vector<Point> getListOfHoles();
    
    Vector<Point> getListOfPegs();
    
    int numPegsLeft();
    
    bool isVacant(Point p);
    
    bool isOnBoard(Point p);
    
    bool canJump(Point hole, Direction dir);
    
    //  The jump dir is the direction of movement for the jump
    void jump(Point hole, Direction dir);
    
    //  Reset the last move
    void unJump(Point hole, Direction dir);
    
    void mark(Point hole);
    
    std::string toString();
    
    
    //  Instance Variables:
    int numRows;
    int numColumns;
    int cornerSize;
    Grid<char> board;

    Point p;
    Point hole;
    Direction dir;
    
    
};

#endif /* defined(__Programming_Abstractions_C____pegBoard__) */
