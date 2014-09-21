#include <iostream>
#include <string>
#include "simpio.h"

using namespace std;

void listPermutations(string str);
string generatePermutaions(string str, int index);
void swapChar(char &a, char &b);


int main () {
	string str = getLine("Enter a string: ");
	cout << "The permutations of \"" << str << "\" are:" << endl;
	listPermutations(str);

	return 0;
}

void listPermutations(string str) {
	cout << generatePermutaions(str, 0) << endl;
}

string generatePermutaions(string str, int index) {
	string result;
	if (index == str.length()) {
		return str;
	} else {
		for (int i = index; i < str.length(); i++) {
			swapChar(str[index], str[i]);
			result += generatePermutaions(str, index + 1) + " ";
			swapChar(str[index], str[i]);
		}
		return result;
	}
}

void swapChar(char &a, char &b) {
	char temp = a;
	a = b;
	b = temp;

}