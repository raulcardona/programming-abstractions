/*
 * File: 5_23.cpp
 * -------------
 * Get all the 2 letter words and list the ones that will still be
 * a word if we add a letter to the front or the back.
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
    // C++11 "for" iteration loop
    for (string str : english) {
    	if (str.length() == 2) {
            char alphabet = 'a';
            while (alphabet <= 'z') {
                string a = alphabet + str;
                string b = str + alphabet;
                if (english.contains(a)) {
                    cout << str << " + " << alphabet << " ---> " << a << endl;
                } else if (english.contains(b)) {
                    cout << str << " + " << alphabet << " ---> " << b << endl;
                }
                alphabet++;
            }
        }
    }
    return 0;
}
