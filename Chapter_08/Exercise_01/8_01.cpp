#include <iostream>
#include "simpio.h"
using namespace std;

int countHanoiMoves(int n);

int main() {
	int n = getInteger("Enter number of disks: ");
	cout << countHanoiMoves(n) << endl;
	return 0;
}

int countHanoiMoves(int n) {
	if (n == 0)  {
		return 0;
	} else {
		return countHanoiMoves(n - 1) + countHanoiMoves(n - 1) + 1;
	}
}