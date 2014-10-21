// Credit for the idea to use a vector for the output variable : http://www.geeksforgeeks.org/find-possible-words-phone-digits/ 
// I was using a string and just couldn't get it to work.  

#include <iostream>
#include <string>
#include <stdlib.h>
#include "vector.h"
#include "set.h"
#include "strlib.h"

using namespace std;

string listMnemonics(string str);
void fillheads(Vector<string> &heads);
void fillheads(Vector<string> heads, Vector<string> &heads, string str);
string generatePermutations(Vector<string> heads, Vector<char> output, int index = 0);


int main () {
	cout << listMnemonics("012345") << endl;
	return 0;
}

string listMnemonics(str) {
	string result;
	Vector<string> heads;
	heads.add(str);
	heads.add(str);
	heads.add(str);
	heads.add(str);
	Vector<char> output(heads.size());
	result = generatePermutations(heads, output);
	return result;
}

string generatePermutations(Vector<string> heads, Vector<char> output, int index) {
	string result;
	if (index == heads.size()) {
		string str;
		for (int i = 0; i < output.size(); i++) {
			str += output[i];
		}
		return str;
	}

	for (int i = 0; i < heads.get(index)[i]; i++) {
		output[index] = heads.get(index)[i];
		result += generatePermutations(heads, output, index + 1) + " ";
	}
	return result;

}