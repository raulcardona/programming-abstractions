#include <iostream>
using namespace std;
int raiseToPower(int n, int k);

int main() {
	int number = 5;
	int power = 3; 

	cout << number << " to the power of " << power << " is " << raiseToPower(number, power) << endl;
}

int raiseToPower(int n, int k) {
	if (k <= 0) {
		return 1;
	} else {
		return n * raiseToPower(n, k - 1);
	}
}