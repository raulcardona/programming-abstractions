/*
 * File: 1_2.c]]-pp
 * -------------
 * This program reads a number in Celcius and converts it to
 * Fahrenheit. *
 *
*/

#include <iostream>
#include "console.h"
using namespace std;

// Constants
const int SENTINEL = 0;

int main() {
    setConsoleSize(700, 400);

    double value;

    while (true) {
        cout << "Enter a value in meters to convert to inches: ";
        cin >> value;
        if (value == SENTINEL) break;
        int TotalInches;
        int feet;
        int inches;
        TotalInches = value / 0.0254;
        feet = TotalInches / 12;
        inches = TotalInches % 12;

        cout << value << " meters in US measurement would be " << feet << " feet and " << inches << " inches." << endl;
    }
    return 0;
}

