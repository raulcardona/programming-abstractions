/*
 * File: 5_19_2.cpp  (There are two # 19s)
 * -------------
 * Reads a file and builds a map of area code keys and state values
 * User can also enter a state to see all the codes in that state.
 *
 * This file compiles but does not run.  It seems from the lecture that
 * the Map class can only have string "keys" but the assignment clearly 
 * requests that we use a "Map<int, string>" setup.  Maybe a different 
 * StanfordCPPLib will allow it?  Oh well.
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "map.h"
#include "simpio.h"
#include "strlib.h"

using namespace std;

/* Constants */

const string FILE_NAME = "area_codes.txt";

/* Function Prototypes */
string getFile(ifstream &infile);
void initMap(Map<int, string> &areaCodes, ifstream &infile);
void findAreaCode(Map<int, string> &areaCodes);
void printState(string line, Map<int, string> &areaCodes);
void printAreaCode(string line, Map<int, string> &areaCodes);

/* main */
int main() {
    Map<int, string> areaCodes;
    ifstream infile;
    getFile(infile);
    initMap(areaCodes, infile);
    findAreaCode(areaCodes);
    
    return 0;
}

string getFile(ifstream &infile) {
    string filename = FILE_NAME;
    infile.open(filename.c_str());
    if (!infile.fail()) return filename;
    infile.clear();
    cout << "Unable to locate" << filename << endl;
    return 0;
}

void initMap(Map<int, string> &areaCodes, ifstream &infile) {
    string line;
    string strCode = "";
    int code = 0;

    while (getline(infile, line)) {
        strCode = line.substr(0, 3);
        code = stringToInteger(strCode);
        areaCodes.put(code, line.substr(5));
    }
    infile.close();
}

void findAreaCode(Map<int, string> &areaCodes) {
    while(true) {
        string line = "";
        line = getLine("Enter area code or state name: ");
        if(isdigit(line[0])) {
            printState(line, areaCodes);
        } else if (isalpha(line[0])) {
            printAreaCode(line, areaCodes);
        } else {
            cout << "goodbye" << endl;
            break;
        }
    }
}

void printState(string line, Map<int, string> &areaCodes) {
    cout << areaCodes.get(stringToInteger(line)) << endl;
}

void printAreaCode(string line, Map<int, string> &areaCodes) {
    for(int code : areaCodes) {
        if(code == stringToInteger(line)) {
            cout << areaCodes.get(code) << " ";
        }
    }
}
