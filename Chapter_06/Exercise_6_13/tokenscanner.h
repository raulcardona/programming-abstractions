#indef _tokenscanner_h
#define _tokenscanner_h

#include <string>
#include "stack.h"

class TokenScanner {
	
public:

	TokenScanner();
	TokenScanner(std::string str);

	void setInput(std::string str);

	bool hasMoreTokens();

	std::string nextToken();

	void TokenScanner::saveToken(std::string str);

	void ingnoreWhitespace();

private:

	//instance variables
	std::string buffer;
	int cp;
	bool ignoreWhitespaceFlag;
	Stack<string> savedTokens;

	void skipWhitespace();
};

#endif