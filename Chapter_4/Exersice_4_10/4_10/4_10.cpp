/*
 * File: 4_10.cpp
 * -------------
 * This program replaces tabs with the appropriate number of spaces.
 * At this point it just replaces every tab with 4 spaces
 * it doesn't account for tab areas that are less than 4.
 */

#include <iostream>
#include <fstream>
#include <string>

/* Constants */


/* Function Prototypes */
std::string promptUserForFile(std::ifstream &inFile, std::string prompt);
std::string promptUserForFile(std::ofstream &outFile, std::string prompt);
void replaceTabs(std::ifstream &inFile, std::ofstream &outFile);

/* main */
int main() {
    std::ifstream inFile;
    std::ofstream outFile;
    promptUserForFile(inFile, "Input file: ");
    promptUserForFile(outFile, "Output file: ");
    replaceTabs(inFile, outFile);
    inFile.close();
    outFile.close();
    
    return 0;
}

/* functions */
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
        std::cout << "Unable to open or create that file. Try again." << std::endl;
        if (prompt == "") prompt = "Output file: ";
        
    }
}

void replaceTabs(std::ifstream &inFile, std::ofstream &outFile) {
    char ch;
    int spaceCounter = 0;
    int sizeToTab = 0;
    while (inFile.get(ch)) {
        if (ch == '\n') spaceCounter = -1;
        if (spaceCounter < 0) {
            sizeToTab = 4;
        } else {
            sizeToTab = 4 - (spaceCounter % 4);
        }
        if (ch == '\t') {
            for (int i = 0; i < sizeToTab; i++) {
                outFile.put(' ');
                std::cout << ' ';
            }
            spaceCounter += sizeToTab;
        } else {
            outFile.put(ch);
            std::cout << ch;
        }
        spaceCounter++;
    }
    
    
    
}


