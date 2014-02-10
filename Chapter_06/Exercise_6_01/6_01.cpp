/*
 * File: 6_01.cpp
 * -------------
 * Use my domino class to list out a full set of dominos.
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include "domino.h"
#include "vector.h"

using namespace std;

/* Constants */

const int NUM_SIDES = 6;

/* Function Prototypes */

/* main */
int main() {
	Vector<Domino> dominoTiles;
	for (int i = 0; i <= NUM_SIDES; i++) {
		for (int j = 0; j <= NUM_SIDES; j++) {
			if (i <= j) {
				Domino tile(i, j);
				dominoTiles.add(tile);
			}
		}
	}
    int count = 0;
	while (count < dominoTiles.size()) {
		cout << dominoTiles.get(count) << endl;
		count++;
	}

    return 0;
}

