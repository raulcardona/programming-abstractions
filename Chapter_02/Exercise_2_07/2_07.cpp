/*
 * File: 2_7.cpp
 * -------------
 *  Homebrew SQRT function
 *  Some numbers get stuck :(  not sure how to fix yet.
 */

#include <iostream>
using namespace std;

float sqrt(float x);

int main() {
    float n;
    cout << "Enter a number to find the square root of: ";
    cin >> n;
    cout << endl;
    cout << "The root is " << sqrt(n);
    
return 0;
}

float sqrt(float x) {
    float g = x / 2;
    float average = (g + (x / g)) / 2;
    
    while (true) {
        g = average;
        average = (g + (x / g)) / 2;
        if (average == g || average == x / g) {
            break;
        }
    }
    
    return average;
}
