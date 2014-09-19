#include <iostream>
#include "vector.h"

bool isMeasureable(int target, Vector<int> &weigth);

int main() {
	Vector<int> sampleWeights;
	sampleWeights += 1, 3;
	cout << isMeasureable(2, sampleWeights) << endl;
	cout << isMeasureable(5, sampleWeights) << endl;
	cout << isMeasureable(4, sampleWeights) << endl;

	return 0;
}

bool isMeasureable(int target, Vector<int> &weight) {
	if (weight.isEmpty()) {
		return target == 0;
	} else {
		int element = weight[0];
		Vector<int> rest = weight;
		rest.remove(0);
		return isMeasureable(target + element, rest) || isMeasureable(target - element, rest);
	}
}