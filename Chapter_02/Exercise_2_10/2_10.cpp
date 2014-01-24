/*
 * File: 2_10.cpp
 * -------------
 *  Permutations & combinations together!
 *  With a library!
 */

#include <iostream>
#include "combinatorics.h"
using namespace std;

/* Function Prototypes */
void getValues(int & n, int & k);

int main() {
    int n;
    int k;
    
    getValues(n, k);
    
    cout << "There are " << permutations(n, k) << " permutations with " <<
    n << " values in sets of " << k << endl;
    
    cout << "There are " << combinations(n, k) << " combinations with " <<
    n << " values in sets of " << k << endl;
    
    
return 0;
}

void getValues(int & n, int & k) {
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the number per set: ";
    cin >> k;
}
