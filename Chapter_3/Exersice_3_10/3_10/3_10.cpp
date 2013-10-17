/*
 * File: 3_10.cpp
 * -------------
 * A function to replace characters with
 * chosen characters.
 *
 */

#include <iostream>
#include <string>
#include "simpio.h"

using namespace std;

/* Constants */

/* Enumerated Type */

/* Function Prototypes */
string replaceAll(string line, char c1, char c2);

/* main */
int main() {
    string line;
    char c1, c2;
    
    cout << "Enter a line: ";
    line = getLine();
    cout << "Enter a letter to change: ";
    cin >> c1;
    cout << "Enter the letter to be the replacement: ";
    cin >> c2;
    cout << "\"" << line << "\"" << " with " << c2 << " replacing " << c2 << " is " << replaceAll(line, c1, c2);
    
    return 0;
}

string replaceAll(string line, char c1, char c2) {
    for (int i = 0; i < line.length(); i++) {
        if (line.at(i) == c1) {
            line.at(i) = c2;
        }
    }
    
    return line;
}