/*
 * File: 1_11.cpp
 * -------------
 *   *
 */

#include <iostream>




int main() {
    double number = 1.0;
    int count = 1;
    for (int i = 1; i < 20000; i += 2) {
        double fraction = 1.0 / (i + 2.0);
        if (count % 2 == 0) number += fraction;
        else number -= fraction;
        count++;
    }
    std::cout << "PI is about: " << number * 4;
}

