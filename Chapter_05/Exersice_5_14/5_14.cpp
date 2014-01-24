
/*
 * File: 5_14.cpp
 * -------------
 * This program checks for correct use of bracketing operators
 *
 */

/* Imports */
#include <iostream>
#include <fstream>
#include "stack.h"
#include "simpio.h"
#include "strlib.h"
#include "benfile.h"

/* Function Prototypes */
bool isCorrectlyBracketed(std::string str);

/* main */
int main() {
    std::ifstream inFile;
    std::string fileName = promptUserForFile(inFile, "Enter a file to check: ");
    std::string line;
    int lineCount = 0;
    while (getline(inFile, line)) {
        lineCount++;
        if (isCorrectlyBracketed(line)) {
            std::cout << "Line " << lineCount << ": Correctly Bracketed." << std::endl;
        } else {
            std::cout << "Line " << lineCount << ": Incorrectly Bracketed." << std::endl;

        }
    }
    
    return 0;
}

/* functions */

bool isCorrectlyBracketed(std::string str) {
    Stack<char> stack;
    char currentStackChar;
    std::string justTheBrackets;

    // creates the justTheBrackets string and gets rid of all the rest.
    for (int i = 0; i < str.length() ; i++) {
        if (str[i] == '(' || str[i] == ')' || str[i] == '{' || str[i] == '}' || str[i] == '[' || str[i] == ']') {
            justTheBrackets += str[i];
        }
    }
    
    
    for (int i = 0; i < justTheBrackets.length(); i++) {
        if (stack.size() > 0) {
            currentStackChar = stack.peek();
        }
        if (justTheBrackets[i] == '(' || justTheBrackets[i] == '{' || justTheBrackets[i] == '[') {
            stack.push(justTheBrackets[i]);
        } else {
            if (!stack.size() > 0) {
                return false;
            } else if (currentStackChar == '(' && justTheBrackets[i] == ')') {
                stack.pop();
            } else if (currentStackChar == '{' && justTheBrackets[i] == '}') {
                stack.pop();
            } else if (currentStackChar == '[' && justTheBrackets[i] == ']') {
                stack.pop();
            } else {
                return false;
            }
        }
    }
    
    if (stack.isEmpty()) {
        return true;
    } else {
        return false;
    }
    
    
}