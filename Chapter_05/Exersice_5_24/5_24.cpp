/*
 * File: 5_24.cpp
 * -------------
 * Produces a list of all the words that can use an "s" tile to make a new
 * word, in Scrabble.
 *
 */

#include <iostream>
#include "lexicon.h"

using namespace std;

/* Constants */

/* Function Prototypes */


/* main */
int main() {
    Lexicon english;
    english.addWordsFromFile("dictionary.txt");
    int total = 0;
    int totalWords = english.size();
    // C++11 "for" iteration loop
    for (string str : english) {
        string prefix = "s" + str;
        string suffix = str + "s";
    	if (english.contains(prefix) && english.contains(suffix)) {
            cout << str << " :: " << prefix << " & " << suffix << endl;
            total++;
        }
    }
    cout << endl << "The total number of words: " << totalWords << endl;
    cout << "The total S words: " << total << endl;
    return 0;
}
