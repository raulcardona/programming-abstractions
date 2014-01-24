/*
 * File: 3_04.cpp
 * -------------
 * Includes a function capitalize(str) were a new string is returned
 * that capitalizes the first letter only.  All other characters are stet
 * to lowercase
 *
 */

#include <iostream>
#include <string>
#include "simpio.h"

using namespace std;

/* Constants */



/* Function Prototypes */
string capitalize(string str);


/* main */
int main() {
    string line = "i wish I had a BRAIN.";
    cout << capitalize(line);
    
    return 0;
}

string capitalize(string str) {
    string newStr = str;
    if (isalpha(str.at(0)) ) {
        newStr.at(0) = toupper(str.at(0));
    }
    for (int i = 1; i < str.length(); i++) {
        newStr.at(i) = tolower(str.at(i));
    }
    return newStr;
}
