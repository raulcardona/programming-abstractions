/*
 * File: 4_04.cpp
 * -------------
 * Reads a file and prints the number of characters, lines, and words it contains.
 *
 *
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/* Constants */



/* Function Prototypes */
string promptUserForFile(ifstream &infile, string prompt = "");


/* main */
int main() {
    ifstream infile;
    promptUserForFile(infile, "Input file: ");
    int lineCount = 1;
    int wordCount = 1;
    int charCount = 0;
    char ch;
    while (infile.get(ch)) {
        if (ch == '\n') {
            lineCount++;
            wordCount++;
        } else if (ch == ' ' ) {
            wordCount++;
        } else if (isalnum(ch)) {
            charCount++;
        }
    
    }
    
    cout << "Chars: " << charCount << endl;
    cout << "Words: " << wordCount << endl;
    cout << "Lines: " << lineCount << endl;
    
    
    infile.close();
    
    
    return 0;
}

string promptUserForFile(ifstream &infile, string prompt) {
    while (true) {
        cout << prompt;
        string filename;
        getline(cin, filename);
        infile.open(filename.c_str());
        if (!infile.fail()) return filename;
        infile.clear();
        cout << "Unable to open that file. Try again." << endl;
        if (prompt == "") prompt = "Input file: ";
    }
}
