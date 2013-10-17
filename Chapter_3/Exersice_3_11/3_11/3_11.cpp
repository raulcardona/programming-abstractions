/*
 * File: 3_11.cpp
 * -------------
 * A function to find a palindrome that ignores punctuation
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
bool isSentancePalindrome(string str);
string reverseLine(string str);
string removePunctuation(string str);


/* main */
int main() {
    while (true) {
        string line;
        cout << "This program tests for sentance palindromes." << endl;
        cout << "Indicate the end of the input with a blank line." << endl;
        cout << "Enter a sentance: ";
        line = getLine();
        if (line == "") break;
        line = removePunctuation(line);
        if (isSentancePalindrome(line)) {
            cout << "That sentance is a palindrome." << endl << endl;
        } else {
            cout << "That sentance is not a palindrom." << endl << endl;
        }
    }
    
    return 0;
}


bool isSentancePalindrome(string str) {
    if (equalsIgnoreCase(str, reverseLine(str))) {
        return true;
    }
    return false;
}

string reverseLine(string str) {
    string reverse;
    for (int i = str.length() - 1; i >= 0; i--) {
        reverse += str.at(i);
    }
    return reverse;
}

string removePunctuation(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (!isalpha(str.at(i))) {
            str.erase(i, 1);
            i--;  // this makes sure that double punctuation or spaces get axed.
        }
    }
    return str;
}