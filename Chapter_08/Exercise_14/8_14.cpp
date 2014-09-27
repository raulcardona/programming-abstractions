//
//  File: 8_14.cpp
//  Programming Abstractions C++
//
//	Exercise Description:
//
//  Created by Ben Mills on 9/25/14.
//
//

#include <stdio.h>
#include "gwindow.h"

using namespace std;
void oneInchLine(GWindow &gw, double tickSize, double xPos);

const double HALF_INCH_TICK = 0.5;
const int TICK_SIZER = 400;
const double MINIMUM_TICK_SIZE = 0.0625 * TICK_SIZER;


int main() {
    GWindow gw(800, 250);
    oneInchLine(gw, HALF_INCH_TICK * TICK_SIZER, gw.getWidth() / 2);
    return 0;
}

void oneInchLine(GWindow &gw, double tickSize, double xPos) {
    if (tickSize >= MINIMUM_TICK_SIZE) {
        gw.drawLine(xPos, gw.getHeight(), xPos, gw.getHeight() - tickSize);
        oneInchLine(gw, tickSize / 2, xPos - tickSize);
        oneInchLine(gw, tickSize / 2, xPos + tickSize);
    }
}