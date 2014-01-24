/*
 * File: 3_07.cpp
 * -------------
 * A function to remove characters from a line!
 *
 */

#include <iostream>
#include <string>
#include "simpio.h"

using namespace std;

/* Constants */

/* Enumerated Type */

/* Function Prototypes */
string removeCharacters(string line, string remove);
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
        cout << "\"" << line << "\"" << " with " << remove << " removed is " << removeCharacters(line, remove) << endl;
    }
    
    return 0;
}

// killCount helps offset the shrinking string length.
string removeCharacters(string line, string remove) {
    string newLine = line;
    int killCount = 0;
    for (int i = 0; i < line.length(); i++) {
        if (isLetterToRemove(line.at(i), remove)) {
            newLine.erase(i - killCount, 1);
            killCount++;
        }
    }
    
    return newLine;
}

bool isLetterToRemove(char c, string remove){
    for (int i = 0; i < remove.length(); i++) {
        if (c == remove.at(i)) {
            return true;
        }
    }
    return false;
}

