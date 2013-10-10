/*
 * File: 2_13.cpp
 * -------------
 * Aproximate PI
 * 
 * This program simulates 10,000 darts being thrown at a circle in a square.
 * The dart lies inside the circle if x^2 + y^2 < 1
 * The result should be PI/4
 */

#include <iostream>
#include "random.h"

using namespace std;

int const DARTS_TROWN = 10000;

/* Function Prototypes */
void throwDarts(int & in);
void printResults(double ratio, int in);

int main() {
    int dartsInside = 0;
    double ratio = 0.0;
    
    throwDarts(dartsInside);
    ratio = double(dartsInside) / DARTS_TROWN;
    printResults(ratio, dartsInside);
    
    return 0;
}


void throwDarts(int & in) {
    double x, y;
    
    for (int i = 0; i < DARTS_TROWN; i++) {
        x = randomReal(-1, 1);
        y = randomReal(-1, 1);
        
        if ((x * x) + (y * y) < 1) in++;
    }
}

void printResults(double ratio, int in) {
    cout << DARTS_TROWN << " darts reveal:" << endl;
    cout << in << " fell inside the circle" << endl;
    cout << "creating a ratio of " << ratio << endl;
    cout << "multiply by 4 to get the PI approximation of: " << ratio * 4.0;
}
