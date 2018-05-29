//  myDate.cpp

#include "myDate.hpp"
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

//Default constructor
myDate::myDate()
{
    //Set date to May 11, 1959 (A very important date!!!)
    month = 5;
    day = 11;
    year = 1959;
}

//Overloaded constructor
myDate::myDate(int M, int D, int Y)
{
    int a, b, c, jd;
    
    a = M;
    b = D;
    c = Y;
    
    //Convert this date to JD
    jd = JD(M, D, Y);
    
    //And back to GD
    GDate(jd, M, D, Y);
    
    //If the GD that was passed into the constructor is the same
    //as the GD after JD conversion, the date is valid
    if (M==a && D==b && Y==c)
    {
        month = M;
        day = D;
        year = Y;
    }
    //If invalid, use default date
    else
    {
        month = 5;
        day = 11;
        year = 1959;
    }
}

//Print the date
void myDate::display()
{
    string Months[12] = {"January", "February", "March", "April", "May", "June", "July", "August",
                         "September", "October", "November", "December"};
    
    cout << Months[month - 1] << " " << day << ", " << year;
}

string myDate::outputString()
{
    string Months[12] = {"January", "February", "March", "April", "May", "June", "July", "August",
                         "September", "October", "November", "December"};
    
    string someString = Months[month-1] + " " + to_string(day) + ", " + to_string(year);
    return someString;
}

//Increment the date by N days
void myDate::incrDate(int N)
{
    //Convert to JD
    int jd = JD(month, day, year);
    
    //Add N days to JD
    jd += N;
    
    //Convert back to GD
    GDate(jd, month, day, year);
}

//Decrement the date by N days
void myDate::decrDate(int N)
{
    //Convert to JD
    int jd = JD(month, day, year);
    
    //Subtract N days from JD
    jd -= N;
    
    //Convert back to GD
    GDate(jd, month, day, year);
}

//Return the number of days between this date and date D
int myDate::daysBetween(myDate D)
{
    //If date D is a future date, the return value will be a positive
    //If date D is a past date, the return value will be a negative
    
    int jd1, jd2;
    
    jd1 = JD(D.getMonth(), D.getDay(), D.getYear());
    jd2 = JD(month, day, year);
    
    return jd1 - jd2;
}

int myDate::getMonth()
{
    return month;
}

int myDate::getDay()
{
    return day;
}

int myDate::getYear()
{
    return year;
}

void myDate::setMonth(int M)
{
    month = M;
}

void myDate::setDay(int D)
{
    day = D;
}

void myDate::setYear(int Y)
{
    year = Y;
}

//Return the number of days since the current year began
int myDate::dayOfYear()
{
    int monthLength[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int DOY = day;
    
    //If this year is a leap year, the length of February is 29
    int leap = (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
    if (leap)
        monthLength[1] = 29;
    
    if (month > 1)
    {
        for (int m = month - 2; m >= 0; m--)
        {
            DOY += monthLength[m];
        }
    }
    
    return DOY;
}


//Returns the day of the week
string myDate::dayOfWeek()
{
    string Days[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    
    int julianDate, DOW;
    
    julianDate = JD(month, day, year);
    DOW = julianDate%7;
    
    return Days[DOW];
}

//Covert Gregorian Date to Julian Date
int myDate::JD(int m, int d, int y)
{
    //Formula from "Astronomical Applications"
    int jd = d-32075+1461*(y+4800+(m-14)/12)/4+367*(m-2-(m-14)/12*12)/12-3*((y+4900+(m-14)/12)/100)/4;
    
    return jd;
}

//Convert Julian Date to Gregorian Date
void myDate::GDate(int JD, int &month, int &day, int &year)
{
    int I, J, K;
    int L, N;
    
    //Equations from "Astronomical Applications"
    L = JD+68569;
    N = 4*L/146097;
    L = L-(146097*N+3)/4;
    I = 4000*(L+1)/1461001;
    L = L-1461*I/4+31;
    J = 80*L/2447;
    K = L-2447*J/80;
    L = J/11;
    J = J+2-12*L;
    I = 100*(N-49)+I+L;
    
    year = I;
    month = J;
    day = K;
}


