/*
 * File: 4_02.cpp
 * -------------
 * The wind chill table from chapter 2.
 *
 *
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>

using namespace std;

/* Constants */



/* Function Prototypes */
int getWindChill(int temp, int wind);

/* main */
int main() {
    int maxTemp = 40;
    int minTemp = -45;
    int maxWind = 60;
    int minWind = 5;
    int stepperSize = 5;
    

    for (int i = minWind - 5 ; i < maxWind; i += stepperSize) {
        cout << right << setw(5) << i;
        for (int j = maxTemp; j >= minTemp; j -= stepperSize) {
            if (i < minWind) {
                cout << right << setw(5) << j;
            } else {
            cout << right << setw(5) << getWindChill(j, i);
            }
        }
        cout << endl;
    }
    
    
    return 0;
}

int getWindChill(int temp, int wind) {
    int windChill;
    if (wind == 0) {
        windChill = temp;
    } else if (temp > 40) {
        windChill = 0;
        cout << "ERRORRRRR";
    } else {
        windChill = 35.74 + 0.6215 * temp - 35.75 * pow(wind, 0.16) + 0.4275 * temp * pow(wind, 0.16);
    }
    
    
    return windChill;
}
