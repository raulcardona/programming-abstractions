/*
 * File: 3_17.cpp
 * -------------
 * A Caesar Cypher function!  With uppercase and lowercase even!
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
string encodeCaesarCipher(string str, int shift);


/* main */
int main() {
    while (true) {
        int shift = getInteger("Enter the number of charater positions to shift: ");
        string str = getLine("Enter a message: ");
        if (str == "") break;
        cout << "Encoded message: " << encodeCaesarCipher(str, shift) << endl;
        
    }
    cout << "Program End.";
    
    return 0;
}

string encodeCaesarCipher(string str, int shift) {
    string encoded;
    if (shift < 0) 26 - (-shift % 26); // changes a negative shift into a positive value (ex. -1 --> 25, so 'a' becomes 'z')
    
    for (int i = 0; i < str.length(); i++) {
        if (isupper(str.at(i))) {
            encoded += ('A' + (str.at(i) - 'A' + shift) % 26);
        } else if ( islower(str.at(i))){
            encoded += ('a' + (str.at(i) - 'a' + shift) % 26);
        } else {
            encoded += str.at(i);
        }
        
    }
    
    
    return encoded;
}
