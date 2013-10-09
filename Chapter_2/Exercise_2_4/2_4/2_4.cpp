/*
 * File: 2_4.cpp
 * -------------
 *  Wind chill calculator
 *
 */

#include <iostream>
#include <math.h>
using namespace std;

int getWindChill(int temp, int wind);

int main() {
    int temperature;
    int windSpeed;
    
    cout << "Enter a temperature: ";
    cin >> temperature;
    cout << endl << "Enter a wind speed: ";
    cin >> windSpeed;
    cout << endl << "The wind chill makes it feel " << getWindChill(temperature, windSpeed);
    
    
    
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


