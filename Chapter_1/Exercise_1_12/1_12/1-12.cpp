/*
 * File: 1_12.cpp
 * -------------
 *  Split the arc of a quarter circle into 10,000 pieces and find the area of each.
 *  It's about PI!
 */

#include <iostream>
#include <math.h>

int const NUMBER_OF_RECTANGLES = 10000;
double const RADIUS = 2.0;
double const WIDTH = RADIUS / NUMBER_OF_RECTANGLES;

int main() {
    double x = WIDTH / 2;
    double h = 0.0;
    double area = 0.0;
    
    for (int i = 0; i < NUMBER_OF_RECTANGLES; i++) {
        h = sqrt((RADIUS * RADIUS) - (x * x));
        
        area += (h * WIDTH);
        x += WIDTH;
    }
    
    std::cout << area;
}
