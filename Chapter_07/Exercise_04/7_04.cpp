#include <iostream>

using namespace std;

int gcd(int x, int y);

int main() {
	cout << gcd(5, 10) << endl << gcd(12, 90) << endl;
	return 0;
}

int gcd(int x, int y) {
	if (y % x == 0) {
		return y;
	} else {
		return gcd(y, y % x);
	}
}

