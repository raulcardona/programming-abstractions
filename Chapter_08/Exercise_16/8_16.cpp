#include <stdio.h>
#include "gwindow.h"

using namespace std;

void drawHFractal(GWindow gw, double x, double y, double size, int order);

int main() {
    GWindow gw;
    double cx = gw.getWidth() / 2;
    double cy = gw.getHeight() / 2;
    drawHFractal(gw, cx, cy, 100, 5);
    return 0;
}

void drawHFractal(GWindow gw, double x, double y, double size, int order) {
    if (order == 0) {
        gw.drawLine(x - (size / 2), y, x + (size / 2), y);
        gw.drawLine(x - (size / 2), y - (size / 2), x - (size / 2), y + (size / 2));
        gw.drawLine(x + (size / 2), y - (size / 2), x + (size / 2), y + (size / 2));
                    
    } else {
        drawHFractal(gw, x, y, size, order - 1);
        drawHFractal(gw, x - (size / 2), y - (size / 2), size / 2, order - 1);
        drawHFractal(gw, x - (size / 2), y + (size / 2), size / 2, order - 1);
        drawHFractal(gw, x + (size / 2), y - (size / 2), size / 2, order - 1);
        drawHFractal(gw, x + (size / 2), y + (size / 2), size / 2, order - 1);
    }
}