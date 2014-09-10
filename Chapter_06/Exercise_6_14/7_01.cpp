#include <iostream>

int cannonball(int n);

int main() {
	int num = 10;
	cout << "A " << num << " tall pyramid has " << cannonball(num) << " cannonballs inside.";
}

int cannonball(int n) {
	int totalBalls = 0 ;
	if (n == 1) {
		return n + totalBalls;
	} else {
		totalBalls += n * n;
		return cannonball(n - 1);
	}
}


// 1, 4, 9, 16, 25
// 1  2  3   4   5, 