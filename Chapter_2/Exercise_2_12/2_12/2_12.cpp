/*
 * File: 2_12.cpp
 * -------------
 * This program will repeatedly generate random numbers between 0-1 and
 * average the numbers.  The user decides how many trials to average.
 *
 */

#include <iostream>
#include "random.h"
#include "simpio.h"
using namespace std;

/* Function Prototypes */
double computeAverageReal(int num);

int main() {
    cout << "This program will give an average of " << endl;
    cout << "random numbers beteen 0 and 1." << endl;
    cout << "------------------------------------" << endl;
    cout << "Enter a number of trials to process: ";
    int num_trials = getInteger("Enter a number of trials to process: ");
    cout << "The average random number between 0 and 1 with " << num_trials <<
    " trials was " << computeAverageReal(num_trials);
    return 0;
}

/* this function finds the average of random numbers hardcoded between 0 and 1 */

double computeAverageReal(int num) {
    double total = 0.0;
    
    for (int i = 0; i < num; i++) {
        double number = randomReal(0, 1);
        total += number;
    }
    return total / num;
}




