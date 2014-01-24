/*
 * File: 2_3.cpp
 * -------------
 *  Rounding Floating Point numbers
 */

#include <iostream>
using namespace std;

float const NUMBER = 1.544;

int roundToNearestInt(float x);

int main() {
    cout << NUMBER << " rounded becomes " << roundToNearestInt(NUMBER);
return 0;
}

int roundToNearestInt(float x) {
    int roundedNumber = 0;
    if (x > 0) {
        x += 0.5;
    } else {
        x -= 0.5;
    }
    roundedNumber = x; // float to int truncation is here
    return roundedNumber;
}

