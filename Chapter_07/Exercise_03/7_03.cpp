#include <iostream>
#include "vector.h"
#include <iomanip>
using namespace std;

double getTitiusBodeDistance(int k);
int getIntInSeqAt(int b);
void fillVector(Vector<string> &planets);

int main() {
	Vector<string> planets;
	fillVector(planets);

	for (int i = 1; i < 9; i++) {
		cout << setw(9) << left << planets[i] << setw(5) << right << getTitiusBodeDistance(i) << " AU" << endl;
	}
}

double getTitiusBodeDistance(int k) {
		return (4.0 + getIntInSeqAt(k)) / 10.0;
}

int getIntInSeqAt(int b) {
	if (b == 1) {
		return b;
	} else if (b == 2) {
		return b + 1;
	} else {
		return getIntInSeqAt(b - 1) * 2;
	}

}

void fillVector(Vector<string> &planets) {
	planets.add("Will not Print");
	planets.add("Mercury");
	planets.add("Venus");
	planets.add("Earth");
	planets.add("Mars");
	planets.add("?");
	planets.add("Jupiter");
	planets.add("Saturn");
	planets.add("Uranus");
}