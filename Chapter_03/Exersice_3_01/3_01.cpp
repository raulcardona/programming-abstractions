/*
 * File: 3_01.cpp
 * -------------
 * A program with a function to add a suffix to a string
 *
 */

#include <iostream>
#include <string>

using namespace std;

/* Constants */



/* Function Prototypes */
bool endsWith(string str, string suffix);
bool endsWith(string str, char suffix);


/* main */
int main() {
    string suffix;
    string word;
    cout << "Enter a word: ";
    cin >> word;
    cout << "Enter a suffix: ";
    cin >> suffix;
    
    if (endsWith(word, suffix)) {
        cout << endl << "Match!";
    } else cout << endl << "No Match.";
    
    return 0;
}

bool endsWith(string str, string suffix) {
    int suffixLength = suffix.length();
    int strLength = str.length();
    int startPos = strLength - suffixLength;
    string comparer = "";
    int suffixPos = 0;
    
    for (int i = startPos; i < strLength; i++) {
        
        if (str.at(i) == suffix.at(suffixPos)) {
            comparer += str.at(i);
            suffixPos++;
        }
    }
    if (comparer == suffix) return true;
    else return false;
}
