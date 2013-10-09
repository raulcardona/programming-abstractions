/*
 * File: 2_4.cpp
 * -------------
 *  Wind chill calculator
 *
 */

#include <iostream>
using namespace std;

bool isPrime(int n);

int main() {

    for (int i = 1; i < 100; i++) {
        if (isPrime(i)) {
            cout << i << endl;
        }
    }
return 0;
}

bool isPrime(int n) {
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    
    return true;
}