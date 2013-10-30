/*
 * File: 5_01.cpp
 * -------------
 *  A program to test 3 overloaded readVector functions
 *
 */

/* Imports */
#include <iostream>
#include <string>
#include "vector.h"
#include "filelib.h"
#include "strlib.h"


/* Function Prototypes */
void readVector(std::istream &is, Vector<int> &vec);
void readVector(std::istream &is, Vector<double> &vec);
void readVector(std::istream &is, Vector<std::string> &vec);
void printVector(Vector<double> &vec);


/* main */
int main() {
    std::ifstream inFile;
    Vector<double> roots;
    promptUserForFile(inFile);
    readVector(inFile, roots);
    printVector(roots);
    readVector(inFile, roots);
    printVector(roots);
    readVector(inFile, roots);
    printVector(roots);
    inFile.close();
    return 0;
}

/* functions */
void readVector(std::istream &is, Vector<int> &vec) {
    vec.clear();
    std::string line;
    int i;
    while (getline(is, line)) {
        if (line.length() < 1) break;
        i = stringToInteger(line);
        vec.add(i);
    }
}

void readVector(std::istream &is, Vector<double> &vec){
    vec.clear();
    std::string line;
    double d;
    while (getline(is, line)) {
        if (line.length() < 1) break;
        d = stringToReal(line);
        vec.add(d);
    }
}

void readVector(std::istream &is, Vector<std::string> &vec) {
    vec.clear();
    std::string line;
    while (getline(is, line)) {
        if (line.length() < 1) break;
        vec.add(line);
    }
}

void printVector(Vector<double> &vec) {
    std::cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        if (i > 0) std::cout << ", ";
        std::cout << vec[i];
    }
    std::cout << "]" << std::endl;
}


