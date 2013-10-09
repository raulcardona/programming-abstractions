/*
 * File: 2_2.cpp
 * -------------
 * Meters to Inches and Feet
 * Now with functions!
 */

#include <iostream>
using namespace std;

// Constants
const int SENTINEL = 0;

int convertToFeet(int value);
int convertToInches(int value);

int main() {
    
    double value;
    
    while (true) {
        
        cout << "Enter a value in meters to convert to feet and inches: ";
        cin >> value;
        if (value == SENTINEL) break;
        
        cout << value << " meters in US measurement would be " << convertToFeet(value) << " feet and " << convertToInches(value) << " inches." << endl;
    }
    return 0;
}

int convertToFeet(int value) {
    int feet = 0;
    int totalInches = value / 0.0254;
    feet = totalInches / 12;
    return feet;
}

int convertToInches(int value) {
    int inches;
    int totalInches = value / 0.0254;
    inches = totalInches % 12;
    return inches;
}
