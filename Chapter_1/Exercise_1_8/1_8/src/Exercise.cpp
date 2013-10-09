/*
 * File: 1_1.cpp
 * -------------
 * This program reads a number in Celcius and converts it to
 * Fahrenheit. *
 *
*/


#include <iostream>

using namespace std;

/* Constants */

/* Function Prototypes */
int reverseNumber(int n);
int raiseToPower(int n, int k);


/* Main Program */
int main() {


    int number;

    std::cout << "This program reverses the digits in an integer." << std::endl;
    std::cout << "Enter a positive integer: ";
    std::cin >> number;
    std::cout << "The reversed integer is " << reverseNumber(number);

    return 0;
}

int reverseNumber(int n) {
    int number = n;
    int reversal = 0;
    int count = -1;

    while(n > 0) {
        n /= 10;
        count++;
    }

    while(number > 0) {
        if (count == 0) {
            reversal += number % 10;
        } else {
            reversal += (number % 10) * raiseToPower(10, count);
        }

        number /= 10;
        count--;
    }

    return reversal;
}

int raiseToPower(int n, int k) {
    int result = 1;
    for (int i = 0; i < k; i++) {
        result *=n;
    }
    return result;
}
