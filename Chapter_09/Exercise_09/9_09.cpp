//
//  9_09.cpp
//  Programming Abstractions C++
//
//  Created by Ben Mills on 10/28/14.
//
//  Dominoes End-To-End

#include <stdio.h>
#include "vector.h"
#include "domino.h"
#include "console.h"

const int NUM_SIDES = 6;

bool formsDominoChain(Vector<Domino> &dominos, Vector<Domino> toBeSorted, Vector<Domino> &solution);
bool isValidChain(Vector<Domino>(dominos));
Vector<Domino> subtract(Vector<Domino> vectA, Vector<Domino> vectB);

int main() {
    Vector<Domino> dominos = getVectorOfDominoes(NUM_SIDES);
    Vector<Domino> toBeSorted = dominos;
    toBeSorted.remove(0);   //remove first element since we start with it in the solution.
    Vector<Domino> solution;
    solution.add(Domino(0, 0));
    if (formsDominoChain(dominos, toBeSorted, solution)) {
        cout << "TRUE" << endl;
    } else {
        cout << "FALSE" << endl;;
    }
    return 0;
}

bool formsDominoChain(Vector<Domino> &dominos, Vector<Domino> toBeSorted, Vector<Domino> &solution) {
    if (solution.size() >= dominos.size() && isValidChain(solution)) {
        cout << solution << endl;
        return true;
    }
    for (int i = 0; i < toBeSorted.size(); i++) {
        for (int j = 0; j < 2; j++) {
            Vector<Domino> tester;
            tester += solution[solution.size() - 1];
            tester += toBeSorted[i];
            if (j == 0 && isValidChain(tester)) {
                solution += toBeSorted[i];
                if (formsDominoChain(dominos, subtract(dominos, solution), solution)) {
                    return true;
                }
                solution.remove(solution.size() - 1);
            }
            tester.clear();
            tester += solution[solution.size() - 1];
            tester += toBeSorted[i];
            tester[tester.size() - 1].flip();
            if (j == 1 && isValidChain(tester)) {
                solution += toBeSorted[i];
                Vector<Domino> flippedSolution = solution;
                flippedSolution[flippedSolution.size() - 1].flip();
                if (formsDominoChain(dominos, subtract(dominos, solution), flippedSolution)) {
                    return true;
                }
                solution.remove(solution.size() - 1);
            }
        }
    }
    return false;

}

bool isValidChain(Vector<Domino>(dominos)) {
    if (dominos.size() <= 1) {
        return true;
    } else {
        for (int i = 0; i < dominos.size() - 1; i++) {
            if (dominos[i].getDotB() != dominos[i + 1].getDotA()) {
                return false;
            }
        }
    }
    return true;
}

Vector<Domino> subtract(Vector<Domino> vectA, Vector<Domino> vectB) {
    Vector<int> indexes;
    for (int i = 0; i < vectA.size(); i++) {
        for (int j = 0; j < vectB.size(); j++) {
            Domino flipped = vectB[j];
            flipped.flip();
            if (vectA[i] == vectB[j] || vectA[i] == flipped) {
                indexes += i;
            }
        }
    }
    //proceeding backwards through vectA as to not mess with the index locations
    for (int i = indexes.size() - 1; i >= 0; i--) {
        vectA.remove(indexes[i]);
    }
    return vectA;

}
