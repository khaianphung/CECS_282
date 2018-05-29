//  Kyle Pamintuan
//  CECS 282 - Section 05
//  Prog3 - Structs and Pointers
//  Due Date:     October 11, 2016
//  Turn-In Date: October 11, 2016

//  main.cpp

#include <iostream>
#include <cstring>
#include <iomanip>
#include "myDate.hpp"

using namespace std;

struct student
{
    char name[20];
    char grade;
    int ID;
    myDate birthDate;
    string hometown;
};

// Swap function for sorting
void swap(student **X, student **Y)
{
    student *temp;
    temp = *X;
    *X = *Y;
    *Y = temp;
}

// Output format
void print(student **A)
{
    // Print sorted list
    cout << setw(13) << left << "Student ID"
         << setw(20) << left << "Name"
         << setw(20) << left << "Birthday"
         << setw(10) << left << "Grade"
         << setw(20) << left << "Hometown"
         << endl;
    for (int i=0; i<10; i++)
    {
        cout << setw(13) << left << A[i]->ID
             << setw(20) << left << A[i]->name
             << setw(20) << left << A[i]->birthDate.outputString()
             << setw(10) << left << A[i]->grade
             << setw(20) << left << A[i]->hometown
             << endl;
    }
    cout << endl;
    cout << endl;
}

void sortByID(student **IDptr)
{
    //Bubble sort and print
    for (int i=0; i<10-1; i++)
    {
        for (int j=0; j<10-i-1; j++)
        {
            if (IDptr[j]->ID > IDptr[j+1]->ID)
            {
                swap(IDptr[j], IDptr[j+1]);
            }
        }
    }
    print(IDptr);
}

void sortByBirthdate(student **Birthdateptr)
{
    //Bubble sort and print
    for (int i=0; i<10-1; i++)
    {
        for (int j=0; j<10-i-1; j++)
        {
            int M, D, Y, month, day, year;
            M = Birthdateptr[j]->birthDate.getMonth();
            D = Birthdateptr[j]->birthDate.getDay();
            Y = Birthdateptr[j]->birthDate.getYear();
            month = Birthdateptr[j+1]->birthDate.getMonth();
            day = Birthdateptr[j+1]->birthDate.getDay();
            year = Birthdateptr[j+1]->birthDate.getYear();
            
            if (Birthdateptr[j]->birthDate.JD(M,D,Y) > Birthdateptr[j+1]->birthDate.JD(month, day, year))
            {
                swap(Birthdateptr[j], Birthdateptr[j+1]);
            }
        }
    }
    print(Birthdateptr);
}

void sortByGrade(student **Gradeptr)
{
    //Bubble sort and print
    for (int i=0; i<10-1; i++)
    {
        for (int j=0; j<10-i-1; j++)
        {
            if (Gradeptr[j]->grade > Gradeptr[j+1]->grade)
            {
                swap(Gradeptr[j], Gradeptr[j+1]);
            }
        }
    }
    print(Gradeptr);
}

void sortByName(student **Nameptr)
{
    //Bubble sort and print
    for (int i=0; i<10-1; i++)
    {
        for (int j=0; j<10-i-1; j++)
        {
            if (strcmp(Nameptr[j]->name, Nameptr[j+1]->name) > 0)
            {
                swap(Nameptr[j], Nameptr[j+1]);
            }
        }
    }
    print(Nameptr);
}

void sortByHometown(student **Hometownptr)
{
    //Bubble sort and print
    for (int i=0; i<10-1; i++)
    {
        for (int j=0; j<10-i-1; j++)
        {
            if (Hometownptr[j]->hometown > Hometownptr[j+1]->hometown)
            {
                swap(Hometownptr[j], Hometownptr[j+1]);
            }
        }
    }
    print(Hometownptr);
}

int main()
{
    student CECS282[10];
    int sizeOfCECS282 = 10;
    
    // Variables for ID
    int random, min, max;
    min = 999;
    max = 2000;
    
    // Variables for Birthdate
    myDate minDate(1, 1, 1994);
    myDate maxDate(12, 31, 1998);
    int startRange, endRange, randNum;
    startRange = maxDate.JD(maxDate.getMonth(), maxDate.getDay(), maxDate.getYear());
    endRange = minDate.JD(minDate.getMonth(), minDate.getDay(), minDate.getYear());
    
    // Variables for Grade
    char grades[5] = {'A', 'B', 'C', 'D', 'F'};
    int randGrade;
    
    // Variables for Hometown
    string places[20] = {"Cerritos", "Buena Park", "La Palma", "La Mirada", "La Habra", "Whittier", "Artesia", "Norwalk", "Downey", "Santa Ana", "Tustin", "Costa Mesa", "Fullerton", "Brea", "Long Beach", "Cypress", "Los Alamitos", "Irvine", "Anaheim", "Hawaiian Gardens"};
    int randPlace;
    int sizeOfplaces = 20;
    
    //  Variables for Name
    string firstNames[20] = {"Kyle", "John", "Bill", "Tyler", "Michael", "John", "Andrew", "Matthew", "Mark", "Jason", "Kelly", "Megan", "Clarissa",        "Kylie", "Andrea", "Catherine", "Hilary", "Diana", "Tara", "Julienne"};
    string lastNames[20] = {"Gates", "Zuckerberg", "Cook", "Cuban", "Bryant", "Williams", "Johnson", "Abdul-Jabbar", "Jobs", "Wozniak", "Bezos", "Koch", "Jordan", "Iverson", "McGrady", "Irving", "James", "Olajuwon", "O'Neal", "Allen"};
    int randFirstName, randLastName;
    int sizeOfNames = 20;
    string fullName;
    
    //  Set student values
    for (int i=0; i<sizeOfCECS282; i++)
    {
        //  IDs
        random = rand()%(max-min)+min;
        if (i==0)
        {
            CECS282[i].ID = random;
        }
        else if (i>0)
        {
            //  Ensures no duplicate student IDs
            for (int j=(i-1);j>=0;j--)
            {
                while (random == CECS282[j].ID)
                {
                    random = rand()%(max-min)+min;
                }
            }
            CECS282[i].ID = random;
        }
        
        //  Birthdates
        randNum = rand()%(startRange-endRange)+endRange;
        int M,D,Y;
        CECS282[i].birthDate.GDate(randNum,M,D,Y);
        CECS282[i].birthDate.setMonth(M);
        CECS282[i].birthDate.setDay(D);
        CECS282[i].birthDate.setYear(Y);
        
        //  Grades
        randGrade = rand()%sizeof(grades);
        CECS282[i].grade = grades[randGrade];
        
        //  Hometowns
        randPlace = rand()%sizeOfplaces;
        CECS282[i].hometown = places[randPlace];
        
        //  Names
        randFirstName = rand()%sizeOfNames;
        randLastName = rand()%sizeOfNames;
        fullName = firstNames[randFirstName] + " " + lastNames[randLastName];
        strncpy(CECS282[i].name, fullName.c_str(), sizeof(CECS282[i].name));    //Convert string to cstring
        CECS282[i].name[sizeof(CECS282[i].name)-1] = 0;                         //cstrings have a null value after the last char
    }
    
    // Initialzing and setting pointer values to students
    student *Original_ptr[10];
    student *Name_ptr[10];
    student *Grade_ptr[10];
    student *ID_ptr[10];
    student *Birthdate_ptr[10];
    student *Hometown_ptr[10];
    for(int i=0; i<10; i++)
    {
        Original_ptr[i] = &CECS282[i];
        Name_ptr[i] = &CECS282[i];
        Grade_ptr[i] = &CECS282[i];
        ID_ptr[i] = &CECS282[i];
        Birthdate_ptr[i] = &CECS282[i];
        Hometown_ptr[i] = &CECS282[i];
    }
    
    bool toggle = true;
    while (toggle)
    {
        // Menu and user input
        cout << "============== Student Database ==============" << endl;
        cout << "Menu" << endl;
        cout << "1) Display original list" << endl;
        cout << "2) Display list sorted by Student ID" << endl;
        cout << "3) Display list sorted by Birthday" << endl;
        cout << "4) Display list sorted by Name" << endl;
        cout << "5) Display list sorted by Grade" << endl;
        cout << "6) Display list sorted by Hometown" << endl;
        cout << "7) Exit" << endl;
        int selection;
        cin >> selection;
        cout << endl;
        cout << endl;
        
        if (selection == 1)
            print(Original_ptr);
        else if (selection == 2)
            sortByID(ID_ptr);
        else if(selection == 3)
            sortByBirthdate(Birthdate_ptr);
        else if(selection == 4)
            sortByName(Name_ptr);
        else if(selection == 5)
            sortByGrade(Grade_ptr);
        else if(selection == 6)
            sortByHometown(Hometown_ptr);
        else
            toggle=false;
    }
    
    return 0;
}
