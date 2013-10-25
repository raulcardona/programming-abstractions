/*
 * File: 4_08.cpp
 * -------------
 * Includes a function that copies characters from the input stream
 * to the output stream except for commented characters.
 * Works except for "//" or "/*" that are not being used as comments 
 * i.e. they are printed out etc.
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include "random.h"


/* Constants */



/* Function Prototypes */
std::string promptUserForFile(std::ifstream &inFile, std::string prompt = "");
void removeComments(std::istream &is, std::ostream &os);

/* main */
int main() {
    //setRandomSeed(1);
    std::ifstream inFile;
    promptUserForFile(inFile, "Input file: ");
    removeComments(inFile, std::cout);
    inFile.close();
    
    
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

void removeComments(std::istream &is, std::ostream &os) {
    std::string line;
    while (getline(is, line)) {
        if (line.find("//") != std::string::npos){
            line.erase(line.find("//"));  // erases the rest of the line
            os << line << std::endl;
            
        } else if (line.find("/*") == std::string::npos
                   && line.find("*/") == std::string::npos) { // if the line does not contain a comment marker
            os << line << std::endl;
            
        } else if (line.find("/*") != std::string::npos
                   && line.find("*/") != std::string::npos) { // if the line contains a start and stop comment
            line.erase(line.find("/*")); // erases from the begining of the comment to the end
            os << line << std::endl;
            
        } else if (line.find("/*") != std::string::npos) {  // if the line contains a comment starter
            line.erase(line.find("/*"));  // erases the rest of the line after it
            os << line << std::endl;
            getline(is, line);  // get another line
            while (line.find("*/") == std::string::npos) { // while the lines don't contain a comment closer keep getting lines
                getline(is, line);
            }
            if (line.find("*/") > 1) {
                line.erase(0, line.length() - line.find("*/") - 2);  // after it finds one, erase the line up to the closer
            } else {
                line.erase(line.find("*/"));
            }
            os << line << std::endl;
            
        } else {
            os << line << std::endl;
        }
        
        
    }
    
}




