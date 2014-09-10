#include <iostream>

using namespace std;

int digitSum(int n);
int digitalRoot(int n);

int main() {
	cout << digitalRoot(1729) << endl;

	return 0;
}

int digitSum(int n) {
	if (n < 10) {
		return n;
	} else {
		return digitSum(n % 10) + digitSum(n / 10);
	}
}

int digitalRoot(int n) {
	if (digitSum(n) < 10) {
		return digitSum(n);
	} else {
		return digitalRoot(digitSum(n));
	}
}