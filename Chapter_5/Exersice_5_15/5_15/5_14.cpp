
/*
 * File: 5_14.cpp
 * -------------
 * This program moves n characters k possitions in a stack
 * preforming a roll.
 *
 */

/* Imports */
#include <iostream>
#include <fstream>
#include "stack.h"
#include "queue.h"
#include "simpio.h"
#include "strlib.h"
#include "benfile.h"

/* Function Prototypes */
void roll(Stack<char> &stack, int n, int k);
std::string stackToString(Stack<char> stack);

/* main */
int main() {
    Stack<char> stack;
    stack.push('a');
    stack.push('b');
    stack.push('c');
    stack.push('d');
    int num = getInteger("Enter a number of characters: ");
    if (num > stack.size() || num < 0) {
        std::cout << "roll: argument out of range";
        return 0;
    }
    int pos = getInteger("Enter a number of possitions to move back: ");
    if (pos < 0) {
        std::cout << "roll: argument out of range";
        return 0;
    }
    std::cout << "Before: " << stackToString(stack) << std::endl;
    roll(stack, num, pos);
    std::cout << "After: " << stackToString(stack) << std::endl;
    return 0;
}

/* functions */

void roll(Stack<char> &stack, int n, int k) {
    Stack<char> secondStack;
    std::string str;
    for (int i = 0; i < n; i++) {
        str += stack.pop();
    }
    str.insert(0, str.substr(k % n));
    //str.erase(size - 1);
    for (int i = 0; i < n; i++) {
        secondStack.push(str[i]);
    }
    for (int i = 0; i < n; i++) {
        stack.push(secondStack.pop());
    }
}

std::string stackToString(Stack<char> stack) {
    std::string str;
    int size = stack.size();
    for (int i = 0; i < size; i++) {
        str += stack.pop();
        
    }
    return str;
}
