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



int main() {
    setConsoleSize(700, 400);

    int runningTotal = 0;
    for(int i = 1; i < 101; i++) {
        runningTotal += i;
        cout << i << "  : " << runningTotal << endl;
    }

    return 0;
}

