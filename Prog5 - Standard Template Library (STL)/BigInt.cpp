//  Kyle Pamintuan
//  Prog5 - Standard Template Library (STL)
//  Due Date:     November 15,2016
//  Turn-In Date: November 15, 2016

//  BigInt.cpp

#include "BigInt.hpp"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

//Default constructor
BigInt::BigInt()
{
    values.push_back(0);
}

//Destructor
BigInt::~BigInt()
{
    values.clear();
    values.push_back(0);
}

//Overloaded constructor
BigInt::BigInt(string num)
{
    for (char& c: num)
    {
        int i = c - '0';
        values.push_back(i);
    }
}

//Overloaded constructor
BigInt::BigInt(int num)
{
    while (num/10 >= 1)
    {
        values.push_back(num%10);
        num/=10;
    }
    values.push_back(num);
}

//Copy constructor
BigInt::BigInt(const BigInt& B)
{
    values = B.values;
}

// ================================= Overloaded Operators =================================

BigInt BigInt::operator =(BigInt B)
{
    values = B.values;
    return (*this);
}

BigInt BigInt::operator +(BigInt B)
{
    BigInt left(*this);
    BigInt right(B);
    BigInt result;
    BigInt temp;
    int carry = 0;
    int largest = 0;
    int sizeDiff = 0;
    int rightSize = right.values.size();
    int leftSize = left.values.size();
    
    /*
        Example: 345678 + 1
     
         left = 345678
         right = 1

         This program will try to add left + right like so...

            876543
        +   1
            --------
            9XXXXX

             vector<int> left = [8][7][6][5][4][3]
                   index    i =  0  1  2  3  4  5
 
             vector<int> right = [1]
                    index    i =  0
        
         
         BUT If we don't want errors, we need to add left + right like so...


             876543
         +   100000
             --------
             976543
             
             vector<int> left = [8][7][6][5][4][3]
                   index    i =  0  1  2  3  4  5
             
             vector<int> right = [1][0][0][0][0][0]
             index           i =  0  1  2  3  4  5
     
    */
    
    //Find size of the biggest number
    largest = (leftSize > rightSize) ? leftSize : rightSize;
    
    //If the left is bigger
    if (largest == leftSize)
    {
        //Fill right's vector with zeros so that both numbers have equal amount of digits
        sizeDiff = largest - rightSize;
        for (int i=0; i<sizeDiff; i++)
        {
            right.values.push_back(0);
        }
    }
    //But, if the right is bigger
    else if ((largest == rightSize) && (leftSize != rightSize))
    {
        //Fill left's vector with zeros so that both numbers have equal amount of digits
        sizeDiff = largest - leftSize;
        for (int i=0; i<sizeDiff; i++)
        {
            left.values.push_back(0);
        }
    }
    
    //Result also needs to have equal amount of digits as left and right
    for (int i=0; i<largest-1;i++)
    {
        result.values.push_back(0);
    }
    
    //Add left + right starting from the leftmost digit
    for (int i=0; i<largest;i++)
    {
        int temp = left.values[i] + right.values[i] + carry;
        
        if (temp >= 10)
        {
            carry = 1;
            result.values[i] = temp%10;
        }
        else if (temp < 10)
        {
            result.values[i] = temp;
            carry = 0;
        }
    }
    if (carry == 1)
        result.values.push_back(1);
        
    return result;
}

ostream &operator <<(ostream &out, BigInt &B)
{
    vector<int>::reverse_iterator it;
    for (it = B.values.rbegin(); it != B.values.rend(); it++)
    {
        out << *it;
    }
    return out;
}

