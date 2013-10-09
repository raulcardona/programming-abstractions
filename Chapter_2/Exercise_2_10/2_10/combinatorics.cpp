//
//  combinatorics.cpp
//  2_10
//
//  Created by Ben Mills on 10/9/13.
//
//

#include <stdio.h>
#include <math.h>

/* Functino: permutatinos(n, k)
 * Usage: int nWays = permutations(n, k);
 * ---------------------------------------
 * Returns the mathematical combinations function P(n, k), which is
 * the number of ways one can choose k elements from a set of size n.
 * Permutations define k1/k2 not equal to k2/k1.
 */

int permutations(int n, int k) {
    int perm = 1;
    int count = n - (n - k);
    
    for (int i = 0; i < count; i++) {
        perm *= n;
        n -= 1;
    }
    
    return perm;
}



/* Functino: combinations(n, k)
 * Usage: int nWays = combinations(n, k);
 * ---------------------------------------
 * Returns the mathematical combinations function C(n, k), which is
 * the number of ways one can choose k elements from a set of size n.
 * The combinations function defines k1/k2 = k2/k1.
 */

int combinations(int n, int k) {
    int comb = 1;
    int k_count = 1;
    int count = n - (n - k);
    
    for (int i = 0; i < count; i++) {
        comb *= n;
        n -= 1;
    }
    
    for (int i = 1; i <= k; i++) {
            k_count *= i;
    }
    
    comb /= k_count;
    
    return comb;
}

