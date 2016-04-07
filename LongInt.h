#ifndef LONGINT_H
#define LONGINT_H

#include <iostream>
#include "StackLi.h"

using namespace std;

class LongInt
{
private:
    StackLi<int> myStack;
public:
    LongInt();
    friend istream& operator>>(istream& is, LongInt &rhs);     
    friend ostream& operator<<(ostream& os, const LongInt &rhs);
    LongInt& operator=(const LongInt& rhs);
    LongInt& operator+(const LongInt& rhs) const;
};



#endif 