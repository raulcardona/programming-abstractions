/*
 * File: 3_02.cpp
 * -------------
 * A program with a function to trim whitespace 
 * from the front and back of the string
 *
 */

#include <iostream>
#include <string>
#include "simpio.h"

using namespace std;

/* Constants */



/* Function Prototypes */
string trim(string str);



/* main */
int main() {
    string line;
    string trimmedLine;
    cout << "Enter a line of text: ";
    getline(cin, line);
    trimmedLine = trim(line);
    cout << "The trimmed line is: " << trimmedLine;
    
    return 0;
}
/* This function employs two while(true) loops 
 * one for the front of the string
 * and one for the back */
string trim(string str) {
    while (true) {
        if (str.at(0) == ' ') {
            str.erase(0, 1);
        } else break;
    }
    
    while (true) {
        if (str.at(str.length() - 1) == ' ') {
            str.erase(str.length() - 1, 1);
        } else break;
    }
    
    return str;
}