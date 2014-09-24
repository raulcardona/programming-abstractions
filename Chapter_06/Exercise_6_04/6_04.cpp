//
//  File: 6_04.cpp
//  Programming Abstractions C++
//
//	Exercise Description:
//
//  Created by Ben Mills on 9/24/14.
//
//

#include <stdio.h>
#include "gtypes.h"
#include "gwindow.h"

using namespace std;

const int W_WIDTH = 1500;
const int W_HEIGHT = 1000;
const int PEG_SPACER = 10;
const int N_ACROSS = W_WIDTH / PEG_SPACER;
const int N_DOWN = W_HEIGHT / PEG_SPACER;
const int DELTA = 180;

void makePoints(Vector<GPoint> &vec);
void drawStringPattern(Vector<GPoint> &vec, GWindow &window);

int main() {
    
    GWindow window(W_WIDTH, W_HEIGHT);
    Vector<GPoint> vec;
    makePoints(vec);
    drawStringPattern(vec, window);
    return 0;
}

void makePoints(Vector<GPoint> &vec) {
    // Input top row values
    for (int i = 0; i < N_ACROSS; i++) {
        GPoint point(PEG_SPACER * i, 0);
        vec.add(point);
    }
    
    // Input right column values
    for (int i = 0; i < N_DOWN; i++) {
        GPoint point(W_WIDTH, PEG_SPACER * i);
        vec.add(point);
    }
    
    // Input bottom row values
    for (int i = 0; i < N_ACROSS; i++) {
        GPoint point(W_WIDTH - (PEG_SPACER * i), W_HEIGHT);
        vec.add(point);
    }
    
    // Input left column values
    for (int i = 0; i < N_DOWN; i++) {
        GPoint point(0, (W_HEIGHT - (PEG_SPACER * i)));
        vec.add(point);
    }
    
}

void drawStringPattern(Vector<GPoint> &vec, GWindow &window) {
    
    for (int i = 0; i < vec.size(); i++) {
        if (i == 0) {
            window.drawLine(vec[i], vec[i + (DELTA)]);

        } else {
        window.drawLine(vec[i], vec[(i + DELTA) % vec.size()]);
        }
    }
    
}


