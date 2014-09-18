#include <iostream>
#include <fstream>
#include "tokenscanner.h"
#include "lexicon.h"
#include "error.h"

using namespace std;

const string FILETOCHECK = "test.txt";
const string DICTIONARY = "dictionary.txt";

int main(int argc, char *argv[]) {
	Lexicon dict(DICTIONARY);
	ifstream infile;
	infile.open(FILETOCHECK.c_str());
	if (infile.fail()) {
		error("Can't read file.");
		return 1;
	} else {
		TokenScanner scanner(infile);
		scanner.ignoreWhitespace();
		cout << "Input file: " << FILETOCHECK << endl;
		while (scanner.hasMoreTokens()) {
			string token = scanner.nextToken();
			if (!dict.contains(token)) {
				cout << "\"" << token << "\"" << " is not in the dictionary." << endl;
			}
		}
	}
	return 0;
}