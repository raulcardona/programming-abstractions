//
//  calendar.h
//  2_11
//
//  Created by Ben Mills on 10/9/13.
//
//

#ifndef _calendar_h
#define _calendar_h

#include <string>
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

int daysInMonth(Month month, int year);

bool isLeapYear(int year);

string monthToString(Month month);


#endif
