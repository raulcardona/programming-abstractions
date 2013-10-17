/*
 * File: 3_07.cpp
 * -------------
 * A function to remove characters from a line!
 *
 */

#include <iostream>
#include <string>
#include "simpio.h"
#include "strlib.h"

using namespace std;

/* Constants */

/* Enumerated Type */

/* Function Prototypes */
string createOrdinalForm(string n);

/* main */
int main() {
    while (true) {
        string line;
        cout << "Enter an integer: ";
        line = getLine();
        if (line == "") break;
        cout << line << " in ordinal form is " << createOrdinalForm(line) << endl;
    }
    
    return 0;
}

string createOrdinalForm(string n) {
    int intN = stringToInteger(n);
    string ordinal;
   
    if (intN > 9 && n.at(n.length() - 2) == '1') {
        ordinal = n + "th";
    } else {
        int lastDigit = intN % 10;
        switch (lastDigit) {
            case 1:
                ordinal = n + "st";
                break;
            case 2:
                ordinal = n + "nd";
                break;
            case 3:
                ordinal = n + "rd";
                break;
            default:
                ordinal = n + "th";
                break;
        }
        
    }
    return ordinal;
}