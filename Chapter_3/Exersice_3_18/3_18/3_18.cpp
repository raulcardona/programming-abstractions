/*
 * File: 3_18.cpp
 * -------------
 * A letter substitution cipher function
 *
 */

#include <iostream>
#include <string>
#include <cctype>
#include "simpio.h"
using namespace std;

/* Constants */

/* Enumerated Type */

/* Function Prototypes */
string encodeLetterSubCipher(string str, string key);


/* main */
int main() {
    while (true) {
        string key = getLine("Enter 26-letter key: ");
        string str = getLine("Enter a message: ");
        if (str == "") break;
        cout << "Encoded message: " << encodeLetterSubCipher(str, key) << endl;
        
    }
    cout << "Program End.";
    
    return 0;
}

string encodeLetterSubCipher(string str, string key) {
    string encoded;
    for (int i = 0; i < str.length(); i++) {
        if (isupper(str.at(i))) encoded += key.at(str.at(i) - 'A');
        else encoded += str.at(i);
    }
    return encoded;
}

