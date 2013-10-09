/*
 * File: 2_9.cpp
 * -------------
 * Calendar with Library
 * main program will display the number of days in each month
 * for a given year.
 */

#include <iostream>
#include "calendar.h"   
#include <string>
using namespace std;


int main() {
    int year;
    cout << "Enter a year: ";
    cin >> year;
    
    for (Month i = JANUARY; i <= 12; i++) {
        cout << monthToString(i) << " has " << daysInMonth(i, year) << " days" << endl;
    }
    
return 0;
}
