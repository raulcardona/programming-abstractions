/*
 * File: 5_03.cpp
 * -------------
 *  A program to find the standard deviation of all the items in a vector.
 *  The vector pulls it's data from an external file that contains
 *  one double per line.
 *
 */

/* Imports */
#include <iostream>
#include <string>
#include "vector.h"
#include "strlib.h"
#include "benfile.h"
#include <math.h>


/* Function Prototypes */
double mean(Vector<double> &data);
double stddev(Vector<double> &data);


/* main */
int main() {
    std::ifstream inFile;
    Vector<double> data;
    std::string line;
    promptUserForFile(inFile, "Enter file name: ");
    
    while (getline(inFile, line)) {
        if (line.length() < 1) data.add(0);
        data.add(stringToReal(line));
    }
    
    std::cout << "The mean is: " << mean(data) << std::endl;
    std::cout << "The standard deviation is: " << stddev(data) << std::endl;
    inFile.close();
    return 0;
}

/* functions */

double mean(Vector<double> &data) {
    double total = 0.0;
    for (int i = 0; i < data.size(); i++) {
        total += data[i];
    }
    return total / data.size();
}

double stddev(Vector<double> &data) {
    double variance = 0.0;
    double total = 0.0;
    
    //get the mean first
    for (int i = 0; i < data.size(); i++) {
        total += data[i];
    }
    double mean = total / data.size();
    
    //find the square of the difference between each value, total these.
    for (int i = 0; i < data.size(); i++) {
        variance += (data[i] - mean) * (data[i] - mean);
    }
    variance = variance / data.size();
    return sqrt(variance);
}



