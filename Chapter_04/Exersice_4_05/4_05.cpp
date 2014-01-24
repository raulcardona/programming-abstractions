/*
 * File: 4_05.cpp
 * -------------
 * Implementations of "getRoot" and "getExtension" from the filelib.h
 *
 *
 */

#include <iostream>
#include <fstream>
#include <string>


/* Constants */



/* Function Prototypes */
std::string promptUserForFile(std::ifstream &infile, std::string prompt = "");
std::string getRoot(std::string fileName);
std::string getExtension(std::string fileName);

/* main */
int main() {
    while (true) {
        std::ifstream infile;
        std::string fileName = promptUserForFile(infile);
        std::cout << "The root of the file name is: " << getRoot(fileName) << std::endl;
        std::cout << "The extension of the file is: " << getExtension(fileName) << std::endl;
    }
    
    
    
    
    return 0;
}

std::string promptUserForFile(std::ifstream &infile, std::string prompt) {
    while (true) {
        std::cout << prompt;
        std::string fileName;
        getline(std::cin, fileName);
        infile.open(fileName.c_str());
        if (!infile.fail()) return fileName;
        infile.clear();
        std::cout << "Unable to open that file. Try again." << std::endl;
        if (prompt == "") prompt = "Input file: ";
    }
}

std::string getRoot(std::string fileName) {
    std::string root;
    for (int i = 0; i < fileName.length(); i++) {
        if ( fileName.at(i) == '.') break;
        root += fileName.at(i);
    }
    return root;
}

std::string getExtension(std::string fileName) {
    std::string extension;
    for (int i = fileName.length() - 1; i >= 0; i--) {
        if (fileName.at(i) == '.') break;
        extension.insert(0, 1, fileName.at(i));
    }
    return extension;
}




