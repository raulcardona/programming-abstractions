/*
 * File: 2_8.cpp
 * -------------
 *  Find Easter!!
 */

#include <iostream>
using namespace std;

/* Function Prototypes */
int getYear(int & year);
void findEaster(int year, string & month, int & day);  // 1700 to 1899
void findEaster2(int year, string & month, int & day); // 1900 to 2099

int main() {
    string month;
    int day;
    int year;
    
    while (true) {
        getYear(year);
        if (year < 1899 && year > 1699) {
            findEaster(year, month, day);
        } else if (year < 2100 && year > 1899) {
            findEaster2(year, month, day);
        } else {
            break;
        }
        cout << "Easter falls on " << month << " " << day << " in " << year << "." << endl;

    }
    cout << "Date outside range.  Goodbye.";

return 0;
}

int getYear(int & year) {
    cout << "Enter a year that is between 1700 and 2099 to calculate Easter: ";
    cin >> year;
    
    return year;
}


void findEaster(int year, string & month, int & day) {
    int a, b, c, d, e;
    a = year % 19;
    b = year % 4;
    c = year % 7;
    d = (19 * a + 23) % 30;
    
    if (year > 1699 && year < 1800) {
        e = (2 * b + 4 * c + 6 * d + 3) % 7;
    } else {
        e = (2 * b + 4 * c + 6 * d + 4) % 7;
    }
    
    if (d + e < 9) {
        month = "March";
        day = 22 + d + e;
    } else {
        month = "April";
        day = d + e - 9;
    }
}

void findEaster2(int year, string & month, int & day) {
    int b, d, e, q;
    b = 225 - 11 * (year % 19);
    d = ((b - 21) % 30) + 21;
    if (d > 48) d -= 1;
    e = (year + (year / 4) + d + 1) % 7;
    q = d + 7 - e;
    if (q < 32) {
        month = "March";
        day = q;
    } else {
        month = "April";
        day = q - 31;
    }
}



/* Credit to http://www.smart.net/~mmontes/carter.html for the 1900 to 2099 algorithm
 
 Calculate B = 225 - 11(Y MOD 19).
 Calculate D = ((B-21) MOD 30) + 21.
 If D is greater than 48 subtract 1 from it.
 Calculate E = (Y + [Y/4] + D + 1) MOD 7 .
 Calculate Q= D + 7 - E.
 If Q is less than 32 then Easter is in March (on the Qth day). 
 If Q is greater than 31 then Q - 31 is its date in April.
 
 */
