/*
 * File: 4_01.cpp
 * -------------
 * A formated Trig Table
 *
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>

using namespace std;

/* Constants */
double const PI = 3.14159265;


/* Function Prototypes */


/* main */
int main() {
    cout << " theta | sin(theta) | cos(theta) |" << endl;
    cout << "-------+------------+------------+" << endl;
    
    int theta = -90;
    for (int i = 0; i < 13; i++) {
        double currentSin = sin(theta * PI / 180); // angle must be a radian
        double currentCos = cos(theta * PI / 180);
        cout << right << setprecision(7) << showpoint << fixed
            << setw(5) << theta << "  |"
            << setw(11) << currentSin << " |"
            << setw(11) << currentCos << " |" << endl;
        
        
        theta += 15;
    }
    return 0;
}

