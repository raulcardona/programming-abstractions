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
void fillKeypad(Vector<string> &keypad);
void fillKeyPresses(Vector<string> keypad, Vector<string> &keyPresses, string str);
string generatePermutations(Vector<string> keyPresses, Vector<char> output, int index = 0);


int main () {
	cout << listMnemonics("26795") << endl;
	return 0;
}

string listMnemonics(string str) {
	string result;
	Vector<string> keypad;
	Vector<string> keyPresses;
	fillKeypad(keypad);
	fillKeyPresses(keypad, keyPresses, str);
	Vector<char> output(keyPresses.size());
	result = generatePermutations(keyPresses, output);
	return result;
}

string generatePermutations(Vector<string> keyPresses, Vector<char> output, int index) {
	string result;
	if (index == keyPresses.size()) {
		string str;
		for (int i = 0; i < output.size(); i++) {
			str += output[i];
		}
		return str;
	}

	for (int i = 0; i < keyPresses.get(index)[i]; i++) {
		output[index] = keyPresses.get(index)[i];
		result += generatePermutations(keyPresses, output, index + 1) + " ";
		if (keyPresses.get(index) == "0") {
			return "0";
		} else if (keyPresses.get(index) == "1") {
			return "1";
		}
	}
	return result;

}

void fillKeypad(Vector<string> &keypad) {
	keypad.add("0"); // pos 0
	keypad.add("1"); // pos 1
	keypad.add("ABC"); // ABC begins at button "2" on a keypad
	keypad.add("DEF");
	keypad.add("GHI");
	keypad.add("JKL");
	keypad.add("MNO");
	keypad.add("PQRS");
	keypad.add("TUV");
	keypad.add("WXYZ");
}

// Take strings from keypad and move them into keyPresses in order.
void fillKeyPresses(Vector<string> keypad, Vector<string> &keyPresses, string str) {
	for (int i = 0; i < str.length(); i++) {
		char currentChar = str[i];
		int currentNumber = currentChar - '0';
		keyPresses.add(keypad.get(currentNumber));
	}
}
