//  Kyle Pamintuan
//  Prog4 - Overloading Operators
//  Due Date:     October 25,2016
//  Turn-In Date: October 25, 2016

//  upDate.cpp

#include "upDate.hpp"
#include <iostream>

using namespace std;

//Default constructor
upDate::upDate()
{
    //To dynamically allocate -> keyword 'new'
    dptr = new int[3];
    
    //Set date to May 11, 1959 (A very important date!!!)
    dptr[0] = 5;
    dptr[1] = 11;
    dptr[2] = 1959;
    
    count++;
}

//Overloaded constructor
upDate::upDate(int M, int D, int Y)
{
    dptr = new int[3];
    int jd;
    
    dptr[0] = M;
    dptr[1] = D;
    dptr[2] = Y;
    
    //Convert this date to JD
    jd = julian();
    
    //And back to GD
    GDate(jd, M, D, Y);
    
    //If the GD that was passed into the constructor is the same
    //as the GD after JD conversion, the date is valid
    if (M==dptr[0] && D==dptr[1] && Y==dptr[2])
    {
        dptr[0] = M;
        dptr[1] = D;
        dptr[2] = Y;
    }
    //If invalid, use default date
    else
    {
        dptr[0] = 5;
        dptr[1] = 11;
        dptr[2] = 1959;
    }
    
    count++;
}

//Copy constructor
upDate::upDate(const upDate &obj)
{
    dptr = new int[3];
    dptr[0] = obj.dptr[0];
    dptr[1] = obj.dptr[1];
    dptr[2] = obj.dptr[2];
    
    count++;
}

//Destructor
upDate::~upDate()
{
    count--;
    delete []dptr;
}

//Increment the date
void upDate::incrDate(int N)
{
    //Convert to JD
    int jd = julian();
    
    //Add N days to JD
    jd += N;
    
    //Convert back to GD
    GDate(jd, dptr[0], dptr[1], dptr[2]);
}

//Decrement the date
void upDate::decrDate(int N)
{
    //Convert to JD
    int jd = julian();
    
    //Subtract N days from JD
    jd -= N;
    
    //Convert back to GD
    GDate(jd, dptr[0], dptr[1], dptr[2]);
}

//Return the number of days between this date and date D
int upDate::daysBetween(upDate D)
{
    int jd1, jd2;
    
    jd1 = julian();
    jd2 = D.julian();
    
    return jd1 - jd2;
}

//Convert to Julian Date
int upDate::julian()
{
    int m, d, y;
    m = dptr[0];
    d = dptr[1];
    y = dptr[2];
    
    int jd = d-32075+1461*(y+4800+(m-14)/12)/4+367*(m-2-(m-14)/12*12)/12-3*((y+4900+(m-14)/12)/100)/4;
    
    return jd;
}

//Convert to Gregorian Date
void upDate::GDate(int JD, int &month, int &day, int &year)
{
    int I, J, K;
    int L, N;
    
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

void upDate::setDate(int M, int D, int Y)
{
    dptr[0] = M;
    dptr[1] = D;
    dptr[2] = Y;
}

int upDate::getMonth()
{
    return dptr[0];
}

int upDate::getDay()
{
    return dptr[1];
}

int upDate::getYear()
{
    return dptr[2];
}

string upDate::getMonthName()
{
    string Months[12] = {"January", "February", "March", "April", "May", "June", "July", "August",
        "September", "October", "November", "December"};
    
    return Months[dptr[0]-1];
}

//Counter for amount of upDate that objects are created
int upDate::count = 0;

//Returns the upDate object counter
int upDate::GetDateCount()
{
    return count;
}

//  ==================== OVERLOADED OPERATORS =======================

upDate upDate::operator =(upDate T)
{
    dptr[0] = T.dptr[0];
    dptr[1] = T.dptr[1];
    dptr[2] = T.dptr[2];
    return (*this);
}

upDate upDate::operator +(int n)
{
    upDate temp(*this);
    temp.incrDate(n);
    return temp;
}

upDate operator +(int x, upDate D)
{
    return D + x;
}

upDate upDate::operator -(int n)
{
    upDate temp(*this);
    temp.decrDate(n);
    return temp;
}

int upDate::operator -(upDate D)
{
    int num = daysBetween(D);
    return num;
}

upDate operator -(int x, upDate D)
{
    return D - x;
}

ostream &operator <<(ostream &out, upDate D)
{
    out << D.getMonthName() << " " << D.getDay() << ", " << D.getYear();
    return out;
}

upDate upDate::operator ++(int dummy)
{
    incrDate(1);
    return (*this);
}

upDate upDate::operator ++()
{
    incrDate(1);
    return (*this);
}

upDate upDate::operator --(int dummy)
{
    decrDate(1);
    return (*this);
}

upDate upDate::operator --()
{
    decrDate(1);
    return (*this);
}

bool upDate::operator <(upDate T)
{
    if(julian() < T.julian())
        return true;
    
    return false;
}

bool upDate::operator > (upDate T)
{
    if(julian() > T.julian())
        return true;
    
    return false;
}

bool upDate::operator ==(upDate T)
{
    if(julian() == T.julian())
        return true;
    
    return false;
}
