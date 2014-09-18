#include <iostream>
#include <string>
#include "simpio.h"
#include "set.h"
#include "vector.h"
#include "lexicon.h"
#include "simpio.h"
#include "set.h"
#include "foreach.h"
using namespace std;

Vector<string> fillSubsetVector(string str, string target);
void printSubsetWords(Vector<string> vec);

Vector<string> vec;

int main() {
	Lexicon dictionary("dictionary2.txt"); 
	string line = getLine("Enter starting word: ");
	cout << "The embedded starting words are: " << endl;
	
	

	for (string word : dictionary) {
		vec = fillSubsetVector(word, line);
	}

	printSubsetWords(vec);
	return 0;
}

Vector<string> fillSubsetVector(string str, string target) {
	if (str == "") {
		return vec += str;
	} else {
		string rest = str.substr(1);
		return vec += (fillSubsetVector(rest, target) + fillSubsetVector(rest, target.substr(1)));
	}
}

void printSubsetWords(Vector<string> vec) {
	for (string str : vec) {
		if (str != "") {
			cout << str << endl;
		}
	}
}

