/*
 * File: 1_9.cpp
 * -------------
 * Prime factors!
 *
 *
 */


#include <iostream>

using namespace std;

/* Constants */

/* Function Prototypes */
void factor(int n);


/* Main Program */
int main() {
    
    
    int number;
    
    std::cout << "This program factors a number." << std::endl;
    std::cout << "Enter a number to be factored: ";
    std::cin >> number;
    factor(number);
    
    return 0;
}

void factor(int n) {
    while (n % 2 == 0) {
        if (n  == 2) std::cout << "2";
        else std::cout << "2 x ";
        n /= 2;
    }
    
    while (n % 3 == 0) {
        if (n == 3) std::cout << "3";
        else std::cout << "3 x ";
        n /= 3;
    }
    
    while (n % 5 == 0) {
        if (n == 5) std::cout << "5";
        else std::cout << "5 x ";
        n /= 5;
    }
    
    while (n % 7 == 0) {
        if (n == 7) std::cout << "7";
        else std::cout << "7 x ";
        n /= 7;
    }
    
    while (n % 11 == 0) {
        if (n == 11) std::cout << "11";
        else std::cout << "11 x ";
        n /= 11;
    }
    
    while (n % 13 == 0) {
        if (n == 13) std::cout << "13";
        else std::cout << "13 x ";
        n /= 13;
    }
    
    while (n % 17 == 0) {
        if (n == 17) std::cout << "17";
        else std::cout << "17 x ";
        n /= 17;
    }
    
    while (n % 19 == 0) {
        if (n == 19) std::cout << "19";
        else std::cout << "19 x ";
        n /= 19;
    }
    
    while (n % 23 == 0) {
        if (n == 23) std::cout << "23";
        else std::cout << "23 x ";
        n /= 23;
    }
    
    while (n % 29 == 0) {
        if (n == 29) std::cout << "29";
        else std::cout << "29 x ";
        n /= 29;
    }
    
    while (n % 31 == 0) {
        if (n == 31) std::cout << "31";
        else std::cout << "31 x ";
        n /= 31;
    }
    
    while (n % 37 == 0) {
        if (n == 37) std::cout << "37";
        else std::cout << "37 x ";
        n /= 37;
    }
}



/*   2      3      5      7     11     13     17     19     23     29
 31     37     41     43     47     53     59     61     67     71
 73     79     83     89     97    101 */
