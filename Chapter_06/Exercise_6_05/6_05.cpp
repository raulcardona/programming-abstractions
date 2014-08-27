#include <iostream>
#include "calendar.h"

int main() {

	Date moonLanding(JULY, 20, 1969);

	cout << moonLanding.toString() << endl;

	return 0;
}