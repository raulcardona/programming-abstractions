/*
 * File: 4_11.cpp
 * -------------
 * An implemenation of two conversion functions
 * based on "stringToInteger" and "integerToString"
 * 
 */

/* Imports */
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "error.h"

/* Function Prototypes */
double stringToReal(std::string str);
std::string realToString(double real);



/* main */
int main() {
    std::cout << realToString(3.1415) << std::endl;
    std::cout << stringToReal("0.0005") << std::endl;
    return 0;
}

/* functions */


double stringToReal(std::string str) {
    std::istringstream stream(str);
    double value;
    stream >> value >> std::ws;
    if (stream.fail() || !stream.eof()) {
        error("stringToReal: Illegal real format.");
    }
    return value;
}


std::string realToString(double real) {
    std::ostringstream stream;
    stream << real;
    return stream.str(); // the book says this "str()" function copies and returns the stream as a string
}