//  Kyle Pamintuan
//  Prog5 - Standard Template Library (STL)
//  Due Date:     November 15,2016
//  Turn-In Date: November 15, 2016

//  main.cpp

#include <iostream>
#include "BigInt.hpp"
#include <vector>
#include <map>
#include <time.h>
#include <iomanip>

using namespace std;

map<int, BigInt> resultMap;

BigInt goldRabbits(int n)
{
    static int count = 0;
    count++;
    cout << "\b\b\b\b\b\b\b\b" << count;
    
    if (n==0 || n==1)
    {
        resultMap[n] = 1;
        return resultMap[n];
    }
    else
    {
        BigInt sum = resultMap[n-1] + resultMap[n-2];
        resultMap[n] = sum;
        return resultMap[n];
    }
}

int main()
{
    long start = time(0);
    for (int n = 0; n <= 1000; n++)
    {
        BigInt answer(goldRabbits(n));
        long current = time(0);
        long deltaSeconds = current - start;
        
        cout << "\n Seconds: " << setw(5) << deltaSeconds << " , ";
        cout << "   goldRabbits(" << setw(2) << n << ") = ";
        cout << setw(11) << answer << endl;
        
    }
    return 0;
}
