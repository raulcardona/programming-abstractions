/*
 * File: 3_03.cpp
 * -------------
 * A program with a function to create a 
 * substring from a string with a starting
 * possition and a number of chars to include
 *
 */

#include <iostream>
#include <string>
#include "simpio.h"

using namespace std;

/* Constants */



/* Function Prototypes */
string substr(string str, int pos, int n);



/* main */
int main() {
    string line;
    string subString;
    int start;
    int numChars;
    cout << "Enter a line of text: ";
    getline(cin, line);
    cout << "Enter a string start possition: ";
    start = getInteger("Enter an Integer: ");
    cout << "Enter a number of characters to include: ";
    numChars = getInteger("Enter an Integer: ");
    
    subString = substr(line, start, numChars);
    cout << "The substring is: " << subString;
    
    return 0;
}

string substr(string str, int pos, int n) {
    string subString = "";
    for (int i = 0; i < n; i++) {
        subString += str.at(pos + i);
    }
    return subString;
}
    
