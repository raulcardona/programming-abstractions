#include <iostream>

using namespace std;

int fib(int tn);

int main() {
	for (int i = 0; i < 20; i++) {
		cout << fib(i) << endl;
	}
	return 0;
}

int fib(int tn) {
	int t0 = 0;
	int oldt0 = 0;
	int t1 = 1;
	int oldt1 = 0;

	for (int i = 0; i < tn; i++) {
		if (tn == 1) return i;
		oldt0 = t0;
		oldt1 = t1;
		t0 = t1;
		t1 = oldt0 + t1;
	}
	return oldt1;
}