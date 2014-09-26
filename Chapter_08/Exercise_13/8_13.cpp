//
//  File: 8_13.cpp
//  Programming Abstractions C++
//
//	Exercise Description:
//
//  Created by Ben Mills on 9/25/14.
//
//

#include <stdio.h>
#include <iostream>
#include "gwindow.h"
#include "random.h"

using namespace std;

const double MIN_AREA = 5000;
const double MAX_AREA = 10000;
const double MIN_EDGE = 20;
const int LINE_THICKNESS = 5;

void setRandomColor(GWindow &gw);
void subdivideCanvas(GWindow &gw, double x, double y, double width, double height);

int main() {
    GWindow gw(600, 400);
    subdivideCanvas(gw, 0, 0, gw.getWidth(), gw.getHeight());
    return 0;
}

void subdivideCanvas(GWindow &gw, double x, double y, double width, double height) {
    if (width * height >= MIN_AREA) {
        if (width > height) {
            double mid = randomReal(MIN_EDGE, width - MIN_EDGE);
            
            subdivideCanvas(gw, x, y, mid, height);
            subdivideCanvas(gw, x + mid, y, width - mid, height);
            gw.setColor("Black");
            gw.fillRect(x + mid, y, LINE_THICKNESS, height);
            //gw.drawLine(x + mid, y , x + mid, y + height);
            setRandomColor(gw);
            if (width * height <= MAX_AREA) {
                gw.fillRect(x, y, width, height);
            }
            pause(200);
            
            
        } else {
            double mid = randomReal(MIN_EDGE, height - MIN_EDGE);
            subdivideCanvas(gw, x, y, width, mid);
            subdivideCanvas(gw, x, y + mid, width, height - mid);
            gw.setColor("Black");
            gw.fillRect(x, y + mid, width, LINE_THICKNESS);
            //gw.drawLine(x, y + mid, x + width, y + mid);
            setRandomColor(gw);
            pause(200);
            //gw.fillRect(x, y, width, height);
        }
    }
}



void setRandomColor(GWindow &gw) {
    int color = randomInteger(0, 3);
    switch (color) {
        case 0:
            gw.setColor("Red");
            break;
        case 1:
            gw.setColor("White");
            break;
        case 2:
            gw.setColor("Yellow");
            break;
        case 3:
            gw.setColor("Blue");
            break;
        default:
            break;
    }
}