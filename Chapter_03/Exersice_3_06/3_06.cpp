/*
 * File: 3_06.cpp
 * -------------
 * An Acronym generator!
 *
 */

#include <iostream>
#include <string>
#include "simpio.h"

using namespace std;

/* Constants */

/* Enumerated Type */

/* Function Prototypes */
string acronymGenerator(string line);

/* main */
int main() {
    string line;
    while (true) {
        cout << "Enter a line: ";
        line = getLine();
        if (line == "") break;
        cout << "\"" << line << "\"" << " as an acronym is " << acronymGenerator(line) << endl;
    }
    
    return 0;
}

string acronymGenerator(string line) {
    string acronym;
    for (int i = 0; i < line.length(); i++) {
        if (i == 0) {
            acronym += toupper(line.at(i));
        } else if (!isalpha(line.at(i))) {
            acronym += toupper(line.at(i + 1));
        }
    }
    
    
    
    
    
    return acronym;
}
