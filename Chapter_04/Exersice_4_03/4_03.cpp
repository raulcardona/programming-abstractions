/*
 * File: 4_03.cpp
 * -------------
 * Reads a file and prints the longest line.
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
    string line;
    string longestLine;
    while (getline(infile, line)) {
        if (line.length() > longestLine.length()) {
            longestLine = line;
        }
    }
    cout << "The longest line is: " << longestLine << endl;
    
    

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
