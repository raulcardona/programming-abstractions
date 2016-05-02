#include <iostream>
#include <string>
#include "set.h"
#include "simpio.h"

using namespace std;

Set<string> generatePermutations(string str);
Set<string> generatePermutationsByBen(string str);
Set<string> insertEveryOther(string str, char ch);

int main() {

	string str = getLine("Enter a string: ");
	cout << "The permutations of \"" << str << "\" are:" << endl;
	cout << generatePermutations(str) << endl;
	cout << generatePermutationsByBen(str) << endl;
	
	return 0;
}

Set<string> generatePermutations(string str) {
	Set<string> result;
	if(str == "") {
		result += "";
	} else {
		for (int i = 0; i < str.length(); i++) {
			char ch = str[i];
			string rest = str.substr(0, i) + str.substr(i + 1);
			foreach (string s in generatePermutations(rest)) {
				result += ch + s;
			}
		}
	}
	return result;
}

Set<string> generatePermutationsByBen(string str) {
	Set<string> result;
	if (str == "") {
		result += "";
	} else {
		for (int i = 0; i < str.length(); i++) {
			char ch = str[i];
			string rest = str.substr(0, i) + str.substr(i + 1);
			foreach (string s in generatePermutationsByBen(rest)) {
				result += insertEveryOther(s, ch);
			}
		}
	}
	return result;
}

Set<string> insertEveryOther(string str, char ch) {
	Set<string> result;
	for (int i = 0; i <= str.length(); i++) {
		string s = str;
		s.insert(i, 1, ch);
		result += s;
	}
	return result;
}