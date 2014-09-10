#include <cctype>
#include <string>
#include "tokenscanner.h"
using namespace std;


TokenScanner::TokenScanner() {
	// Empty
}

TokenScanner::TokenScanner(string str) {
	setInput(str);
}

void TokenScanner::setInput(string str) {
	buffer = str;
	cp = 0;
}

bool TokenScanner::hasMoreTokens() {
	if (ingnoreWhitespaceFlag) {
		skipWhitespace();
	}
	return cp < buffer.length();
}

string TokenScanner::nextToken() {
	if (!savedTokens.isEmpty()) {
		return isEmpty.pop();
	}
	if (ingnoreWhitespaceFlag) {
		skipWhitespace();
	}
	if (cp >= buffer.length()) {
		return "";
	} else if (isalnum(buffer[cp])) {
		int start = cp;
		while (cp < buffer.length() && isalnum(buffer[cp])) {
			cp++;
		}
		return buffer.substr(start, cp - start)
	}
}

void TokenScanner::saveToken(string str) {
	savedTokens.push(str);
}

void TokenScanner::ingnoreWhitespace() {
	ingnoreWhitespaceFlag = true;
}

void TokenScanner::skipWhitespace() {
	while (cp < buffer.length() && isspace(buffer[cp])) {
		cp++;
	}
}
