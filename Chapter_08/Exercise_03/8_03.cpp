#include <iostream>
#include "simpio.h"
#include "stack.h"
using namespace std;

struct Tower
{

	Tower()
    {
        numDisks = 0;
        start = 'A';
        finish = 'B';
        temp = 'C';
    }

    Tower(int n, char a, char b, char c)
    {
        numDisks = n;
        start = a;
        finish = b;
        temp = c;
    }


	int numDisks;
	char start;
	char finish; 
	char temp;
	
};

void moveSingleDisk(Tower t);
void moveTower(Tower t, Stack<Tower> &stackOTowers);

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
		moveTower(stackOTowers.pop(), stackOTowers);
	}
	return 0;
}

void moveSingleDisk(Tower t) {
	cout << t.start << " -> " << t.finish << endl;
}

void moveTower(Tower t, Stack<Tower> &stackOTowers) {
	if (t.numDisks == 1) {
		moveSingleDisk(t);
	} else {
		stackOTowers.push(Tower(t.numDisks - 1, t.temp, t.finish, t.start));
		stackOTowers.push(Tower(1, t.start, t.finish, t.temp));
		stackOTowers.push(Tower(t.numDisks - 1, t.start, t.temp, t.finish));
	}
}
