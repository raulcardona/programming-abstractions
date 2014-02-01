/*
 * File: 5_25.cpp
 * -------------
 * Produces a list of all the words in the lexicon by length.
 *
 */

#include <iostream>
#include <iomanip>
#include "lexicon.h"
#include "vector.h"

using namespace std;

/* Constants */

/* Function Prototypes */


/* main */
int main() {
    Lexicon english;
    english.addWordsFromFile("dictionary.txt");
    Vector<int> words(18);
    // C++11 "for" iteration loop
    for (string str : english) {
        words.set(str.length(), (words.get(str.length())) + 1);
    }
    for (int i = 0; i < words.size(); i++) {
        cout << left << setw(10) << i << right << words.get(i) << endl;
    }
    return 0;
}
