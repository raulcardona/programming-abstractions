/*
 * File: 2_1.cpp
 * -------------
 * This program reads a number in Celcius and converts it to
 * Fahrenheit. This time with a function!
 *
 */

#include <iostream>
using namespace std;

double convertToFahrenheit(double value);

// Constants
const int SENTINEL = 0;

int main() {
    
    double value;
    
    while (true) {
        cout << "Enter a value in Celcius to convert to Fahrenheit: ";
        cin >> value;
        if (value == SENTINEL) break;
        cout << value << " in Celcius would be " << convertToFahrenheit(value) << endl;
    }
    cout << "goodbye.";
    return 0;
}

double convertToFahrenheit(double value) {
    
    double converted;
    converted = (1.8 * value) + 32;
    return converted;
}