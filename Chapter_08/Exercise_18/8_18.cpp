#include <stdio.h>
#include "simpio.h"
#include <iostream>
#include "gwindow.h"

using namespace std;

void drawSierpinski(GWindow &gw, double x, double y, double size, int order);

int main() {
    GWindow gw(700, 600);
    double edge = getReal("Enter an edge size: ");
    int order = getInteger("Enter an order size: ");
    double x = gw.getWidth() / 2;
    double y = gw.getHeight() / 2 - edge / 2;
    drawSierpinski(gw, x, y, edge, order);
    return 0;
}

void drawSierpinski(GWindow &gw, double x, double y, double size, int order) {
    if (order == 0) {
        gw.drawLine(x, y, x - (size / 2), y + size);
        gw.drawLine(x - (size / 2), y + size, x + (size / 2), y + size);
        gw.drawLine(x + (size / 2), y + size, x, y);
    } else {
        drawSierpinski(gw, x, y, size, order - 1);
        drawSierpinski(gw, x, y, size / 2, order - 1);
        drawSierpinski(gw, x - (size / 4), y + (size / 2), size / 2, order - 1);
        drawSierpinski(gw, x + (size / 4), y + (size / 2), size / 2, order - 1);
    }
}