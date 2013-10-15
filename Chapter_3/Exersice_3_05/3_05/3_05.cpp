/*
 * File: 3_05.cpp
 * -------------
 * Scrabble Points!  User enters a word, the program calculates
 * the score and displays it.
 *
 */

#include <iostream>
#include <string>
#include "simpio.h"

using namespace std;

/* Constants */

/* Enumerated Type */

/* Function Prototypes */
int scrabbleScore(string word);

/* main */
int main() {
    string word;
    while (true) {
        cout << "Enter a word and I'll calcuate the Scrabble score: ";
        word = getLine();
        if (word == "") break;
        cout << word << " is worth " << scrabbleScore(word) << " points." << endl;
    }
    
    return 0;
}

int scrabbleScore(string word) {
    int score = 0;
    for (int i = 0; i < word.length(); i++) {
        if (isupper(word.at(i))) {
            switch (word.at(i)) {
                case 'Q':
                case 'Z':
                    score += 10;
                    break;
                case 'J':
                case 'X':
                    score += 8;
                    break;
                case 'K':
                    score += 5;
                    break;
                case 'F':
                case 'H':
                case 'V':
                case 'W':
                case 'Y':
                    score += 4;
                    break;
                case 'B':
                case 'C':
                case 'M':
                case 'P':
                    score += 3;
                    break;
                case 'D':
                case 'G':
                    score += 2;
                    break;
                default:
                    score += 1;
                    break;
            }

        }
    }
    
    
    return score;
}
