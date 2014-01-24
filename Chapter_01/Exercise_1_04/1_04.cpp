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

    int numberOfIntegers;
    int sum = 0;
    int currentNumber = 1;
    cout << "Please enter the number of odd integers you would like to add together: ";
    cin >> numberOfIntegers;

    for(int i = 0; i < numberOfIntegers; i++) {

        if (i == 0) {
            cout << currentNumber;
        }
        else {
            cout << " + " << currentNumber;
        }
        sum += currentNumber;
        currentNumber = currentNumber + 2;

    }

    cout << "." << "  The sum is " << sum << ".";

    return 0;
}

