#include <iostream>
#include "simpio.h"
#include "set.h"
using namespace std;

int countSubsetSumWays(Set<int> &set, int target);

int main() {
	Set<int> sampleSet;
	sampleSet += 1, 2, 3, 4, 5;
	cout << countSubsetSumWays(sampleSet, 5) << endl;
	cout << countSubsetSumWays(sampleSet, 16) << endl;
}

int countSubsetSumWays(Set<int> &set, int target) {
	if (set.isEmpty() && target != 0) {
		return 0;
	} else if (set.isEmpty() && target == 0) {
		return 1;
	} else {
		int element = set.first();
		Set<int> rest = set - element;
	 	return countSubsetSumWays(rest, target) + countSubsetSumWays(rest, target - element);
	}
}



/*	bool subsetSumExists(Set<int> &set, int target) {
		if (set.isEmpty() {
			return target == 0;
		} else {
			int element = set.first();
			Set<int> rest = set - element;
			return subsetSumExists(rest, target) || subsetSumExists(rest, target - element);
		}
	}
*/
