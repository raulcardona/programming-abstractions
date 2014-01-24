/*
 * File: 1_1.cpp
 * -------------
 * This program reads a number in Celcius and converts it to
 * Fahrenheit. *
 *
*/

#include <iostream>
#include "StanfordCPPLib/console.h"
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
        double inches;

        inches = value * 0.0254;
        cout << endl << value << " meters as inches would be " << inches << " inches." << endl;
    }

    return 0;
}
