//
//  GRectangle.cpp
//  Programming Abstractions C++
//
//  Created by Ben Mills on 9/24/14.
//
//

#include "BenGRectangle.h"
#include "gtypes.h"
#include "strlib.h"

using namespace std;

BenGRectangle::BenGRectangle() {
    // Empty
}

BenGRectangle::BenGRectangle(double xc, double yc, double widthC, double heightC) {
    x = xc;
    y = yc;
    width = widthC;
    height = heightC;
}

double BenGRectangle::getX() const {
    return x;
}

double BenGRectangle::getY() const {
    return y;
}

double BenGRectangle::getWidth() const {
    return width;
}

double BenGRectangle::getHeight() const {
    return height;
}

bool BenGRectangle::isEmpty() const {
    return width <= 0 || height <= 0;
}

bool BenGRectangle::contains(double xc, double yc) const {
    return xc >= x && yc >= y && xc < x + width && yc < y + width;
}

std::string BenGRectangle::toString() const {
    return "(" + realToString(x) + "," + realToString(y) + ")";    
}
