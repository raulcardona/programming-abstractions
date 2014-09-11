#include <iostream>
#include <string>

using namespace std;

string reverse(string str);

int main() {
	string str = "program";
	cout << str << " reversed is " << reverse(str) << endl;
	return 0;
}

string reverse(string str) {
	if (str.length() <= 1) {
		return str;
	} else {
		return reverse(str.substr(1, str.length())) + str[0];
	}
}