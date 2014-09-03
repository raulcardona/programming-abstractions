
#include <stdio.h>
#include <string>
#include <cctype>
#include "calendar.h"
#include "strlib.h"
#include "error.h"


using namespace std;

/* Function Prototypes */
string monthToString(Month m);
string abbreviateString(int numSpaces, string str);
int daysInMonth(Month m, int y);
int monthToInt(Month m);
Month intToMonth(int num);
bool isLeapYear(int y);
Date advanceDate(Date &d);
Date retreatDate(Date &d);

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

void Date::setDate(Month m, int d, int y) {
    month = m;
    day = d;
    year = y;
}


string Date::toString() {

    return integerToString(day) + "-" + abbreviateString(3, monthToString(month)) + "-" + integerToString(year);
}

/* Operator Overloads */
std::ostream &operator<<(std::ostream &os, Date d) {
    return os << d.toString();
}

Date operator++(Date &d, int) {
    Date old = d;
    d = advanceDate(d);
    return old;
}

Date operator++(Date &d) {
    d = advanceDate(d);
    return d;
}

Date operator--(Date &d, int) {
    Date old = d;
    d = retreatDate(d);
    return old;
}

Date operator--(Date &d) {
    d = retreatDate(d);
    return d;
}

Date operator+=(Date &d, int n) {
    for (int i = 0; i < n; i++) {
        d = advanceDate(d);
    }
    return d;
}

Date operator-=(Date &d, int n) {
    for (int i = 0; i < n; i++) {
        d = retreatDate(d);
    }
    return d;
}



bool operator<(Date d1, Date d2) {
    if (d1.getYear() < d2.getYear()) {
        return true;
    } else if (d1.getYear() == d2.getYear()) {
        if (monthToInt(d1.getMonth()) < monthToInt(d2.getMonth())) {
            return true;
        } else if (d1.getDay() < d2.getDay()) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool operator<=(Date d1, Date d2) {
    if ((d1.getYear() < d2.getYear()) || (d1.toString() == d2.toString())) {
        return true;
    } else if (d1.getYear() == d2.getYear()) {
        if (monthToInt(d1.getMonth()) < monthToInt(d2.getMonth())) {
            return true;
        } else if (d1.getDay() < d2.getDay()) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }

}

bool operator>(Date d1, Date d2) {
    if (d1.getYear() > d2.getYear()) {
        return true;
    } else if (d1.getYear() == d2.getYear()) {
        if (monthToInt(d1.getMonth()) > monthToInt(d2.getMonth())) {
            return true;
        } else if (d1.getDay() > d2.getDay()) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool operator>=(Date d1, Date d2) {
    if ((d1.getYear() > d2.getYear()) || (d1.toString() == d2.toString())) {
        return true;
    } else if (d1.getYear() == d2.getYear()) {
        if (monthToInt(d1.getMonth()) > monthToInt(d2.getMonth())) {
            return true;
        } else if (d1.getDay() > d2.getDay()) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool operator==(Date d1, Date d2) {
    if (d1.toString() == d2.toString()) {
        return true;
    } else {
        return false;
    }
}

bool operator!=(Date d1, Date d2) {
    return !(d1 == d2);
}

Date operator+(Date &d, int n) {
    Date plusDate;
    for (int i = 0; i < n; i++) {
        d = advanceDate(d);
    }
    return d;
}

Date operator-(Date &d, int n) {
    for (int i = 0; i < n; i++) {
        d = retreatDate(d);
    }
    return d;   
}

int operator-(Date d1, Date d2) {
    int count = 0;
    if (d1 > d2) {
        while (d1 > d2) {
            retreatDate(d1);
            count++;
        }
        return count;
    } else {
        error("Can't give negative value. Date 1 larger than Date 2.");
    }
}

/* Free Functions */
Date advanceDate(Date &d) {
    
    if (d.getDay() < daysInMonth(d.getMonth(), d.getYear())) {
        d.setDate(d.getMonth(), d.getDay() + 1, d.getYear());
    } else if (monthToInt(d.getMonth()) < 12) {
        d.setDate(intToMonth(monthToInt(d.getMonth()) + 1), 01, d.getYear());
    } else {
        d.setDate(JANUARY, 1, d.getYear() + 1);
    }
    
    return d;
}

Date retreatDate(Date &d) {
    
    if (d.getDay() > 1) {
        d.setDate(d.getMonth(), d.getDay() - 1, d.getYear());
    } else if (monthToInt(d.getMonth()) > 1) {
        d.setDate(intToMonth(monthToInt(d.getMonth()) - 1), 
            daysInMonth(intToMonth(monthToInt(d.getMonth()) - 1), d.getYear()) , d.getYear());
    } else {
        d.setDate(DECEMBER, 31, d.getYear() - 1);
    }
    
    return d;
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

Month intToMonth(int num) {
    switch (num) {
        case 1:
            return JANUARY;
        case 2:
            return FEBRUARY;
        case 3:
            return MARCH;
        case 4:
            return APRIL;
        case 5:
            return MAY;
        case 6:
            return JUNE;
        case 7:
            return JULY;
        case 8:
            return AUGUST;
        case 9:
            return SEPTEMBER;
        case 10:
            return OCTOBER;
        case 11:
            return NOVEMBER;
        case 12:
            return DECEMBER;
        default:
            return JANUARY;
    } 
}

int monthToInt(Month m) {
    switch (m) {
        case JANUARY:
            return 1;
        case FEBRUARY:
            return 2;
        case MARCH:
            return 3;
        case APRIL:
            return 4;
        case MAY:
            return 5;
        case JUNE:
            return 6;
        case JULY:
            return 7;
        case AUGUST:
            return 8;
        case SEPTEMBER:
            return 9;
        case OCTOBER:
            return 10;
        case NOVEMBER:
            return 11;
        case DECEMBER:
            return 12;
        default:
            return 0;
    } 
}


bool isLeapYear(int y){
    return ((y % 4 == 0) && (y % 100 != 0))
        ||  (y % 400 == 0);
}





