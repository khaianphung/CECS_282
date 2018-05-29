//  myDate.hpp

#ifndef myDate_hpp
#define myDate_hpp
#include <string>
#include <stdio.h>

using namespace std;

class myDate
{
    private:
        int month;
        int day;
        int year;
    public:
        myDate();
        myDate(int M, int D, int Y);
        void display();
        string outputString();
        void incrDate(int N);
        void decrDate(int N);
        int daysBetween(myDate D);
        void setMonth(int M);
        void setDay(int D);
        void setYear(int Y);
        int getMonth();
        int getDay();
        int getYear();
        int dayOfYear();
        string dayOfWeek();
        int JD(int m, int d, int y);
        void GDate(int JD, int &month, int &day, int &year);
};

#endif /* myDate_hpp */
