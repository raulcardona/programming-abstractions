/*
 * File: 4_07.cpp
 * -------------
 * Reads a file and changes randomly replaces
 * upper and lower case chars leaving other
 * non alphabet chars alone.
 *
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include "random.h"

using namespace std;

/* Constants */



/* Function Prototypes */
std::string promptUserForFile(std::ifstream &inFile, std::string prompt = "");
std::string itsAllGreek(std::ifstream &inFile);

/* main */
int main() {
    //setRandomSeed(1);
    std::ifstream inFile;
    promptUserForFile(inFile, "Input file: ");
    std::cout << itsAllGreek(inFile) << std::endl;
    inFile.close();
    
    
    return 0;
}

std::string itsAllGreek(std::ifstream &inFile) {
    std::string greek;
    char ch;
    while (inFile.get(ch)) {
        if (isupper(ch)) {
            int rand = randomInteger('A', 'Z');
            greek += rand;
        } else if (islower(ch)) {
            int rand = randomInteger('a', 'z');
            greek += rand;
        } else greek += ch;
    }
    return greek;
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
