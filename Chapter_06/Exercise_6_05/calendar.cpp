//
//  calendar.cpp
//  2_11
//
//  Created by Ben Mills on 10/9/13.
//
//

#include <stdio.h>
#include <string>
#include "calendar.h"
#include "strlib.h"
#include <cctype>

using namespace std;

/* Function Prototypes */
string monthToString(Month m);
string abbreviateString(int numSpaces, string str);
int daysInMonth(Month m, int y);
bool isLeapYear(int y);

Date::Date() {
    month = JANUARY;
    day = 1;
    year = 1900;
}

Date::Date(Month m, int d, int y) {
    month = m;
    day = d;
    year = y;
}

Date::Date(int d, Month m, int y) {
    month = m;
    day = d;
    year = y;
}

int Date::getDay() {
    return day;
}

Month Date::getMonth() {
    return month;
}

int Date::getYear() {
    return year;
}

string Date::toString() {

    return integerToString(day) + "-" + abbreviateString(3, monthToString(month)) + "-" + integerToString(year);
}

string abbreviateString(int numSpaces, string str) {
    string newString = "";
    for (int i = 0; i < numSpaces; i++) {
        if (i == 0) {
            newString += toupper(str.at(i));
        }
        else newString += tolower(str.at(i));
    }
    return newString;

}

int daysInMonth(Month m, int y) {
    switch (m) {
        case APRIL:
        case JUNE:
        case SEPTEMBER:
        case NOVEMBER:
            return 30;
        case FEBRUARY:
            return (isLeapYear(y)) ? 29 : 28;
        default:
            return 31;
    }
    
}

bool isLeapYear(int y){
    return ((y % 4 == 0) && (y % 100 != 0))
        ||  (y % 400 == 0);
}

string monthToString(Month m){
    switch (m) {
        case JANUARY:
            return "JANUARY";
        case FEBRUARY:
            return "FEBRUARY";
        case MARCH:
            return "MARCH";
        case APRIL:
            return "APRIL";
        case MAY:
            return "MAY";
        case JUNE:
            return "JUNE";
        case JULY:
            return "JULY";
        case AUGUST:
            return "AUGUST";
        case SEPTEMBER:
            return "SEPTEMBER";
        case OCTOBER:
            return "OCTOBER";
        case NOVEMBER:
            return "NOVEMBER";
        case DECEMBER:
            return "DECEMBER";
        default:
            return "???";
    }
}