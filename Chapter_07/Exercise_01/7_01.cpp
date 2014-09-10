#include <iostream>
using namespace std;

int cannonball(int n, int totalBalls);

int main() {
	int num = 100;
	int total = 0;
	cout << "A " << num << " level pyramid is a total of " << cannonball(num, total) << " cannonball(s)." << endl;
}

int cannonball(int n, int totalBalls) {
	if (n == 1) {
		return n + totalBalls;
	} else {
		totalBalls += n * n;
		return cannonball(n - 1, totalBalls);
	}
}


// 1, 4, 9, 16, 25
// 1  2  3   4   5, 