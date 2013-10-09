/*
 * File: 1_1.cpp
 * -------------
 * This program reads a number in Celcius and converts it to
 * Fahrenheit. *
 *
*/

#include <iostream>
#include "console.h"


// Constants
const int SENTINEL = -1;

int main() {
    setConsoleSize(700, 400);

    int value;
    int runningTotal = 0;
    int count = 0;

    std::cout << "This program finds the averages integers in a list." << std::endl;
    std::cout << "Enter " << SENTINEL << " to signal the end of the list." << std::endl;

    while (true) {

        std::cout << "? ";
        std::cin >> value;
        if (value == SENTINEL) break;
        runningTotal += value;
        count++;
    }

    std::cout << "The average score was " << runningTotal / count << ".";

    return 0;
}
