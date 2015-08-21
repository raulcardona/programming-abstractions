//
//  9_11.cpp
//  Programming Abstractions C++
//
//  Created by Ben Mills on 8/21/15.
//
//  Wildcards

#include <stdio.h>
#include <string>
#include "strlib.h"
#include "console.h"
#include "vector.h"

using namespace std;

bool wildcardMatch(string fileName, string pattern);
bool match(string fileName, string pattern, int position);

int main() {
    cout << wildcardMatch("abc", "abc") << endl;
    cout << wildcardMatch("US.txt", "*.*") << endl;
    cout << wildcardMatch("test", "*.*") << endl;
    cout << wildcardMatch("test.h", "test.?") << endl;
    cout << wildcardMatch("test.cpp", "test.?") << endl;
    cout << wildcardMatch("x", "??*") << endl;
    cout << wildcardMatch("yy", "??*") << endl;
    cout << wildcardMatch("zzz", "??*") << endl;
    return 0;
}


bool wildcardMatch(string fileName, string pattern) {
    int position = 0;
    return match(fileName, pattern, position);
}

bool match(string fileName, string pattern, int position) {
    if (position == fileName.length()) {
        if (pattern.length() > fileName.length()) {
            return false;
        } else {
        return true;
        }
    }

    for (int i = 0; i < (fileName.length() - position); i++) {
        if (fileName[i + position] == pattern[0]) {
            string SubPattern = pattern.substr(1);
            if (match(fileName, SubPattern, position + 1)) {
                return true;
            }
        }
        if (pattern[0] == '*') {
            if (pattern.length() > 1) {
                string SubPattern = pattern.substr(1);
                if (match(fileName, SubPattern, position + 1)) {
                    return true;
                }
            } else {
                return true;
            }
        }
        if (pattern[0] == '?') {
            
            string SubPattern = pattern.substr(1);
            if (match(fileName, SubPattern, position + 1)) {
                return true;
            }
        }
    }

    return false;
}
