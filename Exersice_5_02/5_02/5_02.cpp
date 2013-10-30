/*
 * File: 5_02.cpp
 * -------------
 *  A program to find the mean of all the items in a vector.
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


/* Function Prototypes */
double mean(Vector<double> &data);


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
    
    std::cout << "The mean: " << mean(data) << std::endl;
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


