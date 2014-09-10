#include <iostream>
#include "stack.h"
#include "tokenscanner.h"
using namespace std;

const string FILETOCHECK = "test.txt";

int main(int argc, char *argv[]) {
	ifstream infile;
	infile.open(FILETOCHECK.c_str());
	if (infile.fail()) {
		error("Can't read file.");
		return 1;
	} else {
		string text;
		string line;
		while (getline(infile, line)) {
			text += line;
		}
		TokenScanner scanner(text);
		scanner.scanStrings();
		cout << "Input file: " << FILETOCHECK << endl;
		while (scanner.hasMoreTokens()) {
			string token = scanner.nextToken();
			cout << token << endl;
		}
	}
	return 0;
}