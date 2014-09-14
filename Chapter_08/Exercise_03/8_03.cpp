#include <iostream>
#include "simpio.h"
#include "stack.h"
using namespace std;

struct Tower
{
	int numDisks;
	char start;
	char finish; 
	char temp;
	
};

void moveSingleDisk(Tower t);
void moveTower(Tower t);

int main() {
	Stack<Tower> stackOTowers;
	int n = getInteger("Enter number of disks: ");
	Tower tower;
	tower.numDisks = n;
	tower.start = 'A';
	tower.finish = 'B';
	tower.temp = 'C';
	stackOTowers.push(tower);
	while(!stackOTowers.isEmpty()) {
		moveTower(stackOTowers.pop());
	}
	return 0;
}

void moveSingleDisk(Tower t) {
	cout << t.start << " -> " << t.finish << endl;
	t.numDisks--;
}

void moveTower(Tower t) {
	if (t.numDisks <= 1) {
		moveSingleDisk(start, finish);
	} else {
		
	}





		moveTower(n - 1, start, tmp, finish);
		moveSingleDisk(start, finish);
		moveTower(n - 1, tmp, finish, start);