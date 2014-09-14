// Changing the moveTower function to check n == 0 instead of n == 1 makes it take one
// more longer every time it moves a tower.

#include <iostream>
#include "simpio.h"
using namespace std;


void moveTower(int n, char start, char finish, char tmp);
void moveSingleDisk(char start, char finish);

int main() {
	int n = getInteger("Enter number of disks: ");
	moveTower(n, 'A', 'B', 'C');
	return 0;
}


void moveTower(int n, char start, char finish, char tmp) {
	if (n == 0) {
		moveSingleDisk(start, finish);
	} else {
		moveTower(n - 1, start, tmp, finish);
		moveSingleDisk(start, finish);
		moveTower(n - 1, tmp, finish, start);
	}
}

void moveSingleDisk(char start, char finish) {
	
	cout << start << " -> " << finish << endl;
}