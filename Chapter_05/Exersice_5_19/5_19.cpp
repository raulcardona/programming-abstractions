
// File: 5_19.cpp
// ---------------
// Morse Code Translator

#include <stdio.h>
#include <string.h>
#include <cctype>
#include "simpio.h"
#include "map.h"
using namespace std;

// Function Prototypes
void initMaps(Map<string, string> &toMorse, Map<string, string> &fromMorse);
void transFromMorse(string line, Map<string, string> fromMorse);
void transToMorse(string line, Map<string, string> toMorse);
void printMaps(Map<string, string> toMorse, Map<string, string> fromMorse);

// Main
int main() {
	Map<string,string> toMorse;
	Map<string,string> fromMorse;
	initMaps(toMorse, fromMorse);
	printMaps(toMorse, fromMorse);
	cout << "MORSE CODE TRANSLATOR" << endl;
	while(true) {
		string line = getLine("> ");
		if(line.at(0) == '-' || line.at(0) == '.') {
			transFromMorse(line, fromMorse);
		} else if(isalpha(line.at(0))) {
			transToMorse(line, toMorse);
		} else {
			cout << "Only dots dashes or alpha please!" << endl;
		}
	}
	
}

// Functions

void initMaps(Map<string,string> &toMorse, Map<string,string> &fromMorse) {
	toMorse.put("A", ".-");
	toMorse.put("B", "-...");
	toMorse.put("C", "-.-.");
	toMorse.put("D", "-..");
	toMorse.put("E", ".");	
	toMorse.put("F", "..-.");
	toMorse.put("G", "--.");
	toMorse.put("H", "....");
	toMorse.put("I", "..");
	toMorse.put("J", ".---");
	toMorse.put("K", "-.-");
	toMorse.put("L", ".-..");
	toMorse.put("M", "--");
	toMorse.put("N", "-.");
	toMorse.put("O", "---");
	toMorse.put("P", ".--.");
	toMorse.put("Q", "--.-");
	toMorse.put("R", ".-.");
	toMorse.put("S", "...");
	toMorse.put("T", "-");
	toMorse.put("U", "..-");
	toMorse.put("V", "...-");
	toMorse.put("W", ".--");
	toMorse.put("X", "-..-");
	toMorse.put("Y", "-.--");
	toMorse.put("Z", "--..");

	fromMorse.put(".-", "A");
	fromMorse.put("-...", "B");
	fromMorse.put("-.-.", "C");
	fromMorse.put("-..", "D");
	fromMorse.put(".", "E");	
	fromMorse.put("-...", "F");
	fromMorse.put("--.", "G");
	fromMorse.put("....", "H");
	fromMorse.put("..", "I");
	fromMorse.put(".---", "J");
	fromMorse.put("-.-", "K");
	fromMorse.put(".-..", "L");
	fromMorse.put("--", "M");
	fromMorse.put("-.", "N");
	fromMorse.put("---", "O");
	fromMorse.put(".--.", "P");
	fromMorse.put("--.-", "Q");
	fromMorse.put(".-.", "R");
	fromMorse.put("...", "S");
	fromMorse.put("-", "T");
	fromMorse.put("..-", "U");
	fromMorse.put("...-", "V");
	fromMorse.put(".--", "W");
	fromMorse.put("-..-", "X");
	fromMorse.put("-.--", "Y");
	fromMorse.put("--..", "Z");

}

void transFromMorse(string line, Map<string, string> fromMorse) {
	string letterPieces = "";
	string fullLetter = "";

	for(int i = 0; i < line.length(); i++) {
		if(line.at(i) != ' ') {
			letterPieces += line.at(i);
		} else {
			fullLetter += fromMorse.get(letterPieces);
			cout << fullLetter;
			letterPieces = "";
			fullLetter = "";

		}

	}
	fullLetter += fromMorse.get(letterPieces);
	cout << fullLetter << endl;
}

void transToMorse(string line, Map<string, string> toMorse) {
	string translation;
	for(int i = 0; i < line.length(); i++) {
		string letter = "";
		letter += line.at(i);
		translation += toMorse.get(letter);
		translation += ' ';
	}
	cout << translation << endl;
}

void printMaps(Map<string, string> toMorse, Map<string, string> fromMorse) {
	for(int i = 0; i < 26; i++) {
		char ch = 'A' + i;
		string letter = "";
		letter += ch;
		cout << ch << " : " << toMorse.get(letter) << " " << endl;
	}

}

