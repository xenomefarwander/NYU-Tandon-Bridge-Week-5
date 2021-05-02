/* Question 3: Print an annual calendar given any year and the first day of that year */

#include <iostream>
#include <string>
using namespace std;

void printYearCalendar(int year, int startingDay);
// Prints a formatted yearly calendar for the given year

int printMonthCalendar(int numOfDays, int startingDay);
/*  This function is given two parameters: "numOfDays" (number of days in the month)
 *   and "startingDay" (a number 1-7 that represents the day in the week of the first day
 *   in that month, e.g. 1 for Monday, 2 for Tuesday, 3 for Wednesday, etc.).
 *  Prints a formatted monthly calendar of that month and returns a number 1-7 that
 *  represents the day in the week of the last day in that month.
 */

string getMonth (int monthNum);
// Returns the name of the current month

int numOfDaysCalculator(int monthNum, int year);
// Returns number of days based on current month

bool isLeapYear(int year);
// Takes as input a year from Gregorian calendar and if a leap year returns true.

void initializeCal ();
// Prints first row of calendar, i.e. days of week

int main() {
    int inputYear;
    int startingDay;

    cout << "Please enter year in YYYY format (e.g. 2021): ";
    cin >> inputYear;
    cout << "Please enter an integer 1-7 that represents the day the year starts on\n";
    cout << "(e.g. 1 for Monday, 2 for Tuesday, 3 for Wednesday, etc.): ";
    cin >> startingDay;
    cout << "\n " << endl;

    printYearCalendar(inputYear, startingDay);

    return 0;
}

void printYearCalendar(int year, int startingDay){
    const int MONTHS_IN_YEAR = 12;
    int monthCounter;
    int numOfDays;
    int lastDay;

    for (monthCounter = 1; monthCounter <= MONTHS_IN_YEAR; monthCounter += 1){
        //Print month and year as header
        cout << getMonth(monthCounter) << " " << year << endl;
        //Get number of days in month
        numOfDays = numOfDaysCalculator(monthCounter, year);
        // Print calendar for month and return integer value (1 for Monday, 2 for Tues, etc.) for last day
        lastDay = printMonthCalendar(numOfDays, startingDay);
        startingDay = lastDay + 1;
        cout << "\n" << endl;
    }

    return;
}

int printMonthCalendar(int numOfDays, int startingDay) {
    int tabCount;
    int dayCount;
    int lastDay;

    // Print days of week
    initializeCal();
    // Print tabs so that startingDay prints under the proper day of the week
    for (tabCount = 1; tabCount < startingDay; tabCount +=1)
        cout << "\t";
    // Iterate through remaining days of week and break to new line at end of each week, stop printing on last day
    for(dayCount = 1; dayCount <= numOfDays; dayCount +=1){
        cout << dayCount;
        if (startingDay == 7) {
            if (dayCount < numOfDays)
                cout << endl;
            startingDay = 1;
        }
        else {
            cout << "\t";
            startingDay += 1;
        }
    }

    lastDay = startingDay - 1;
    return lastDay;
}

string getMonth (int monthNum){
    switch(monthNum){
        case 1:
            return "January";
            break;
        case 2:
            return "February";
            break;
        case 3:
            return "March";
            break;
        case 4:
            return "April";
            break;
        case 5:
            return "May";
            break;
        case 6:
            return "June";
            break;
        case 7:
            return "July";
            break;
        case 8:
            return "August";
            break;
        case 9:
            return "September";
            break;
        case 10:
            return "October";
            break;
        case 11:
            return "November";
            break;
        case 12:
            return "December";
            break;
        default:
            return "ERR??";
    }
}

int numOfDaysCalculator(int monthNum, int year){
    int numOfDays;
    switch(monthNum) {
        case 1:
            numOfDays = 31;
            break;
        case 2:
            if (isLeapYear(year))
                numOfDays = 29;
            else
                numOfDays = 28;
            break;
        case 3:
            numOfDays = 31;
            break;
        case 4:
            numOfDays = 30;
            break;
        case 5:
            numOfDays = 31;
            break;
        case 6:
            numOfDays = 30;
            break;
        case 7:
            numOfDays = 31;
            break;
        case 8:
            numOfDays = 31;
            break;
        case 9:
            numOfDays = 30;
            break;
        case 10:
            numOfDays = 31;
            break;
        case 11:
            numOfDays = 30;
            break;
        case 12:
            numOfDays = 31;
            break;
        default:
            numOfDays = -1;
    }

    return numOfDays;
}

void initializeCal(){
    cout << "Mon" << "\t";
    cout << "Tue" << "\t";
    cout << "Wed" << "\t";
    cout << "Thr" << "\t";
    cout << "Fri" << "\t";
    cout << "Sat" << "\t";
    cout << "Sun" << endl;

    return;
}

bool isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return true;
            } else {
                return false;
            }
        } else {
            return true;
        }
    } else {
        return false;
    }
}
