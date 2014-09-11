#include <iostream>
#include <iomanip>
using namespace std;

int c(int n, int k);

int main() {

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j <= i; j++) {
			cout << right << setw(6) << c(i, j);
		}
		cout << endl;
	}

	return 0;
}

int c(int n, int k) {
	if (n == k) {
		return 1;
	} else if (k == 0) {
		return 1;
	} else {
		return c(n-1, k-1) + c(n-1, k);
	}
}