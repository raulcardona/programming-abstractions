#include <stdio.h>
#include "gwindow.h"

using namespace std;

const double SIZE = 300;
const int ORDER = 8;

void drawFractalTree(GWindow &gw, GPoint pt, double r, double theta, int order);

int main() {
    GWindow gw(1200, 800);
    GPoint pt(gw.getWidth() / 2, gw.getHeight());
    drawFractalTree(gw, pt, SIZE, 90, ORDER);
    return 0;
}

void drawFractalTree(GWindow &gw, GPoint pt, double r, double theta, int order) {
    if (order == 0) {
        pt = gw.drawPolarLine(pt, r, theta);
        pt = gw.drawPolarLine(pt, r / 2, theta + 45);
        pt = gw.drawPolarLine(pt, r / 2, theta + 225);
        pt = gw.drawPolarLine(pt, r / 2, theta - 45);
    } else {
        drawFractalTree(gw, pt, r, theta, order - 1);
        pt = gw.drawPolarLine(pt, r, theta);
        pt = gw.drawPolarLine(pt, r / 2, theta + 45);
        drawFractalTree(gw, pt, r / 2, theta + 45, order - 1);
        pt = gw.drawPolarLine(pt, r / 2, theta + 225);
        pt = gw.drawPolarLine(pt, r / 2, theta - 45);
        drawFractalTree(gw, pt, r / 2, theta - 45, order - 1);
    }
}