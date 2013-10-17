/*
 * File: 3_08.cpp
 * -------------
 * A function to remove characters from a line!
 * adjusted to remove the characters in place instead
 * of returning a new string.
 */

#include <iostream>
#include <string>
#include "simpio.h"

using namespace std;

/* Constants */

/* Enumerated Type */

/* Function Prototypes */
string removeCharactersInPlace(string line, string remove);
bool isLetterToRemove(char c, string remove);

/* main */
int main() {
    string line;
    string remove;
    while (true) {
        cout << "Enter a line: ";
        line = getLine();
        if (line == "") break;
        cout << "Enter letters to remove: ";
        remove = getLine();
        cout << "\"" << line << "\"" << " with " << remove << " removed is " << removeCharactersInPlace(line, remove) << endl;
    }
    
    return 0;
}

// killCount helps offset the shrinking string length.
string removeCharactersInPlace(string line, string remove) {
    for (int i = 0; i < line.length(); i++) {
        if (isLetterToRemove(line.at(i), remove)) {
            line.erase(i, 1);
            i--;
        }
    }
    
    return line;
}

bool isLetterToRemove(char c, string remove){
    for (int i = 0; i < remove.length(); i++) {
        if (c == remove.at(i)) {
            return true;
        }
    }
    return false;
}

