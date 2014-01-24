/*
 * File: 3_12.cpp
 * -------------
 * A function to make words plural
 *
 */

#include <iostream>
#include <string>
#include "simpio.h"

using namespace std;

/* Constants */

/* Enumerated Type */

/* Function Prototypes */
string createRegularPlural(string line);
string getLastTwoCharacters(string line);
bool isVowel(char c);
string removeLastChar(string line);

/* main */
int main() {
    string line;
    while (true) {
        cout << "Enter a line: ";
        line = getLine();
        if (line == "") break;
        cout << "\"" << line << "\"" << " pluralized is " << createRegularPlural(line) << endl;
    }
    
    return 0;
}

string createRegularPlural(string line) {
    string lastTwo = getLastTwoCharacters(line);
    
    if (lastTwo.at(1) == 's' || lastTwo.at(1) == 'x' ||
        lastTwo.at(1) == 'z' || lastTwo == "ch" ||
        lastTwo == "sh") {
        line += "es";
    } else if (!isVowel(lastTwo.at(0)) && (lastTwo.at(1) == 'y')) {  //checks second to last letter is consinent
        line = removeLastChar(line); //removes the y
        line += "ies";
    } else line += 's';
    
    return line;
}

string getLastTwoCharacters(string line) {
    string secondToLast;
    string last;
    string lastTwo;
    
    secondToLast = line.at(line.length() - 2);
    last = line.at(line.length() - 1);
    lastTwo = secondToLast + last;
    return lastTwo;
}

bool isVowel(char c) {
    switch (c) {
        case 'a':
            return true;
            break;
        case 'e':
            return true;
            break;
        case 'i':
            return true;
            break;
        case 'o':
            return true;
            break;
        case 'u':
            return true;
            break;
            
        default:
            return false;
            break;
    }
}

string removeLastChar(string line) {
    line = line.erase(line.length(), 1);
    return line;
}
