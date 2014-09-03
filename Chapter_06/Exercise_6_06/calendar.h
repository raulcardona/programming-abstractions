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
        void setDate(Month m, int d, int y);
        string toString();
        
/* Instance Variables */
    private:
        Month month;
        int day;
        int year;

};

/* Operator Overloads */

std::ostream &operator<<(std::ostream &os, Date d);
Date operator++(Date &d, int );
Date operator++(Date &d);
Date operator--(Date &d, int );
Date operator--(Date &d);
Date operator+=(Date &d, int n);
Date operator-=(Date &d, int n);
bool operator<(Date d1, Date d2);
bool operator<=(Date d1, Date d2);
bool operator>(Date d1, Date d2);
bool operator>=(Date d1, Date d2);
bool operator==(Date d1, Date d2);
bool operator!=(Date d1, Date d2);
Date operator+(Date &d, int n);
Date operator-(Date &d, int n);
int operator-(Date d1, Date d2);

/* Private Methods */

Date advanceDate(Date &d);

Date retreatDate(Date &d);

string monthToString(Month m);

string abbreviateString(int numSpaces, string str);

int daysInMonth(Month m, int y);

int monthToInt(Month m);

Month intToMonth(int num);
 
bool isLeapYear(int y);


 









#endif
