/*
 * File: 3_16.cpp
 * -------------
 * A function for translating into the made up 
 * language of Obenglobish.
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
string obenglobish(string word);

bool isVowel(char ch);

/* main */
int main() {
    while (true) {
        string word = getLine("Enter a word: ");
        if (word == "") break;
        string trans = obenglobish(word);
        cout << word << " -> " << trans << endl;
    }
    
    
    return 0;
}

string obenglobish(string word) {
    string ob = "ob";
    string trans;
    for (int i = 0; i < word.length(); i++) {
        // add consinents
        if (!isVowel(word[i])) trans += word.at(i);
        // check if the last letter is an e or not
        else if (i == word.length() - 1) {
            if (isVowel(word[i]) && word[i] != 'e') {
                trans += ob;
                trans += word.at(i);
            } else if (word[i] == 'e')
                trans += word.at(i);
        // check if it's a vowel and if the previous was a vowel
        } else if (i > 0) {
            if (isVowel(word[i]) && !isVowel(word[i - 1])) {
                trans += ob;
                trans += word.at(i);
            } else {
                trans += word.at(i);
            }
        // adds the first letter -- it's not included above
        // in order to avoid looking at the -1 position in the string
        } else {
            if (isVowel(word[i])) {
                trans += ob;
                trans += word.at(i);
            }
        }
    }
    return trans;
}


bool isVowel(char ch) {
    switch (ch) {
        case 'A': case 'E': case 'I': case 'O': case 'U':
        case 'a': case 'e': case 'i': case 'o': case 'u':
            return true;
        default:
            return false;
    }
}









