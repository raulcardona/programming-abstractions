/*
 * File: domino.h
 * -------------
 * This interface exports the Domino class, which represents a domino game tile.
 *
 */

#ifndef _point_h
#define _point_h

#include <iostream>
#include <string>
#include "vector.h"

class Domino {

public:

/* Constructor */
	Domino();
	Domino(int dA, int dB);

/* Methods */
	int getDotA();
	int getDotB();
    void flip();
	std::string toString();

/* Friend declaration */

	friend bool operator==(Domino tile1, Domino tile2);

/* Instance variables */
private:
	int dotA;
	int dotB;
};

/* Operator overloads */

bool operator==(Domino tile1, Domino tile2);

bool operator!=(Domino tile1, Domino tile2);

std::ostream &operator<<(std::ostream &os, Domino tile);

/* Functions */

Vector<Domino> getVectorOfDominoes(int numSides);

#endif