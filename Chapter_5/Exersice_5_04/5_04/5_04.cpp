/*
 * File: 5_04.cpp
 * -------------
 *  A program to print a histogram of exam scores using vectors.
 *  The vector pulls it's data from an external file that contains
 *  one value per line.
 *
 */

/* Imports */
#include <iostream>
#include <string>
#include "vector.h"
#include "strlib.h"
#include "benfile.h"

/* Constants */
int const DECADE_NUM = 11;


/* Function Prototypes */
void printHistogram(Vector<int> &data);
void initializeAsterisk(Vector<int> &data, Vector<std::string> &asterisk);
void initializeDecades(Vector<std::string> &decades);


/* main */
int main() {
    std::ifstream inFile;
    Vector<int> data;
    std::string line;
    promptUserForFile(inFile, "Enter file name: ");
    while (getline(inFile, line)) {
        if (line.length() < 1) data.add(0);
        data.add(stringToReal(line));
    }
    printHistogram(data);
    inFile.close();
    return 0;
}

/* functions */
void printHistogram(Vector<int> &data) {
   
    Vector<std::string> asterisk(data.size());
    Vector<std::string> decades;
    initializeDecades(decades);
    
    //initialize asterisk
    for (int i = 0; i < data.size(); i++) {
        if (data[i] > 0 && data[i] < 10) {
            asterisk[0] += '*';
        } else if (data[i] >= 10 && data[i] < 20) {
            asterisk[1] += '*';
        } else if (data[i] >= 20 && data[i] < 30) {
            asterisk[2] += '*';
        } else if (data[i] >= 30 && data[i] < 40) {
            asterisk[3] += '*';
        } else if (data[i] >= 40 && data[i] < 50) {
            asterisk[4] += '*';
        } else if (data[i] >= 50 && data[i] < 60) {
            asterisk[5] += '*';
        } else if (data[i] >= 60 && data[i] < 70) {
            asterisk[6] += '*';
        } else if (data[i] >= 70 && data[i] < 80) {
            asterisk[7] += '*';
        } else if (data[i] >= 80 && data[i] < 90) {
            asterisk[8] += '*';
        } else if (data[i] >= 90 && data[i] < 100) {
            asterisk[9] += '*';
        } else if (data[i] == 100) {
            asterisk[10] += '*';
        }
    }

    //actual printing
    for (int i = 0; i < decades.size(); i++) {
        std::cout << decades[i] << ": " << asterisk[i] << std::endl;
    }
}

void initializeDecades(Vector<std::string> &decades) {
    int count = 0;
    for (int i = 0; i < DECADE_NUM; i++) {
        if (count > 90) decades.add(integerToString(i) + "0");
        else decades.add(integerToString(i) + "0s");
        count += 10;
    }
}





