//
//  cube.h
//  Programming Abstractions C++
//
//  Created by Ben Mills on 10/8/14.
//
//
//  Cube class to define a cube of 6 sides.
//  Cube sides are numbered top to bottom left to right when viewed in the
//  flat diagram in the book i.e. the "heads" would be side 0 and side 5.
//  If I was better at ascii art this would be much better:
//			0
//	1	2	3 	4
//			5


#ifndef __Programming_Abstractions_C____cube__
#define __Programming_Abstractions_C____cube__

#include <stdio.h>


#include "vector.h"

class Cube {
    
public:
    
    Cube();
    Cube(char s0, char s1, char s2, char s3, char e4, char e5);
    char getFace(int sideNum);
    
    // This function will return a vector of just the 4 sides we need to test against the other cubes (not the "heads").
    // We just supply the cube object and which side we are using as a head.
    // The returned vector will never include the head or the side opposite the head in 3d space.
    Vector<char> getRotationSides(int head);
    
    
    
    std::string toString();
    
private:
    char side0;
    char side1;
    char side2;
    char side3;
    char side4;
    char side5;
    
    
};


#endif /* defined(__Programming_Abstractions_C____cube__) */
