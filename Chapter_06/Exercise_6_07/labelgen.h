#ifndef _labelgen_h
#define _labelgen_h
#include <string>

using namespace std;

class labelGenerator {
	public:
		labelGenerator();

		labelGenerator(string str, int num);

		string toString();

		string nextLabel();

	private:
	/* Instance Variables */
		string label = "";
		int number = 0;
};


#endif