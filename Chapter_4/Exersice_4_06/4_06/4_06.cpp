/*
 * File: 4_06.cpp
 * -------------
 * Implementation of "defaultExtension" from the filelib.h
 *
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include "simpio.h"


/* Constants */



/* Function Prototypes */
std::string promptUserForFile(std::ifstream &infile, std::string prompt = "");
std::string defaultExtension(std::string fileName, std::string ext);

/* main */
int main() {
    while (true) {
        std::ifstream infile;
        std::string fileName = promptUserForFile(infile, "Enter a file name: ");
        std::string ext = getLine("Enter a new file extention: ");
        std::cout << "The file is now: " << defaultExtension(fileName, ext) << std::endl;
        
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

std::string defaultExtension(std::string fileName, std::string ext) {
    std::string newFile;
    
    if (ext.find('*') != -1) {
        for (int i = 0; i < fileName.length(); i++) {
            if (fileName.at(i) == '.') {
                fileName.replace(i, fileName.length() - i, ext.erase(0, 1));
                return fileName;
            }
        }
    } else if (fileName.find('.') != -1) {
        return fileName;
    }
    return fileName + ext;
}




