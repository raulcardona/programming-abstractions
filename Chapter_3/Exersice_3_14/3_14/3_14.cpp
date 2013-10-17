/*
 * File: 3_14.cpp
 * -------------
 * A function to add commas to large numbers
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
string addCommas(string digits);

/* main */
int main() {
    while (true) {
        string digits;
        cout << "Enter a number";
        getline(cin, digits);
        if (digits == "") break;
        cout << addCommas(digits) << endl;
    }
    
    return 0;
}

string addCommas(string digits) {
   
    int commaCount = digits.length() / 3.01;
    int length = digits.length();
    
    for (int i = commaCount; i > 0; i--) {
        int insertionPoint = length - (i * 3);
        digits.insert(insertionPoint, 1, ',');
        length++;
    }
    
    
    
    return digits;
}