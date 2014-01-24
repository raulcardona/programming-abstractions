/*
 * File: 5_05.cpp
 * -------------
 *  A program to print a histogram of exam scores using vectors.
 *  This version impliments a hist.h to give the client more
 *  flexablility.
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
void fileSetup(std::ifstream &inFile, Vector<int> &data, std::string &line);


/* main */
int main() {
    std::ifstream inFile;
    Vector<int> data;
    Vector<std::string> asterisk; // actual asterisks to be displayed
    Vector<int> interval; // the histogram format - each range that may or may not get an asterisk for each data point.
    std::string line; // raw info from the inFile
    
    fileSetup(inFile, data, line); // get file name from user and open it and set it to the string line.
    
    // Initializing data:
    while (getline(inFile, line)) {
        if (line.length() < 1) data.add(0);
        data.add(stringToInteger(line));
    }
    
    
    initializeVectors(data, asterisk, interval);  // fill the other vectors with data.
    printHistogram(asterisk, interval); // print the vectors in a histogram format.
    inFile.close();
    return 0;
}

/* functions */
void fileSetup(std::ifstream &inFile, Vector<int> &data, std::string &line) {
    promptUserForFile(inFile, "Enter file name: ");
    while (getline(inFile, line)) {
        if (line.length() < 1) data.add(0);
        data.add(stringToReal(line));
    }
}