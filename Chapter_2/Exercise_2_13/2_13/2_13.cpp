/*
 * File: 2_12.cpp
 * -------------
 * Half Life 3?
 * 
 * This program simulates 10,000 atom of radioactive material decaying.
 *
 */

#include <iostream>
#include "random.h"
#include "simpio.h"
using namespace std;

double const DECAY_RATE = 0.5;
/* Function Prototypes */

int main() {
    int atoms = 10000;
    int year = 0;
    cout << "There are " << atoms << " atoms initially." << endl;
    
    while (atoms > 0) {
        int currentDecay = atoms;
        for (int i = 0; i < atoms; i++) {
            if (randomChance(DECAY_RATE)) {
                currentDecay--;
            }
        }
        atoms = currentDecay;
        year++;
        cout << "There are " << atoms << " atoms at the end of year " << year << endl;
    }
    
    return 0;
}

