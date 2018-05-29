//  Kyle Pamintuan
//  Prog5 - Standard Template Library (STL)
//  Due Date:     November 15,2016
//  Turn-In Date: November 15, 2016

// BigInt.hpp

#ifndef BigInt_hpp
#define BigInt_hpp
#include <vector>
#include <stdio.h>

using namespace std;

class BigInt
{
    private:
        vector <int> values;
    public:
        BigInt();
        ~BigInt();
        BigInt(int);
        BigInt(string);
        BigInt(const BigInt&);
        BigInt operator =(BigInt);
        BigInt operator +(BigInt);
        friend ostream &operator <<(ostream &, BigInt &);
};

#endif /* BigInt_hpp */
