//
//  cube.cpp
//  Programming Abstractions C++
//
//  Created by Ben Mills on 10/8/14.
//
//
#include "vector.h"
#include "cube.h"
#include <string>

using namespace std;

Cube::Cube() {
    //empty
}

Cube::Cube(char s0, char s1, char s2, char s3, char s4, char s5) {
    side0 = s0;
    side1 = s1;
    side2 = s2;
    side3 = s3;
    side4 = s4;
    side5 = s5;
    
}

char Cube::getFace(int sideNum) {
    switch (sideNum) {
        case 0:
            return side0;
        case 1:
            return side1;
        case 2:
            return side2;
        case 3:
            return side3;
        case 4:
            return side4;
        case 5:
            return side5;
        default:
            return -1;
    }
}

Vector<char> Cube::getRotationSides(int head) {
    Vector<char> vec;
    switch (head) {
        case 0:
            return vec += side1, side2, side3, side4;
        case 1:
            return vec += side0, side2, side4, side5;
        case 2:
            return vec += side0, side1, side3, side5;
        case 3:
            return vec += side0, side2, side4, side5;
        case 4:
            return vec += side0, side1, side3, side5;
        case 5:
            return vec += side1, side2, side3, side4;
        default:
            return vec;
    }
}

string Cube::toString() {
    string s0;
    string s1;
    string s2;
    string s3;
    string s4;
    string s5;
    s0 += side0;
    s1 += side1;
    s2 += side2;
    s3 += side3;
    s4 += side4;
    s5 += side5;
    
    return "{ " + s0 + ", " + s1 + ", " + s2 + ", " + s3 + ", " + s4 + ", " + s5 + " }";
}






