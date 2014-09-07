// This works but it is so messy and cluttered.  I feel like I missed the point - I should redo using a class and trying to simplify.
#include <iostream>
#include <cctype>
#include <stdlib.h>
#include "tokenscanner.h"
#include "strlib.h"
#include "simpio.h"
#include "error.h"
#include "map.h"

using namespace std;

void setupScanner(TokenScanner &scanner);
double findCurrentTotal(string v1, string v2, string op, Map<string, double> &variables);

int main(int argc, char *argv[]) {
	string line = "not blank";
	double total = 0;
	Map<string, double> variables;
	while (line != "") {
		line = getLine("> ");
		TokenScanner scanner(line);
		setupScanner(scanner);
		string v1;
		string v2;
		string op;
		int counter = 0;
		bool complexAssignmentFlag = false;
		string complexVariable;
		while (scanner.hasMoreTokens()) {
			if (counter == 0) {
				v1 = scanner.nextToken();
			}
			op = scanner.nextToken();
			v2 = scanner.nextToken();
			if (op == "" && isdigit(v1[0])) {
				cout << v1 << endl;
			} else if (op == "" && isalpha(v1[0])) {
				cout << variables.get(v1) << endl;
			} else if (op == "=") {
					if (!scanner.hasMoreTokens()) {
						if (isalpha(v1[0]) && isdigit(v2[0])) {
							variables.put(v1, atof(v2.c_str()));							
						} else {
							variables.put(v1, variables.get(v2));
						}
					} else {
						complexAssignmentFlag = true;
						complexVariable = v1;
						v1 = v2;
					}
			} else {
				total = findCurrentTotal(v1, v2, op, variables);
				if (!scanner.hasMoreTokens()) {
					if (!complexAssignmentFlag) {
					cout << total << endl;
					} else {
						variables.put(complexVariable, total);
					}
				}
				v1 = realToString(total);
			}
			counter++;
		}
	}
	return 0;
}

void setupScanner(TokenScanner &scanner) {
	scanner.ignoreWhitespace();
	scanner.scanNumbers();

}

double findCurrentTotal(string v1, string v2, string op, Map<string, double> &variables) {
	double a;
	double b;

	if (isalpha(v1[0]) && isdigit(v2[0])) {
		cout << "a.d" << endl;
		a = variables.get(v1);
		b = atof(v2.c_str());
	} else if (isdigit(v1[0]) && isalpha(v2[0])) {
		cout << "d.a" << endl;
		a = atof(v1.c_str());
		b = variables.get(v2);
	} else if (isalpha(v1[0]) && isalpha(v2[0])) {
		cout << "a.a" << endl;
		a = variables.get(v1);
		b = variables.get(v2);
	} else {
		cout << "d.d" << endl;
		a = atof(v1.c_str());
		b = atof(v2.c_str());
	}

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


