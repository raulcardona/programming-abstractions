/*
 * File: 5_22.cpp
 * -------------
 * Find all the palindromes in EnglishWords.dat
 *
 */

#include <iostream>
#include "lexicon.h"

using namespace std;

/* Constants */

/* Function Prototypes */
string reverse(string str);
bool isPalendrome(string str);

/* main */
int main() {
    Lexicon english;
    english.addWordsFromFile("dictionary.txt");
    // C++11 "for" iteration loop
    for (string str : english) {
    	if (isPalendrome(str)) {
    		cout << str << endl;
    	}
    }
    return 0;
}

string reverse(string str) {
	string rev = "";
	for (int i = str.length() -1; i >= 0; i--) {
		rev += str[i];
	}
	return rev;
}

bool isPalendrome(string str) {
	return str == reverse(str);
}