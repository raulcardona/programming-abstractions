/*
 * File: 2_9.cpp
 * -------------
 *  Permutations!
 *  P(n, k)
 *  P(n, k) = n! / (n - k)!
 *  Find a more efficient way than calling the fact function.
 */

#include <iostream>
using namespace std;

/* Function Prototypes */
int permutations(int n, int k);
void getValues(int & n, int & k);

int main() {
    int n;
    int k;
    
    getValues(n, k);
    
    cout << "There are " << permutations(n, k) << " permutations with " <<
    n << " values in sets of " << k << endl;
    
return 0;
}

int permutations(int n, int k) {
    int perm = 1;
    int count = n - (n - k);
    
    for (int i = 0; i < count; i++) {
        perm *= n;
        n -= 1;
    }
    
    
    return perm;
}

void getValues(int & n, int & k) {
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the number per set: ";
    cin >> k;
}
