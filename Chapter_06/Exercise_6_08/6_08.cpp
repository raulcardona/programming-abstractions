#include <iostream>
#include "rational.h"

using namespace std;


int main() {
	Rational half(1, 2);
	Rational third(1, 3);
	Rational total;
	total = half + third;
	cout << half << " + " << third << " = " << total << endl;
	for (int i = 0; i < 10; i++) {
		cout << half << endl;
		half++;
	}
	return 0;
}