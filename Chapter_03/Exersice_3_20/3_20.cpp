/*
 * File: 3_20.cpp
 * -------------
 * This program matches DNA strands.  The function for finding the match
 * returns the position in the string where the match begins.
 * Cytosine and Guanine match each other and Adenosine with Thymine.
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
int findDNAMatch(string s1, string s2, int start = 0);
string createAttachableDNA(string s);

/* main */
int main() {
    string s2 = getLine("Enter a DNA sequence: ");
    string s1 = getLine("Enter a sequence to search for: ");
    int start = getInteger("Enter a specific position to begin: ");
    int position = findDNAMatch(s1, s2, start);
    if (position == -1) {
        cout << "No match found.";
    } else {
        cout << "Match found at position " << position << "." << endl;
    }
        return 0;
}


int findDNAMatch(string s1, string s2, int start) {
    
    string attach = createAttachableDNA(s1);
    return s2.find(attach); // find will return -1 if not found.
    
}

string createAttachableDNA(string s) {
    for (int i = 0; i < s.length(); i++) {
        switch (s.at(i)) {
            case 'C':
                s.at(i) = 'G';
                break;
            case 'G':
                s.at(i) = 'C';
                break;
            case 'A':
                s.at(i) = 'T';
                break;
            case 'T':
                s.at(i) = 'A';
                break;
                
            default:
                break;
        }
    }
    return s;
}

