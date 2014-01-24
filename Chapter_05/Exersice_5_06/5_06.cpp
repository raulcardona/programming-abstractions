/*
 * File: 5_06.cpp
 * -------------
 * A program to use the algorithm: sieve of Eratosthenes.
 *
 */

/* Imports */
#include <iostream>
#include <string>
#include "simpio.h"
#include "vector.h"
#include "strlib.h"
#include "benfile.h"
#include "histogram.h"


/* Function Prototypes */

/* main */
int main() {
    int n = getInteger("Enter the upper limit to find primes: ");
    Vector<int> sieve;
    Vector<int> primes;
    
    // fill the sieve starting with 2 as per sieve of Eratosthenes rules
    for (int i = 0; i < n - 1; i++) {
        sieve.add(2 + i);
    }

    
    // remove non primes
    int currentPrimePos = 0;
    while (currentPrimePos != sieve.size()) {
        for (int i = currentPrimePos + 1; i < sieve.size(); i++) {
            if (sieve.get(i) % sieve.get(currentPrimePos) == 0) {
                sieve.remove(i);
            }
        }
        currentPrimePos++;
    }
    
    // print results
    for (int i = 0; i < sieve.size(); i++) {
        std::cout << sieve.get(i) << std::endl;
    }
    
    return 0;
}

/* functions */




