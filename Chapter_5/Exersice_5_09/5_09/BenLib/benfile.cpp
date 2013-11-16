//
//  benfile.cpp
//  5_02
//
//  Created by Ben Mills on 10/30/13.
//
//

#include <iostream>
#include <fstream>
#include <string>
#include "benfile.h"

// To choose the input file
std::string promptUserForFile(std::ifstream &inFile, std::string prompt) {
    while (true) {
        std::cout << prompt;
        std::string fileName;
        getline(std::cin, fileName);
        inFile.open(fileName.c_str());
        if (!inFile.fail()) return fileName;
        inFile.clear();
        std::cout << "Unable to open that file. Try again." << std::endl;
        if (prompt == "") prompt = "Input file: ";
    }
}

// To choose the output file
std::string promptUserForFile(std::ofstream &outFile, std::string prompt) {
    while (true) {
        std::cout << prompt;
        std::string fileName;
        getline(std::cin, fileName);
        outFile.open(fileName.c_str());
        if (!outFile.fail()) return fileName;
        outFile.clear();
        std::cout << "Unable to open that file. Try again." << std::endl;
        if (prompt == "") prompt = "Output file: ";
        
    }
}