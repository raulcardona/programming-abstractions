#include <iostream>
#include <string>
#include "simpio.h"
#include "set.h"
#include "vector.h"
#include "lexicon.h"
#include "simpio.h"
#include "foreach.h"
using namespace std;

void fillVector(Vector<char> &vec, string str);
bool hasWord(Vector<char> vec, string str);
string eraseChar(string str, char ch);
bool leftToRightOk(string line, string str);


int main() {
	Lexicon dictionary("dictionary.txt"); 
	string line = getLine("Enter starting word: ");
	cout << "The embedded starting words are: " << endl;
	Vector<char> vec;
	fillVector(vec, line);
	
	for (string str : dictionary) {
		if (hasWord(vec, str)) {
			cout << str << endl;
		}
	}

	return 0;
}

void fillVector(Vector<char> &vec, string str) {
	for (int i = 0; i < str.length(); i++) {
		vec.add(str[i]);
	}
}

bool hasWord(Vector<char> vec, string str) {
	if (vec.isEmpty()) {
		return str == "";
	} else {
		char element = vec[0];
		Vector<char> rest = vec;
		rest.remove(0);
		return hasWord(rest, str) || hasWord(rest, eraseChar(str, element));

	}
}

string eraseChar(string str, char ch) {
	string result = str;
	if (ch == str[0]) {
		result = result.erase(0, 1);
		return result;
	} else {
		return result;
	}
	
}

/*	bool subsetSumExists(Set<int> &set, int target) {
		if (set.isEmpty() {
			return target == 0;
		} else {
			int element = set.first();
			Set<int> rest = set - element;
			return subsetSumExists(rest, target) || subsetSumExists(rest, target - element);
		}
	}
*/
