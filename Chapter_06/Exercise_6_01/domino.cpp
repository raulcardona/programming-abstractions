/*
 * File: domino.cpp
 * -------------
 * The implementation of domino.h
 *
 */

#include <string>
#include "domino.h"
#include "strlib.h"

using namespace std;

/* Constructor */
	Domino::Domino() {
		dotA = 0;
		dotB = 0;
	}

	Domino::Domino(int dA, int dB) {
		dotA = dA;
		dotB = dB;
	}

/* Methods */
	int Domino::getDotA() {
		return dotA;
	}

	int Domino::getDotB() {
		return dotB;
	}

	string Domino::toString() {
		return "[" + integerToString(dotA) + "|" + integerToString(dotB) + "]";
	}

/* Operator overloads */

bool operator==(Domino tile1, Domino tile2) {
	return tile1.dotA == tile2.dotA && tile1.dotB == tile2.dotB;
}

bool operator!=(Domino tile1, Domino tile2) {
	return !(tile1 == tile2);
}

ostream &operator<<(ostream &os, Domino tile) {
	return os << tile.toString();
}