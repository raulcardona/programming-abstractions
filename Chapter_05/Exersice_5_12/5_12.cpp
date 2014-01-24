
/*
 * File: 5_12.cpp
 * -------------
 * This program diplays the reverse of a stack of numbers 
 *
 */

/* Imports */
#include <iostream>
#include <string>
#include "simpio.h"
#include "vector.h"
#include "strlib.h"
#include "grid.h"
#include "stack.h"


/* Function Prototypes */



/* main */
int main() {
    Stack<int> stack;
    std::cout << "Enter a list of integers, ending in 0:" << std::endl;
    int num = getInteger("? ");
    while (num != 0) {
        stack.push(num);
        num = getInteger("? ");
    }
    
    std::cout << "Those integers in reverse order are:" << std::endl;
    int size = stack.size(); // we need this because the size of the stack changes as we pop items off
    for (int i = 0; i < size; i++) {
        std::cout << stack.pop() << std::endl;
    }
    
    return 0;
}

/* functions */

