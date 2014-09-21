#include <iostream>
#include <string>
#include <stdlib.h>
#include "vector.h"
#include "set.h"

using namespace std;

void fillKeypad(Vector<string> &keypad);
Set<string> listMnemonics(Vector<string> vec, string str);
Set<string> generatePermutations(string str);



int main () {
	Vector<string> keypad;
	fillKeypad(keypad);
	cout << listMnemonics(keypad, "723") << endl;

	return 0;
}

void fillKeypad(Vector<string> &keypad) {
	keypad.add("0"); // pos 0
	keypad.add("0"); // pos 1
	keypad.add("ABC"); // ABC begins at button "2" on a keypad
	keypad.add("DEF");
	keypad.add("GHI");
	keypad.add("JKL");
	keypad.add("MNO");
	keypad.add("PQRS");
	keypad.add("TUV");
	keypad.add("WXYZ");
}


Set<string> listMnemonics(Vector<string> vec, string str) {
	Set<string> mnemonics;
	for (int i = 0; i < str.length(); i++) {
		mnemonics += generatePermutations(vec.get(str[i] - '0'));
	}
	return mnemonics;
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

