#include <iostream>
#include "tokenscanner.h"
#include "strlib.h"
#include "simpio.h"
#include "error.h"

using namespace std;

void setupScanner(TokenScanner &scanner);
double findCurrentTotal(string v1, string v2, string op);

int main(int argc, char *argv[]) {
	string line = "not blank";
	double total = 0;
	while (line != "") {
		line = getLine("> ");
		TokenScanner scanner(line);
		setupScanner(scanner);
		string v1;
		string v2;
		string op;
		v1 = scanner.nextToken();
		while (scanner.hasMoreTokens()) {
			op = scanner.nextToken();
			v2 = scanner.nextToken();
			total = findCurrentTotal(v1, v2, op);
			v1 = realToString(total);	
		}
		cout << total << endl;

	}
	return 0;
}

void setupScanner(TokenScanner &scanner) {
	scanner.ignoreWhitespace();
	scanner.scanNumbers();
	scanner.addOperator("+");
	scanner.addOperator("-");
	scanner.addOperator("*");
	scanner.addOperator("/");
}

double findCurrentTotal(string v1, string v2, string op) {
	double a = atof(v1.c_str());
	double b = atof(v2.c_str());

	if (op == "+") {
		return a + b;
	} else if (op == "-") {
		return a - b;
	} else if (op == "*") {
		return a * b;
	} else if (op == "/") {
		return a / b;
	} else {
		return 0;
	}
}


