#include <iostream>
#include "simpio.h"
using namespace std;

void countHanoiMoves(int n);
void moveTower(int n, char start, char finish, char tmp, int &count);
void moveSingleDisk(char start, char finish, int &count);

int main() {
	int n = getInteger("Enter number of disks: ");
	countHanoiMoves(n);
	return 0;
}


void countHanoiMoves(int n) {
	int count = 0;
	moveTower(n, 'A', 'B', 'C', count);
}

void moveTower(int n, char start, char finish, char tmp, int &count) {
	if (n == 1) {
		moveSingleDisk(start, finish, count);
	} else {
		moveTower(n - 1, start, tmp, finish, count);
		moveSingleDisk(start, finish, count);
		moveTower(n - 1, tmp, finish, start, count);
	}
}

void moveSingleDisk(char start, char finish, int &count) {
	count++;
	cout << count << ": " << start << " -> " << finish << endl;
}