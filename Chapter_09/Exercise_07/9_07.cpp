//
//  File: 9_07.cpp
//  Programming Abstractions C++
//
//	Exercise Description:
//
//  Created by Ben Mills on 10/8/14.
//
//

#include <stdio.h>
#include "cube.h"
#include "console.h"
#include "vector.h"
#include "set.h"
#include <stdlib.h>
#include "strlib.h"


using namespace std;

const int TOTAL_CUBES = 4;
const int MAX_ROTATION = 4;
const int TOTAL_SIDES_PER_CUBE = 6;

bool isUnique(Vector<char> vec);
bool solveInsanity(Vector<Cube> fourCubes, Vector<string> &answer, int cubeIndex, int rotationIndex, int sideIndex);
bool puzzleCheck(Vector<Cube> fourCubes, Vector<string> &answer, int cubeIndex, int rotationIndex, int sideIndex);

int main() {
    Cube cubeA('G', 'W', 'B', 'B', 'R', 'G');
    Cube cubeB('R', 'W', 'W', 'G', 'B', 'G');
    Cube cubeC('W', 'R', 'R', 'W', 'B', 'G');
    Cube cubeD('B', 'G', 'R', 'R', 'R', 'W');
    Vector<Cube> fourCubes;
    fourCubes += cubeA, cubeB, cubeC, cubeD;
    Vector<int> sideIndex(TOTAL_CUBES);
    Vector<string> answer(TOTAL_CUBES);
    if (solveInsanity(fourCubes, answer, 0, 0, 0)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    return 0;
}

bool solveInsanity(Vector<Cube> fourCubes, Vector<string> &answer, int cubeIndex, int rotationIndex, int sideIndex) {
    cout << "CUBE INDEX: " << cubeIndex << endl;
    if (cubeIndex >= TOTAL_CUBES) {
        return true;
    }
    for (int s = 0; s < TOTAL_SIDES_PER_CUBE; s++) {
        cout << "SIDE: " << s << endl;
        for (int r = 0; r < MAX_ROTATION; r++) {
            cout << "ROTATION: " << r << endl;
            if (puzzleCheck(fourCubes, answer, cubeIndex, r, s)) {
                if (solveInsanity(fourCubes, answer, cubeIndex + 1, r, s)) {
                    return true;
                }
                answer[cubeIndex] = "";
            }
            if (s == TOTAL_SIDES_PER_CUBE - 1 && r == MAX_ROTATION - 1) {
                cubeIndex--;
                cout << "CUBE INDEX: "<< cubeIndex << endl;
            }
        }
        cout << endl;
    }
    return false;
}

bool puzzleCheck(Vector<Cube> fourCubes, Vector<string> &answer, int cubeIndex, int rotationIndex, int sideIndex) {
    Vector<char> sideA;
    Vector<char> sideB;
    Vector<char> sideC;
    Vector<char> sideD;

    for (int i = 0; i <= cubeIndex; i++) {
        if (i == cubeIndex) {
            sideA += fourCubes[i].getRotationSides(sideIndex)[(rotationIndex + 0) % 4];
            sideB += fourCubes[i].getRotationSides(sideIndex)[(rotationIndex + 1) % 4];
            sideC += fourCubes[i].getRotationSides(sideIndex)[(rotationIndex + 2) % 4];
            sideD += fourCubes[i].getRotationSides(sideIndex)[(rotationIndex + 3) % 4];
        } else {
            sideA += answer[i][0];
            sideB += answer[i][1];
            sideC += answer[i][2];
            sideD += answer[i][3];

        }
    }
    cout << "PUZZLE CHECK: " << sideA << " " << sideB << " " << sideC << " " << sideD << endl;

    if (isUnique(sideA) && isUnique(sideB) && isUnique(sideC) && isUnique(sideD)) {
        answer[cubeIndex] += sideA[cubeIndex];
        answer[cubeIndex] += sideB[cubeIndex];
        answer[cubeIndex] += sideC[cubeIndex];
        answer[cubeIndex] += sideD[cubeIndex];
    
        cout << "ANSWER: " << answer << endl;
        cout << "GOT IT" << endl;
        return true;
    }
    return false;
}

bool isUnique(Vector<char> vec) {
    Set<char> test;
    for (int i = 0; i < vec.size(); i++) {
        test.add(vec[i]);
    }
    if (test.size() == vec.size()) {
        return true;
    } else {
        return false;
    }

}
