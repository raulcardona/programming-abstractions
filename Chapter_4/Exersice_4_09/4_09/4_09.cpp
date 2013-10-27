/*
 * File: 4_09.cpp
 * -------------
 * This program erases chosen characters from the user selected file.
 * std::cout is working but the std::ofstream is not :(
 */

#include <iostream>
#include <fstream>
#include <string>
#include "simpio.h"



/* Constants */


/* Function Prototypes */
std::string promptUserForFile(std::ifstream &inFile, std::string prompt);
std::string promptUserForFile(std::ofstream &outFile, std::string prompt);

void banishCharacters(std::ifstream &inFile, std::ofstream &outFile, std::string toBanish);



/* main */
int main() {
    std::ifstream inFile;
    std::ofstream outFile;
    promptUserForFile(inFile, "Input file: ");
    promptUserForFile(outFile, "Output file: ");
    std::string toBanish = getLine("Enter letters to remove: ");
    banishCharacters(inFile, outFile, toBanish);
    inFile.close();
    outFile.close();
    
    return 0;
}

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

void banishCharacters(std::ifstream &inFile, std::ofstream &outFile, std::string toBanish) {
    char ch;
    while (inFile.get(ch)) {
        bool toPut = true;
        for (int i = 0; i < toBanish.length(); i++) {
            if (toBanish.at(i) == ch) {
                toPut = false;
            }
        }
        if (toPut) {
            std::cout.put(ch);
            outFile.put(ch);
        }
        
        
    }
}

void copyStream(std::istream &is, std::ostream &os) {
    char ch;
    while (is.get(ch)) {
        os.put(ch);
    }
}






