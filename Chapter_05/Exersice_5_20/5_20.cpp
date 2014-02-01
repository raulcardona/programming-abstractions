/*
 * File: 5_20.cpp 
 * -------------
 * Reads a file and builds a map of area code keys and state values
 * User can also enter a state to see all the codes in that state.
 * same as 5_19_2.cpp except using an inverted map technique with 
 * a vector of integers to be more efficient (in larger applications).
 * 
 * I also ajusted the original map to be Map<string, string> so it actually
 * works with this libary unlike the previous one.
 *
 * EDIT: stringToInteger just isn't working I searched online and read 
 * about "atoi()" that works.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <stdlib.h>
#include "error.h"
#include "vector.h"
#include "map.h"
#include "simpio.h"


using namespace std;

/* Constants */

const string FILE_NAME = "area_codes.txt";

/* Function Prototypes */
string getFile(ifstream &infile);
void initMaps(Map<string, string> &areaCodes, Map<string, Vector<int> > &states, ifstream &infile);
void findAreaCode(Map<string, string> &areaCodes, Map<string, Vector<int> > &states);
void printState(string line, Map<string, string> &areaCodes);
void printAreaCode(string line, Map<string, Vector<int> > &states);

/* main */
int main() {
    Map<string, string> areaCodes;
    Map<string, Vector<int> > states;
    ifstream infile;
    getFile(infile);
    initMaps(areaCodes, states, infile);
    findAreaCode(areaCodes, states);
    
    return 0;
}

string getFile(ifstream &infile) {
    string filename = FILE_NAME;
    infile.open(filename.c_str());
    if (!infile.fail()) return filename;
    infile.clear();
    error("Unable to locate file.");
    return 0;
}

void initMaps(Map<string, string> &areaCodes, Map<string, Vector<int> > &states, ifstream &infile) {
    
// setup areaCodes
    string line;
    string code;
    while (getline(infile, line)) {
        code = line.substr(0, 3);
        areaCodes.put(code, line.substr(4));
    }
    infile.close();

// setup states
    for(string str : areaCodes) {
        Vector<int> allTheCodes;
        if(states.containsKey(areaCodes.get(str))) {
            allTheCodes += states.get(areaCodes.get(str));
        }
        int codeToAdd = atoi(str.c_str());
        allTheCodes.add(codeToAdd);
        string stateToAdd = areaCodes.get(str);
        states.put(stateToAdd, allTheCodes);
    }


}

void findAreaCode(Map<string, string> &areaCodes, Map<string, Vector<int> > &states) {
    while(true) {
        string line = "";
        line = getLine("Enter area code or state name: ");
        if(isdigit(line[0])) {
            printState(line, areaCodes);
        } else if (isalpha(line[0])) {
            printAreaCode(line, states);
        } else {
            cout << "goodbye" << endl;
            break;
        }
    }
}

void printState(string line, Map<string, string> &areaCodes) {
    cout << areaCodes.get(line) << endl;
}

void printAreaCode(string line, Map<string, Vector<int> > &states) {
    cout << states.get(line) << endl;
}
