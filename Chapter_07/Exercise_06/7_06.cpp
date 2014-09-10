#include <iostream>
#include <iomanip>
#include <iomanip>

using namespace std;

int fib1(int n);
int fib2(int n);
int additiveSequence(int n, int t0, int t1);
int countFib1(int n);
int countFib2(int n);

int fib1Counter = 0;
int fib2Counter = 0;

int main() {
	
	// compairing to actual counts
	fib1(5);
	fib2(5);
	cout << fib1Counter << endl;
	cout << fib2Counter << endl;
	cout << countFib1(5) << endl;
	cout << countFib2(5) << endl;

	// assignment
	cout << setw(3) << right << "n" << setw(8) << "fib1" << setw(8) << "fib2" << endl;
	cout << setw(3) << right << "--" << setw(8) << "----" << setw(8) << "----" << endl;
	for (int i = 0; i < 13; i++) {
		cout << setw(3) << right << i << setw(8) << countFib1(i) << setw(8) << countFib2(i) << endl;
	}

	return 0;
}

int fib1(int n) {
	fib1Counter++;
	if (n < 2) {
		return n;
	} else {
		return fib1(n - 1) + fib1(n - 2);
	}
}

int fib2(int n) {
	fib2Counter++;
	return additiveSequence(n, 0, 1);
}

int additiveSequence(int n, int t0, int t1) {
	fib2Counter++;
	if (n == 0) return t0;
	if (n == 1) return t1;
	return additiveSequence(n - 1, t1, t0 + t1);
}

int countFib1(int n) {
	if (n < 2) {
		return 1;
	} else {
		return countFib1(n - 1) + countFib1(n - 2) + 1;
	}
}

int countFib2(int n) {
	if (n < 2) {
		return 2;
	} else {
		return countFib2(n - 1) + 1;
	}

}

