/*
 * File: 3_09.cpp
 * -------------
 * A function to remove double letters
 * leaving just a single
 *
 */

#include <iostream>
#include <string>
#include "simpio.h"

using namespace std;

/* Constants */

/* Enumerated Type */

/* Function Prototypes */
string removeDoubleLetters(string line);

/* main */
int main() {
    string line;
    string remove;
    while (true) {
        cout << "Enter a line: ";
        line = getLine();
        if (line == "") break;
        cout << "\"" << line << "\"" << " with doubles removed is " << removeDoubleLetters(line) << endl;
    }
    
    return 0;
}


string removeDoubleLetters(string line) {
    for (int i = 1; i < line.length(); i++) {
        if (line.at(i) == line.at(i - 1)) {
            line.erase(i, 1);
        }
    }
    
    
    return line;
}
