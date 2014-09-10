#include <iostream>

using namespace std;

int digitSum(int n);

int main() {
	cout << digitSum(1729) << endl;
	return 0;
}

int digitSum(int n) {
	if (n < 10) {
		return n;
	} else {
		return digitSum(n % 10) + digitSum(n / 10);
	}
}