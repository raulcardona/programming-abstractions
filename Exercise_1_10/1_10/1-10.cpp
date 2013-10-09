/*
 * File: 1_10.cpp
 * -------------
 *  It's the hailstore sequence!
 *
 */

#include <iostream>

int isEven(int n);
int isOdd(int n);


int main() {
    
    int number;
    std::cout << "Enter a number to begin the sequence: ";
    std::cin >> number;
    
    while (number != 1) {
        if (number % 2 == 0) number = isEven(number);
        else number = isOdd(number);
    }
    
    return 0;
}

int isEven(int n) {
    int newNumber = 0;
    newNumber = n / 2;
    std::cout << n << " is even, so I divide by 2 and get " << newNumber << std::endl;
    return newNumber;
}

int isOdd(int n) {
    int newNumber = 0;
    newNumber = (n * 3) + 1;
    std::cout << n << " is odd, so I multiply by 3 and add 1 to get " << newNumber << std::endl;
    return newNumber;
}
