
#include <stdio.h>
#include "gwindow.h"
#include "random.h"

using namespace std;

GPoint drawFractalCoastline(GWindow &gw, GPoint pt, double r, double theta, int order);

const double SIZE = 600;
const double RANDOM_CHANCE_VALUE = 0.5;

int main() {
    
    GWindow gw(1000, 600);
    
    GPoint pt((gw.getWidth() / 2) - SIZE / 2, gw.getHeight() / 2);
    pt = drawFractalCoastline(gw, pt, SIZE, 0, 5);
    return 0;
}

GPoint drawFractalCoastline(GWindow &gw, GPoint pt, double r, double theta, int order) {
    if (order == 0) {
        return gw.drawPolarLine(pt, r, theta);
    } else {
        pt = drawFractalCoastline(gw, pt, r / 3, theta, order - 1);
        if (randomChance(RANDOM_CHANCE_VALUE)) {
            pt = drawFractalCoastline(gw, pt, r / 3, theta + 60, order - 1);
            pt = drawFractalCoastline(gw, pt, r / 3, theta - 60, order - 1);
        } else {
            pt = drawFractalCoastline(gw, pt, r / 3, theta - 60, order - 1);
            pt = drawFractalCoastline(gw, pt, r / 3, theta + 60, order - 1);
        }
        return drawFractalCoastline(gw, pt, r / 3, theta, order -1);
    }
}