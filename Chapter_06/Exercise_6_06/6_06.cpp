#include <stdio.h>
#include "calendar.h"
#include <string>
#include "strlib.h"
#include <iomanip>
using namespace std;

int main () {
	Date electionDay(6, NOVEMBER, 2012);
	Date inaugurationDay(21, JANUARY, 2013);
	Date myBirthday(JUNE, 5, 1982);
	Date today(SEPTEMBER, 2, 2014);
	cout << inaugurationDay - electionDay << endl;
	int count = 0;
	for (Date d = myBirthday; d <= today; d++) {
		if (count % 10 == 0) {
			cout << endl;
		}
		count++;
		cout << setw(11) << d << "  ";

	}
	cout << endl << "I'm " << count << "days old." << endl;
	cout << "That's " << count / 30 << " months old." << endl;
	return 0;
}