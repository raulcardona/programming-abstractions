//
//  calendar.h
//  2_11
//
//  Created by Ben Mills on 10/9/13.
//  Extended 08/27/14
//

#ifndef _calendar_h
#define _calendar_h
#include <string>
#include "strlib.h"

using namespace std;

enum Month {
    JANUARY = 1,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
};

class Date {
    public:
        Date();

        Date(Month m, int d, int y);

        Date(int d, Month m, int y); // international order

        int getDay();
        Month getMonth();
        int getYear();

        string toString();

        
/* Instance Variables */
    Month month;
    int day;
    int year;

};


string monthToString(Month m);

string abbreviateString(int numSpaces, string str);

int daysInMonth(Month m, int y);

bool isLeapYear(int y);



 









#endif
